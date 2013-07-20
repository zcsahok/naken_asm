#include <stdio.h>
#include <stdlib.h>
#include "table_dspic.h"

struct _table_dspic table_dspic[] = {
  { "add", 0xb40000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "add", 0xb00000, 0x000000, 0xff8000, 0x000000, OP_LIT10_WN, 1, 1 },
  { "add", 0x400060, 0x000000, 0xf80060, 0x000000, OP_WB_LIT5_WD, 1, 1 },
  { "add", 0x400000, 0x000000, 0xf80000, 0x000000, OP_WB_WS_WD, 1, 1 },
  { "add", 0xcb0000, 0x000000, 0xff7fff, 0x000000, OP_ACC, 1, 1 },
  { "add", 0xc90000, 0x000000, 0xff0000, 0x000000, OP_WS_LIT4_ACC, 1, 1 },
  { "addc", 0xb48000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "addc", 0xb08000, 0x000000, 0xff8000, 0x000000, OP_LIT10_WN, 1, 1 },
  { "addc", 0x480060, 0x000000, 0xf80060, 0x000000, OP_WB_LIT5_WD, 1, 1 },
  { "addc", 0x480000, 0x000000, 0xf80000, 0x000000, OP_WB_WS_WD, 1, 1 },
  { "and", 0xb60000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "and", 0xb20000, 0x000000, 0xff8000, 0x000000, OP_LIT10_WN, 1, 1 },
  { "and", 0x600060, 0x000000, 0xf80060, 0x000000, OP_WB_LIT5_WD, 1, 1 },
  { "and", 0x600000, 0x000000, 0xf80000, 0x000000, OP_WB_WS_WD, 1, 1 },
  { "asr", 0xd58000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "asr", 0xd18000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "asr", 0xde8040, 0x000000, 0xff8070, 0x000000, OP_WB_LIT4_WND, 1, 1 },
  { "asr", 0xde8000, 0x000000, 0xff8070, 0x000000, OP_WB_WNS_WND, 1, 1 },
  { "bclr", 0xa90000, 0x000000, 0xff0000, 0x000000, OP_F_BIT4, 1, 1 },
  { "bclr", 0xa10000, 0x000000, 0xff0b80, 0x000000, OP_WS_BIT4, 1, 1 },
  { "bra", 0x370000, 0x000000, 0xff0000, 0x000000, OP_BRA, 2, 2 },
  { "bra", 0x016000, 0x000000, 0xfffff0, 0x000000, OP_WN, 2, 2 },
  { "bra c", 0x310000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra ge", 0x3d0000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra geu", 0x310000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra gt", 0x3c0000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra gtu", 0x3e0000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra le", 0x340000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra leu", 0x360000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra lt", 0x350000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra ltu", 0x390000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra n", 0x330000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra nc", 0x390000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra nn", 0x3b0000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra nov", 0x380000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra nz", 0x3a0000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra oa", 0x0c0000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra ob", 0x0d0000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra ov", 0x300000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra sa", 0x0e0000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra sb", 0x0f0000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bra z", 0x320000, 0x000000, 0xff0000, 0x000000, OP_BRA, 1, 2 },
  { "bset", 0xa80000, 0x000000, 0xff0000, 0x000000, OP_F_BIT4, 1, 1 },
  { "bset", 0xa00000, 0x000000, 0xff0b80, 0x000000, OP_WS_BIT4, 1, 1 },
  { "bsw", 0xad0000, 0x000000, 0xff0780, 0x000000, OP_WS_WB, 1, 1 },
  { "btg", 0xaa0000, 0x000000, 0xff0000, 0x000000, OP_F_BIT4, 1, 1 },
  { "btg", 0xa20000, 0x000000, 0xff0b80, 0x000000, OP_WS_BIT4, 1, 1 },
  { "btsc", 0xaf0000, 0x000000, 0xff0000, 0x000000, OP_F_BIT4, 1, 3 },
  { "btsc", 0xa70000, 0x000000, 0xff0f80, 0x000000, OP_WS_BIT4_2, 1, 3 },
  { "btss", 0xae0000, 0x000000, 0xff0000, 0x000000, OP_F_BIT4, 1, 3 },
  { "btss", 0xa60000, 0x000000, 0xff0f80, 0x000000, OP_WS_BIT4_2, 1, 3 },
  { "btst", 0xab0000, 0x000000, 0xff0000, 0x000000, OP_F_BIT4, 1, 1 },
  { "btst", 0xa30000, 0x000000, 0xff0780, 0x000000, OP_F_BIT4_2, 1, 1 },
  { "btst", 0xa50000, 0x000000, 0xff0780, 0x000000, OP_WS_WB, 1, 1 },
  { "btsts", 0xac0000, 0x000000, 0xff0000, 0x000000, OP_F_BIT4, 1, 1 },
  { "btsts", 0xa40000, 0x000000, 0xff0780, 0x000000, OP_F_BIT4_2, 1, 1 },
  { "call", 0x020000, 0x000000, 0xff0001, 0xffff80, OP_GOTO, 2, 2 },
  { "call", 0x010000, 0x000000, 0xfffff0, 0x000000, OP_WN, 2, 2 },
  { "clr", 0xef0000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "clr", 0xeb0000, 0x000000, 0xff807f, 0x000000, OP_WD, 1, 1 },
  { "clr", 0xc30000, 0x000000, 0xff4000, 0x000000, OP_A_WX_WY_AWB, 1, 1 },
  { "clrwdt", 0xfe6000, 0x000000, 0xffffff, 0x000000, OP_NONE, 1, 1 },
  { "com", 0xee8000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "com", 0xea8000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "cp", 0xe30000, 0x000000, 0xffa000, 0x000000, OP_CP_F, 1, 1 },
  { "cp", 0xe10060, 0x000000, 0xff83e0, 0x000000, OP_WB_LIT5, 1, 1 },
  { "cp", 0xe10000, 0x000000, 0xff8380, 0x000000, OP_WB_WS, 1, 1 },
  { "cp0", 0xe20000, 0x000000, 0xffa000, 0x000000, OP_CP_F, 1, 1 },
  { "cp0", 0xe00000, 0x000000, 0xfffb80, 0x000000, OP_CP0_WS, 1, 1 },
  { "cpb", 0xe38000, 0x000000, 0xffa000, 0x000000, OP_CP_F, 1, 1 },
  { "cpb", 0xe18060, 0x000000, 0xff83e0, 0x000000, OP_WB_LIT5, 1, 1 },
  { "cpb", 0xe18000, 0x000000, 0xff8380, 0x000000, OP_WB_WS, 1, 1 },
  { "cpseq", 0xe78000, 0x000000, 0xff83f0, 0x000000, OP_WB_WN, 1, 3 },
  { "cpsgt", 0xe60000, 0x000000, 0xff83f0, 0x000000, OP_WB_WN, 1, 3 },
  { "cpslt", 0xe68000, 0x000000, 0xff83f0, 0x000000, OP_WB_WN, 1, 3 },
  { "cpsne", 0xe70000, 0x000000, 0xff83f0, 0x000000, OP_WB_WN, 1, 3 },
  { "daw", 0xfd4000, 0x000000, 0xfffff0, 0x000000, OP_WN, 1, 1 },
  { "dec", 0xed0000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "dec", 0xe90000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "dec2", 0xed8000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "dec2", 0xe98000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "disi", 0xfc0000, 0x000000, 0xffc000, 0x000000, OP_LIT14, 18, 18 },
  { "div", 0xd80000, 0x000000, 0xff8030, 0x000000, OP_S_WM_WN, 18, 18 },
  { "div", 0xd88000, 0x000000, 0xff8030, 0x000000, OP_U_WM_WN, 18, 18 },
  { "divf", 0xd90000, 0x000000, 0xff87f0, 0x000000, OP_WM_WN, 18, 18 },
  { "do", 0x080000, 0x000000, 0xffc000, 0xff0000, OP_LIT14_EXPR, 2, 2 },
  { "do", 0x088000, 0x000000, 0xfffff0, 0xff0000, OP_WN_EXPR, 2, 2 },
  { "ed", 0xf04003, 0x000000, 0xfc4c03, 0x000000, OP_WM_WM_ACC_WX_WY_WXD, 1, 1 },
  { "edac", 0xf04002, 0x000000, 0xfc4c03, 0x000000, OP_WM_WM_ACC_WX_WY_WXD, 1, 1 },
  { "exch", 0xfd0000, 0x000000, 0xfff870, 0x000000, OP_WNS_WND, 1, 1 },
  { "fbcl", 0xdf0000, 0x000000, 0xfff800, 0x000000, OP_WS_WND, 1, 1 },
  { "ff1l", 0xcf8000, 0x000000, 0xfff800, 0x000000, OP_WS_WND, 1, 1 },
  { "ff1r", 0xcf0000, 0x000000, 0xfff800, 0x000000, OP_WS_WND, 1, 1 },
  { "goto", 0x040000, 0x000000, 0xff0001, 0xffff80, OP_GOTO, 2, 2 },
  { "goto", 0x014000, 0x000000, 0xfffff0, 0x000000, OP_WN, 2, 2 },
  { "inc", 0xec0000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "inc", 0xe80000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "inc2", 0xec8000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "inc2", 0xe88000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "ior", 0xb70000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "ior", 0xb30000, 0x000000, 0xff8000, 0x000000, OP_LIT10_WN, 1, 1 },
  { "ior", 0x700060, 0x000000, 0xf80060, 0x000000, OP_WB_LIT5_WD, 1, 1 },
  { "ior", 0x700000, 0x000000, 0xf80000, 0x000000, OP_WB_WS_WD, 1, 1 },
  { "lac", 0xca0000, 0x000000, 0xff0000, 0x000000, OP_WS_LIT4_ACC, 1, 1 },
  { "lnk", 0xfa0000, 0x000000, 0xffc001, 0x000000, OP_LNK_LIT14, 1, 1 },
  { "lsr", 0xd50000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "lsr", 0xd10000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "lsr", 0xde0040, 0x000000, 0xff8070, 0x000000, OP_WB_LIT4_WND, 1, 1 },
  { "lsr", 0xde0000, 0x000000, 0xff8070, 0x000000, OP_WB_WNS_WND, 1, 1 },
  { "mac", 0xc00000, 0x000000, 0xf84000, 0x000000, OP_WM_WN_ACC_WX_WY_AWB, 1, 1 },
  { "mac", 0xf00000, 0x000000, 0xfc4003, 0x000000, OP_WM_WM_ACC_WX_WY, 1, 1 },
  { "mov", 0xbf8000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "mov", 0xb7a000, 0x000000, 0xffa000, 0x000000, OP_CP_F, 1, 1 },
  { "mov", 0x800000, 0x000000, 0xf80000, 0x000000, OP_F_WND, 1, 1 },
  { "mov", 0x880000, 0x000000, 0xf80000, 0x000000, OP_WNS_F, 1, 1 },
  { "mov", 0xb3c000, 0x000000, 0xfff000, 0x000000, OP_LIT8_WND, 1, 1 },
  { "mov", 0x200000, 0x000000, 0xf00000, 0x000000, OP_LIT16_WND, 1, 1 },
  { "mov", 0x900000, 0x000000, 0xf80000, 0x000000, OP_WS_LIT10_WND, 1, 1 },
  { "mov", 0x980000, 0x000000, 0xf80000, 0x000000, OP_WNS_WD_LIT10, 1, 1 },
  { "mov", 0x780000, 0x000000, 0xf80000, 0x000000, OP_WS_WB_WD_WB, 1, 1 },
  { "mov", 0xbe0000, 0x000000, 0xfff880, 0x000000, OP_D_WNS_WND_2, 2, 2 },
  { "mov", 0xbe8000, 0x000000, 0xffc071, 0x000000, OP_D_WNS_WND_1, 2, 2 },
  { "movsac", 0xc70000, 0x000000, 0xff4000, 0x000000, OP_A_WX_WY_AWB, 1, 1 },
  { "mpy", 0xc00003, 0x000000, 0xf84003, 0x000000, OP_WM_WN_ACC_WX_WY, 1, 1 },
  { "mpy", 0xf00001, 0x000000, 0xfc4003, 0x000000, OP_WM_WM_ACC_WX_WY, 1, 1 },
  { "mpy", 0xc04003, 0x000000, 0xf84003, 0x000000, OP_N_WM_WN_ACC_AX_WY, 1, 1 },
  { "msc", 0xc04000, 0x000000, 0xf84000, 0x000000, OP_WM_WN_ACC_WX_WY_AWB, 1, 1 },
  { "mul", 0xbc0000, 0x000000, 0xffa000, 0x000000, OP_CP_F, 1, 1 },
  { "mul", 0xb98000, 0x000000, 0xff8000, 0x000000, OP_SS_WB_WS_WND, 1, 1 },
  { "mul", 0xb90060, 0x000000, 0xff8060, 0x000000, OP_SU_WB_LIT5_WND, 1, 1 },
  { "mul", 0xb90000, 0x000000, 0xff8000, 0x000000, OP_SU_WB_WS_WND, 1, 1 },
  { "mul", 0xb88000, 0x000000, 0xff8000, 0x000000, OP_US_WB_WS_WND, 1, 1 },
  { "mul", 0xb80060, 0x000000, 0xff8060, 0x000000, OP_UU_WB_LIT5_WND, 1, 1 },
  { "mul", 0xb80000, 0x000000, 0xff8000, 0x000000, OP_UU_WB_WS_WND, 1, 1 },
  { "neg", 0xee0000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "neg", 0xea0000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "neg", 0xcb1000, 0x000000, 0xff7fff, 0x000000, OP_ACC, 1, 1 },
  { "nop", 0x000000, 0x000000, 0xff0000, 0x000000, OP_NONE, 1, 1 },
  { "nopr", 0xff0000, 0x000000, 0xff0000, 0x000000, OP_NONE, 1, 1 },
  { "pop", 0xf90000, 0x000000, 0xff0001, 0x000000, OP_F, 1, 1 },
  { "pop", 0x78004f, 0x000000, 0xf8407f, 0x000000, OP_POP_WD, 1, 1 },
  { "pop", 0xbe004f, 0x000000, 0xfff8ff, 0x000000, OP_POP_D_WND, 2, 2 },
  { "pop", 0xfe8000, 0x000000, 0xffffff, 0x000000, OP_POP_S, 1, 1 },
  { "push", 0xf80000, 0x000000, 0xff0001, 0x000000, OP_F, 1, 1 },
  { "push", 0x781f80, 0x000000, 0xf87f80, 0x000000, OP_WS_PLUS_WB, 1, 1 },
  { "push", 0xbe9f80, 0x000000, 0xfffff1, 0x000000, OP_PUSH_WNS, 2, 2 },
  { "push", 0xfea000, 0x000000, 0xffffff, 0x000000, OP_POP_S, 1, 1 },
  { "pwrsav", 0xfe4000, 0x000000, 0xfffffe, 0x000000, OP_LIT1, 1, 1 },
  { "rcall", 0x070000, 0x000000, 0xff0000, 0x000000, OP_BRA, 2, 2 },
  { "rcall", 0x012000, 0x000000, 0xfffff0, 0x000000, OP_WN, 2, 2 },
  { "repeat", 0x090000, 0x000000, 0xffc000, 0x000000, OP_LIT14, 1, 1 },
  { "repeat", 0x098000, 0x000000, 0xfffff0, 0x000000, OP_WN, 1, 1 },
  { "reset", 0xfe0000, 0x000000, 0xffffff, 0x000000, OP_NONE, 1, 1 },
  { "retfie", 0x064000, 0x000000, 0xffffff, 0x000000, OP_NONE, 2, 3 },
  { "retlw", 0x050000, 0x000000, 0xff8000, 0x000000, OP_LIT10_WN, 2, 3 },
  { "return", 0x060000, 0x000000, 0xffffff, 0x000000, OP_NONE, 2, 3 },
  { "rlc", 0xd68000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "rlc", 0xd28000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "rlnc", 0xd60000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "rlnc", 0xd20000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "rrc", 0xd78000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "rrc", 0xd38000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "rrnc", 0xd70000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "rrnc", 0xd30000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "sac", 0xcc0000, 0x000000, 0xfe0000, 0x000000, OP_ACC_LIT4_WD, 1, 1 },
  //{ "sac", 0xcc0000, 0x000000, 0xff0000, 0x000000, OP_ACC_LIT4_WD, 1, 1 },
  //{ "sac", 0xcd0000, 0x000000, 0xff0000, 0x000000, OP_ACC_LIT4_WD, 1, 1 },
  { "se", 0xfb0000, 0x000000, 0xfff800, 0x000000, OP_WS_WND, 1, 1 },
  { "setm", 0xef8000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "setm", 0xeb8000, 0x000000, 0xff807f, 0x000000, OP_WD, 1, 1 },
  { "sftac", 0xc80040, 0x000000, 0xff7fc0, 0x000000, OP_ACC_LIT6, 1, 1 },
  { "sftac", 0xc80000, 0x000000, 0xff7ff0, 0x000000, OP_ACC_WB, 1, 1 },
  { "sl", 0xd40000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "sl", 0xd00000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 1, 1 },
  { "sl", 0xdd0040, 0x000000, 0xff8070, 0x000000, OP_WB_LIT4_WND, 1, 1 },
  { "sl", 0xdd0000, 0x000000, 0xff8070, 0x000000, OP_WB_WNS_WND, 1, 1 },
  { "sub", 0xb50000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "sub", 0xb10000, 0x000000, 0xff8000, 0x000000, OP_LIT10_WN, 1, 1 },
  { "sub", 0x500060, 0x000000, 0xf80060, 0x000000, OP_WB_LIT5_WD, 1, 1 },
  { "sub", 0x500000, 0x000000, 0xf80000, 0x000000, OP_WB_WS_WD, 1, 1 },
  { "sub", 0xcb3000, 0x000000, 0xff7fff, 0x000000, OP_ACC, 1, 1 },
  { "subb", 0xb58000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "subb", 0xb18000, 0x000000, 0xff8000, 0x000000, OP_LIT10_WN, 1, 1 },
  { "subb", 0x580060, 0x000000, 0xf80060, 0x000000, OP_WB_LIT5_WD, 1, 1 },
  { "subb", 0x580000, 0x000000, 0xf80000, 0x000000, OP_WB_WS_WD, 1, 1 },
  { "subbr", 0xbd8000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "subbr", 0x180060, 0x000000, 0xf80060, 0x000000, OP_WB_LIT5_WD, 1, 1 },
  { "subbr", 0x180000, 0x000000, 0xf80000, 0x000000, OP_WB_WS_WD, 1, 1 },
  { "subr", 0xbd0000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "subr", 0x100060, 0x000000, 0xf80060, 0x000000, OP_WB_LIT5_WD, 1, 1 },
  { "subr", 0x100000, 0x000000, 0xf80000, 0x000000, OP_WB_WS_WD, 1, 1 },
  { "swap", 0xfd8000, 0x000000, 0xffbff0, 0x000000, OP_WN, 1, 1 },
  { "tblrdh", 0xba8000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 2, 2 },
  { "tblrdl", 0xba0000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 2, 2 },
  { "tblwth", 0xbb8000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 2, 2 },
  { "tblwtl", 0xbb0000, 0x000000, 0xff8000, 0x000000, OP_WS_WD, 2, 2 },
  { "ulnk", 0xfa8000, 0x000000, 0xffffff, 0x000000, OP_NONE, 1, 1 },
  { "xor", 0xb68000, 0x000000, 0xff8000, 0x000000, OP_F_WREG, 1, 1 },
  { "xor", 0xb28000, 0x000000, 0xff8000, 0x000000, OP_LIT10_WN, 1, 1 },
  { "xor", 0x680060, 0x000000, 0xf80060, 0x000000, OP_WB_LIT5_WD, 1, 1 },
  { "xor", 0x680000, 0x000000, 0xf80000, 0x000000, OP_WB_WS_WD, 1, 1 },
  { "ze", 0xfb8000, 0x000000, 0xffc000, 0x000000, OP_WS_WND, 1, 1 },
  { NULL, 0, 0, 0, 0,  0,  0, 0 }
};


