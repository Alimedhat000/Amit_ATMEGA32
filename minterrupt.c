#include "minterrupt.h"

void INT0_selectMode(char mode) {
    // Clear the ISC00 and ISC01 bits in MCUCR to reset the mode
    MCUCR &= ~((1 << ISC00) | (1 << ISC01));
    // Set the new mode by shifting the mode value to the ISC00 position
    MCUCR |= (mode << ISC00);
}

void init_INT0(char mode) {
    INT0_selectMode(mode);   // Set the mode for INT0
    GICR |= (1 << INT0);     // Enable INT0 interrupt
}

void INT0_disable() {
    GICR &= ~(1 << INT0);    // Clear the INT0 enable bit to disable the interrupt
}

void INT0_changeMode(char mode) {
    INT0_disable();          // Disable INT0 to allow mode change
    INT0_selectMode(mode);   // Set the new mode for INT0
    GICR |= (1 << INT0);     // Re-enable INT0 interrupt
}

void INT1_selectMode(char mode) {
    // Clear the ISC10 and ISC11 bits in MCUCR to reset the mode
    MCUCR &= ~((1 << ISC10) | (1 << ISC11));
    // Set the new mode by shifting the mode value to the ISC10 position
    MCUCR |= (mode << ISC10);
}

void init_INT1(char mode) {
    INT1_selectMode(mode);   // Set the mode for INT1
    GICR |= (1 << INT1);     // Enable INT1 interrupt
}

void INT1_disable() {
    GICR &= ~(1 << INT1);    // Clear the INT1 enable bit to disable the interrupt
}

void INT1_changeMode(char mode) {
    INT1_disable();          // Disable INT1 to allow mode change
    INT1_selectMode(mode);   // Set the new mode for INT1
    GICR |= (1 << INT1);     // Re-enable INT1 interrupt
}

void INT2_selectMode(char mode) {
    // Clear the ISC2 bit in MCUCSR to reset the mode
    MCUCSR &= ~(1 << ISC2);
    // Set the new mode by shifting the mode value to the ISC2 position
    MCUCSR |= (mode << ISC2);
}

void init_INT2(char mode) {
    INT2_selectMode(mode);   // Set the mode for INT2
    GICR |= (1 << INT2);     // Enable INT2 interrupt
}

void INT2_disable() {
    GICR &= ~(1 << INT2);    // Clear the INT2 enable bit to disable the interrupt
}

void INT2_changeMode(char mode) {
    INT2_disable();          // Disable INT2 to allow mode change
    INT2_selectMode(mode);   // Set the new mode for INT2
    GICR |= (1 << INT2);     // Re-enable INT2 interrupt
}

void global_interrupt_enable() {
    sei();  // Set the I-bit in SREG to enable global interrupts
}