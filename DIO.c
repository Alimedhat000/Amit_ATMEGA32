#include "DIO.h"
#include <xc.h>

//PORT A
void setPortA_DIR_val(int val,int dir){
    switch(dir){
        case(OUT):
            DDRA  |= val;   
            break;
        case(IN):
            DDRA &= ~val;
            break ;
    }
}

void setPinA_DIR(int pinNum , int dir){
    switch(dir){
        case(OUT):
            DDRA |= (1<<pinNum);
            break;
        case(IN):
            DDRA &= ~(1<<pinNum);
            break;
        default :
            break;
    }
}

void setPortA_DIR(int dir){
    switch(dir){
        case(OUT):
            DDRA = 0xFF;
            break;
        case(IN):
            DDRA = 0x00;
            break;
        default:
            break;
    }
}

void setPINA(int pinNUM, int status){
    switch(status){
        case HIGH:
            PORTA |= (1<<pinNUM);
            break;
        case LOW:
            PORTA &= ~(1<<pinNUM);
            break;
    }
}

char readPortA(){
    return PINA;
}

char readPinA(int pinNum){
    return PINA &(1<<pinNum);
}

//PORT B
void setPortB_DIR_val(int val,int dir){
    switch(dir){
        case(OUT):
            DDRB  |= val;   
            break;
        case(IN):
            DDRB &= ~val;
            break ;
    }
}

void setPinB_DIR(int pinNum , int dir){
    switch(dir){
        case(OUT):
            DDRB |= (1<<pinNum);
            break;
        case(IN):
            DDRB &= ~(1<<pinNum);
            break;
        default :
            break;
    }
}

void setPortB_DIR(int dir){
    switch(dir){
        case(OUT):
            DDRB = 0xFF;
            break;
        case(IN):
            DDRB = 0x00;
            break;
        default:
            break;
    }
}

void setPINB(int pinNUM, int status){
    switch(status){
        case HIGH:
            PORTB |= (1<<pinNUM);
            break;
        case LOW:
            PORTB &= ~(1<<pinNUM);
            break;
    }
}

char readPortB(){
    return PINB;
}

char readPinB(int pinNum){
    return PINB &(1<<pinNum);
}

//PORT C
void setPortC_DIR_val(int val,int dir){
    switch(dir){
        case(OUT):
            DDRC  |= val;   
            break;
        case(IN):
            DDRC &= ~val;
            break ;
    }
}

void setPinC_DIR(int pinNum , int dir){
    switch(dir){
        case(OUT):
            DDRC |= (1<<pinNum);
            break;
        case(IN):
            DDRC &= ~(1<<pinNum);
            break;
        default :
            break;
    }
}

void setPortC_DIR(int dir){
    switch(dir){
        case(OUT):
            DDRC = 0xFF;
            break;
        case(IN):
            DDRC = 0x00;
            break;
        default:
            break;
    }
}

void setPINC(int pinNUM, int status){
    switch(status){
        case HIGH:
            PORTC |= (1<<pinNUM);
            break;
        case LOW:
            PORTC &= ~(1<<pinNUM);
            break;
    }
}

char readPortC(){
    return PINC;
}

char readPinC(int pinNum){
    return PINC &(1<<pinNum);
}

//PORT D
void setPortD_DIR_val(int val,int dir){
    switch(dir){
        case(OUT):
            DDRD  |= val;   
            break;
        case(IN):
            DDRD &= ~val;
            break ;
    }
}

void setPinD_DIR(int pinNum , int dir){
    switch(dir){
        case(OUT):
            DDRD |= (1<<pinNum);
            break;
        case(IN):
            DDRD &= ~(1<<pinNum);
            break;
        default :
            break;
    }
}

void setPortD_DIR(int dir){
    switch(dir){
        case(OUT):
            DDRD = 0xFF;
            break;
        case(IN):
            DDRD = 0x00;
            break;
        default:
            break;
    }
}

void setPIND(int pinNUM, int status){
    switch(status){
        case HIGH:
            PORTD |= (1<<pinNUM);
            break;
        case LOW:
            PORTD &= ~(1<<pinNUM);
            break;
    }
}

char readPortD(){
    return PIND;
}

char readPinD(int pinNum){
    return PIND &(1<<pinNum);
}