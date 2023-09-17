#include "common.h"
#include "adc.h"
#include <avr/io.h>

#define ADC_RESOLUTION 1024  // 2^10 for a 10-bit ADC
#define V_REF 5000  // 5V in millivolts

void adc_init(void) {
	// Configure the ADMUX
	ADMUX = (1 << REFS0); // Reference voltage set to AVCC
	ADMUX |= (1 << MUX0); // Channel selection ADC1

	// Configure the ADCSRA
	ADCSRA = (1 << ADEN) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC and set prescaler to 125kHz (for F_CPU = 2MHz)
}

uint16_t adc_read(uint8_t chan) {
	// Set the channel
	ADMUX &= 0xF0;
	ADMUX |= 0x01;

	// Start the conversion
	ADCSRA |= (1 << ADSC);

	// Wait for the conversion to finish
	while(!(ADCSRA & (1 << ADIF)));

	// Clear the ADIF bit
	ADCSRA |= (1 << ADIF);

	// Read and return the ADC result (combining ADCH and ADCL)
	return ADC;
}

int adc_convert_mv(int value) {
	// Calculate the voltage resolution
	int voltage_resolution = V_REF / ADC_RESOLUTION;
	
	// Convert the ADC count to millivolts
	int millivolts = value * voltage_resolution;
	
	// Return the calculated millivolt value
	return millivolts;
}
