/*
 * lab_6_PII.c
 *
 * Created: 29/09/2023 2:19:07 pm
 * Author : rtor313
 */ 

#define F_CPU 2000000UL

#include <avr/io.h>
#include "display.h"
#include <util/delay.h>
#include "timer0.h"
#include <avr/interrupt.h>

int main(void)
{
	/* Replace with your application code */
	display_init();
	timer0_init();
	sei();
	
	while (1)
	{
		_delay_ms(100); 
	}
}


