#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	static int cnt =0;
	char str[20];
	SystemInit();
	UartInit(BAUD_9600);
	SwitchInit(SWITCH);
	UartPuts("KILL COUNT\n");
	while(1)
	{
		while(exti0_flag == 0)
				;
		cnt++;
		sprintf(str,"\r%d",cnt);
		UartPuts(str);
		exti0_flag = 0;
	}
	return 0;
}

