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

#include "freertos/include/FreeRTOS.h"
#include "freertos/include/FreeRTOSConfig.h"
#include "freertos/include/task.h"


void TaskFun1(void *Param);
void TaskFun2(void *Param);
void TaskFun3(void *Param);

void TaskFun1(void *Param) {

    while (1) {
        Usart_Transmit(*((char *)Param));
        vTaskDelay(500);
    }
    vTaskDelete(NULL);
}

int main(void) {
    initLEDs();
    init_Usart(USART_BAUD_9600,USART_TRANSMIT,USART_ASYNC_MODE);
    
    TaskHandle_t Handeler1 = NULL;
    TaskHandle_t Handeler2 = NULL;
    
    char TASK1str = 'a';
    char TASK2str = 'b';

    xTaskCreate(TaskFun1, "MyTask1", 100, (void*)&TASK1str, 1, &Handeler1);
    xTaskCreate(TaskFun1, "MyTask2", 100, (void*)&TASK2str, 1, &Handeler2);

    vTaskStartScheduler();
}