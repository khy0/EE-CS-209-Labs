#include "common.h"
#include "adc.h"
#include <avr/io.h>

void adc_init(void) {
	// Configure the ADMUX
	ADMUX = (1 << REFS0); // Reference voltage set to AVCC
	ADMUX |= (1 << MUX0); // Channel selection ADC1

	// Configure the ADCSRA
	ADCSRA = (1 << ADEN) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC and set prescaler to 125kHz (for F_CPU = 2MHz)
}
