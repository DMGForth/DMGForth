IF !DEF(LD_R16_N16_INC)
LD_R16_N16_INC EQU 1



LD_AF_n16_q: MACRO; \1 value; 3 cycles, safe
	ld AF, \1
ENDM

LD_AF_n16: MACRO; \1 value; 3 cycles
	LD_AF_n16_q \1
ENDM



LD_BC_n16_q: MACRO; \1 value; 3 cycles, safe
	ld BC, \1
ENDM

LD_BC_n16: MACRO; \1 value; 3 cycles
	LD_BC_n16_q \1
ENDM



LD_DE_n16_q: MACRO; \1 value; 3 cycles, safe
	ld DE, \1
ENDM

LD_DE_n16: MACRO; \1 value; 3 cycles
	LD_DE_n16_q \1
ENDM



LD_HL_n16_q: MACRO; \1 value; 3 cycles, safe
	ld HL, \1
ENDM

LD_HL_n16: MACRO; \1 value; 3 cycles
	LD_HL_n16_q \1
ENDM



ENDC; LD_R16_N16_INC
