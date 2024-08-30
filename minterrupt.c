#include <avr/io.h>
#include <xc.h>
#include "DIO.h"
#include "minterrupt.h"

void INT0_selectmode(char mode) {

    MCUCR &= ~((1 << ISC00) | (1 << ISC01));
    MCUCR |= (mode << ISC00);

}

void init_INT0(char mode) {
    INT0_selectmode(mode);
    GICR |= (1 << INT0);
}

void INT0_disable() {
    GICR &= ~(1 << INT0);

}

void INT0_changemode(char mode) {
    INT0_disable();
    INT0_selectmode(mode);
    GICR |= (1 << INT0);
}

void INT1_selectmode(char mode) {

    MCUCR &= ~((1 << ISC10) | (1 << ISC11));
    MCUCR |= (mode << ISC10);

}

void init_INT1(char mode) {
    INT1_selectmode(mode);
    GICR |= (1 << INT1);
}

void INT1_disable() {
    GICR &= ~(1 << INT1);

}

void INT1_changemode(char mode) {
    INT1_disable();
    INT1_selectmode(mode);
    GICR |= (1 << INT1);
}
