/* 
 * File:   LCD4.h
 * Author: LapStore
 *
 * Created on August 13, 2024, 8:14 PM
 */

#ifndef LCD4_H
#define	LCD4_H

#define F_CPU 16000000UL
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "DIO.h"

#define LCD4_DATA_DIR DDRA
#define LCD4_DATA PORTA

#define LCD4_CONTROL PORTB
#define LCD4_CONTROL_DIR DDRB

#define RS PB1
#define RW PB2
#define EN PB3

#define CLEAR 0x01
#define RETURN_HOME 0x02
#define MODE_8BIT  0x38
#define MODE_4BIT  0x28
#define DEC_CURSOR 0x04
#define INC_CURSOR 0x06
#define ENTRY_MODE 0x05
#define CURSOR_OFF_DISPLAY_ON 0x0c
#define CURSOR_BLINKING 0x0F
#define MOVE_RIGHT  0x14
#define MOVE_LEFT   0x10

void init_LCD4();
void LCD4_CMD(char command);
void LCD4_Enable();
void LCD4_Data(char data);
void LCD4_DATA_str(char*str);
void reverse4(char s[]);
void itoa4(int n, char s[]);
void LCD4_Data_int(int value);
void LCD4_Clear();
void LCD4_MOVE_LEFT(char steps);
void LCD4_MOVE_RIGHT(char steps);
void LCD4_GOTO(char row, char column);

#endif	/* LCD4_H */

