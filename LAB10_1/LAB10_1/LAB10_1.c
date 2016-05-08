#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "led.h"
#include "avr/interrupt.h"

unsigned int timer0Counter = 0;


void init_interrupts() {
	EIMSK = (1 << INT2) | (1 << INT3); //activate interrupts for INT2 and INT3
	EICRA = 0b11100000;                //falling edge of INT2, rising edge for INT3
	sei();                             //activate interrupts
}

void init_timer0() {
	TCCR0A = 0x00;
	TCCR0B = 0x01;
	TIMSK0 |= (1<<TOIE0);              //set timer0 interrupt overflow
}

void init_timer1() {
	TCCR1A = 0x00;
	TCCR1B = 0b00001100; //mode 4
	OCR1A = 15625-1;      //((16000000/256)/4)-1
	TIMSK1 |= (1<<OCIE1A);
}


ISR(TIMER1_COMPA_vect) {
	toggleLED(5);
}

ISR(TIMER0_OVF_vect) {
	timer0Counter++;
	if (timer0Counter == 62500) {
		toggleLED(6);
		timer0Counter = 0;
	}
}

ISR(INT2_vect) {
	//do stuff when INT2 interrupt happens
	toggleLED(2);
}

ISR(INT3_vect) {
	//do stuff when INT3 interrupt happens
	toggleLED(3);
}


int main(void)
{
	init_LEDport();
	init_interrupts();
	init_timer0();
	init_timer1();
	while (1)
	{
		toggleLED(7);
		_delay_ms(1000);
	}
}

