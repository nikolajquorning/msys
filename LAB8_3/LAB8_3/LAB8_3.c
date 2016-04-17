/*
 * LAB8_3.c
 *
 * Created: 17-04-2016 15:35:58
 * Author : rasmu
 */ 

#include <avr/io.h>
#include "led.h"


int main(void)
{
	initLEDport();
	DDRD = 0x00;
	TCCR0A = 0x00;
	TCCR0B = 0b00000111;
    while (1) 
    {
		writeAllLEDs(TCNT0);
    }
}

