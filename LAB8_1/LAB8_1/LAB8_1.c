/*************************************
* MSYS, LAB8, Part 1                 *
* Timer 0 in Normal Mode             *
* Led port increments 125 times/sec. *
*                                    *
* Henning Hargaard 5/10 2015         *
**************************************/
#include <avr/io.h>
#include "led.h"

// Prototype
void T0Delay();

int main()
{
  unsigned char x = 0;
  // Klargør LED port
  initLEDport();
  while(1)
  {
    // Vent 1/125 sekund
    T0Delay();
    // Inkrementer og vis variablen x
    x++;
    writeAllLEDs(x);
  }
}

void T0Delay()
{
  // <----- Skriv den manglende kode her
  //16000000 Hz / 1024 = 15625
  //15625 / 125 = 125
  TCNT0 = 256-125;
  // Timer 0 i Normal Mode og Prescaling = 1024
  TCCR0A = 0b00000000;
  TCCR0B = 0b00000101;
  //Vent på TImer 0 overflow flag
  while ((TIFR0 & 1) == 0) {}
  //Stop timer 0 
  TCCR0B = 0;
  //Nulstil Timer 0 overflow flag
  TIFR0 = 1;
}