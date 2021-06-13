#include "stdint.h"
#include <stdio.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <math.h>

#include "string.h"
#include "stdlib.h"
void SystemInit(){}
#define blue_led 	0x04
#define red_led  0x02
#define green_led 0x08
char UART7_read();
void PortE_Init();
void UART7_Init();
uint8_t UART7_ReadAvailable(void);
#define RS 0x01        /* PORTD BIT0 mask */
#define RW 0x02        /* PORTD BIT1 mask */
#define EN 0x04        /* PORTD BIT2 mask */
	
void delayMs(int n);
void delayUs(int n);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);
void LCDSendNumber(uint32_t Number);
void LCD_write_string(char *str);
uint8_t UART7_ReadAvailable();
double read_alon();	
char c;

	void UART7_Init(){
    SYSCTL_RCGCUART_R |= 0x80;
    while((SYSCTL_PRUART_R & 0x80) == 0);
    UART7_CTL_R &= ~UART_CTL_UARTEN;
    UART7_IBRD_R = 104;
    UART7_FBRD_R = 11;
	UART7_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
    UART7_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);
}
	
void init_portf(){
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

	
	
	char RRAD(void){
	
	while((UART1_FR_R&0X0010)!=0){}
		return((char)(UART1_DR_R&0xFF));
	}
	
	void LCD_init(void)
{

SYSCTL_RCGCGPIO_R  |= 0x08;   /* enable clock to GPIOD */
while( (SYSCTL_PRGPIO_R & 0x08) == 0x00 ) {}
	
SYSCTL_RCGCGPIO_R  |= 0x02;   /* enable clock to GPIOB */
while( (SYSCTL_PRGPIO_R & 0x02) == 0x00 ) {}
	
	
GPIO_PORTB_LOCK_R = 0x4C4F434B;
GPIO_PORTD_LOCK_R = 0x4C4F434B;
GPIO_PORTB_CR_R = 0xFF;
GPIO_PORTD_CR_R = 0x07;	
	
GPIO_PORTD_DIR_R = 0x07;     /* set PORTA pin 7-5 as output for control */
GPIO_PORTD_DEN_R  = 0x07;    /* set PORTA pin 7-5 as digital pins */
GPIO_PORTB_DIR_R = 0xFF;      /* set all PORTB pins as output for data */
GPIO_PORTB_DEN_R  = 0xFF;     /* set all PORTB pins as digital pins */
	
GPIO_PORTB_AMSEL_R = 0x00;	
GPIO_PORTD_AMSEL_R = 0x00;
GPIO_PORTB_AFSEL_R = 0x00;	
GPIO_PORTD_AFSEL_R = 0x00;	
GPIO_PORTB_PCTL_R = 0x00000000;
GPIO_PORTD_PCTL_R = 0x00000000;	
		
delayMs(20);                  /* initialization sequence */
LCD_command(0x30);
delayMs(5);
LCD_command(0x30);
delayUs(100);
LCD_command(0x30);
LCD_command(0x38); /* set 8-bit data, 2-line, 5x7 font */
LCD_command(0x06); /* move cursor right */
LCD_command(0x01); /* clear screen, move cursor to home */
LCD_command(0x0F); /* turn on display, cursor blinking */
}


void LCD_command(unsigned char command)
{
GPIO_PORTD_DATA_R = 0x00; /* RS = 0, R/W = 0 */
GPIO_PORTB_DATA_R = command;
GPIO_PORTD_DATA_R = EN; /* pulse E */
delayUs(0);
GPIO_PORTD_DATA_R = 0x00;
if (command < 4)
delayMs(2); /* command 1 and 2 needs up to 1.64ms */
else
delayUs(40); /* all others 40 us */
}
void LCD_write_string(char *str)
{
int i = 0;
while (str[i] != 0)
{
LCD_data(str[i]); 
delayMs(15);
i++;
}
}
void LCD_data(unsigned char data)
{
GPIO_PORTD_DATA_R = RS; /* RS = 1, R/W = 0 */
GPIO_PORTB_DATA_R = data;
GPIO_PORTD_DATA_R = EN | RS; /* pulse E */
delayUs(0);
GPIO_PORTD_DATA_R = 0x00;
delayUs(40);
}

void LCDSendNumber(uint32_t Number)
{uint8_t Numbers[10];
	int8_t Count;
	if(Number==0)
	{
		LCD_data(48);
		return;
	}
	for(Count=0;Number>0;Count++)
	{
		Numbers[Count]=(Number%10)+48;
		Number=Number/10;
	}
	for(Count--;Count>=0;Count--)
	{
		LCD_data(Numbers[Count]);
	}	}
void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} /* do nothing for 1 ms */
}
void delayUs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3; j++)
{}     
}
	
	double read_alon(){
		char str[80];
		int i;
		char* token;
		double alon ;
	for(i=0;i<=80;i++){
		str[i]=RRAD();
		
	  if((strncmp(str,"$GPRMC",6)==0)&& str[17] == 'A' ){

	// Returns first token
     token = strtok(str, ",");
  
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
			
       // printf("%s\n", token);
        token = strtok(NULL, ",");
			if(i==4){ alon=atof(token);
			}
	
	
	}
	
	}
} return alon;
	
	}
