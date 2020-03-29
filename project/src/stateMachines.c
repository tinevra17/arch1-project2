#include <msp430.h>
#include "stateMachines.h"
#include "led.h"


// state variables 
static enum {off=0, on=1, dim=2 } cases;
static char count = 0;		

void caseSwitcher()	
{
  cases = (cases + 1) % 3;
}

void fast()
{
   count = (count + 1) % 2; 
}

void ledStates()
{
  char temp;
  switch (cases) {
  case off:
    temp = 0; break; //off
  case on:
    temp = 1; break; //on
  case dim:
    temp = (count < 1); break;  //dim
  }

  if (green_on != temp) {
    green_on = temp;
    led_changed = 1;
  }
}

void redLightOn()
{
  red_on = 1; 
}

void redLightOff()
{
  red_on = 0; 

}


