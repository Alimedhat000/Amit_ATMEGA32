#ifndef UART_H
#define	UART_H

#include <xc.h> 
#include "DIO.h"

#define F_CPU 16000000UL
#define USART_BAUD_9600 9600
#define USART_TRANSMIT  1
#define USART_RECIEVE  2
#define USART_FULL_DUPLEX  3

#define USART_ASYNC_MODE 1
#define USART_ASYNC_2X_MODE 2 
#define USART_SYNC_MASTER 3
#define USART_SYNC_SLAVE 4

#define XCK PB0
// when accessing UCSRC the command should be like:
// UCSRC = UCSRC | (1<<URSEL) .....
void init_Usart(unsigned int baud, char TX_RX, char mode);
void Usart_Buadrate_select(char baudrate);
void Usart_Transmit(char data);
unsigned char USART_Receive(void);
void USART_Transmit_en();
void USART_Recieve_en();
void USART_Recieve_disable();
void USART_Transmit_disable();
#endif	/* XC_HEADER_TEMPLATE_H */

