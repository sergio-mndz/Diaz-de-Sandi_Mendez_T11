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

void FTM0_IRQHandler()
{
	static uint32_t counter = 0;
	counter++;
	FTM0->SC &= ~ FTM_SC_TOF_MASK;
	/** Toggling the output in port C*/
	if(counter == 700){
		GPIOC->PSOR ^= 0x02;
		counter = 0;
	} else {
		GPIOC->PCOR ^= 0x02;
	}

}

void FlexTimer_Init()
{
	/**Clock gating for FlexTimer*/
	SIM->SCGC6 |= SIM_SCGC6_FTM0(1);
	/**It enable the FTM*/
	FTM0->MODE |= FTM_MODE_FTMEN_MASK;
	/**Selects the FTM behavior in BDM mode.In this case in functional mode*/
	FTM0->CONF |= FTM_CONF_BDMMODE(3);
	/**Assign modulo register with a predefined value*/
	FTM0->MOD = 0xF0;
	/**Configure FlexTimer in output compare in clear mode*/
	FTM0->CONTROLS[0].CnSC = FTM_CnSC_MSA(1) | FTM_CnSC_ELSA(2);
	/**Assign channel value register with a predefined value*/
	FTM0->CONTROLS[0].CnV = 0x10;
	/**Select clock source and prescaler*/
	FTM0->SC |= FTM_SC_TOIE(1) | FTM_SC_CLKS (FLEX_TIMER_CLKS_1)| FTM_SC_PS(FLEX_TIMER_PS_128);
}

