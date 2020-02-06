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
	// set PORTD for output
	DDRD = 0b11111111; // PORTD.7 = input all other bits output
	DDRC = 0x00;

	while (1)
	{
		if (PINC & 0b00000001)
		{
			PORTD = 0x80; // write 0 to all the bits of PortD
			wait(100);
			PORTD = 0x00;
			wait(100);
		}
		else
		{
			PORTD = 0x00; // write 1 to all the bits of PortD
		}
		wait(150);
	}
	return 1;
}