#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char pwmCount = 0;
static enum case = 1;


void sm_fast_clock()		/* slowly cycle through {off, dim, bright} */
{
 case = (case + 1) % 2;
}



char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  
  switch (case) {

  case 0: changed = toggle_red() ; break;

  case 1: changed = toggle_green(); break;
  }

  led_changed = changed;
  led_update();
}



