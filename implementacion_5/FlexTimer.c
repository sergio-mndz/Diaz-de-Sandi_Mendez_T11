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
		SIM->SCGC6 = SIM_SCGC6_FTM0(3);
		SIM->SCGC5 |= 0x3E00;
		/**Selects the FTM behavior in BDM mode.In this case in functional mode*/
		FTM0->CONF = FTM_CONF_BDMMODE(3);
		FTM0->FMS = 0x00;
		FTM0->MODE = 0x5;
		FTM0->MOD = 500000;
		FTM0->CONTROLS[0].CnSC = 0x28;
		FTM0->CONTROLS[1].CnSC = 0x28;
		FTM0->COMBINE = 0x02;
		FTM0->COMBINE |= 0x10;
		FTM0->DEADTIME = 0x1F;
		FTM0->CONTROLS[0].CnV = 10;
		FTM0->CONTROLS[1].CnV = 10;
		FTM0->CNTIN = 0x00;

		FTM0->CONTROLS[2].CnSC = 0x28;
		FTM0->CONTROLS[3].CnSC = 0x28;
		FTM0->COMBINE |= 0x0200;
		FTM0->COMBINE |= 0x1000;
		FTM0->CONTROLS[3].CnV = 10;
		FTM0->CONTROLS[2].CnV = 10;
		FTM0->SC |= FTM_SC_CLKS(FLEX_TIMER_CLKS_1)| FTM_SC_PS(FLEX_TIMER_PS_128);
}

