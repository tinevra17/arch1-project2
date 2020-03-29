#include <msp430.h>
#include "stateMachines.h"
#include "led.h"


// state variables 
static enum {off=0, on=1, dim=2, } cases;
static char pwmCount = 0;		

void
caseSwitcher()	
{
  cases = (cases + 1) % 3;
}

void
fast()	/* quickly cycle through 0...3 */
{
  pwmCount = (pwmCount + 1) % 3; 
}

void ledStates()
{
  char greenB;
  switch (cases) {
  case off:
    greenB = 0; break; //off
  case on:
    greenB = 1; break; //bright
  case dim:
    greenB = (pwmCount < 1); break;  //dim
  }

  if (green_on != greenB) {
    green_on = greenB;
    led_changed = 1;
  }
}


