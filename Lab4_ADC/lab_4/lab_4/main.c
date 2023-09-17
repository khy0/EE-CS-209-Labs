/*
 * lab_4.c
 *
 * Created: 17/09/2023 10:44:10 pm
 * Author : Rodolfo
 */ 

#include "adc.h"
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 2000000

int main(void) {
	adc_init(); // Initialize the ADC

	while (1) {
		// Your main loop code here
		_delay_ms(1000);
	}
	return 0;
}


