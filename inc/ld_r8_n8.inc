IF !DEF(LD_R8_N8_INC)
LD_R8_N8_INC EQU 1



LD_A_n8_q: MACRO; \1-value; [1,2] cycles; safe
IF \1 == 0; 1 cycle
	xor a, a
ELSE; 2 cycles
	ld a, \1
ENDC
ENDM

LD_A_n8: MACRO; \1-value; [1,2] cycles
	LD_A_q \1
ENDM



WARN "LD_F_n8 not implemented"



WARN "LD_B_n8 not implemented"



WARN "LD_C_n8 not implemented"



WARN "LD_D_n8 not implemented"



WARN "LD_E_n8 not implemented"



WARN "LD_H_n8 not implemented"



WARN "LD_L_n8 not implemented"



ENDC; LD_R8_N8_INC
