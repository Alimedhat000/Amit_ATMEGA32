/* 
 * File:   interrupt.h
 * Author: LapStore
 *
 * Created on August 16, 2024, 8:38 PM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <avr/io.h>
#include "DIO.h"

#define INT_LOW_LEVEL 0
#define INT_TOGGLE 1
#define INT_FALLING_EDGE 2
#define INT_RISING_EDGE 3

void INT0_selectmode(char mode);
void init_INT0(char mode);
void INT0_disable();
void INT0_changemode(char mode);

void INT1_changemode(char mode);
void INT1_disable();
void init_INT1(char mode);
void INT1_selectmode(char mode);

#endif	/* INTERRUPT_H */

