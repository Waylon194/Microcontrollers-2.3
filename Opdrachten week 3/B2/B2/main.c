/*
 * B2.c
 *
 * Created: 19-Feb-20 08:44:28
 * Author : Jaspe
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int msCount = 0;
int high = 0;

void timer2Init( void )
{
	OCR2 = 125;			// Compare value of counter 2
	TIMSK |= 1<<7;		// T2 compare match interrupt enable
	TCCR2 = 0b00001011; // Initialize T2: timer, prescaler=64,
						// compare output disconnected,CTC,RUN
	sei();				// turn_on intr all
}

ISR( TIMER2_COMP_vect )
{
	msCount++; // Increment ms counter
	
	if(high)
	{
		if (msCount == 15)
		{
			high = 0;
			PORTC ^= 1<<0; // Toggle bit 0 van PORTC
			msCount = 0; // Reset ms_count value
		}
	}
	else
	{
		if(msCount == 25)
		{
			high = 1;
			PORTC ^= 1<<0; // Toggle bit 0 van PORTC
			msCount = 0; // Reset ms_count value
		}
	}}int main( void )
{
	DDRC = 0xFF; // set PORTC for output (toggle PC0)
	timer2Init();
	while (1)
	{
		// do something else
		_delay_ms(10); // every 10 ms (busy waiting
	}
}