;===============================================;
;           Extended Instruction Set            ;
;-----------------------------------------------;
; This provides additional operations to extend ;
; what is available in the normal instruction   ;
; set.                                          ;
;                                               ;
; The number of cycles taken by each macro is   ;
; listed after the declaration of each macro.   ;
; Cycles are system cycles, or                  ;
; (clock cycles / 4).                           ;
;                                               ;
; Macros with the _q suffix are quick, but may  ;
; clobber registers that should be unaffected.  ;
; What registers are changed by a macro are     ;
; listed after the declaration each quick       ;
; macro                                         ;
;                                               ;
; All groups of macros are in their own .inc    ;
; file.                                         ;
;===============================================;

IF !DEF(EXTENDED_INSTRUCTIONS_INC)
EXTENDED_INSTRUCTIONS EQU 1



INCLUDE "ld_r8_n8.inc"
INCLUDE "ld_r8_r8.inc"
INCLUDE "ld_r16_r8.inc"
INCLUDE "ld_r16_n16.inc"
INCLUDE "ld_r16_pr16.inc"



ENDC ; EXTENDED_INSTRUCTIONS_INC
