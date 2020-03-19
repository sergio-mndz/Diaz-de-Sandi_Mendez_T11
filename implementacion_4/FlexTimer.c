/**
	\file
	\brief
		This is the starter file of FlexTimer.
		In this file the FlexTimer is configured in overflow mode.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	21/03/2019
	\todo
	    Add configuration structures.
 */



#include "FlexTimer.h"
#include "MK64F12.h"



void FlexTimer_update_channel_value(int16_t channel_value)
{
	/**Assigns a new value for the duty cycle*/
	FTM0->CONTROLS[0].CnV = channel_value;
}


void FlexTimer_Init()
{


	/**Clock gating for FlexTimer*/
	SIM->SCGC6 |= SIM_SCGC6_FTM0(1);
	/**When write protection is enabled (WPDIS = 0), write protected bits cannot be written.
	* When write protection is disabled (WPDIS = 1), write protected bits can be written.*/
	FTM0->MODE |= FTM_MODE_WPDIS_MASK;
	/**Enables the writing over all registers*/
	FTM0->MODE &= ~ FTM_MODE_FTMEN_MASK;
	/**Assigning a default value for modulo register*/
	FTM0->MOD = 0x00FF;
	/**Selects the Edge-Aligned PWM mode mode*/
	FTM0->CONTROLS[0].CnSC = FTM_CnSC_MSB(1) | FTM_CnSC_ELSB(1);
	/**Assign a duty cycle of 50%*/
	FTM0->CONTROLS[0].CnV = FTM0->MOD/2;
	/**Configure the times*/
	FTM0->SC |= FTM_SC_CLKS(FLEX_TIMER_CLKS_1)| FTM_SC_PS(FLEX_TIMER_PS_128);
}
