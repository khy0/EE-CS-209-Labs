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
	adc_init(); // Initialize the ADC

	while (1) {
		// Read from ADC2
		uint16_t adc_value = adc_read(2);

		// Convert the ADC value to millivolts
		int adc_convert_mv(int value);

		// You can add code here to do something with the voltage_in_mV value
		// (like display it, send it to another device, etc.)

		// Wait for 1ms before reading the value again
		_delay_ms(1);
	}
	return 0;
}


