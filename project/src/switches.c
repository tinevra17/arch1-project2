#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "stateMachines.h"


char switch_state_down, switch_state_changed; /* effectively boolean */

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */
  return p2val;
}

void
switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();
  char button1 = (p2val & SW1) ? 0 : SW1;
  char button2 = (p2val & SW2) ? 0 : SW2;
  char button3 = (p2val & SW3) ? 0 : SW3;
  char button4 = (p2val & SW4) ? 0 : SW4;

  if(button1){
    //buzzer_init();
    song();
  }

  if(button2){
    //led_init();
    song();
    enableWDTInterrupts();
   
  }


  if(button3){
     //blink();
    

  }

  if(button4){

  }
}