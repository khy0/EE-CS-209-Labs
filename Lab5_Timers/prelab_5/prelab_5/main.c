/*
 * prelab_5.c
 *
 * Created: 20/09/2023 5:38:03 pm
 * Author : rtor313
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRB = 0xFF;
	DDRC = 0x00;
	DDRD = 0x00;
    while (1) 
    {
		PORTB |= (1 << PORTB5);
		_delay_ms(375);
		PORTB &= ~(1 << PORTB5);
		_delay_ms(125);
		
    }
}

