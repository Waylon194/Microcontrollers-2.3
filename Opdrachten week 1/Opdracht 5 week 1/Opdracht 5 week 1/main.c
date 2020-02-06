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
	//Up and down lights
	int firstLightArray[] = {0x81, 0xC3, 0xE7, 0xFF};
	DDRD = 0xFF;

	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			PORTD = firstLightArray[i];
			wait(200);
		}
		for (int i = 0; i < 8; i++)
		{
			PORTD = ((1<<i)|(0x80>>i));
			wait(200);
		}
		PORTD = 0x00;
		wait(100);
	}
	return 1;
}