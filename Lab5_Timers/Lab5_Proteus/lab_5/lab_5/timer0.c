
#include "timer0.h"
#include "uart.h"
#include "led.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>

//volatile uint16_t timer_var = 0;
volatile uint8_t timer_count = 0;
volatile bool running = true;

/*ISR(TIMER0_COMPA_vect) { //This ISR function is called when timer0 reaches
	//compare value, compare flag is automatically cleared
	timer_var++;
	if  (timer_var >= 100){
		PORTB ^= (1 << PORTB5);
		timer_var = 0;
	}
	
	led_toggle();
}*/

ISR(INT0_vect){
	if (running){
		//stop
		timer0_stop();
		running = false;
	}
	else {
		//start
		timer0_init();
		running = true;
	}
	
	
	/*if((EICRA & (1 << ISC00))) {
		timer0_init();
		EICRA &= ~(1 << ISC00);
	}
	else {
		uint8_t freq = 1/(TCNT0*2) + 48;
		
		usart_transmit(freq);
		TCCR0B &= ~(1 << CS02);
		//TIMSK0 &= ~(1 << OCIE0A);
		//TCNT0 = 0;
		//OCR0A = 77;
		EICRA |= (1 << ISC00);
	}*/
}

void calc_freq(){
	uint16_t freq = ((15625)/(timer_count*4));
	convert_ascii(freq);
}

void timer0_main(){
	calc_freq();
}

void convert_ascii(uint16_t millivolts){
	usart_transmit(millivolts / 1000 + 48);
	usart_transmit(((millivolts / 100 ) % 10) + 48);
	usart_transmit(((millivolts / 10 ) % 10) + 48);
	usart_transmit(millivolts % 10 + 48);
	usart_transmit('\r');
}

void timer0_init(){
	//TODO: initialise and configure timer0 to count to 10ms
	//TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS02);
	//TIMSK0 |= (1 << OCIE0A);
	TCNT0 = 0;
	//OCR0A = 77;
	EIMSK |= (1 << INT0);
	EICRA |= (1 << ISC00);
	//EICRA |= (1 << ISC01);
}

void timer0_stop(){
	TCCR0B &= ~(1 << CS02);
	timer_count = TCNT0;
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