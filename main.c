/*
 * File:   main.c
 * Author: LapStore
 *
 * Created on August 3, 2024, 8:04 PM
 */

#define F_CPU 16000000UL
#include <xc.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <string.h>
#include "DIO.h"
#include "Buttons.h"
//#include "LED.h"
#include "Out_device.h"
#include "LCD4.h"
#include "KeyPad.h"
#include "minterrupt.h"

// Define the correct password
#define PASSWORD "1234"
#define PASSWORD_LENGTH 4

void init_system() {
    init_LCD4();
    init_keypad();
    LCD4_Clear();
}

void display_message(const char* message) {
    LCD4_Clear();
    LCD4_DATA_str(message);
    _delay_ms(500);
}

ISR(INT0_vect){
    PORTB ^= (1<<7);
}
int main(void) {
//
//    init_system();
//    char key;
//    char input[PASSWORD_LENGTH + 1] = {0};
//    uint8_t input_index = 0;
//
//    display_message("Enter Password:");
//    _delay_ms(50);
//    LCD4_GOTO(0, 63);
//    LCD4_MOVE_RIGHT(1);
    sei();
    setPinB_DIR(7,OUT);
    init_INT0(INT_TOGGLE);
//
    while (1) {
        
        
        
//        key = returnkey();
//
//        if (key != '\0') { // Check if a key is pressed
//            if (input_index < PASSWORD_LENGTH) {
//                input[input_index++] = key;
//
//                LCD4_Data(key);
//            }
//
//            if (input_index == PASSWORD_LENGTH) {
//                input[input_index] = '\0';
//
//                // Check if the entered password matches the predefined password
//                if (strcmp(input, PASSWORD) == 0) {
//                    display_message("Access Granted");
//                } else {
//                    display_message("Access Denied");
//                }
//
//                // Reset input index for the next attempt
//                input_index = 0;
//                LCD4_Clear();
//                _delay_ms(200);
//                display_message("Enter Password:"); // Prompt for the next password attempt
//                LCD4_GOTO(0, 63);
//                LCD4_MOVE_RIGHT(1);
//
//            }
//        _delay_ms(200);
    }

    return 0;
}
