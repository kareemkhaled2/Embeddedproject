#include "stdint.h"
#include <stdio.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "C:/Keil/EE319Kware/inc/math.h"
void SystemInit(){}
#define blue_led 	0x04
#define red_led  0x02
#define green_led 0x08
	void init_UART(){
SYSCTL_RCGCUART_R|=0X001;
SYSCTL_RCGCGPIO_R|=0X001;
UART0_CTL_R&=~0X0001;
UART0_IBRD_R=520;
UART0_FBRD_R=520;	
UART0_LCRH_R=0X0070;
UART0_CTL_R=0X0301;	
GPIO_PORTA_AFSEL_R|=0X03;
GPIO_PORTA_PCTL_R=(GPIO_PORTA_PCTL_R&0XFFFFFF00)+0X00000011;
GPIO_PORTA_DEN_R|=0X03;
GPIO_PORTA_AMSEL_R&=~0X03;}