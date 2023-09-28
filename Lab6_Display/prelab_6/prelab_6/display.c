/*
 * display.c
 *
 * Created: 26/09/2023 8:21:06 am
 *  Author: rtor313
 */ 

#include "display.h"
#include "timer0.h"

#include <avr/io.h>
#include <stdbool.h>

uint8_t tens = 0;
uint8_t ones = 0;

/*
uint8_t segments[9] = {00111111, 00000110, 01011011, 01100110, 01101101, 01111101, 00000111, 01111111, 01101111};
*/

void display_init() {
	// set I/O pin connected to the push button as an input
	DDRB &= ~(1 << PINB7);
	// Enable the internal pull-up resistor
	PORTB |= (1 << PINB7);
	
	// anodes of LED set to output
	DDRC |= (1 << PINC0) | (1 << PINC1);
	DDRC |= (1 << PINC2) | (1 << PINC3);
	DDRC |= (1 << PINC4) | (1 << PINC5);
	DDRB |= (1 << PINB4);
	// Ds1 and Ds2 set to output
	DDRB |= (1 << PINB0) | (1 << PINB1);
}

void disable_digits() {
	// set Ds1 = 1
	PORTB |= (1 << PORTB0);
	// set Ds2 = 1
	PORTB |= (1 << PORTB1);
	
}

void enable_Ds1(){
	// set Ds1 = 0
	PORTB &= ~(1 << PORTB0);
	// set Ds2 = 1
	PORTB |= (1 << PORTB1);
}

void enable_Ds2(){
	// set Ds1 = 1
	PORTB |= (1 << PORTB0);
	// set Ds2 = 0
	PORTB &= ~(1 << PORTB1);
}

void increment_num() {
	ones++;
	if (ones > 9)
	{
		ones = 0;
		tens++;
		if (tens > 9)
		{
			tens = 0;
		}
	}
}

uint8_t get_ones() {
	return ones;
}

uint8_t get_tens() {
	return tens;
}

void display_counter(uint8_t number) {
	if (number == 1)
	{
		PORTC &= ~(1 << PORTC0);
		PORTC |= (1 << PORTC1);
		PORTC |= (1 << PORTC2);
		PORTC &= ~(1 << PORTC3);
		PORTC &= ~(1 << PORTC4);
		PORTC &= ~(1 << PORTC5);
		PORTB &= ~(1 << PORTB4);
	} else if (number == 2)
	{
		PORTC |= (1 << PORTC0);
		PORTC |= (1 << PORTC1);
		PORTC &= ~(1 << PORTC2);
		PORTC |= (1 << PORTC3);
		PORTC |= (1 << PORTC4);
		PORTC &= ~(1 << PORTC5);
		PORTB |= (1 << PORTB4);
	} else if (number == 3)
	{
		PORTC |= (1 << PORTC0);
		PORTC |= (1 << PORTC1);
		PORTC |= (1 << PORTC2);
		PORTC |= (1 << PORTC3);
		PORTC &= ~(1 << PORTC4);
		PORTC &= ~(1 << PORTC5);
		PORTB |= (1 << PORTB4);
	} else if (number == 4)
	{
		PORTC &= ~(1 << PORTC0);
		PORTC |= (1 << PORTC1);
		PORTC |= (1 << PORTC2);
		PORTC &= ~(1 << PORTC3);
		PORTC &= ~(1 << PORTC4);
		PORTC |= (1 << PORTC5);
		PORTB |= (1 << PORTB4);
	} else if (number == 5)
	{
		PORTC |= (1 << PORTC0);
		PORTC &= ~(1 << PORTC1);
		PORTC |= (1 << PORTC2);
		PORTC |= (1 << PORTC3);
		PORTC &= ~(1 << PORTC4);
		PORTC |= (1 << PORTC5);
		PORTB |= (1 << PORTB4);
	} else if (number == 6)
	{
		PORTC |= (1 << PORTC0);
		PORTC &= ~(1 << PORTC1);
		PORTC |= (1 << PORTC2);
		PORTC |= (1 << PORTC3);
		PORTC |= (1 << PORTC4);
		PORTC |= (1 << PORTC5);
		PORTB |= (1 << PORTB4);
	} else if (number == 7)
	{
		PORTC |= (1 << PORTC0);
		PORTC |= (1 << PORTC1);
		PORTC |= (1 << PORTC2);
		PORTC &= ~(1 << PORTC3);
		PORTC &= ~(1 << PORTC4);
		PORTC &= ~(1 << PORTC5);
		PORTB &= ~(1 << PORTB4);
	} else if (number == 8)
	{
		PORTC |= (1 << PORTC0);
		PORTC |= (1 << PORTC1);
		PORTC |= (1 << PORTC2);
		PORTC |= (1 << PORTC3);
		PORTC |= (1 << PORTC4);
		PORTC |= (1 << PORTC5);
		PORTB |= (1 << PORTB4);
	} else if (number == 9)
	{
		PORTC |= (1 << PORTC0);
		PORTC |= (1 << PORTC1);
		PORTC |= (1 << PORTC2);
		PORTC |= (1 << PORTC3);
		PORTC &= ~(1 << PORTC4);
		PORTC |= (1 << PORTC5);
		PORTB |= (1 << PORTB4);
	} else
	{
		PORTC |= (1 << PORTC0);
		PORTC |= (1 << PORTC1);
		PORTC |= (1 << PORTC2);
		PORTC |= (1 << PORTC3);
		PORTC |= (1 << PORTC4);
		PORTC |= (1 << PORTC5);
		PORTB &= ~(1 << PORTB4);
	}
}
