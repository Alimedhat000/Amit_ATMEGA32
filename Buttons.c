#include "DIO.h"
#include "Buttons.h"

void init_buttons(){
    setPinB_DIR(Button0,IN); //Button 0    
    setPinD_DIR(Button1,IN); //Button 1
    setPinD_DIR(Button2,IN); //Button 2    
}

int is_pressed(int Button){
    switch(Button){
        case(Button0):
            if (readPinB(Button0)){
                return 1;
            }
            else 
                return 0;
            break;
            
        case(Button1):
            if (readPinD(Button1)){
                return 1;
            }
             else 
                return 0;
            break;
        case(Button2):
            if (readPinD(Button2)){
                return 1;
            }
            else 
                return 0;
            break;
        default:
            return 0;
            break;
    } 
}