#include <stdint.h>

#define DDRB_LED 	(*(volatile uint8_t *)0x24)
#define PORTB_LED 	(*(volatile uint8_t *)0x25)
#define TCCR1A 		(*(volatile uint8_t *)0x80)
#define TCCR1B 		(*(volatile uint8_t *)0x81)
#define TCNT1 		(*(volatile uint16_t *)0x84)
#define TIFR1 		(*(volatile uint8_t *)0x36)

int main() {
	DDRB_LED |= (1<<5);
	TCCR1A = 0x00;
	TCCR1B = 0x00;

	for(;;) {
		TCNT1 = 34286;
		TCCR1B = (1<<2)|(1<<0);
		while((TIFR1 & (1<<0)) == 0) {
		}
		TIFR1 = (1<<0);
		PORTB_LED ^= (1<<5);
		TCCR1B = 0x00;
	}
}
