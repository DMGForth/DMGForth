IF !DEF(CONSOLE_INC)
CONSOLE_INC EQU 1

INCLUDE "ibmpc1.inc"
INCLUDE "gbhw.inc"

TileData:
	chr_IBMPC1 1,8 ; Load Font

CursorRow:
	DB 0
CursorCol:
	DB 0

StopLCD: MACRO
	ld a, [rLCDC]
	rlca	; Put the high bit of LCDC into the carry flag
	jr nc, .continue\@
; Wait for VBlank
.wait\@:
	ld a, [rLY]
	cp 145	; Is display on scan line 145 yet?
	jr nz, .wait\@
; Turn off LCD
	ld a, [rLCDC]
	res 7,a	; Reset bit 7 of LCDC
	ld [rLCDC], a
.continue\@:
ENDM



WaitForVRAM: MACRO
	ld a, [rSTAT]
	and STATF_BUSY
	jr nz, @-4
ENDM



; Set palette to white on black
NormalVideo: MACRO
	ld a, %00001111
	ld [rBGP], a
ENDM



; Reverse background and foreground in palette
ReverseVideo: MACRO
	ld a, [rBGP]
	swap a
	ld [rBGP], a
ENDM



ClearScreen: MACRO
	ld a, 32 ; Space character
	ld bc, SCRN_VX_B * SCRN_VY_B ; Bytecount
	ld hl, _SCRN0 ; Destination
	inc b
	inc c
	jr .skip\@
.loop\@:
	push af
	di
	WaitForVRAM
	pop af
	ld [hl+], a
	ei
.skip\@:
	dec c
	jr nz, .loop\@
	dec b
	jr nz, .loop\@

	; Move cursor to top left
	ld a, 0
	ld [CursorRow], a
	ld [CursorCol], a
ENDM



Print: MACRO
	; save return stack (de)
	push de

	ld de, _SCRN0 + \3 + (SCRN_VY_B * \2)
	ld hl, \1
.loop\@
	WaitForVRAM
	ld a, [hl+]
	and a ; set the z register
	jr z, .break\@ ; Break on 'null' character
	ld [de], a
	ei
	inc de
	jr .loop\@
.break\@
	; restore return stack (de)
	pop de
ENDM



Console: MACRO
	; save return stack (de)
	push de

	StopLCD

	NormalVideo
	
	ld a, 0 ; Screen Scroll at 0,0
	ld [rSCX], a
	ld [rSCY], a
	
	; Copy font into VRAM
	ld hl, TileData ; Source
	ld de, _VRAM ; Destination
	ld bc, 8 * 256 ; Bytecount
	inc b
	inc c
	jr .skip\@
.loop\@:
	ld a, [hl+]
	ld [de], a
	inc de
	ld [de], a
	inc de
.skip\@
	dec c
	jr nz, .loop\@
	dec b
	jr nz, .loop\@

	; Turn the LCD on
	ld	a, LCDCF_ON|LCDCF_BG8000|LCDCF_BG9800|LCDCF_BGON|LCDCF_OBJ16|LCDCF_OBJOFF 
	ld [rLCDC], a

	ClearScreen
	
	; restore return stack (de)
	pop de
ENDM

ENDC ; CONSOLE_INC
