void UART7_Init(){
    SYSCTL_RCGCUART_R |= 0x80;
    while((SYSCTL_PRUART_R & 0x80) == 0);
    UART7_CTL_R &= ~UART_CTL_UARTEN;
    UART7_IBRD_R = 104;
    UART7_FBRD_R = 11;
	UART7_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
    UART7_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);
}