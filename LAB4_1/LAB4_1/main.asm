;**********************************
;******** MSYS LAB4,DEL 1  ********
;******** Henning Hargaard ********
;******** 7.september 2015 ********
;**********************************
;*********** INITIERING ***********
   LDI  R16,HIGH(RAMEND)  ;Initier Stack Pointer
   OUT  SPH,R16
   LDI  R16,LOW(RAMEND)
   OUT  SPL,R16
   SER  R16
   OUT  DDRB,R16          ;PB benene er udgange 

;---> Skriv kode her, der konfigurer PA benene til INDGANGE
   CLR R16
   OUT DDRA, R16

;********** PROGRAM LOOP **********
HERE:
   LDI  R20,239   ;c
   SBIS PINA, 7
   CALL TONE
   LDI  R20,213   ;D
   SBIS PINA, 6
   CALL TONE
   LDI  R20,190   ;E
   SBIS PINA, 5
   CALL TONE
   LDI  R20,179   ;F
   SBIS PINA, 4
   CALL TONE
   LDI  R20,160   ;G
   SBIS PINA, 3
   CALL TONE 
   LDI  R20,142   ;A 
   SBIS PINA, 2
   CALL TONE 
   LDI  R20,127   ;H
   SBIS PINA, 1
   CALL TONE 
   LDI  R20,120   ;C
   SBIS PINA, 0
   CALL TONE
   RJMP HERE

;********* DELAY (R18*4us) ********
DELAY:
   LDI  R17,20
AGAIN:
   DEC  R17
   BRNE AGAIN
   DEC  R18
   BRNE DELAY
   RET	
;**********************************

TONE:
   COM R26
   OUT PORTB, R26
   CALL DELAY
   JMP HERE            ;Retur til program loop