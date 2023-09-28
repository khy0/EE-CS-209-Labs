#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "display.h"
#include "timer0.h"

uint8_t counter = 0;
// uint8_t ms_counter = 0;

int main(void)
{
	timer0_init();
	sei();
	display_init();
	
    
    while (1) 
    {
		/*
		_delay_ms(100);
		// When button is pressed, reset to 0
		if (!(PINB & (1 << PINB7)))
		{
			counter = 0;
			ms_counter = 0;		
		} 
		else
		{
			// Increment the ms counter so that we know when 1s has passed
			ms_counter++;
			if (ms_counter == 10) // When 1s has passed
			{
				// Display the number
				display_counter(counter);
				counter++;
				ms_counter = 0;
			}
		}
		
		// Once the counter reaches 9, we want to reset the number
		if (counter > 9)
		{
			counter = 0;
			display_counter(counter);
		}
		*/
    }
}
