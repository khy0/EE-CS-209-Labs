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

void display_init();

// This function disables both of the digits
void disable_digits();

// This function enables Ds1 by setting it to 0, and sets Ds2 to 1
void enable_Ds1();

// This function enables Ds2 by setting it to 0, and sets Ds1 to 1
void enable_Ds2();

// This function increments our ones and tens digit individually so that we know which digit to display
void increment_num();

uint8_t get_ones();

uint8_t get_tens();

// This function inputs the signal to display the number
void display_counter(uint8_t number);

#endif /* DISPLAY_H_ */