/*
 * display.h
 *
 * Created: 26/09/2023 8:21:20 am
 *  Author: rtor313
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdbool.h>
#include <stdint.h>

void display_init(void);
void send_next_character_to_display(void);
void usart_init(uint16_t UBRR);
void usart_transmit (uint8_t data);
void fourdigits(uint16_t millivolts);

#endif /* DISPLAY_H_ */