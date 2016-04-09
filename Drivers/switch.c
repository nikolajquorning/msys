/**********************************************************
* "Switch.c"                                              *
* Implementation for "Mega2560 I/O Shield" SWITCH driver. *
* Henning Hargaard, 23/9 2015                             *
***********************************************************/
#include <avr/io.h>

// Klargør switch-porten
void initSwitchPort()
{
	DDRA = 0b00000000;
}

// Læser alle switches samtidigt
unsigned char switchStatus()
{
	return ~PINA;
}

// Returnerer TRUE, hvis switchen med nummeret
// "switch_nr" er aktiveret - ellers returneres FALSE
unsigned char switchOn(unsigned char switch_nr)
{
	unsigned char mask;
	if (switch_nr <= 7)
	{
		mask = 0b00000001 << switch_nr;
		return ~PINA & mask;
	}
	else return 0;
} 