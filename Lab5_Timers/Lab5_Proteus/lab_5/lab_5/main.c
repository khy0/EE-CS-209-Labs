/*
 * lab_5.c
 *
 * Created: 22/09/2023 4:23:43 pm
 * Author : rtor313
 */ 

#define F_CPU 2000000UL
#include "timer0.h"
#include "led.h"
#include "uart.h"
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void){
	PORTB |= (1 << PORTB5);
	usart_init(12);
	//TODO: set direction of LED port to OUTPUT
	timer0_init();
	sei(); //This special function call enables the use of interrupts
	while (1) { }
}

