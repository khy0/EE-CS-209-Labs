#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t counter_for_400ms = 0;
volatile uint16_t main_number = 0;

ISR(TIMER0_COMPA_vect) {
	counter_for_400ms++;
	if (counter_for_400ms == 40) {
		counter_for_400ms = 0; // Reset counter
		main_number++; // Increment main number
		if (main_number > 9999) {
			main_number = 0; // Reset main number if it goes above 9999
		}
		seperate_and_load_characters(main_number, 4); // Update segments
	}
	send_next_character_to_display(); // Refresh display
}


void timer0_init(void){
	// Set CTC mode with prescaler 64
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS01) | (1 << CS00);

	// Set the value to compare against (for 10ms ISR with 2MHz clock and 64 prescaler)
	OCR0A = 31;

	// Enable the compare match interrupt
	TIMSK0 |= (1 << OCIE0A);
}
