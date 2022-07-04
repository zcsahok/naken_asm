/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: https://www.mikekohn.net/
 * License: GPLv3
 *
 * Copyright 2010-2022 by Michael Kohn
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disasm/arc.h"
#include "table/arc.h"

#define READ_RAM16(a) ((memory_read_m(memory, a + 0) << 8) | \
                       (memory_read_m(memory, a + 1)))

#define READ_RAM32(a) (memory_read16_m(memory, a + 0) << 16) | \
                       memory_read16_m(memory, a + 2);

#define LIMM 0x3e

static char *condition_codes[] =
{
  ".al",
  ".eq",
  ".ne",
  ".pl",
  ".mi",
  ".cs",
  ".cc",
  ".vs",
  ".vc",
  ".gt",
  ".ge",
  ".lt",
  ".le",
  ".hi",
  ".ls",
  ".pnz",
};

#if 0
static int compute_s12(int data)
{
  int s12 = ((data & 0x3f) << 6) | ((data >> 6) & 0x3f);
  if ((s12 & 0x800) != 0) { s12 |= 0xfffff000; }

  return s12;
}
#endif

int get_register(struct _memory *memory, int address, int r, char *s)
{
  switch (r)
  {
    case 26: strcpy(s, "gp"); break;
    case 27: strcpy(s, "fp"); break;
    case 28: strcpy(s, "sp"); break;
    case 29: strcpy(s, "ilink1"); break;
    case 30: strcpy(s, "ilink2"); break;
    case 31: strcpy(s, "blink"); break;
    case 60: strcpy(s, "lp_count"); break;
    case 62:
    {
      int limm = READ_RAM32(address + 4);
      sprintf(s, "0x%08x", limm);
      return 4;
    }
    case 63: strcpy(s, "pcl"); break;
    default: sprintf(s, "r%d", r); break;
  }

  return 0;
}

int map16_bit_register(int r)
{
  if (r <= 3) { return r; }

  return r + 8;
}

int get_cycle_count_arc(unsigned short int opcode)
{
  return -1;
}

uint32_t calc_address(struct _memory *memory, uint32_t address, int offset, int d)
{
  //int cycles_min, cycles_max;
  //char instruction[128];

  if (d == 1)
  {
    //address += disasm_arc(memory, address + 4, instruction, &cycles_min, & cycles_max);
    address += 4;
  }

  return address + 4 + offset;
}

