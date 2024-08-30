#include "KeyPad.h"
#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

// Initialize keypad

void init_keypad() {
    Keypad_PORT_DIR = 0x0F; // Set rows as outputs and columns as inputs
    Keypad_PORT |= 0x0F; // Enable pull-up resistors on columns
}

// Function to check if any key is pressed

char is_key_pressed() {
    return (readPortC() & 0xF0) != 0;
}

// Function to read a key press from the keypad

char returnkey() {
    while (1) {
        Keypad_PORT |= 0x0F; // Set the lower 4 bits high to enable pull-up resistors

        // Check if any key is pressed by checking the upper nibble
        if (is_key_pressed()) {

            // Row 1
            Keypad_PORT &= 0xF0; // Clear lower 4 bits
            Keypad_PORT |= (1 << 0); // Set the first row (Row A) high
            _delay_ms(10);
            if (is_key_pressed()) {
                if (readPortC() & 0x10) return '7';
                if (readPortC() & 0x20) return '8';
                if (readPortC() & 0x40) return '9';
                if (readPortC() & 0x80) return '/';

            }

            // Row 2
            Keypad_PORT &= 0xF0; // Clear lower 4 bits
            Keypad_PORT |= (1 << 1); // Set the second row (Row B) high
            _delay_ms(10);
            if (is_key_pressed()) {
                if (readPortC() & 0x10) return '4';
                if (readPortC() & 0x20) return '5';
                if (readPortC() & 0x40) return '6';
                if (readPortC() & 0x80) return 'x';
            }

            // Row 3
            Keypad_PORT &= 0xF0; // Clear lower 4 bits
            Keypad_PORT |= (1 << 2); // Set the third row (Row C) high
            _delay_ms(10);
            if (is_key_pressed()) {
                if (readPortC() & 0x10) return '1';
                if (readPortC() & 0x20) return '2';
                if (readPortC() & 0x40) return '3';
                if (readPortC() & 0x80) return '-';

            }

            // Row 4
            Keypad_PORT &= 0xF0; // Clear lower 4 bits
            Keypad_PORT |= (1 << 3); // Set the fourth row (Row D) high
            _delay_ms(10);
            if (is_key_pressed()) {
                if (readPortC() & 0x10) return 'C';
                if (readPortC() & 0x20) return '0';
                if (readPortC() & 0x40) return '=';
                if (readPortC() & 0x80) return '+';
            }
        }
    }

    // If no key is pressed, return null character
    return 'A';
}
