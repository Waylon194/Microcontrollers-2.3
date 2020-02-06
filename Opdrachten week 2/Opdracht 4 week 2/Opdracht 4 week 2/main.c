#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

const unsigned char simpleSnake[6] = {	
	0b00000001,
	0b00000010,
	0b00000100,
	0b00001000,
	0b00010000,
	0b00100000
};

const unsigned char complexerSnake[8] = {
	0b00000001,
	0b00000011,
	0b00000111,
	0b00001110,
	0b00011100,
	0b00111000,
	0b00110001,
	0b00100001
};

const unsigned char flash[8] = {
	0b00111111,
	0b00000000,
	0b00111111,
	0b00000000,
	0b00111111,
	0b00000000,
	0b00111111,
	0b00000000
};

void wait(int ms)
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms(1); //Library function (max 30 ms at 8MHz)
	}
}

int main (void)
{
	DDRD = 0b11111111;
	while (1)
	{	
		for (int i = 0; i < 8; i++)
		{
			PORTD = flash[i];
			wait(250);
		}
	}
}