int disasm_arc(struct _memory *memory, uint32_t address, char *instruction, int *cycles_min, int *cycles_max)
{
  uint32_t opcode;
  uint16_t opcode16;
  int opcode_type;
  char temp[128];
  char name[64];
  char reg_a[32];
  char reg_b[32];
  char reg_c[32];
  //int offset;
  int immediate;
  int n, a, c, b, q, f;
  const char *cc = "??";

  opcode_type = memory_read16_m(memory, address) >> 11;

  opcode16 = memory_read16_m(memory, address);
  opcode = (memory_read16_m(memory, address) << 16) |
            memory_read16_m(memory, address + 2);

  a = opcode & 0x3f;
  c = (opcode >> 6) & 0x3f;
  b = (((opcode >> 12) & 0x7) << 3) | ((opcode >> 24) & 0x7);
  f = (opcode >> 15) & 0x1;
  q = opcode & 0x1f;
  //u6 = (opcode >> 6) & 0x3f;

  if (q <= 0xf) { cc = condition_codes[q]; }

  *cycles_min = -1;
  *cycles_max = -1;

  // ALU instructions.
  if (opcode_type == 0x04)
  {
    int o = opcode16 & 0x3f;

    for (n = 0; table_arc_alu[n].instr != NULL; n++)
    {
      if (table_arc_alu[n].opcode == o)
      {
        int sub_type = (opcode16 >> 6) & 0x03;
        strcpy(name, table_arc_alu[n].instr);
        int size = 0;

        get_register(memory, address, a, reg_a);
        get_register(memory, address, b, reg_b);
        get_register(memory, address, c, reg_c);

        switch (sub_type)
        {
          case 0:
            if (a == LIMM && c == LIMM)
            {
              // xxx.f 0,b,limm
              immediate = READ_RAM32(address + 4);
              sprintf(temp, "0, %s, 0x%04x", reg_b, immediate);
              size += 4;
            }
              else
            if (a == LIMM)
            {
              // xxx.f 0,b,c
              sprintf(temp, "0, %s, %s", reg_b, reg_c);
            }
              else
            if (b == LIMM)
            {
              // xxx.f a,limm,c
              immediate = READ_RAM32(address + 4);
              sprintf(temp, "%s, 0x%04x, %s", reg_a, immediate, reg_c);
              size += 4;
            }
              else
            if (c == LIMM)
            {
              // xxx.f a,b,limm
              immediate = READ_RAM32(address + 4);
              sprintf(temp, "%s, %s, 0x%04x", reg_a, reg_b, immediate);
              size += 4;
            }
              else
            {
              // xxx.f a,b,c
              sprintf(temp, "%s, %s, %s", reg_a, reg_b, reg_c);
            }
            break;
          case 1:
            if (c == LIMM)
            {
              // xxx.f 0,b,u6
              sprintf(temp, "0, %s, %d", reg_b, c);
            }
              else
            {
              // xxx.f a,b,u6
              sprintf(temp, "%s, %s, %d", reg_a, reg_b, c);
            }
            break;
          case 2:
            // xxx.f b,b,s12
            immediate = opcode & 0xfff;
            if ((immediate & 0x800) != 0) { immediate |= 0xfffff000; }
            sprintf(temp, "%s, %s, %d", reg_b, reg_b, immediate);
            break;
          case 3:
            strcat(name, cc);

            if ((opcode & 0x0020) != 0)
            {
              // xxx.cc.f b,b,u6
              sprintf(temp, "%s, %s, %d", reg_b, reg_b, c);
            }
              else
            if (a == LIMM)
            {
              // xxx.cc.f 0,limm,c
              immediate = READ_RAM32(address + 4);
              sprintf(temp, "0, 0x%04x, %s", immediate, reg_c);
              size += 4;
            }
              else
            if (c == LIMM)
            {
              // xxx.cc.f b,b,limm
              immediate = READ_RAM32(address + 4);
              sprintf(temp, "%s, %s, 0x%04x", reg_b, reg_b, immediate);
              size += 4;
            }
              else
            {
              // xxx.cc.f b,b,c
              sprintf(temp, "%s, %s, %s", reg_b, reg_b, reg_c);
            }
            break;
        }

        if (f == 1)
        {
          strcat(name, ".f");
        }

        sprintf(instruction, "%s %s", name, temp);

        return size == 0 ? 4 : 8;
      }
    }

    if (table_arc_alu[n].instr != NULL)
    {
      if (f != 0) { strcat(name, ".f"); }
      strcpy(instruction, name);

      return 4;
    }
  }

  // Single operand instructions.
  if (opcode_type == 0x04 && a == 1)
  {
    int o = opcode & 0x3f;

    for (n = 0; table_arc_single[n].instr != NULL; n++)
    {
      if (table_arc_single[n].opcode == o)
      {
        int sub_type = (opcode16 >> 6) & 0x03;
        strcpy(name, table_arc_single[n].instr);
        int size = 0;

        get_register(memory, address, a, reg_a);
        get_register(memory, address, b, reg_b);
        get_register(memory, address, c, reg_c);

        switch (sub_type)
        {
          case 0:
            if (c == LIMM)
            {
              // xxx.f b,limm
              // xxx.f 0,limm
              immediate = READ_RAM32(address + 4);
              sprintf(temp, "%s, 0x%04x", b == LIMM ? "0" : reg_b, immediate);
              size += 4;
            }
              else
            {
              // xxx.f b,c
              // xxx.f 0,c
              sprintf(temp, "%s, %s", b == LIMM ? "0" : reg_b, reg_c);
            }
            break;
          case 1:
            if (b == LIMM)
            {
              // xxx.f b,limm
              immediate = READ_RAM32(address + 4);
              sprintf(temp, "%s, 0x%04x", reg_b, immediate);
              size += 4;
            }
              else
            {
              // xxx.f b,u6
              sprintf(temp, "%s, %d", reg_b, c);
            }
            break;
          case 2:
          case 3:
            continue;
        }

        if (f == 1)
        {
          strcat(name, ".f");
        }

        sprintf(instruction, "%s %s", name, temp);

        return size == 0 ? 4 : 8;
      }
    }
  }

  // 16 bit opcodes.
  for (n = 0; table_arc16[n].instr != NULL; n++)
  {
    int o = opcode16 & table_arc16[n].mask;
    strcpy(instruction, table_arc16[n].instr);

    if (table_arc16[n].opcode == o)
    {
      int i, size = 2;
      temp[0] = 0;

      for (i = 0; i < table_arc16[n].operand_count; i++)
      {
        strcat(instruction, i == 0 ? " " : ", ");

        switch (table_arc16[n].operands[i])
        {
          case OP_A:
            sprintf(temp, "r%d", opcode16 & 0x7);
            strcat(instruction, temp);
            break;
          case OP_B:
            sprintf(temp, "r%d", (opcode16 >> 8) & 0x7);
            strcat(instruction, temp);
            break;
          case OP_C:
            sprintf(temp, "r%d", (opcode16 >> 5) & 0x7);
            strcat(instruction, temp);
            break;
          case OP_H:
            a = (opcode16 >> 5) | ((opcode16 & 0x7) << 3);
            if (a == LIMM)
            {
              i = 100;
              break;
            }
            get_register(memory, address, a, reg_a);
            strcat(instruction, reg_a);
            break;
          case OP_LIMM:
            size = 6;
            immediate = READ_RAM32(address + 2);
            sprintf(temp, "0x%04x", immediate);
            break;
          case OP_U3:
            sprintf(temp, "%d", opcode16 & 0x7);
            strcat(instruction, temp);
            break;
          case OP_U5:
            sprintf(temp, "%d", opcode16 & 0x1f);
            strcat(instruction, temp);
            break;
          case OP_U7:
            sprintf(temp, "%d", (opcode16 & 0x1f) << 2);
            strcat(instruction, temp);
            break;
          case OP_U8:
            sprintf(temp, "%d", opcode16 & 0xff);
            strcat(instruction, temp);
            break;
          case OP_S11:
            immediate = opcode16 & 0x1ff;
            if ((immediate & 0x100) != 0) { immediate |= 0xffffff00; }
            sprintf(temp, "%d", immediate << 2);
            strcat(instruction, temp);
            break;
          case OP_R0:
            strcat(instruction, "r0");
            break;
          case OP_GP:
            strcat(instruction, "gp");
            break;
          case OP_SP:
            strcat(instruction, "sp");
            break;
        }
      }

      if (i == table_arc16[n].operand_count)
      {
        return size;
      }
    }
  }

#if 0
  opcode = memory_read16_m(memory, address);
  c = map16_bit_register((opcode >> 5) & 0x7);
  b = map16_bit_register((opcode >> 8) & 0x7);
  a = map16_bit_register(opcode & 0x7);
  h = ((opcode >> 5) & 0x7) | ((opcode & 0x7) << 3);
#endif


  strcpy(instruction, "???");

  return 4;
}

