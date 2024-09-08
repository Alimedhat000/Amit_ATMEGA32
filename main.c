#define F_CPU 16000000UL
#include <stdio.h>
#include <xc.h>
#include <util/delay.h>
#include <avr/io.h>
#include <string.h>
#include "DIO.h"
#include "Buttons.h"
//#include "LED.h"
#include "Out_device.h"
#include "LCD4.h"
#include "KeyPad.h"
#include "minterrupt.h"
#include "myADC.h"
#include "mTimer.h"
#include "myUsart.h"

int main(void) {

    init_Usart(USART_BAUD_9600, USART_TRANSMIT, USART_ASYNC_MODE);
    char string[17] = "Usart Test String \n";
    char A = '0';
    while (1) {
        for (int i = 0; i < 17; i++) {
            Usart_Transmit(string[i]);  // Transmit each character in the string
            _delay_ms(250);  // Delay between transmissions
        }
    }
}