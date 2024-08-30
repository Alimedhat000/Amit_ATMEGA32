///* 
// * File:   LCD.h
// * Author: LapStore
// *
// * Created on August 10, 2024, 5:28 PM
// */
//
//#ifndef LCD_H
//#define	LCD_H
//#define F_CPU 16000000UL
//#include <stdlib.h>
//#include <avr/io.h>
//#include <util/delay.h>
//#include "DIO.h"
//
//#define LCD_DATA_DIR DDRA
//#define LCD_DATA PORTA
//
//#define LCD_CONTROL PORTB
//#define LCD_CONTROL_DIR DDRB
//
//#define RS PB1
//#define RW PB2
//#define EN PB3
//
//#define CLEAR 0x01
//#define RETURN_HOME 0x02
//#define MODE_8BIT  0x38
//#define MODE_4BIT  0x28
//#define DEC_CURSOR 0x04
//#define INC_CURSOR 0x06
//#define CURSOR_OFF_DISPLAY_ON 0x0c
//#define CURSOR_BLINKING 0x0F
//
//
//void init_LCD();
//void LCD_Cmd(char command);
//void LCD_Data(char data);
//void LCD_EN();
//void LCD_Data_str(char*str);
//void LCD_GOTO(char row, char column);
//void LCD_Clear();
//
//#endif	/* LCD_H */
//
