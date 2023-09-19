/*
 * lab_4.c
 *
 * Created: 17/09/2023 10:44:10 pm
 * Author : rtor313
 */ 

#include <avr/io.h>
#include "common.h"
#include "adc.h"
#include "uart.h"

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <util/delay.h>

int uart_printf(char var, FILE *stream);

//creating a stream variable
static FILE usart_stdout = FDEV_SETUP_STREAM(uart_printf, NULL, _FDEV_SETUP_WRITE);




int main(void) {
	stdout = &usart_stdout;
	
	usart_init(12);
	adc_init(); // Initialize the ADC
	uint32_t adc0_values[40];
	uint32_t adc1_values[40];
	uint8_t sample_count = 0;
	uint32_t dc_voltage_mv = 0;
	for (int sample_count=0; sample_count < 80; sample_count++){
		if (sample_count % 2 == 0){
			adc0_values[sample_count / 2] = ((uint32_t)adc_read(0)*5000)/1024;
		}
		else {
			adc1_values[sample_count / 2] = ((uint32_t)adc_read(1)*5000)/1024;
		}
	}
	/*
	while (sample_count < 80){
		if (sample_count % 2 == 0){	
			adc0_values[sample_count / 2] = ((uint32_t)adc_read(0)*5000)/1024;
		}
		else {
			adc1_values[sample_count / 2] = ((uint32_t)adc_read(1)*5000)/1024;
		}
		sample_count++;
	}
	*/
	printf("Voltage(mV), Current(mA)\n\r");
	for (int i=0; i < 40; i++){
		printf("%d,%d\n\r", (uint16_t)adc0_values[i], (uint16_t)adc1_values[i]);
	}

	while (1) {
		// Read from ADC2
		//uint16_t adc_value = adc_read(2);

		// Convert the ADC value to millivolts
		//int adc_convert_mv(int value);

		// You can add code here to do something with the voltage_in_mV value
		// (like display it, send it to another device, etc.)
		dc_voltage_mv = ((uint32_t)adc_read(2)*5000)/1024;
		printf("Voltage: %d mV\n\r", (uint16_t)dc_voltage_mv);
		_delay_ms(500);
	}
	return 0;
}



int uart_printf(char var, FILE *stream) {
	usart_transmit(var);
	return 0;
}



