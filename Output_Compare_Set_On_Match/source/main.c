/**
 * @file    Output_Compare_Set_On_Match.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include <stdint.h>
#include "MK64F12.h"
#include "flexTimer.h"
#include "bits.h"
#include "GPIO.h"

/**
 * Output compare frequency = (bus clock)/(Prescaler(mod+1)).
 * Note that is the same frequency of the overflow flow.
 */

int main(void) {
	SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTA | GPIO_CLOCK_GATING_PORTC;
	PORTC->PCR[1]   = PORT_PCR_MUX(0x4);

	FlexTimer_Init();

    while(1) {

    }
    return 0 ;
}
