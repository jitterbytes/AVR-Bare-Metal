#include <avr/interrupt.h>

#define DDRB_LED   (*(volatile uint8_t *)0x24)
#define PORTB_LED  (*(volatile uint8_t *)0x25)
#define TCCR1A     (*(volatile uint8_t *)0x80)
#define TCCR1B     (*(volatile uint8_t *)0x81)
#define TCNT1      (*(volatile uint16_t *)0x84)
#define TIFR1      (*(volatile uint8_t *)0x36)
#define TIMSK1     (*(volatile uint8_t *)0x6F)
#define OCR1A      (*(volatile uint16_t *)0x88)

void setup() {
  DDRB_LED |= (1<<5);           // Configuring led as output
  // Timer 1 config
  TCCR1A = 0x00;                // Timer CTC Mode (No change in this reg) 
  TCCR1B = 0x08;                // CTC Mode
  OCR1A = 15624;                // Compare Value set for 1s
  TIMSK1 |= (1<<1);            // Timer 1 Compare A interrupt enable  
  sei();
  TCCR1B |= (1<<2) | (1<<0);   // Starting timer Clk selection with 1024 Prescaler
}

void loop() {
  // Does Nothing..
}

ISR(TIMER1_COMPA_vect) {
  PORTB_LED ^= (1<<5);      // toggling led
}