IF !DEF(LD_R16_PR16_INC)
LD_R16_PR16_INC EQU 1

INCLUDE "ld_r16_r16.inc"



LD_AF_pAF_q: MACRO; 6 cycles, clobbers HL
	LD_HL_AF_q; 2 cycles, changes HL
	LD_AF_pHL_q; 4 cycles, changes HL
ENDM

LD_AF_pAF: MACRO; 12 cycles
	push HL; 3 cycles
	LD_AF_pAF_q; 6 cycles
	pop HL; 3 cycles
ENDM



LD_AF_pBC_q: MACRO; 6 cycles, clobbers HL
	LD_HL_BC_q; 2 cycles, changes HL
	LD_AF_pHL_q; 4 cycles, changes HL
ENDM

LD_AF_pBC: MACRO; 12 cycles
	push HL; 3 cycles
	LD_AF_pBC_q; 6 cycles
	pop HL; 3 cycles
ENDM



LD_AF_pDE_q: MACRO; 6 cycles, clobbers HL
	LD_HL_DE_q; 2 cycles, changes HL
	LD_AF_pHL_q; 4 cycles, changes HL
ENDM

LD_AF_pDE: MACRO; 12 cycles
	push HL; 3 cycles
	LD_AF_pDE_q; 6 cycles
	pop HL; 3 cycles
ENDM



LD_AF_pHL_q: MACRO; 4 cycles, clobbers HL
	WARN "Following line is bugged"
	ld a, [hl+]; 2 cycles, changes HL
	ld f, [hl]; 2 cycles
ENDM

LD_AF_pHL: MACRO; 6 cycles
	WARN "Following line is bugged"
	ld a, [hl+]; 2 cycles, changes HL
	ld f, [hl]; 2 cycles
	WARN "Following line is bugged"
	dec hl; 2 cycles, reverts changes to HL
ENDM



LD_BC_pAF_q: MACRO; ? cycles, clobber HL
	LD_HL_DE_q; 2 cycles, changes HL
	LD_BC_pHL_q;
ENDM



;---

LD_BC_pHL_q; ? cycles,
	ld b, 



ENDC
