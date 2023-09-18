#include "common.h"
#include "adc.h"
#include <avr/io.h>

#define ADC_RESOLUTION 1024  // 2^10 for a 10-bit ADC
#define V_REF 5000  // 5V in millivolts

void adc_init() {
	// Configure the ADMUX
	ADMUX |= (1 << REFS0); // Reference voltage set to AVCC
	ADMUX |= (1 << MUX1); // Channel selection ADC2

	// Configure the ADCSRA
	ADCSRA |= 0x84; // Enable ADC and set prescaler to 16 (for F_CPU = 2MHz)
}

uint16_t adc_read(uint8_t chan) {
	// Set the channel
	ADMUX &= 0xF0;
	ADMUX |= chan;

	// Start the conversion
	ADCSRA |= (1 << ADSC);

	// Wait for the conversion to finish
	while((ADCSRA & (1 << ADIF)) == 0){
		;
	}

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

void usart_init(uint16_t ubrr) {
	UCSR0B |= (1 << TXEN0);
	UBRR0 = ubrr;
}

void usart_transmit (uint8_t data) {
	
	while( (UCSR0A & (1 << UDRE0)) == 0) {
		;
	}
	
	UDR0 = data;
}

void adc_convert_ascii(uint16_t millivolts){
	usart_transmit(millivolts / 1000 + 48);
	usart_transmit(millivolts / 100 + 48);
	usart_transmit(millivolts / 10 + 48);
	usart_transmit(millivolts % 10 + 48);
}
