#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main( void )
{	
	DDRD = 0xFF; //output
	DDRC = 0x00; //input PC0
	int delay = 1000;
	
	while (1)
	{	
		if (PINC & 0b00000001)
		{

		}

		PORTD = 0x80;
		wait(delay);
		PORTD = 0x00;
		wait(delay);
	}
	return 1;
}