/*
 * LAB9_1.c
 *
 * Created: 17-04-2016 16:01:15
 * Author : rasmu
 */ 

#include <avr/io.h>
#include "led.h"

int main(void)
{
    initLEDport();
	TCCR1A = 0b01000000; 
	TCCR1B = 0b00001000; //
    while (1) 
    {
		
    }
}

