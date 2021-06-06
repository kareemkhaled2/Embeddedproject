void LCD_data(unsigned char data)
{
GPIO_PORTD_DATA_R = RS; /* RS = 1, R/W = 0 */
GPIO_PORTB_DATA_R = data;
GPIO_PORTD_DATA_R = EN | RS; /* pulse E */
delayUs(0);
GPIO_PORTD_DATA_R = 0x00;
delayUs(40);
}