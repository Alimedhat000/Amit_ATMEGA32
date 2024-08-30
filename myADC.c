#include "myADC.h"

void init_ADC(char ch,char ref,char freq) {

    ADC_select_ch(ch);
    
    ADC_select_freq(freq);
    
    ADC_select_ref(ref);

    ADC_enable();
    
    ADC_enable_int();
}

void ADC_select_ch(char ch) {

    ADMUX &= ~(0x7); // reset ADMUX channels
    if (ch < 8) {
        ADMUX |= (ch); // set the new channel
    }
}
   
void ADC_select_ref(char ref) {
    ADMUX &= ~((1<<REFS0)|(1<<REFS1));
    ADMUX |= (ref<<6);
}

void ADC_select_freq(char freq) {
    ADCSRA &= ~(0x7);
    ADCSRA |= (freq);
}

void ADC_start_conv(){
    ADCSRA |= (1<<ADSC);
}

void ADC_enable() {
    ADCSRA |= (1<<ADEN);
}

void ADC_enable_int(){
    ADCSRA |= (1<<ADIE);
    
}