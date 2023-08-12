/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: https://www.mikekohn.net/
 * License: GPLv3
 *
 * Copyright 2010-2023 by Michael Kohn
 *
 */

#include "cpu_list.h"

#include "asm/1802.h"
#include "asm/4004.h"
#include "asm/6502.h"
#include "asm/65816.h"
#include "asm/6800.h"
#include "asm/6809.h"
#include "asm/68hc08.h"
#include "asm/68000.h"
#include "asm/8008.h"
#include "asm/8048.h"
#include "asm/8051.h"
#include "asm/86000.h"
#include "asm/arc.h"
#include "asm/arm.h"
#include "asm/arm64.h"
#include "asm/avr8.h"
#include "asm/cell.h"
#include "asm/cp1610.h"
#include "asm/common.h"
#include "asm/copper.h"
#include "asm/dotnet.h"
#include "asm/dspic.h"
#include "asm/ebpf.h"
#include "asm/epiphany.h"
#include "asm/java.h"
#include "asm/lc3.h"
#include "asm/m8c.h"
#include "asm/mips.h"
#include "asm/msp430.h"
#include "asm/pdp8.h"
#include "asm/pdk13.h"
#include "asm/pdk14.h"
#include "asm/pdk15.h"
#include "asm/pdk16.h"
#include "asm/pic14.h"
#include "asm/pic18.h"
#include "asm/powerpc.h"
#include "asm/propeller.h"
#include "asm/propeller2.h"
#include "asm/ps2_ee_vu.h"
#include "asm/riscv.h"
#include "asm/sh4.h"
#include "asm/sparc.h"
#include "asm/stm8.h"
#include "asm/super_fx.h"
#include "asm/sweet16.h"
#include "asm/thumb.h"
#include "asm/tms340.h"
#include "asm/tms1000.h"
#include "asm/tms9900.h"
#include "asm/unsp.h"
#include "asm/webasm.h"
#include "asm/xtensa.h"
#include "asm/z80.h"
#include "disasm/1802.h"
#include "disasm/4004.h"
#include "disasm/6502.h"
#include "disasm/65816.h"
#include "disasm/6800.h"
#include "disasm/6809.h"
#include "disasm/68hc08.h"
#include "disasm/68000.h"
#include "disasm/8008.h"
#include "disasm/8048.h"
#include "disasm/8051.h"
#include "disasm/86000.h"
#include "disasm/arc.h"
#include "disasm/arm.h"
#include "disasm/arm64.h"
#include "disasm/avr8.h"
#include "disasm/cell.h"
#include "disasm/copper.h"
#include "disasm/cp1610.h"
#include "disasm/dotnet.h"
#include "disasm/dspic.h"
#include "disasm/ebpf.h"
#include "disasm/epiphany.h"
#include "disasm/java.h"
#include "disasm/lc3.h"
#include "disasm/m8c.h"
#include "disasm/mips.h"
#include "disasm/msp430.h"
#include "disasm/pdp8.h"
#include "disasm/pdk13.h"
#include "disasm/pdk14.h"
#include "disasm/pdk15.h"
#include "disasm/pdk16.h"
#include "disasm/pic14.h"
#include "disasm/pic18.h"
#include "disasm/powerpc.h"
#include "disasm/propeller.h"
#include "disasm/propeller2.h"
#include "disasm/ps2_ee_vu.h"
#include "disasm/riscv.h"
#include "disasm/sh4.h"
#include "disasm/sparc.h"
#include "disasm/stm8.h"
#include "disasm/super_fx.h"
#include "disasm/sweet16.h"
#include "disasm/thumb.h"
#include "disasm/tms340.h"
#include "disasm/tms1000.h"
#include "disasm/tms9900.h"
#include "disasm/unsp.h"
#include "disasm/webasm.h"
#include "disasm/xtensa.h"
#include "disasm/z80.h"
#include "simulate/1802.h"
#include "simulate/6502.h"
#include "simulate/65816.h"
#include "simulate/8008.h"
#include "simulate/avr8.h"
#include "simulate/ebpf.h"
#include "simulate/lc3.h"
#include "simulate/mips.h"
#include "simulate/msp430.h"
#include "simulate/riscv.h"
#include "simulate/stm8.h"
#include "simulate/tms9900.h"
#include "simulate/z80.h"

