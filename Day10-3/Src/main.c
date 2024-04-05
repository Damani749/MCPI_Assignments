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

#include "uart.h"
#include "timer.h"
#include "i2c_lcd.h"
#include "i2c.h"
extern volatile int flag;
int c = 0;
char str[16] = " ";
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	int ret = 0;
	SystemInit();
	ret = LcdInit();
	TimerInit(5000);

	while(1)
	{
		//LcdWrite(LCD_CMD, LCD_CLEAR);
		if(flag == 1)
		{
			c++;
			flag = 0;
		}
		sprintf(str,"count = %d",c);
		LcdPuts(LCD_LINE1,str);
		DelayMs(1000);
	}
}

