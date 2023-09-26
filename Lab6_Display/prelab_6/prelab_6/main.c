/*
 * prelab_6.c
 *
 * Created: 27/09/2023 12:15:34 am
 * Author : rtor313
 */ 

#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "display.h"

uint8_t counter = 0;

int main(void)
{
	display_init();
	
	while (1)
	{
		display_counter(counter);
		counter++;
		
		if (counter > 9)
		{
			counter = 0;
		}
	}
}

