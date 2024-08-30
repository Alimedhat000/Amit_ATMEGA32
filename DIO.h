/* 
 * File:   DIO.h
 * Author: LapStore
 *
 * Created on August 3, 2024, 8:22 PM
 */
#ifndef DIO_H
#define	DIO_H
#include <avr/io.h>

#define OUT      1
#define IN       0

#define HIGH     1
#define LOW      0

#define ON       1
#define OFF      0

//PORT A
void setPortA_DIR_val(int val,int dir);
void setPinA_DIR(int pinNum , int dir);
void setPortA_DIR(int dir);
void setPINA(int pinNUM, int status);
char readPortA();
char readPinA(int pinNum);

//PORT B
void setPortB_DIR_val(int val,int dir);
void setPinB_DIR(int pinNum , int dir);
void setPortB_DIR(int dir);
void setPINB(int pinNUM, int status);
char readPortB();
char readPinB(int pinNum);

//PORT C
void setPortC_DIR_val(int val,int dir);
void setPinC_DIR(int pinNum , int dir);
void setPortC_DIR(int dir);
void setPINC(int pinNUM, int status);
char readPortC();
char readPinC(int pinNum);

//PORT D
void setPortD_DIR_val(int val,int dir);
void setPinD_DIR(int pinNum , int dir);
void setPortD_DIR(int dir);
void setPIND(int pinNUM, int status);
char readPortD();
char readPinD(int pinNum);    
    
    
   
#endif	/* DIO_H */

