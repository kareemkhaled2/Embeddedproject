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