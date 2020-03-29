#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 125) {
    caseSwitcher();
    printf("sam");
    
  }
  sm_fast_clock(); //makes led blink
  sm_update_led();
  led_update();
}
