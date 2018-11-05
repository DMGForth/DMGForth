;===========;
;; GBForth ;;
;===========;

INCLUDE "version.inc" ; Defines VERSION
INCLUDE "gbhw.inc" ; standard hardware definitions from devrs.com
INCLUDE "ibmpc1.inc" ; Extended ASCII character set

;------------;
; Interrupts ;
;------------;

SECTION	"Vblank",ROM0[$0040]
	reti
SECTION	"LCDC",ROM0[$0048]
	reti
SECTION	"Timer_Overflow",ROM0[$0050]
	reti
SECTION	"Serial",ROM0[$0058]
	reti
SECTION	"p1thru4",ROM0[$0060]
	reti

;--------;
; Header ;
;--------;

SECTION	"start",ROM0[$0100]
	nop
	jp	begin

;ROM_HEADER	ROM_NOMBC, ROM_SIZE_32KBYTE, RAM_SIZE_0KBYTE

; Nintendo scrolling logo
INCLUDE "nintendo_logo.inc"
	NINTENDO_LOGO

INCLUDE "cart.inc" ; Includes constants for cart specs

IF DEF(DEBUG)
	DB "GBForth dev",0,0,0,0	; Cart name - 15bytes
ELSE
	DB "GBForth",0,0,0,0,0,0,0,0 	; Cart name - 15bytes
ENDC
	DB 0	; $143
	DB 0,0	; $144 - Licensee code (not important)
	DB 0	; $146 - SGB Support indicator
	DB ROM_NOMBC	; $147 - Cart type
	DB ROM_SIZE_32KBYTE	; $148 - ROM Size
	DB RAM_SIZE_0KBYTE	; $149 - RAM Size
	DB 1	; $14a - Destination code
	DB $33	; $14b - Old licensee code
	DB 0	; $14c - Mask ROM version
	DB 0	; $14d - Complement check (important)
	DW 0	; $14e - Checksum (not important)


INCLUDE "memory.inc"

INCLUDE "console.inc"

begin:
	di

	; Initialize stack
	ld	sp, $ffff

	Console
	
	Print Line1, 0, 0
	Print Line2, 1, 0
	Print Line3, 2, 0
	Print Line4, 3, 0
	
wait:
	halt
	nop
	jr	wait
	
; ****************************************************************************************
; hard-coded data
; ****************************************************************************************
Line1:
	DB	"GBForth "
IF DEF(DEBUG)
	DB 	"dev build", 0
ELSE
	DB	"{VERSION}", 0
ENDC

Line2:
	DB "Copyright 2018", 0
Line3:  
	DB "Brayden Morris", 0
Line4:
	DB "MIT License", 0
