//Note the use of #ifndef, #define, #endif to protect against multiple inclusions
#ifndef _ADC_H
#define _ADC_H

#include <stdint.h> //Necessary for definitions of uint8_t etc

void adc_init();
uint16_t adc_read(uint8_t chan);
int adc_convert_mv(int value);
void adc_convert_ascii(uint16_t millivolts);

#endif