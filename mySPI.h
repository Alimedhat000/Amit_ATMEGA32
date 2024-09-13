#ifndef MY_SPI_H
#define MY_SPI_H

#include <avr/io.h>

// Define SPI modes
#define SPI_MASTER 1
#define SPI_SLAVE  0

// Define SPI clock speed settings
#define SPI_CLOCK_DIV4   0  // f_osc / 4   000
#define SPI_CLOCK_DIV16  1  // f_osc / 16  001
#define SPI_CLOCK_DIV64  2  // f_osc / 64  010
#define SPI_CLOCK_DIV128 3  // f_osc / 128 011
#define SPI_CLOCK_DIV2   4  // f_osc / 2 (use SPI2X in SPSR)  100
#define SPI_CLOCK_DIV8   5  // f_osc / 8 (use SPI2X in SPSR)  101
#define SPI_CLOCK_DIV32  6  // f_osc / 32 (use SPI2X in SPSR) 110

// Define SPI Pins
#define MOSI PB3
#define MISO PB4
#define SCK  PB5
#define SS   PB2

// Define SPI DDR
#define SPI_DDR DDRB

// Function prototypes
void init_SPI(char mode, char clock);
void SPI_Transmit(char data);
char SPI_Receive();
void SPI_wait();
void SPI_int_en();
void SPI_disable();

#endif // MY_SPI_H
