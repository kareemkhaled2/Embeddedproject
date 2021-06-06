#include "stdint.h"
#include "C:/Keil/EE319KwareSpring2021/inc/tm4c123gh6pm.h" 
void SystemInit() {}
	
	
// Initialization Port 
void PORTF_Init() 
	{
	SYSCTL_RCGCGPIO_R |= 0x20 ;
	while( (SYSCTL_PRGPIO_R & 0x20) == 0 ) {}
	GPIO_PORTF_LOCK_R = 0x4C4F434B ;
	GPIO_PORTF_CR_R = 0x1F ; 
	GPIO_PORTF_AFSEL_R = 0 ;
	GPIO_PORTF_AMSEL_R = 0 ;
	GPIO_PORTF_PCTL_R = 0 ;
	GPIO_PORTF_DIR_R = 0x0E ;
	GPIO_PORTF_DEN_R = 0x1F ;
	GPIO_PORTF_PUR_R = 0x11 ;	
}


int main() {
	
PORTF_Init() ;
	
	while(1) {
		switch (GPIO_PORTF_DATA_R & 0x11) {
			
			case 0x00 :
				GPIO_PORTF_DATA_R = 0x08 ;
				break ;
			case 0x10 :
				GPIO_PORTF_DATA_R = 0x04 ;  
			break ;
			case 0x01 : 
				GPIO_PORTF_DATA_R = 0x02 ;
			break ;
			case 0x11 :
			GPIO_PORTF_DATA_R &=0x11 ;
			break ;
			default:
				continue ;
		}
	}	
}