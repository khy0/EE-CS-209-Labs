/*
 * lab_6_PII.c
 *
 * Created: 29/09/2023 2:19:07 pm
 * Author : rtor313
 */ 

#define F_CPU 2000000UL

#include <avr/io.h>
#include "display.h"
#include <util/delay.h>
#include "timer0.h"
#include <avr/interrupt.h>

int main(void)
{
    /* Replace with your application code */
	display_init();
	PORTD |= (1 << PORTD4) | (1 << PORTD5) | (1 << PORTD6) | (1 << PORTD7); // Disable Ds1, Ds2, Ds3 by setting them to 1
	PORTD &= ~(1 << PORTD7);  // Enable Ds4 by setting it to 0
	send_next_character_to_display();
	timer0_init();
	sei();
	
    while (1) 
    {
		send_next_character_to_display();
    }
}

