/*
 * lab_4.c
 *
 * Created: 17/09/2023 10:44:10 pm
 * Author : rtor313
 */ 

#include <avr/io.h>
#include "adc.h"
#include "common.h"
#include <util/delay.h>

int main(void) {
	void adc_init(void); // Initialize the ADC

	while (1) {
		// Your main loop code here
		_delay_ms(1000);
	}
	return 0;
}


