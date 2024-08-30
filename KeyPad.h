/* 
 * File:   KeyPad.h
 * Author: LapStore
 *
 * Created on August 13, 2024, 9:26 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#define Keypad_PORT_DIR    DDRC
#define Keypad_PORT        PORTC

void init_keypad();
char returnkey();
char is_key_pressed();

#endif	/* KEYPsAD_H */

