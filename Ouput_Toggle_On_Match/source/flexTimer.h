/*
 * flexTimer.h
 *
 *  Created on: 14 mar. 2020
 *      Author: kcdia
 */

#ifndef FLEXTIMER_H_
#define FLEXTIMER_H_

#include "MK64F12.h"
#include "stdint.h"
#include "stdio.h"

#define FLEX_TIMER_CLKS_0  (0U)
#define FLEX_TIMER_CLKS_1  (1U)
#define FLEX_TIMER_CLKS_2  (2U)
#define FLEX_TIMER_CLKS_3  (3U)

#define FLEX_TIMER_PS_1    (0U)
#define FLEX_TIMER_PS_2    (1U)
#define FLEX_TIMER_PS_4    (2U)
#define FLEX_TIMER_PS_8    (3U)
#define FLEX_TIMER_PS_16    (4U)
#define FLEX_TIMER_PS_32    (5U)
#define FLEX_TIMER_PS_64    (6U)
#define FLEX_TIMER_PS_128    (7U)

typedef enum {CH_0, CH_1, CH_2, CH_3, CH_4, CH_5, CH_6, CH_7, CH_8} FTMchannel;

typedef struct
{
	FTM_Type * FTM;
	FTMchannel CH;
	uint32_t MODE;
	uint32_t CONF;
	uint32_t MOD;
	uint32_t CNTIN;
	uint32_t CnSC;
	uint32_t SC;
	uint32_t CnV;
} FlexTimer_configType;

void FTM_init_input_capture(FlexTimer_configType * FTM_conf);

void FTM_clk(FTM_Type * FTM);
void FTM_MODE(FTM_Type * FTM, uint32_t mode);
void FTM_CONF(FTM_Type * FTM, uint32_t conf);
void FTM_MOD(FTM_Type * FTM, uint32_t mod);
void FTM_CnSC(FTM_Type * FTM, FTMchannel ch, uint32_t csc);
void FTM_SC(FTM_Type * FTM, uint32_t sc);
void FTM_CnV(FTM_Type * FTM, FTMchannel ch, uint32_t count_value);



#endif /* FLEXTIMER_H_ */
