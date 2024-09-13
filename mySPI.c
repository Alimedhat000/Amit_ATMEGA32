#include "mySPI.h"

void init_SPI(char mode, char clk) {
    switch (mode) {
        case SPI_MASTER:
            SPI_DDR |= (1 << MOSI) | (1 << SCK) | (1 << SS); // Set MOSI, SCK, and SS as output
            SPCR = (1 << MSTR) | (clk & 3); // Set master mode and clock speed
            SPSR |= ((clk >> 2)); // Set double mode if configured
            SPCR |= (1 << SPE); // Enable SPI
            break;

        case SPI_SLAVE:
            SPI_DDR |= (1 << MISO); // Set MISO as output for slave
            SPCR |= (1 << SPE); // Enable SPI in slave mode
            break;

        default:
            // Invalid mode, do nothing
            break;
    }
}

void SPI_Transmit(char data) {
    SPDR = data; // Load data into SPI data register
    SPI_wait(); // Wait for transmission to complete
}

char SPI_Receive() {
    SPI_wait(); // Wait for reception to complete
    return SPDR; // Return received data
}

void SPI_wait() {
    while (!(SPSR & (1 << SPIF))); // Wait for SPI interrupt flag to be set
}

void SPI_int_en() {
    SPCR |= (1 << SPIE); // Enable SPI interrupt
}

void SPI_disable() {
    SPCR &= ~(1 << SPE); // Disable SPI
}
