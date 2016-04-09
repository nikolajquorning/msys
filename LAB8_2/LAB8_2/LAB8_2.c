/*************************************
* MSYS, LAB8, Part 2                 *
* Timer 1 in Normal Mode             *
* "Binary Clock" (seconds)           *
* PC:[7..4] = Sec.10  [3..0] = Sec.1 *
*                                    *
* Henning Hargaard 6/4 2016          *
**************************************/
#include <avr/io.h>
#include "led.h"

// Prototype
void T1Delay();

int main()
{
unsigned char tiere = 0;
unsigned char enere = 0;
  // Klargør LED port
  DDRB = 0xFF;
  initLEDport();
  
  while(1)
  {
    // Juster enere og tiere (BCD format)
	for (int i=0; i<=5; i++)
	{
		for (int j=0; j<=9; j++)
		{
			// Vent til 1 sekund
			T1Delay();
			enere++;
			writeAllLEDs((tiere << 4) | enere);
		}
		enere = 0;
		tiere++;
		writeAllLEDs((tiere << 4) | enere);
	}
	tiere = 0;
	writeAllLEDs((tiere << 4) | enere);
  }
}

void T1Delay()
{
	//16000000 / 1024 = 15625 Hz
	//Dvs. 15626 trin i sekundet
	TCNT1 = 65535-15626;
	// Timer 1 i Normal Mode og Prescaling = 1024
	TCCR1A = 0b00000000;
	TCCR1B = 0b00000101;
	//Afvent timer 1 overflow flag
	while ((TIFR1 & 1)==0){}
	// Stop TImer 1
	TCCR1B = 0b00000000;
	// Reset Timer 1 flag
	TIFR1 = 1;
}

