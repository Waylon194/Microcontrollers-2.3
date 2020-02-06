#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

/*
	Implementeer ook de functionaliteit dat de waarde op het display steeds met 1 wordt verhoogd / verlaagd bij het indrukken van toetsen (up / down).
	Als je op beide toetsen tegelijk drukt wordt het display gereset naar ‘0’.
*/

void display(int digit);

const unsigned char numbers[15] = {	
	0b00111111, //0
	0b00000110, //1
	0b01011011, //2
	0b01001111, //3
	0b01100110, //4
	0b01101101, //5
	0b01111101, //6
	0b00000111, //7
	0b01111111, //8
	0b01101111, //9
	0b01110111, //A
	0b01111100, //B
	0b00111001, //C
	0b01011110, //D
	0b01111001 //E
	//0b01110001 //F
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
	int digit = 0;
	display(digit);
	
	while (1)
	{
		loopNumbers();
		//Button 1 pressed up
		if (PINC & 0b00000001)
		{
			digit++;
			display(digit);
		}
		
		//Button 2 pressed down
		if (PINC & 0b00000010)
		{
			digit--;
			display(digit);
		}
		
		//Button 1 and 2 reset
		//Try PINC & 0b00000011
		if (PINC & 0b00000001 & PINC & 0b00000010)
		{
			digit = 0;
			display(digit);
		}
		//PORTD = numbers[digit];
	}
}

void display(int digit){
	if (digit < 15)
	{
		PORTD = numbers[digit];
	}
	else
	{
		PORTD = numbers[16];
	}
}

void loopNumbers()
{	
	for (int i = 0; i < 17; i++){
		display(i);
		wait(500);
	}
}