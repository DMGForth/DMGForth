IF !DEF(LD_R16_R8_INC)
LD_R16_R8_INC EQU 1

INCLUDE "ld_r8_n8.inc"
INCLUDE "ld_r8_r8.inc"



LD_AF_A_q: MACRO; [2,3] cycles, safe
	LD_F_A_q; 1 cycle, safe
	LD_A 0; [1,2] cycles
ENDM

LD_AF_A: MACRO; [2,3] cycles
	LD_AF_A_q
ENDM



LD_AF_F_q: MACRO; [1,2] cycles, safe
	LD_A 0; [1,2] cycles
ENDM

LD_AF_F: MACRO; [1,2] cycles
	LD_AF_F_q
ENDM




ENDC; LD_R16_R8_INC
