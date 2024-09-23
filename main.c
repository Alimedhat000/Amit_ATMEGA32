#define F_CPU 16000000UL
#include <stdio.h>
#include <xc.h>
#include <util/delay.h>
#include <avr/io.h>
#include <string.h>
#include "DIO.h"
#include "Buttons.h"
#include "LED.h"
#include "Out_device.h"
#include "LCD4.h"
#include "KeyPad.h"
#include "minterrupt.h"
#include "myADC.h"
#include "mTimer.h"
#include "myUsart.h"
#include "mySPI.h"
#include "myI2C.h"

#define Myadd 0x01
#define Slave 0x0A

int main(void) {


    Timer2_OC2_en();
    Timer2_OC2_select_mode(TIMER2_OC2_CTC_TOGGLE);
    init_Timer2(TIMER2_CTC_MODE, TIMER2_CLK_1024);

    init_buttons();

    while (1) {
        if (is_pressed(Button0)) {
            OCR2 += 5;
        }
        if (is_pressed(Button1)) {
            OCR2 -= 5;
        }
        _delay_ms(50);
    }
}