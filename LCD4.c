#include "LCD4.h"
#include "LCD.h"
#include <stdlib.h>
#include <string.h>

void init_LCD4() {
    //initializing the Data ports
    setPortA_DIR_val(0xF0, OUT);
    //initializing the Control ports
    setPinB_DIR(RS, OUT);
    setPinB_DIR(RW, OUT);
    setPinB_DIR(EN, OUT);

    _delay_ms(20);
    setPINB(RW, LOW);

    LCD4_CMD(ENTRY_MODE);
    LCD4_CMD(RETURN_HOME);
    LCD4_CMD(MODE_4BIT);
    LCD4_CMD(CURSOR_BLINKING);
    LCD4_CMD(CLEAR);
}

void LCD4_CMD(char command) {
    //set the selection port to zero for commands
    LCD4_CONTROL &= ~(1 << RS);
    //sending the HIgh nibble of the command
    LCD4_DATA = (LCD4_DATA & 0x0F) | (command & 0xF0);
    LCD4_Enable();
    //sending the LOW nibble of the command
    LCD4_DATA = (LCD4_DATA & 0xF0) | (command << 4);
    LCD4_Enable();
    _delay_ms(20);

}

void LCD4_Enable() {
    LCD4_CONTROL |= (1 << EN);
    _delay_ms(5);
    LCD4_CONTROL &= ~(1 << EN);
}

void LCD4_Data(char data) {
    LCD4_CONTROL |= (1 << RS);
    //sending the HIgh nibble of the command
    LCD4_DATA = (LCD4_DATA & 0x0F) | (data & 0xF0);
    LCD4_Enable();
    //sending the LOW nibble of the command
    LCD4_DATA = (LCD4_DATA & 0x0F) | (data << 4);
    LCD4_Enable();
    _delay_ms(20);
}

void LCD4_DATA_str(char*str) {
    while (*str) {
        LCD4_Data(*str++);
    }
}

void reverse4(char s[]) {
    int i, j;
    char c;
    int len = strlen(s);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa4(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0) { // record sign
        n = -n; // make n positive
    }
    i = 0;
    do { // generate digits in reverse order 
        s[i++] = n % 10 + '0'; // get next digit
    } while ((n /= 10) > 0); // delete it
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse4(s);
}

void LCD4_Data_int(int value) {
    char str [16];
    itoa4(value, str);

    LCD4_DATA_str(str);
}

void LCD4_Clear() {
    LCD4_CMD(CLEAR);
    _delay_ms(10);
}

void LCD4_MOVE_LEFT(char steps) {
    for (int i = 0; i < steps; i++) {
        LCD4_CMD(MOVE_LEFT);
    }
}

void LCD4_MOVE_RIGHT(char steps) {
    for (int i = 0; i < steps; i++) {
        LCD4_CMD(MOVE_RIGHT);
    }
}

void LCD4_GOTO(char row, char column) {
    // Calculate address based on row and column
    char address;
    if (row == 0) {
        address = 0x80 + column; // Base address for the first row
    } else if (row == 1) {
        address = 0xC0 + column; // Base address for the second row
    } else {
        address = 0x80; // Default to the first row if row is invalid
    }
    LCD4_CMD(address); // Send the address to the LCD
}

