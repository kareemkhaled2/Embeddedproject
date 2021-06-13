#include "stdint.h"
#include "C:/Keil/ARM/ARMCC/include/tm4c123gh6pm.h"
#include "string.h"
#include "C:/Keil/ARM/ARMCC/include/math.h"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>

void SystemInit() {}

	
#define RS 0x01        /* PORTD BIT0 mask */
#define RW 0x02        /* PORTD BIT1 mask */
#define EN 0x04        /* PORTD BIT2 mask */
const double PI = 3.1415926;
char c;

char UART7_read();
void PortE_Init();
void UART7_Init();
uint8_t UART7_ReadAvailable(void);	
void delayMs(int n);
void delayUs(int n);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);
void LCDSendNumber(uint32_t Number);
void LCD_write_string(char *str);
uint8_t UART7_ReadAvailable();
double read_alon();
int total_dis(double lat1,double lon1);
double distance(double lat1, double lat2, double lon1, double lon2);	
	
int main(){

LCD_init();
PortE_Init();
UART7_Init();	
	
while(1){

LCD_command(0x01);         /* clear display */
LCD_command(0x80);      /* lcd cursor location */ 

delayMs(500);

//c = UART7_read();
//read_alon();
double distance(alat, double lat2, alon, double lon2);
//LCD_write_string("Distance_");
//total_dis(alat,alon);

delayMs(500);
	
 }}