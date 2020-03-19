/**
 * @file    Output_Compare_Set_On_Match.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "stdint.h"
#include "MK64F12.h"
#include "flexTimer.h"
#include "bits.h"
#include "GPIO.h"
#include "NVIC.h"

#define OUTPUT_PINS 0x02

/**
 * Output compare frequency = (bus clock)/(Prescaler(mod+1)).
 * Note that is the same frequency of the overflow flow.
 */
int main(void)
{
	volatile uint16_t cntTimerValue=0;
	/** Configuration for pin 1 on port c.
	 * Output compare is on option 4 in the pin control register*/
    SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTA | GPIO_CLOCK_GATING_PORTC;
    GPIOC->PDDR = OUTPUT_PINS;
	PORTC->PCR[1] = GPIO_MUX1|GPIO_PE|GPIO_PS;
	/**Initialization of FlexTimer in output compare mode*/
	FlexTimer_Init();
	NVIC_enable_interrupt_and_priotity(FTM0_IRQ,PRIORITY_9);
	NVIC_global_enable_interrupts;
	for(;;) {
		cntTimerValue = FTM0->CNT;
	}
	return 0;
}
