#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );	// library function (max 30 ms at 8MHz)
	}
}

int main( void )
{
	// set PORTD for output
	DDRD = 0b11111111; // all bits output
	PORTD = 0x01;

	while (1)
	{
		PORTD = PORTD << 1;
		wait(50);
		if (PORTD == 0x80){
			PORTD = 0x01;
			wait(50);
		}	
	}
}