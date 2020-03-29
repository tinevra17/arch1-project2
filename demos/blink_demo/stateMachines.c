#include <msp430.h>
#include "stateMachines.h"
#include "led.h"


// state variables 
static enum {one=0, two=1, three=2, } cases;
static char pwmCount = 0;		

void
sm_slow_clock()		/* slowly cycle through {off, dim, bright} */
{
  cases = (cases + 1) % 3;
}

void
sm_fast_clock()	/* quickly cycle through 0...3 */
{
  pwmCount = (pwmCount + 1) & 3; 
}

void 
sm_update_led()
{
  char greenB;
  switch (cases) {
  case one:
    greenB = 0; break; //off
  case two:
    greenB = 1; break; 
  case dim:
   greenB = 1; break; 
    //greenB = (pwmCount < 1); break; 
  }

  if (green_on != greenB) {
    green_on = greenB;
    led_changed = 1;
  }
}


