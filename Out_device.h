/* 
 * File:   Out_device.h
 * Author: LapStore
 *
 * Created on August 9, 2024, 8:23 PM
 */

#ifndef OUT_DEVICE_H
#define	OUT_DEVICE_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <avr/io.h>
#include "DIO.h"

#define RELAY PA2
#define BUZZER PA3

    void initRelay();
    
    void initBuzzer();
    
    void SetRelay();
    
    void ResetRelay();
    
    void SetBuzzer();

    void ResetBuzzer();


#ifdef	__cplusplus
}
#endif

#endif	/* OUT_DEVICE_H */

