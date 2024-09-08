#include "myUsart.h"

void init_Usart(unsigned int baud, char TX_RX, char mode) {
    unsigned int ubrr_value = 0;

    /* Select the mode and set the baud rate accordingly */
    switch (mode) {
        case (USART_ASYNC_MODE):
            // Set Asynchronous mode, clear UMSEL bit, and disable double speed
            UCSRC = (UCSRC | (1 << URSEL)) & (~(1 << UMSEL));
            UCSRA &= ~(1 << U2X); // Disable double speed
            ubrr_value = (F_CPU / 16.0 / baud) - 1; // Calculate UBRR for standard async mode
            break;

        case (USART_ASYNC_2X_MODE):
            // Set Asynchronous mode with double speed (U2X bit enabled)
            UCSRC = (UCSRC | (1 << URSEL)) & (~(1 << UMSEL));
            UCSRA |= (1 << U2X); // Enable double speed
            ubrr_value = (F_CPU / 8.0 / baud) - 1; // Calculate UBRR for double speed async mode
            break;

        case (USART_SYNC_MASTER):
            // Set Synchronous Master mode, UMSEL bit enabled, and disable double speed
            UCSRC = (UCSRC | (1 << URSEL)) | (1 << UMSEL);
            UCSRA &= ~(1 << U2X); // Disable double speed
            ubrr_value = (F_CPU / 2.0 / baud) - 1; // Calculate UBRR for sync mode
            setPinB_DIR(XCK, OUT); // Set PB0 as output for clock
            break;

        case (USART_SYNC_SLAVE):
            // Set Synchronous Slave mode, UMSEL bit enabled, and disable double speed
            UCSRC = (UCSRC | (1 << URSEL)) | (1 << UMSEL);
            UCSRA &= ~(1 << U2X); // Disable double speed
            ubrr_value = (F_CPU / 2.0 / baud) - 1; // Calculate UBRR for sync mode
            setPinB_DIR(XCK, IN); // Set PB0 as input for clock
            break;

        default:
            return; // Invalid mode, return from function
    }

    // Set UBRR register for baud rate
    UBRRH = (unsigned char) (ubrr_value >> 8);
    UBRRL = (unsigned char) ubrr_value;

    // Set 8 data bits, no parity, 1 stop bit
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);

    /* Set the TX/RX/Full Duplex mode */
    switch (TX_RX) {
        case (USART_TRANSMIT):
            // Enable transmission only
            USART_Recieve_disable();
            USART_Transmit_en();
            break;
        case (USART_RECIEVE):
            // Enable reception only
            USART_Transmit_disable();
            USART_Recieve_en();
            break;
        case (USART_FULL_DUPLEX):
            // Enable both transmission and reception (full duplex)
            USART_Recieve_en();
            USART_Transmit_en();
            break;
        default:
            return; // Invalid TX/RX mode, return from function
    }
}

/* Function to set baud rate dynamically based on the current mode */
void Usart_set_Baudrate(unsigned int baudrate) {
    unsigned int ubrr_value = 0;

    // Check the current mode: Asynchronous, Double-Speed Asynchronous, or Synchronous
    if (UCSRC & (1 << UMSEL)) {
        // Synchronous mode
        ubrr_value = (F_CPU / 2.0 / baudrate) - 1;
    } else if (UCSRA & (1 << U2X)) {
        // Double-Speed Asynchronous mode
        ubrr_value = (F_CPU / 8.0 / baudrate) - 1;
    } else {
        // Normal Asynchronous mode
        ubrr_value = (F_CPU / 16.0 / baudrate) - 1;
    }

    // Set the UBRR registers
    UBRRL = (unsigned char) ubrr_value;
    UBRRH = (unsigned char) (ubrr_value >> 8);
}

/* Function to get the current baud rate */
unsigned int Usart_get_Baudrate() {
    unsigned int ubrr_value = ((UBRRH << 8) | UBRRL); // Combine UBRRH and UBRRL
    return (F_CPU / (16 * (ubrr_value + 1))); // Return calculated baud rate for normal mode
}

/* Function to transmit a single character */
void Usart_Transmit(char data) {
    while (!(UCSRA & (1 << UDRE))); // Wait until data register is empty
    UDR = data; // Load data into UDR for transmission
}

/* Function to receive a single character */
unsigned char Usart_Receive(void) {
    while (!(UCSRA & (1 << RXC))); // Wait for data to be received
    return UDR; // Return the received data from UDR
}

/* Enable the USART transmitter */
void Usart_Transmit_en() {
    UCSRB |= (1 << TXEN); // Set TXEN bit to enable transmission
}

/* Enable the USART receiver */
void Usart_Recieve_en() {
    UCSRB |= (1 << RXEN); // Set RXEN bit to enable reception
}

/* Disable the USART transmitter */
void Usart_Transmit_disable() {
    UCSRB &= ~(1 << TXEN); // Clear TXEN bit to disable transmission
}

/* Disable the USART receiver */
void Usart_Recieve_disable() {
    UCSRB &= ~(1 << RXEN); // Clear RXEN bit to disable reception
}

/* Enable the RX complete interrupt */
void Usart_en_RX_int() {
    UCSRB |= (1 << RXCIE); // Set RXCIE bit to enable RX interrupt
}

/* Disable the RX complete interrupt */
void Usart_disable_RX_int() {
    UCSRB &= ~(1 << RXCIE); // Clear RXCIE bit to disable RX interrupt
}

/* Enable the TX complete interrupt */
void Usart_en_TX_int() {
    UCSRB |= (1 << TXCIE); // Set TXCIE bit to enable TX interrupt
}

/* Disable the TX complete interrupt */
void Usart_disable_TX_int() {
    UCSRB &= ~(1 << TXCIE); // Clear TXCIE bit to disable TX interrupt
}