#define NO_FLAGS 0

int link_not_supported(
  AsmContext *asm_context,
  Imports *imports,
  const uint8_t *code,
  uint32_t function_offset,
  int size,
  uint8_t *obj_file,
  uint32_t obj_size)
{
  printf("Error: This platform doesn't support linking.\n");
  return -1;
}

struct _cpu_list cpu_list[] =
{
#ifdef ENABLE_MSP430
  {
    "msp430",
    CPU_TYPE_MSP430,
    ENDIAN_LITTLE,
    1,
    ALIGN_2,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_msp430,
    NULL,
    link_function_msp430,
    list_output_msp430,
    disasm_range_msp430,
    SimulateMsp430::init,
    NO_FLAGS,
  },
  {
    "msp430x",
    CPU_TYPE_MSP430X,
    ENDIAN_LITTLE,
    1,
    ALIGN_2,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_24,
    parse_instruction_msp430,
    NULL,
    link_not_supported,
    list_output_msp430x,
    disasm_range_msp430x,
    SimulateMsp430::init,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_1802
  {
    "1802",
    CPU_TYPE_1802,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_1802,
    NULL,
    link_not_supported,
    list_output_1802,
    disasm_range_1802,
    Simulate1802::init,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_4004
  {
    "4004",
    CPU_TYPE_4004,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_4004,
    NULL,
    link_not_supported,
    list_output_4004,
    disasm_range_4004,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_6502
  {
    "6502",
    CPU_TYPE_6502,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_6502,
    NULL,
    link_not_supported,
    list_output_6502,
    disasm_range_6502,
    Simulate6502::init,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_65816
  {
    "65816",
    CPU_TYPE_65816,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_65816,
    NULL,
    link_not_supported,
    list_output_65816,
    disasm_range_65816,
    Simulate65816::init,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_6800
  {
    "6800",
    CPU_TYPE_6800,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_6800,
    NULL,
    link_not_supported,
    list_output_6800,
    disasm_range_6800,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_6809
  {
    "6809",
    CPU_TYPE_6809,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_6809,
    NULL,
    link_not_supported,
    list_output_6809,
    disasm_range_6809,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_68HC08
  {
    "68hc08",
    CPU_TYPE_68HC08,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_68hc08,
    NULL,
    link_not_supported,
    list_output_68hc08,
    disasm_range_68hc08,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_68000
  {
    "68000",
    CPU_TYPE_68000,
    ENDIAN_BIG,
    1,
    ALIGN_2,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_68000,
    NULL,
    link_not_supported,
    list_output_68000,
    disasm_range_68000,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_8008
  {
    "8008",
    CPU_TYPE_8008,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_8008,
    NULL,
    link_not_supported,
    list_output_8008,
    disasm_range_8008,
    Simulate8008::init,
    1,
  },
#endif
#ifdef ENABLE_8048
  {
    "8041",
    CPU_TYPE_8041,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_8048,
    NULL,
    link_not_supported,
    list_output_8048,
    disasm_range_8048,
    NULL,
    1,
  },
  {
    "8048",
    CPU_TYPE_8048,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_8048,
    NULL,
    link_not_supported,
    list_output_8048,
    disasm_range_8048,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_8051
  {
    "8051",
    CPU_TYPE_8051,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_8051,
    NULL,
    link_not_supported,
    list_output_8051,
    disasm_range_8051,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_86000
  {
    "86000",
    CPU_TYPE_86000,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_86000,
    NULL,
    link_not_supported,
    list_output_86000,
    disasm_range_86000,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_ARC
  {
    "arc",
    CPU_TYPE_ARC,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_arc,
    NULL,
    link_not_supported,
    list_output_arc,
    disasm_range_arc,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_ARM
  {
    "arm",
    CPU_TYPE_ARM,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_arm,
    NULL,
    link_not_supported,
    list_output_arm,
    disasm_range_arm,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_ARM64
  {
    "arm64",
    CPU_TYPE_ARM64,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_arm64,
    NULL,
    link_not_supported,
    list_output_arm64,
    disasm_range_arm64,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_AVR8
  {
    "avr8",
    CPU_TYPE_AVR8,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_avr8,
    NULL,
    link_not_supported,
    list_output_avr8,
    disasm_range_avr8,
    SimulateAvr8::init,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_CELL
  {
    "cell",
    CPU_TYPE_CELL,
    ENDIAN_BIG,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_cell,
    NULL,
    link_not_supported,
    list_output_cell,
    disasm_range_cell,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_COPPER
  {
    "copper",
    CPU_TYPE_COPPER,
    ENDIAN_BIG,
    1,
    ALIGN_2,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_copper,
    NULL,
    link_not_supported,
    list_output_copper,
    disasm_range_copper,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_CP1610
  {
    "cp1610",
    CPU_TYPE_CP1610,
    ENDIAN_BIG,
    2,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_cp1610,
    NULL,
    link_not_supported,
    list_output_cp1610,
    disasm_range_cp1610,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_DOTNET
  {
    "dotnet",
    CPU_TYPE_DOTNET,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_dotnet,
    NULL,
    link_not_supported,
    list_output_dotnet,
    disasm_range_dotnet,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_DSPIC
  {
    "dspic",
    CPU_TYPE_DSPIC,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_dspic,
    NULL,
    link_not_supported,
    list_output_dspic,
    disasm_range_dspic,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_EBPF
  {
    "ebpf",
    CPU_TYPE_EBPF,
    ENDIAN_LITTLE,
    8,
    ALIGN_4,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_ebpf,
    NULL,
    link_not_supported,
    list_output_ebpf,
    disasm_range_ebpf,
    SimulateEbpf::init,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_EPIPHANY
  {
    "epiphany",
    CPU_TYPE_EPIPHANY,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_epiphany,
    NULL,
    link_not_supported,
    list_output_epiphany,
    disasm_range_epiphany,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_JAVA
  {
    "java",
    CPU_TYPE_JAVA,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_java,
    NULL,
    link_not_supported,
    list_output_java,
    disasm_range_java,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_LC3
  {
    "lc3",
    CPU_TYPE_LC3,
    ENDIAN_BIG,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_lc3,
    NULL,
    link_not_supported,
    list_output_lc3,
    disasm_range_lc3,
    SimulateLc3::init,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_M8C
  {
    "m8c",
    CPU_TYPE_M8C,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_m8c,
    NULL,
    link_not_supported,
    list_output_m8c,
    disasm_range_m8c,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_MIPS
  {
    "mips",
    CPU_TYPE_MIPS32,
    ENDIAN_BIG,
    1,
    ALIGN_4,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_mips,
    NULL,
    link_function_mips,
    list_output_mips,
    disasm_range_mips,
    SimulateMips::init,
    MIPS_I | MIPS_II | MIPS_III | MIPS_IV | MIPS_FPU,
  },
  {
    "mips32",
    CPU_TYPE_MIPS32,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_mips,
    NULL,
    link_function_mips,
    list_output_mips,
    disasm_range_mips,
    SimulateMips::init,
    MIPS_I | MIPS_II | MIPS_III | MIPS_FPU | MIPS_MSA,
  },
  {
    "n64_rsp",
    CPU_TYPE_MIPS32,
    ENDIAN_BIG,
    1,
    ALIGN_4,
    0,
    0,
    1,
    0,
    0,
    1,
    0,
    SREC_32,
    parse_instruction_mips,
    NULL,
    link_function_mips,
    list_output_mips,
    disasm_range_mips,
    NULL,
    MIPS_I | MIPS_RSP,
  },
  {
    "pic32",
    CPU_TYPE_MIPS32,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_mips,
    NULL,
    link_function_mips,
    list_output_mips,
    disasm_range_mips,
    SimulateMips::init,
    MIPS_I | MIPS_II | MIPS_III | MIPS_32,
  },
  {
    "ps2_ee",
    CPU_TYPE_EMOTION_ENGINE,
    ENDIAN_LITTLE,
    1,
    ALIGN_16,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_mips,
    NULL,
    link_function_mips,
    list_output_mips,
    disasm_range_mips,
    NULL,
    MIPS_I | MIPS_II | MIPS_III | MIPS_IV | MIPS_FPU | MIPS_EE_CORE | MIPS_EE_VU,
  },
#endif
#ifdef ENABLE_PDP8
  {
    "pdp8",
    CPU_TYPE_PDP8,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_pdp8,
    NULL,
    link_not_supported,
    list_output_pdp8,
    disasm_range_pdp8,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_PADAUK
  {
    "pdk13",
    CPU_TYPE_PDK13,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    1,
    0,
    0,
    1,
    SREC_16,
    parse_instruction_pdk13,
    NULL,
    link_not_supported,
    list_output_pdk13,
    disasm_range_pdk13,
    NULL,
    NO_FLAGS,
  },
  {
    "pdk14",
    CPU_TYPE_PDK14,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    1,
    0,
    0,
    1,
    SREC_16,
    parse_instruction_pdk14,
    NULL,
    link_not_supported,
    list_output_pdk14,
    disasm_range_pdk14,
    NULL,
    NO_FLAGS,
  },
  {
    "pdk15",
    CPU_TYPE_PDK15,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    1,
    0,
    0,
    1,
    SREC_16,
    parse_instruction_pdk15,
    NULL,
    link_not_supported,
    list_output_pdk15,
    disasm_range_pdk15,
    NULL,
    NO_FLAGS,
  },
  {
    "pdk16",
    CPU_TYPE_PDK16,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    1,
    0,
    0,
    1,
    SREC_16,
    parse_instruction_pdk16,
    NULL,
    link_not_supported,
    list_output_pdk16,
    disasm_range_pdk16,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_PIC14
  {
    "pic14",
    CPU_TYPE_PIC14,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_pic14,
    NULL,
    link_not_supported,
    list_output_pic14,
    disasm_range_pic14,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_PIC18
  {
    "pic18",
    CPU_TYPE_PIC18,
    ENDIAN_LITTLE,
    1,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_pic18,
    NULL,
    link_not_supported,
    list_output_pic18,
    disasm_range_pic18,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_DSPIC
  {
    "pic24",
    CPU_TYPE_PIC24,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_24,
    parse_instruction_dspic,
    NULL,
    link_not_supported,
    list_output_dspic,
    disasm_range_dspic,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_POWERPC
  {
    "powerpc",
    CPU_TYPE_POWERPC,
    ENDIAN_BIG,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_powerpc,
    NULL,
    link_not_supported,
    list_output_powerpc,
    disasm_range_powerpc,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_PROPELLER
  {
    "propeller",
    CPU_TYPE_PROPELLER,
    ENDIAN_LITTLE,
    4,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_propeller,
    NULL,
    link_not_supported,
    list_output_propeller,
    disasm_range_propeller,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_PROPELLER2
  {
    "propeller2",
    CPU_TYPE_PROPELLER2,
    ENDIAN_LITTLE,
    4,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_propeller2,
    NULL,
    link_not_supported,
    list_output_propeller2,
    disasm_range_propeller2,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_EMOTION_ENGINE
  {
    "ps2_ee_vu0",
    CPU_TYPE_PS2_EE_VU,
    ENDIAN_LITTLE,
    1,
    ALIGN_16,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_ps2_ee_vu,
    NULL,
    link_not_supported,
    list_output_ps2_ee_vu,
    disasm_range_ps2_ee_vu,
    NULL,
    PS2_EE_VU0,
  },
  {
    "ps2_ee_vu1",
    CPU_TYPE_PS2_EE_VU,
    ENDIAN_LITTLE,
    1,
    ALIGN_16,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_ps2_ee_vu,
    NULL,
    link_not_supported,
    list_output_ps2_ee_vu,
    disasm_range_ps2_ee_vu,
    NULL,
    PS2_EE_VU1,
  },
#endif
#ifdef ENABLE_RISCV
  {
    "riscv",
    CPU_TYPE_RISCV,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_riscv,
    NULL,
    link_not_supported,
    list_output_riscv,
    disasm_range_riscv,
    SimulateRiscv::init,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_SH4
  {
    "sh4",
    CPU_TYPE_SH4,
    ENDIAN_LITTLE,
    1,
    ALIGN_2,
    0,
    0,
    1,
    1,
    1,
    0,
    0,
    SREC_16,
    parse_instruction_sh4,
    NULL,
    link_not_supported,
    list_output_sh4,
    disasm_range_sh4,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_SPARC
  {
    "sparc",
    CPU_TYPE_SPARC,
    ENDIAN_BIG,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_sparc,
    NULL,
    link_not_supported,
    list_output_sparc,
    disasm_range_sparc,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_STM8
  {
    "stm8",
    CPU_TYPE_STM8,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_stm8,
    NULL,
    link_not_supported,
    list_output_stm8,
    disasm_range_stm8,
    SimulateStm8::init,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_SUPER_FX
  {
    "super_fx",
    CPU_TYPE_SUPER_FX,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_super_fx,
    NULL,
    link_not_supported,
    list_output_super_fx,
    disasm_range_super_fx,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_SWEET16
  {
    "sweet16",
    CPU_TYPE_SWEET16,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_sweet16,
    NULL,
    link_not_supported,
    list_output_sweet16,
    disasm_range_sweet16,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_THUMB
  {
    "thumb",
    CPU_TYPE_THUMB,
    ENDIAN_LITTLE,
    1,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_thumb,
    NULL,
    link_not_supported,
    list_output_thumb,
    disasm_range_thumb,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_TMS340
  {
    "tms340",
    CPU_TYPE_TMS340,
    ENDIAN_BIG,
    1,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_tms340,
    NULL,
    link_not_supported,
    list_output_tms340,
    disasm_range_tms340,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_TMS1000
  {
    "tms1000",
    CPU_TYPE_TMS1000,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_tms1000,
    NULL,
    link_not_supported,
    list_output_tms1000,
    disasm_range_tms1000,
    NULL,
    NO_FLAGS,
  },
  {
    "tms1100",
    CPU_TYPE_TMS1100,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_tms1100,
    NULL,
    link_not_supported,
    list_output_tms1100,
    disasm_range_tms1100,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_TMS9900
  {
    "tms9900",
    CPU_TYPE_TMS9900,
    ENDIAN_BIG,
    1,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_tms9900,
    NULL,
    link_not_supported,
    list_output_tms9900,
    disasm_range_tms9900,
    SimulateTms9900::init,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_UNSP
  {
    "unsp",
    CPU_TYPE_UNSP,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    1,
    1,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_unsp,
    NULL,
    link_not_supported,
    list_output_unsp,
    disasm_range_unsp,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_WEBASM
  {
    "webasm",
    CPU_TYPE_WEBASM,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    1,
    1,
    0,
    0,
    SREC_16,
    parse_instruction_webasm,
    NULL,
    link_not_supported,
    list_output_webasm,
    disasm_range_webasm,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_XTENSA
  {
    "xtensa",
    CPU_TYPE_XTENSA,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_xtensa,
    NULL,
    link_not_supported,
    list_output_xtensa,
    disasm_range_xtensa,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_Z80
  {
    "z80",
    CPU_TYPE_Z80,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_z80,
    NULL,
    link_not_supported,
    list_output_z80,
    disasm_range_z80,
    SimulateZ80::init,
    NO_FLAGS,
  },
#endif
  { NULL },
};

