#include "FlexTimer.h"
#include "MK64F12.h"

void FTM0_ISR()
{

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
	FTM0->MOD = 0x05;
	/**Configure FlexTimer in output compare in toggle mode*/
	FTM0->CONTROLS[0].CnSC = FTM_CnSC_MSA(1) | FTM_CnSC_ELSA(1);
	/**Assign channel value register with a predefined value*/
	FTM0->CONTROLS[0].CnV = 0x03;
	/**Select clock source and prescaler*/
	FTM0->SC |= FTM_SC_CLKS (FLEX_TIMER_CLKS_1)| FTM_SC_PS(FLEX_TIMER_PS_128);
}
