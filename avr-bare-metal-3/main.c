#include <avr/interrupt.h>

#define DDRB_LED   (*(volatile uint8_t *)0x24)
#define PORTB_LED  (*(volatile uint8_t *)0x25)
#define TCCR1A     (*(volatile uint8_t *)0x80)
#define TCCR1B     (*(volatile uint8_t *)0x81)
#define TCNT1      (*(volatile uint16_t *)0x84)
#define TIFR1      (*(volatile uint8_t *)0x36)
#define TIMSK1     (*(volatile uint8_t *)0x6F)

ISR(TIMER1_OVF_vect) {
  TCNT1 = 49911;            // Reload Timer
  PORTB_LED ^= (1<<5);      // toggling led
}

int main() {

    DDRB_LED |= (1<<5);         // configuring led as output
    // Timer 1 config
    TCCR1A = 0x00;              // Timer mode normal 
    TCCR1B = 0x00;              // Initially timer stop
    TCNT1 = 49911;              // Preloading timer 65536-15625=49911(1s), for 2s 31250 increments needed so preload with 65536-31250=34286
    TIMSK1 |= (1<<0);           // Timer 1 interrupt enable  
    sei();                      // Enable Global Interrupt  
    TCCR1B = (1<<2) | (1<<0);   // Starting timer Clk selection with 1024 Prescaler


    for(;;) {
        // Does Nothing...
    }
}
