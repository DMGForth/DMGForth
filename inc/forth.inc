IF !DEF(FORTH_INC)
FORTH_INC EQU 1

INCLUDE "extended_instructions.inc"


NextWord:
	dw 0

DataStackBottom EQU $fffe ; not $ffff because that is the interrupt enabler
ReturnStackBottom EQU $cfff ; End of working ram 0 (wram0)



NEXT: MACRO
	; Save old pointer's value
	ld hl, NextWord
	ld b, [hl]
	inc hl
	ld c, [hl]
	; LD_BC_pn16 NextWord

	; Increment Pointer
	ld hl, NextWord
	; LD_HL_n16 NextWord
	inc [hl]
	inc [hl]

	; Jump to old poiner's value
	ld h, b
	ld l, c
	; LD_HL_BC
	jp hl

	; Leave pointer in 'hl' (used by DOCOL)
ENDM



PUSHRSP: MACRO ; takes 'hl'
	; move value to 'bc'
	ld b, h
	ld c, l
	; LD_BC_HL

	; move pointer back
	ld h, d
	ld l, e
	; LD_HL_DE
	ld bc, $fffe ; unsigned -2 (utilize overflow)
	; LD_BC_n16 $fffe
	add hl, bc
	ld d, h
	ld e, l
	; LD_DE_HL
	
	; store value
	ld [hl], b
	inc hl
	ld [hl], c
	; LD_pHL_BC
ENDM



POPRSP: MACRO ; puts value in 'hl'
	; load value into 'bc'
	ld h, d
	ld l, e
	ld b, [hl]
	inc hl
	ld c, [hl]

	; save value onto stack
	push bc
	
	; move pointer
	ld bc 2
	add hl, bc
	ld d, h
	ld e, l

	; restore value to 'hl' from stack
	pop hl
ENDM



DOCOL: ; uses 'hl' as current word (from NEXT)
	; save current word
	push hl	

	; get pointer to next word
	ld hl, NextWord
	ld b, [hl]
	inc hl
	ld c, [hl]
	ld h, b
	ld l, c
	
	; save pointer for later
	PUSHRSP

	; retreive current word
	pop hl
	
	; move to first instruction in the word
	ld bc, 2
	add hl, bc
	ld a, h
	ld [NextWord], a
	ld a, l
	ld [NextWord +1], a

	NEXT

ENDC ; FORTH_INC
