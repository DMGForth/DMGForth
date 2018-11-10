;----------;
; LD_r8_r8 ;
;----------;

; While not adding any functionality, this is to provide
; a uniform way of calling LD operations



IF !DEF(LD_R8_R8_INC)
LD_R8_R8_INC EQU 1



LD_A_A_q: MACRO; 0 cycles, safe
ENDM

LD_A_A: MACRO; 0 cycles
	LD_A_A_q
ENDM



LD_A_F_q: MACRO; 1 cycle, safe
	ld a, f
ENDM

LD_A_F: MACRO; 1 cycle
	LD_A_F_q
ENDM



LD_A_B_q: MACRO; 1 cycle, safe
	ld a, b
ENDM

LD_A_B: MACRO; 1 cycle
	LD_A_B_q
ENDM



LD_A_C_q: MACRO; 1 cycle, safe
	ld a, c
ENDM

LD_A_C: MACRO; 1 cycle
	LD_A_C_q
ENDM



LD_A_D_q: MACRO; 1 cycle, safe
	ld a, d
ENDM

LD_A_D: MACRO; 1 cycle
	LD_A_D_q
ENDM



LD_A_E_q: MACRO; 1 cycle, safe
	ld a, e
ENDM

LD_A_E: MACRO; 1 cycle
	LD_A_E_q
ENDM



LD_A_H_q: MACRO; 1 cycle, safe
	ld a, h
ENDM

LD_A_H: MACRO; 1 cycle
	LD_A_H_q
ENDM



LD_A_L_q: MACRO; 1 cycle, safe
	ld a, l
ENDM

LD_A_L: MACRO; 1 cycle
	LD_A_L_q
ENDM



LD_F_A_q: MACRO; 1 cycle, safe
	ld f, a
ENDM

LD_F_A: MACRO; 1 cycle
	LD_F_A_q
ENDM



LD_F_F_q: MACRO; 0 cycles, safe
ENDM

LD_F_F: MACRO; 0 cycles
	LD_F_F_q
ENDM



LD_F_B_q: MACRO; 1 cycle, safe
	ld f, b
ENDM

LD_F_B: MACRO; 1 cycle
	LD_F_B_q
ENDM



LD_F_C_q: MACRO; 1 cycle, safe
	ld f, c
ENDM

LD_F_C: MACRO; 1 cycle
	LD_F_C_q
ENDM



LD_F_D_q: MACRO; 1 cycle, safe
	ld f, d
ENDM

LD_F_D: MACRO; 1 cycle
	LD_F_D_q
ENDM

LD_F_E_q: MACRO; 1 cycle, safe
	ld f, e
ENDM

LD_F_E: MACRO; 1 cycle
	LD_F_E_q
ENDM



LD_F_H_q: MACRO; 1 cycle, safe
	ld f, h
ENDM

LD_F_H: MACRO; 1 cycle
	LD_F_H_q
ENDM



LD_F_L_q: MACRO; 1 cycle, safe
	ld f, l
ENDM

LD_F_L:	MACRO; 1 cycle
	LD_F_L_q
ENDM



WARN "LD_B_x not implemented"



WARN "LD_C_x not implemented"



WARN "LD_D_x not implemented"



WARN "LD_E_x not implemented"



WARN "LD_H_x not implemented"



WARN "LD_L_x not implemented"



ENDC ; LD_R8_R8_INC
