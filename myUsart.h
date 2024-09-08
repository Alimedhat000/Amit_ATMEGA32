#ifndef MYUSART_H
#define MYUSART_H

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

/**
 * Initialize the USART with the given baud rate, TX/RX mode, and USART mode.
 * @param baud The baud rate for communication.
 * @param TX_RX Select whether to enable transmission, reception, or both.
 * @param mode Select USART mode (async, async 2x, sync master, or sync slave).
 */
void init_Usart(unsigned int baud, char TX_RX, char mode);

/**
 * Set the baud rate dynamically based on the current mode.
 * @param baudrate The baud rate to be set.
 */
void Usart_set_Baudrate(unsigned int baudrate);

/**
 * Get the current baud rate based on the UBRR register value.
 * @return The current baud rate.
 */
unsigned int Usart_get_Baudrate(void);

/**
 * Transmit a single character over USART.
 * @param data The character to transmit.
 */
void Usart_Transmit(char data);

/**
 * Receive a single character over USART.
 * @return The received character.
 */
unsigned char Usart_Receive(void);

/**
 * Enable the USART transmitter.
 */
void Usart_Transmit_en(void);

/**
 * Enable the USART receiver.
 */
void Usart_Recieve_en(void);

/**
 * Disable the USART transmitter.
 */
void Usart_Transmit_disable(void);

/**
 * Disable the USART receiver.
 */
void Usart_Recieve_disable(void);

/**
 * Enable RX complete interrupt.
 */
void Usart_en_RX_int(void);

/**
 * Disable RX complete interrupt.
 */
void Usart_disable_RX_int(void);

/**
 * Enable TX complete interrupt.
 */
void Usart_en_TX_int(void);

/**
 * Disable TX complete interrupt.
 */
void Usart_disable_TX_int(void);

/**
 * Helper function to set the direction of a pin (input or output).
 * @param pin The pin number.
 * @param dir Direction (IN or OUT).
 */
void setPinB_DIR(char pin, char dir);

#endif // MYUSART_H
