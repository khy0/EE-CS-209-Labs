
#include "timer0.h"
#include "led.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile uint16_t timer_var = 0;

ISR(TIMER0_COMPA_vect) { //This ISR function is called when timer0 reaches
	//compare value, compare flag is automatically cleared
	timer_var++;
	if  (timer_var >= 100){
		PORTB ^= (1 << PORTB5);
		timer_var = 0;
	}
	
	led_toggle();
}

void timer0_init(){
	//TODO: initialise and configure timer0 to count to 10ms
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS02);
	TIMSK0 |= (1 << OCIE0A);
	TCNT0 = 0;
	OCR0A = 77;
}
/*uint8_t timer0_check_clear_compare(){
	if( TIFR0 & (1 << OCF0A )){ //TODO: check compare flag
		//TODO: clear compare flag.
		//Note: in datasheet this is done by writing 1 to the compare flag
		TIFR0 |= (1 << OCF0A);
		
		return 1;
	}
	return 0;
}*/