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

volatile long adc_result = 0;

ISR(ADC_vect) {
    ADC_wait_conv();
    if (readPinB(PB5)) {
        ADC_select_ch(CH0);
    }
    if (readPinB(PB6)) {
        ADC_select_ch(CH1);
    }
    if (readPinB(PB7)) {
        ADC_select_ch(CH2);
    }
    LCD4_Clear();
    LCD4_Data_int(ADC_read() * ADC_STEP);
    _delay_ms(1000);
}

int main(void) {
    setPinB_DIR(PB5, IN);
    setPinB_DIR(PB6, IN);
    setPinB_DIR(PB7, IN);
    init_LCD4();
    init_ADC(CH0, AVCC, ADC_DREQ_DIV_128);
    global_interrupt_enable();


    while (1) {
        ADC_start_conv();
    }
}
