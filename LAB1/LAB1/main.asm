;********** MSYS, LAB1 **********
;******* Henning Hargaard *******
;*******  14.august 2015  *******
;********************************

;********** INITIERING **********
   LDI  R16,HIGH(RAMEND) ;Initialize Stack Pointer
   OUT  SPH,R16
   LDI  R16,LOW(RAMEND)
   OUT  SPL,R16           
   SER  R16              ;PORTB = Outputs
   OUT  DDRB,R16

;********** PROGRAM-LOOP ********
   CLR  R16
LOOP:
   LDI  R17,1           ;R17 = 1
   ADD  R16,R17         ;R16 = R16 + R17
   CALL DISP_AND_DELAY  ;Display R16
   JMP  LOOP            ;Jump to "LOOP"

;********** DISPLAY R16 *********
;********** AND DELAY ***********
DISP_AND_DELAY:
   MOV  R17,R16
   OUT  PORTB,R17
   CLR  R17
   CLR  R18
   LDI  R19,100
AGAIN:
   DEC  R17
   BRNE AGAIN
   DEC  R18
   BRNE AGAIN
   DEC  R19
   BRNE AGAIN
   RET	
;********************************