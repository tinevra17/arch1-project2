#include <msp430.h>
#include "stateMachines.h"
#include "led.h"


// state variables 
static enum {off=0, dim=1, bright=2, dim2=3, } ledMode;
static char pwmCount = 0;		

void
sm_slow_clock()		/* slowly cycle through {off, dim, bright} */
{
  ledMode = (ledMode + 1) % 3;
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
  switch (ledMode) {
  case off:
    greenB = 0; break;
  case bright:
    greenB = 1; break;
  case dim:
    greenB = (pwmCount < 1); break; /* 25% duty cycle */
    ledMode++;

  case dim2:
    greenB = (pwmCount < 4); break; /* 25% duty cycle */
  }

  if (green_on != greenB) {
    green_on = greenB;
    led_changed = 1;
  }
}


