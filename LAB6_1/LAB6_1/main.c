#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

void playSound() {
	PORTB = ~PORTB;
}

int main()
{
	DDRA = 0x00; //port A as input
	DDRB = 0xFF; //port B as output
	
	while (1)
	{
		if (PINA == 0b01111111)
		{
			playSound();
			_delay_us(239*4);
		}
		if (PINA == 0b10111111)
		{
			playSound();
			_delay_us(213*4);
		}
		if (PINA == 0b11011111)
		{
			playSound();
			_delay_us(190*4);
		}
		if (PINA == 0b11101111)
		{
			playSound();
			_delay_us(179*4);
		}
		if (PINA == 0b11110111)
		{
			playSound();
			_delay_us(160*4);
		}
		if (PINA == 0b11111011)
		{
			playSound();
			_delay_us(142*4);
		}
		if (PINA == 0b11111101)
		{
			playSound();
			_delay_us(127*4);
		}
		if (PINA == 0b11111110)
		{
			playSound();
			_delay_us(120*4);
		}		
	}
	
}



