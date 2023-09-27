/*
 * prelab_6.c
 *
 * Created: 27/09/2023 12:15:34 am
 * Author : rtor313
 */ 

#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "display.h"

uint8_t counter = 0;
uint8_t ms_counter = 0;

void check_button();


int main(void)
{
	display_init();
		// set I/O pin connected to the push button as an input
		DDRB &= ~(1 << DDB7);
		PORTB |= (1 << PORTB7);
	
	
	while (1)
	{
		_delay_ms(100);
		
		if (PINB & (1 << PINB7))
		{
			counter = 0;
			ms_counter = 0;

			display_counter(counter);
		} else {
			// increment the ms_counter to check how much time has passed
			ms_counter++;
			// if 1s has passed we want to display the value and increment the counter value
			if (ms_counter == 10) {
				display_counter(counter);
				counter++;
				ms_counter = 0;
				
			}
		}
		// if the counter is bigger than 9, we want to reset it back to 0
		if (counter > 9)
		{
			counter = 0;
		}
	}
}


void check_button() {
	
}