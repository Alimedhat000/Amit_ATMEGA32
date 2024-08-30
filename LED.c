#include "DIO.h"
#include "LED.h"

void initLEDs(void) {
    setPortC_DIR_val((1<<LED0)|(1<<LED1),OUT);
    setPinD_DIR(LED2, OUT);
}

void LED_ON(int LED_NUM){
    switch(LED_NUM){
        case LED0:
            setPINC(LED0, HIGH);
            break;
        case LED1:
            setPINC(LED1, HIGH);
            break;
        case LED2:
            setPIND(LED2, HIGH);
            break;
    }
}
void LED_OFF(int LED_NUM){
    switch(LED_NUM){
        case LED0:
            setPINC(LED0, LOW);
            break;
        case LED1:
            setPINC(LED1, LOW);
            break;
        case LED2:
            setPIND(LED2, LOW);
            break;
    }
}