void list_output_arc(struct _asm_context *asm_context, uint32_t start, uint32_t end)
{
  char instruction[128];
  int cycles_min, cycles_max;
  uint32_t opcode;
  int count, n;

  fprintf(asm_context->list, "\n");

  while(start < end)
  {
    struct _memory *memory = &asm_context->memory;

    count = disasm_arc(memory, start, instruction, &cycles_min, &cycles_max);

    if (count < 4)
    {
      opcode = memory_read16_m(memory, start);
      fprintf(asm_context->list, "0x%04x: %04x     %-40s\n", start, opcode, instruction);
    }
      else
    {
      opcode = (memory_read16_m(memory, start) << 16) |
                memory_read16_m(memory, start + 2);
      fprintf(asm_context->list, "0x%04x: %08x %-40s\n", start, opcode, instruction);
    }

    for (n = 4; n < count; n = n + 4)
    {
      opcode = (memory_read16_m(memory, start + n) << 16) |
                memory_read16_m(memory, start + n + 2);

      fprintf(asm_context->list, "        %08x\n", opcode);
    }

    start += count;
  }
}

void disasm_range_arc(struct _memory *memory, uint32_t flags, uint32_t start, uint32_t end)
{
  char instruction[128];
  int cycles_min, cycles_max;
  uint32_t opcode;
  int count;
  int n;

  printf("\n");

  printf("%-7s %-7s  %-40s\n", "Addr", "Opcode", "Instruction");
  printf("------- -------- ----------------------------------       ------\n");

  while(start <= end)
  {
    count = disasm_arc(memory, start, instruction, &cycles_min, &cycles_max);

    if (count < 4)
    {
      opcode = memory_read16_m(memory, start);
      printf("0x%04x: %04x     %-40s\n", start, opcode, instruction);
    }
      else
    {
      opcode = (memory_read16_m(memory, start) << 16) |
                memory_read16_m(memory, start + 2);

      printf("0x%04x: %08x %-40s\n", start, opcode, instruction);
    }

    for (n = 4; n < count; n = n + 4)
    {
      opcode = (memory_read16_m(memory, start + n) << 16) |
                memory_read16_m(memory, start + n + 2);

      printf("        %08x\n", opcode);
    }

    start = start + count;
  }
}

