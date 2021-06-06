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