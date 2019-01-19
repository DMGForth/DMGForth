IF !DEF(LD_R16_R16_INC)
LD_R16_R16_INC EQU 1



LD_AF_AF_q: MACRO; 0 cycles, safe
ENDM

LD_AF_AF: MACRO; 0 cycles
	LD_AF_AF_q
ENDM



LD_AF_BC_q: MACRO; 2 cycles, safe
	ld a, b; 1 cycle
	ld f, c; 1 cycle
ENDM

LD_AF_BC: MACRO; 2 cycles
	LD_AF_BC_q
ENDM



LD_AF_DE_q: MACRO; 2 cycles, safe
	ld a, d; 1 cycle
	ld f, e; 1 cycle
ENDM

LD_AF_DE: MACRO; 2 cycles
	LD_AF_DE_q
ENDM



LD_AF_HL_q: MACRO; 2 cycles, safe
	ld a, h; 1 cycle
	ld f, l; 1 cycle
ENDM

LD_AF_HL: MACRO; 2 cycles
	LD_AF_HL_q
ENDM



LD_BC_AF_q: MACRO; 2 cycles, safe
	ld b, a; 1 cycle
	ld c, f; 1 cycle
ENDM

LD_BC_AF: MACRO; 2 cycles
	LD_BC_AF_q
ENDM



LD_BC_BC_q: MACRO; 0 cycles, safe
ENDM

LD_BC_BC: MACRO; 0 cycles
	LD_BC_BC
ENDM



LD_BC_DE_q: MACRO; 2 cycles, safe
	ld b, d
	ld c, e
ENDM

LD_BC_DE: MACRO; 2 cycles
	LD_BC_DE_q
ENDM



LD_BC_HL_q: MACRO; 2 cycles, safe
	ld b, h
	ld c, l
ENDM

LD_BC_HL: MACRO; 2 cycles
	LD_BC_HL_q
ENDM



LD_DE_AF_q: MACRO; 2 cycles, safe
	ld d, a
	ld e, f
ENDM

LD_DE_AF: MACRO; 2 cycles
	LD_DE_AF_q
ENDM



LD_DE_BC_q: MACRO; 2 cycles, safe
	ld d, b
	ld e, c
ENDM

LD_DE_BC: MACRO; 2 cycles
	LD_DE_BC_q
ENDM



LD_DE_DE_q: MACRO; 0 cycles, safe
ENDM

LD_DE_DE: MACRO; 0 cycles
	LD_DE_DE_q
ENDM



LD_DE_HL_q: MACRO; 2 cycles, safe
	ld d, h
	ld e, l
ENDM

LD_DE_HL: MACRO; 2 cycles
	LD_DE_HL_q
ENDM



LD_HL_AF_q: MACRO; 2 cycles, safe
	ld h, a
	ld l, f
ENDM

LD_HL_AF: MACRO; 2 cycles
	LD_LH_AF_q
ENDM



LD_HL_BC_q: MACRO; 2 cycles, safe
	ld h, b
	ld l, c
ENDM

LD_HL_BC: MACRO; 2 cycles
	LD_HL_BC_q
ENDM



LD_HL_DE_q: MACRO; 2 cycles, safe
	ld h, d
	ld l, e
ENDM

LD_HL_DE: MACRO; 2 cycles
	LD_HL_DE_q
ENDM



LD_HL_HL_q: MACRO; 0 cycles, safe
ENDM

LD_HL_HL: MACRO; 0 cycles
	LD_HL_HL_q
ENDM



ENDC; LD_R16_R16_INC
