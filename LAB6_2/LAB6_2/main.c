/*
 * LAB6_2.c
 *
 * Created: 09-04-2016 11:34:59
 * Author : rasmu
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
	DDRA = 0x00;
	DDRB = 0xFF;
	
    /* Replace with your application code */
    while (1) 
    {
		if (PINA == 0b11111110)
		{
			PORTB = 0b00000001;
			_delay_ms(5);
			PORTB = 0b00000000;
			_delay_ms(95);
			
		}
		if (PINA == 0b11111101)
		{
			PORTB = 0b00000001;
			_delay_ms(95);
			PORTB = 0b00000000;
			_delay_ms(5);
		}
		if (PINA == 0b11111011)
		{
			PORTB = 0b00000001;
			_delay_us(50);
			PORTB = 0b00000000;
			_delay_us(950);
		}
		if (PINA == 0b11110111)
		{
			PORTB = 0b00000001;
			_delay_us(950);
			PORTB = 0b00000000;
			_delay_us(50);
		}
			
    }
}

