/*
 * flexTimer.c
 *
 *  Created on: 14 mar. 2020
 *      Author: kcdia
 */

#include "flexTimer.h"

#define IC_FREC (21000000.0 / (128.0 + 1.0))

void FTM0_IRQHandler()
{
	static uint32_t last_value = 0;
	static uint32_t current_value = 0;
	int32_t diff = 0;
	uint32_t time = 0;

	last_value = current_value;
	current_value = FTM0->CONTROLS[0].CnV;

	diff = current_value - last_value;
	if(diff < 0)
	{
		diff += 0xFFFF;
	}
	time = IC_FREC / diff;

	FTM0->CONTROLS[0].CnSC &= ~(FTM_CnSC_CHF_MASK);
}

void FTM_init_input_capture(FlexTimer_configType * FTM_conf)
{
	FTM_clk(FTM_conf->FTM);
	FTM_MOD(FTM_conf->FTM, FTM_conf->MODE);
	FTM_CONF(FTM_conf->FTM, FTM_conf->CONF);
	FTM_MOD(FTM_conf->FTM, FTM_conf->MOD);
	FTM_CnSC(FTM_conf->FTM, FTM_conf->CH, FTM_conf->CnSC);
	FTM_SC(FTM_conf->FTM, FTM_conf->SC);
}

void FTM_clk(FTM_Type * FTM)
{

	if(FTM == FTM0)
	{
		SIM->SCGC6 |= SIM_SCGC6_FTM0(1);
	}
	else if(FTM == FTM1)
	{
		SIM->SCGC6 |= SIM_SCGC6_FTM1(1);
	}
	else if(FTM == FTM2)
	{
		SIM->SCGC3 |= SIM_SCGC3_FTM2(1);
	}
	else
	{
		SIM->SCGC3 |= SIM_SCGC3_FTM3(1);
	}
}

void FTM_MODE(FTM_Type * FTM, uint32_t mode)
{
	FTM->MODE |= mode;
}

void FTM_CONF(FTM_Type * FTM, uint32_t conf)
{
	FTM->CONF |= conf;
}

void FTM_MOD(FTM_Type * FTM, uint32_t mod)
{
	FTM->MOD |= mod;
}

void FTM_CnSC(FTM_Type * FTM, FTMchannel ch, uint32_t csc)
{
	FTM->CONTROLS[ch].CnSC |= csc;
}

void FTM_SC(FTM_Type * FTM, uint32_t sc)
{
	FTM->SC |= sc;
}

void FTM_CnV(FTM_Type * FTM, FTMchannel ch, uint32_t count_value)
{
	FTM->CONTROLS[ch].CnV |= count_value;
}
