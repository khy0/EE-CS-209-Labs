#ifndef _UART_H
#define _UART_H

#include <stdbool.h>
#include <stdio.h>
#include <avr/io.h>

void usart_init(uint16_t ubrr);


void usart_transmit (uint8_t data);

#endif