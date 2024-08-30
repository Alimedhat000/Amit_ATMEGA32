#include "Out_device.h"

void initRelay(){
        setPinA_DIR(RELAY,OUT);
    }
    
    void initBuzzer(){
        setPinA_DIR(BUZZER,OUT);
    }
    
    void SetRelay(){
        setPINA(RELAY,HIGH);
    }
    void ResetRelay(){
        setPINA(RELAY,LOW);
    }
    void SetBuzzer(){
        setPINA(BUZZER,HIGH);
    }
    void ResetBuzzer(){
        setPINA(BUZZER,LOW);
    }

