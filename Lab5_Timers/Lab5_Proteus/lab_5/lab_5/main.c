/*
 * lab_5.c
 *
 * Created: 22/09/2023 4:23:43 pm
 * Author : rtor313
 */ 

#define F_CPU 2000000UL
#include "timer0.h"
#include "led.h"
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void){
	PORTB |= (1 << PORTB5);
	//TODO: set direction of LED port to OUTPUT
	timer0_init();
	while(1){
		if(timer0_check_clear_compare()) {
			led_toggle();
		}
	}
}

