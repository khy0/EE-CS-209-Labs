/*
 * pre_lab.c
 *
 * Created: 11/08/2023 4:58:13 pm
 * Author : rtor313
 */ 
#define F_CPU 2000000UL

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

#define  NUMTOCHECK 7
#define PRIMES_LEN 62

bool check_prime(uint16_t chk_no);
void usart_init(uint16_t ubrr);
void usart_transmit (uint8_t data);

int main(void)
{
	volatile int primes[PRIMES_LEN];
	bool is_prime = check_prime(NUMTOCHECK);
	int j=0;
	for (int i=1; i <= 300; i++){
		if (check_prime(i)){
			primes[j] = i;
			j++;
		}
	}
	usart_init(12);
		
    /* Replace with your application code */
    while (1) 
    {
		for (int i=0; i<62; i++){
			_delay_ms(500);
			uint16_t h = primes[i]/100;
			usart_transmit(h + 48);
			_delay_ms(500);
			uint16_t t = primes[i]/10;
			usart_transmit(48 + t - h*10);
			_delay_ms(500);
			usart_transmit(primes[i]%10 + 48);
			_delay_ms(500);
			usart_transmit(32);
		}
    }
	
}

bool check_prime(uint16_t chk_no){
	for (uint16_t cnt1  = 2; cnt1 < chk_no; cnt1++){
		if ((chk_no % cnt1) == 0){
			return false;
		}
	}
	return true;
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

