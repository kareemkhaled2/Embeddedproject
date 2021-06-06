#include "stdint.h"
#include <stdio.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "C:/Keil/EE319Kware/inc/math.h"
void SystemInit(){}
#define blue_led 	0x04
#define red_led  0x02
#define green_led 0x08
void init(){
uint32_t delay;
SYSCTL_RCGCGPIO_R |=0x20;
delay=1;
GPIO_PORTF_LOCK_R= 0x4c4f434b;
GPIO_PORTF_CR_R= 0x1f;
GPIO_PORTF_AFSEL_R=0x00;
GPIO_PORTF_PCTL_R=0x00;
GPIO_PORTF_AMSEL_R=0x00;
GPIO_PORTF_DIR_R=0x0E;
GPIO_PORTF_DEN_R=0x1f;
GPIO_PORTF_PUR_R=0x11;
	}