#include <stdint.h>

#include "board_io.h"     // for the blink functions
#include "bsp.h"
#include "ticks.h"        // for resetTicks()
#include "lm4f120h5qr.h"  // map of named hardware addresses
//#include "masks.h"        // defined bit mask values
#include "unicorn.h"

////////////////////////////////////////////////////////////

#include <intrinsics.h>


int main()
{ 
  // un-gateclock GPIOF AHB, set digital/direction , set Systick, set SysTck/PendSV priorities
  BSP_init();
  
  //OS stuff
  initializeScheduler();
  
  //***start tasks here***
  readyNewTask(&blinkRed);
  readyNewTask(&blinkBlue);
  readyNewTask(&blinkGreen);
  
  resetTicks(); //set starting number of ticks to 0

  __asm("CPSIE I"); //enable interrupts
  
  //***from this point, the systick interrupt handler will begin executing and will cause scheduling of processes**
  
  while(1);

  //return 0;
}