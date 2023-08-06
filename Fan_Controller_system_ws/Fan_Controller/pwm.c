/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the ATmega16 PWM driver
 *
 * Author: Ahmed El-Askary
 *
 *******************************************************************************/

#include "pwm.h"
#include <avr/io.h>
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0;
	uint16 speed = ((duty_cycle*255)/(100));
	OCR0  = speed;
	GPIO_setupPinDirection(PWM_OUTPUT_PORT_ID, PWM_OUTPUT_PIN_ID, PIN_OUTPUT);
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);;
}




