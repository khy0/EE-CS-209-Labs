#include "led.h"
#include <avr/io.h>
#include <util/delay.h>

void led_toggle(){
	//TODO: LED toggle code
	DDRB = 0xFF;
	DDRC = 0x00;
	DDRD = 0x00;
	
	while(1){
		PORTB |= (1 << PORTB5);
		_delay_ms(375);
		PORTB &= ~(1 << PORTB5);
		_delay_ms(125);
	}
}
