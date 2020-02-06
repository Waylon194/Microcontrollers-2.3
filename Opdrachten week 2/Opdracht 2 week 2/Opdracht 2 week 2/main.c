#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

ISR(INT4_vect)
{
    PORTD |= ~(1<<5);
	wait(100);
}

ISR(INT5_vect)
{
    PORTD &= ~(1<<5);
	wait(100);
}

int main( void )
{
	//Initalisatie
	DDRE = 0x18;
	PORTD = 0x00;
	
	EICRB |= 0x0B;
	EIMSK |= 0x18;

	sei();
		
	while (1)
	{
		
	}
	return 1;
}