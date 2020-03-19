 
/**
 * @file    Ouput_Toggle_On_Match.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include <stdint.h>
#include "MK64F12.h"
#include "flexTimer.h"
#include "bits.h"
#include "GPIO.h"
#include "NVIC.h"

/**
 * Output compare frequency = (bus clock)/(Prescaler(mod+1)).
 * Note that is the same frequency of the overflow flow.
 */
int main(void)
{
	/** Configuration for pin 1 on port c.
	 * Output compare is on option 4 in the pin control register*/
    SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTA | GPIO_CLOCK_GATING_PORTC;
	PORTC->PCR[1]   = PORT_PCR_MUX(0x4);
	/**Initialization of FlexTimer in output compare mode*/
	FlexTimer_Init();
	for(;;) {

	}
	return 0;
}
