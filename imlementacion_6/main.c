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
	gpio_pin_control_register_t pcr_in = GPIO_MUX1 | GPIO_PE | GPIO_PS | INTR_FALLING_EDGE ;
	gpio_pin_control_register_t alt4 = GPIO_MUX4;
	GPIO_clock_gating(GPIO_A);
	GPIO_clock_gating(GPIO_C);
	GPIO_pin_control_register(GPIO_C, bit_6, &pcr_in);
	GPIO_pin_control_register(GPIO_A, bit_4, &pcr_in);
	GPIO_pin_control_register(GPIO_C, bit_1, &alt4);
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, bit_6);
	GPIO_data_direction_pin(GPIO_A, GPIO_INPUT, bit_4);
	GPIO_data_direction_pin(GPIO_C, GPIO_OUTPUT, bit_1);
	NVIC_enable_interrupt_and_priotity(PORTC_IRQ, PRIORITY_5);
	NVIC_enable_interrupt_and_priotity(PORTA_IRQ, PRIORITY_5);

	NVIC_global_enable_interrupts;
	FlexTimer_Init();

	while(1)
	{

	}

	return 0;
}
