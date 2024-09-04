#include "myADC.h"

void init_ADC(char ch, char ref, char freq) {

    ADC_select_ch(ch);

    ADC_select_freq(freq);

    ADC_select_ref(ref);

    //    ADC_auto_trig_enable();

    ADC_enable_int();

    ADC_enable();

}

void ADC_select_ch(char ch) {

    ADMUX &= ~(0x7); // reset ADMUX channels
    if (ch < 8) {
        ADMUX |= (ch); // set the new channel
    }
}

void ADC_select_ref(char ref) {
    ADMUX &= ~((1 << REFS0) | (1 << REFS1));
    ADMUX |= (ref << 6);
}

void ADC_select_freq(char freq) {
    ADCSRA &= ~(0x7);
    ADCSRA |= (freq);
}

void ADC_start_conv() {
    ADCSRA |= (1 << ADSC);
}

void ADC_enable() {
    ADCSRA |= (1 << ADEN);
}

void ADC_enable_int() {
    ADCSRA |= (1 << ADIE);
}

void ADC_select_auto_trig(char source) {
    SFIOR &= ~(0xE0); // clear the select bits
    SFIOR |= (source << ADTS0);
}

void ADC_auto_trig_enable() {
    ADCSRA |= (1 << ADATE);
}

void ADC_enable_leftAdj() { // is used when the intervals between values is 
    ADMUX |= (1 << ADLAR); // significantly large
}

void ADC_wait_conv() {
    while (!(ADCSRA & (1 << ADIF)));
}

int ADC_read() {
    int data = 0;
    if (ADMUX & (1 << ADLAR)) {
        // If ADLAR is set (left adjusted)
        data = (ADCH << 2); // Take the 8 most significant bits from ADCH
        data |= (ADCL >> 6); // Take the 2 least significant bits from ADCL
    } else {
        // If ADLAR is clear (right adjusted)
        data = ADCL; // Take the entire ADCL (low byte)
        data |= (ADCH << 8); // Add the 2 bits from ADCH shifted to their correct positions
    }
    return data;
}

int ADC_read_fast() {
    int data = 0;
    if (ADMUX & (1 << ADLAR)) {
        // If ADLAR is set (left-adjusted) and the changes in the first two bits could be neglected
        data = (ADCH << 2); // Return the 8 most significant bits directly from ADCH with an error of 20mV
    } else {
        // If ADLAR is clear (right-adjusted) if the readings is less than 255
        data = ADCL; // Return the 8 least significant bits from ADCL
        char dummy = ADCH; // Read ADCH to complete the reading process
    }
    return data;
}