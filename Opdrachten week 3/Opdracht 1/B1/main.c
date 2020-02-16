/*
 * B1.c
 *
 * Created: 12-Feb-20 12:35:11
 * Author : Jaspe
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include <string.h>
#include "stdio.h"

#define false 0
#define true 1

void writeToLeds(void);

void writeToLeds(void)
{
	PORTB = TCNT2; // Toon waarde TCCR2 op de PORTB leds
}

int main(void)
{
    DDRD &= ~(1<<7); // PD7 op input: DDRD=0xxx xxxx
    TCCR2 = 0b00000111; // counting via PD7, rising edge
	
	DDRB = 0xFF; // PORTB is output
	
	init_4bits_mode();
	int number = -1;
	
    while (1) 
    {
		writeToLeds();
		
		if(number != TCNT2)
		{
			lcd_clear();
			number = TCNT2;
			char str[10];
			sprintf(str, "%u", number);
			
			lcd_write_text(str, 1, 0);
		}
    }
}