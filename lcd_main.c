#include "stdint.h"
#include "C:/Keil/ARM/ARMCC/include/tm4c123gh6pm.h" 
void SystemInit() {}


//#define LCD_DATA GPIOB
//#define LCD_CTRL GPIOA
	
#define RS 0x01        /* PORTD BIT0 mask */
#define RW 0x02        /* PORTD BIT1 mask */
#define EN 0x04        /* PORTD BIT2 mask */
	
void delayMs(int n);
void delayUs(int n);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);
	
int main(void)
{
LCD_init();
while(1)
{
LCD_command(1);         /* clear display */
LCD_command(0x80);      /* lcd cursor location */
delayMs(1000);
LCD_data('R');
//delayMs(1);
LCD_data('e');
//delayMs(1);
LCD_data('d');
//delayMs(1);
LCD_data('a');
//delayMs(1);
delayMs(500);
}
}
