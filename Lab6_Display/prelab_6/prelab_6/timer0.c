#include "timer0.h"
#include "display.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


volatile uint8_t software_counter = 0;
volatile uint8_t number = 0;
volatile bool tens_digit = true;

ISR(TIMER0_COMPA_vect) {	// This ISR function is called when timer0 reaches
	// compare value, compare flag is automatically cleared
	if (tens_digit)
	{
		software_counter++;
		
		// determine the LEDs
		number = get_tens();
		// disable both digits
		disable_digits();
		// set the I/O pins to display number
		display_counter(number);
		// enable the first digit
		enable_Ds1();
		// update the flag indicating ones digit to update
		tens_digit = false;
	}
	else
	{
		// we want to increment/update our value only after a second has passed
		if (software_counter >= 50)
		{
			software_counter = 0;
			increment_num();
		}
		// determine the LEDs
		number = get_ones();
		// disable both digits
		disable_digits();
		// set the I/O pins to display number
		display_counter(number);
		// enable the second digit
		enable_Ds2();
		// update the flag indicating tens digit to update
		tens_digit = true;
	}
}

void timer0_init(){
	// Initialize and configure timer0 to count to 10ms
	TCCR0A |= (1 << COM0A1);
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS02);
	OCR0A = 77;
	
	TIMSK0 |= (1 << OCIE0A);
}