double read_alat(){
		char str[80];
		int i;
		char* token;
		double  alat;
	for(i=0;i<=80;i++){
		str[i]=RRAD();
		
	  if((strncmp(str,"$GPRMC",6)==0)&& str[17] == 'A' ){

	// Returns first token
     token = strtok(str, ",");
  
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
			
       // printf("%s\n", token);
        token = strtok(NULL, ",");
		
			if(i==2){ alat=atof(token);
			}
    
	
	}
	
	}
} 
	return alat;
	}
	
	
	
	double distance(double lat1, double lat2, double lon1, double lon2)
    {  int R = 6371; // Radius of the earth

    double latDistance = (lat2 - lat1);
    double lonDistance = (lon2 - lon1);
    double a = sin(latDistance / 2) * sin(latDistance / 2)
            + cos((lat1)) * cos((lat2))
            * sin(lonDistance / 2) * sin(lonDistance / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c * 1000; // convert to meters
    return distance;
	}
		void delay_ms(int n)
{
 int i,j;
for(i=0;i<n;i++)
for(j=0;j<3180;j++)
{}
}

	int total_dis(double lat1,double lon1){
		double total_distance;
		double d;
		
		while ( (lat1!= 30.0841475) && (lon1!= 31.2740277) ){
		
			double lat2=read_alat() ; double lon2=read_alat()/*from gps*/;
	
		 d= distance( lat1,  lat2,  lon1,  lon2) ;
		
	
	double total_distance= total_distance+d;
		delay_ms(1000);
		lat1=	lat2;
			lon1=lon2;
	}
	return (int)total_distance;}
	

 	void leds(int distance){
		if (distance >=100){
			GPIO_PORTF_DATA_R=red_led;
		}
		
		else GPIO_PORTF_DATA_R&=~red_led;
	}
	
	
	
	
	
	
	
	
	
 
int main(){
	while(1){
		int d;
		init_portf();
		LCD_init();
PortE_Init();
UART7_Init();
c = UART7_read();
LCD_command(0x01);         /* clear display */
LCD_command(0x80);      /* lcd cursor location */ 
	
delayMs(500);
			

 d=	total_dis(read_alat(),read_alon());
leds(d);
LCD_data('d');
LCD_data('i');
LCD_data('s');
LCD_data('t');
LCD_data('a');
LCD_data('n');
LCD_data('c');			
LCD_data('e');
LCD_data('_');	
LCD_data('i');	
LCD_data('s');
LCD_data('_');
LCD_data('t');
LCDSendNumber(d);
	}		
}