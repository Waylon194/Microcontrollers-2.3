#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 ); // library function (max 30 ms at 8MHz)
	}
}

int main( void )
{
	DDRD = 0b00000000; //input

	while (1)
	{
		//Start
		if (PIND & 0b00011111)
		{
			//State 2
			PORTD = 0x20;
			wait(200);
			PORTD = 0x00;
			wait(200);

			if (PIND & 0b01111111)
			{
				//Start
				PORTD = 0x00;
				wait(200);
				PORTD = 0x00;
			}
			else if (PIND & 0b00111111)
			{
				//State 1
				PORTD = 0x10;
				wait(200);
				PORTD = 0x00;
			}
			else if (PIND & 0b00011111)
			{
				//State 3
				PORTD = 0x30;
				wait(200);
				PORTD = 0x00;
				
				if (PIND & 0b00011111 || PIND & 0b00111111)
				{
					//End
					PORTD = 0x70;
					wait(200);
					PORTD = 0x00;

					if (PIND & 0b01111111)
					{
						//Start
						PORTD = 0x00;
						wait(200);
						PORTD = 0x00;
					}
				}
				else if (PIND & 0b01111111){
					//Start
					PORTD = 0x00;
					wait(200);
					PORTD = 0x00;
				}
			}
		}
		else if (PIND & 0b00111111)
		{
			//State 1
			PORTD = 0x10;
			wait(200);
			PORTD = 0x00;

			if (PIND & 0b00011111)
			{
				//State 2
				PORTD = 0x20;
				wait(200);
				PORTD = 0x00;
			}
			else if (PIND & 0b01111111){
				//Start
				PORTD = 0x00;
				wait(200);
				PORTD = 0x00;
			}
		}
	}
	return 1;
}