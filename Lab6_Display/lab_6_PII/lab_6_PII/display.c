#include "display.h"
#include <avr/io.h>

//Array containing which segments to turn on to display a number between 0 to 9
//As an example seg_pattern[0] is populated with pattern to display number ‘0’
//TODO: Populate this array using your answer to QP.1
const uint8_t seg_pattern[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
//4 characters to be displayed on Ds1 to Ds 4
static volatile uint8_t disp_characters[4]={0,0,0,0};
//The current digit (e.g. the 1's, the 10's) of the 4-digit number we're displaying
static volatile uint8_t disp_position=0;

void display_init(void){
	//TODO: Finish this function
	//Configure DDR bits of the I/O pins connected to the display
	DDRC |= (1 << PORTC5);
	DDRC |= (1 << PORTC4);
	DDRC |= (1 << PORTC3);
	
	DDRD |= (1 << PORTD4);
	DDRD |= (1 << PORTD5);
	DDRD |= (1 << PORTD6);
	DDRD |= (1 << PORTD7);
}
//Populate the array ‘disp_characters[]’ by separating the four digits of ‘number’
//and then looking up the segment pattern from ‘seg_pattern[]’

void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos){
	//TODO: finish this function
	//1. Separate each digit from ‘number’
	// e.g. if value to display is 1230 the separated digits will be
	// ‘1’, ‘2’, ‘3’ and ‘0’
	//2. Lookup pattern required to display each digit from ‘seg_pattern[]’
	// and store this pattern in appropriate position of ‘disp_characters[]’
	// e.g. For digit ‘0’ in example above disp_characters[0] = seg_pattern[0]
	//3. For the project you may modify this pattern to add decimal point at
	// the position ‘decemal_pos’
	for (int i=0; i < 4; i++){
		uint8_t digit = number % 10;
		disp_characters[i] = seg_pattern[digit];
		number /= 10;
	}
	if (decimal_pos < 4){
		disp_characters[decimal_pos] |= 0x80;
	}
}

//Render a single digit from ‘disp_characters[]’ on the display at ‘disp_position’
void send_next_character_to_display(void){
	//TODO: finish this function
	//1. Based on ‘disp_position’, load the digit to send to a local variable
	//2. Send this bit pattern to the shift-register as in Q2.2
	//3. Disable all digits
	//4. Latch the output by toggling SH_ST pin as in Q2.2
	//5. Now, depending on the value of pos, enable the correct digit
	// (i.e. set Ds1, Ds2, Ds3 and Ds4 appropriately)
	//6. Increment ‘disp_position’ so the next of the 4 digits will be displayed
	// when function is called again from ISR (reset ‘disp_position’ after 3)
	uint8_t segment_data = disp_characters[disp_position];
	PORTC &= ~(1 << PORTC3);
	PORTC &= ~(1 << PORTC5);
	
	// Now send the actual segment_data to the shift register
	for (int8_t i=7; i >= 0; i--){
		PORTC &= ~(1 << PORTC4);
		PORTC |= ((segment_data >> i) & 1) << PORTC4;
		
		PORTC |= (1 << PORTC3);
		PORTC &= ~(1 << PORTC3);
		
	}
	PORTC |= (1 << PORTC5);
	PORTC &= ~(1 << PORTC5);
	
	PORTD |= 0xF0;  // Disable all digits
	PORTD &= ~(1 << (PORTD4 + disp_position));  // Enable the current digit

	disp_position = (disp_position + 1) % 4; // Move to the next digit
	
}
