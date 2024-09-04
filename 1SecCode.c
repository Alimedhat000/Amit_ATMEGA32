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

static int number = 1;

ISR(TIMER2_OVF_vect) {
    LCD4_GOTO(0, 0);
    LCD4_Data_int(number);
    number++;
}

int main(void) {
    init_LCD4();

    init_Timer2(TIMER2_NORMAL_MODE, TIMER2_CLK_1024);

    Timer2_SwitchToAsync(TIMER2_NORMAL_MODE, TIMER2_CLK_128);

    global_interrupt_enable();

    while (1) {

    }
}