#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	int choice;
	char str[32];
	SystemInit();
	UartInit(BAUD_9600);
	LedInit(LED_RED);
	LedInit(LED_BLUE);

	while(1)
	{
		UartPuts("\r1.Red Led On.\n");
		UartPuts("\r2.Red Led Off.\n");
		UartPuts("\r3.Blue Led On.\n");
		UartPuts("\r4.Red Led Off.\n");

		UartGets(str);
		sscanf(str, "%d", &choice);

		switch(choice)
		{
			case 0: return 0;

			case 1: UartPuts("\rRed Led On.\n");
					LedOn(LED_RED);
					break;

			case 2: UartPuts("\rRed Led Off.\n");
					LedOff(LED_RED);
					break;

			case 3: UartPuts("\rBlue Led On.\n");
					LedOn(LED_BLUE);
					break;

			case 4: UartPuts("\rBlue Led Off.\n");
					LedOff(LED_BLUE);
					break;

			default:UartPuts("\rentered wrong choice.\n");
		}
	}
	return 0;
}

