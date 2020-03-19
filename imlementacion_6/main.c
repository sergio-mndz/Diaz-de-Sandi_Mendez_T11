/**
	\file
	\brief
		This project shows how to configure FlexTimer in PWM mode.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	21/03/2019
	\todo
	    Add configuration structures.
 */


#include "MK64F12.h" /* include peripheral declarations */
#include "GPIO.h"
#include "FlexTimer.h"
#include "NVIC.h"
#include "stdint.h"
#include "Bits.h"

uint16_t g_duty_cycle;

int main(void)
{
	gpio_pin_control_register_t alt4 = GPIO_MUX4;
	GPIO_clock_gating(GPIO_C);
	GPIO_pin_control_register(GPIO_C, bit_1, &alt4);
	GPIO_pin_control_register(GPIO_C, bit_2, &alt4);
	GPIO_data_direction_pin(GPIO_C, GPIO_OUTPUT, bit_1);
	GPIO_data_direction_pin(GPIO_C, GPIO_OUTPUT, bit_2);

	FlexTimer_Init();

	while(1)
	{

	}

	return 0;
}
