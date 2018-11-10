IF !DEF(FORTH_INC)
FORTH_INC EQU 1


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

	; Increment Pointer
	ld hl, NextWord
	inc [hl]
	inc [hl]

	; Jump to old poiner's value
	ld h, b
	ld l, c
	jp hl

	; Leave pointer in 'hl' (used by DOCOL)
ENDM



PUSHRSP: MACRO ; takes 'hl'
	; move value to 'bc'
	ld b, h
	ld c, l

	; move pointer back
	ld h, d
	ld l, e
	ld bc, $fffe ; unsigned -2 (utilize overflow)
	add hl, bc
	ld d, h
	ld e, l
	
	; store value
	ld [hl], b
	inc hl
	ld [hl], c
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
