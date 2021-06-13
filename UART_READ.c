////////////////////////////////////////////

char UART7_read(){
    while((UART7_FR_R & 0x10) == 0x10);
			return UART7_DR_R & 0xFF;   
}

//////////////////////////////////////////////

uint8_t UART7_ReadAvailable(void){
    return ((UART7_FR_R&UART_FR_RXFE) == UART_FR_RXFE ) ? 0 : 1;
}

///////////////////////////////////