#include <msp430.h>

#ifndef led_included
#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)



extern unsigned char red_on, green_on;
extern unsigned char led_changed;
///
extern unsigned char  green_led_state, red_led_state, led_state;
void led_switch();
///

void led_init();		/* initialize LEDs */
void led_update();		/* update leds */
void state(); //state

#endif