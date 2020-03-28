#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
// #include "buzzer.h"

void main(void) 
{  
  configureClocks();
  switch_init();
  //led_init();

  or_sr(0x18);  // CPU off, GIE on
} 