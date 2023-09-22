#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>

void usart_init(uint16_t ubrr) {
	// Sets the transmitter enable in register B to 1
	UCSR0B |= (1 << TXEN0);
	// Sets the UBRR0 register to the ubrr value
	UBRR0 = ubrr;
}


void usart_transmit (uint8_t data) {
	// checks if everything has been sent through
	while( (UCSR0A & (1 << UDRE0)) == 0) {
		// if UDRE0 is not 0 wait until it is 0
		;
	}
	// puts the data into the UDR0 bit
	UDR0 = data;
}