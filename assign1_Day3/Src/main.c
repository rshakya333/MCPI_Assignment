/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// Orange LED -- GPIOD pin 13.
//	1 -- Led On
//	0 -- Led Off

int main(void) {
	SystemInit();
	// enable GPIOD clock -- RCC AHB1ENR[3] = 1
	RCC->AHB1ENR |= BV(3);
	// config GPIOD.13 as output -- MODER[27:26] - 01
	GPIOD->MODER &= ~BV(27);
	GPIOD->MODER |= BV(26);
	// config GPIOD.13 as pushpull -- OTYPER[13] - 0
	GPIOD->OTYPER &= ~BV(13);
	// config GPIOD.13 as low-speed -- OSPEEDR[27:26] - 00
	GPIOD->OSPEEDR &= ~(BV(27) | BV(26));
	// config GPIOD.13 with no pullup & pulldown resistor PUPDR[27:26] -- 00
	GPIOD->PUPDR &= ~(BV(27) | BV(26));

	while(1) {
		// Led ON -- GPIOD.13 = 1 -- ODR[13] = 1
		GPIOD->BSRR |= BV(13);
		// Delay
		DelayMs(500);
		// Led OFF -- GPIOD.13 = 0 -- ODR[13] = 0
		GPIOD->BSRR |= BV(29);
		// Delay
		DelayMs(500);
	}
	return 0;
}












