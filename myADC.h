/* 
 * File:   myADC.h
 * Author: LapStore
 *
 * Created on August 17, 2024, 8:28 PM
 */

#ifndef MYADC_H
#define	MYADC_H

#include <avr/io.h>
#include <avr/interrupt.h>

#define CH0  0
#define CH1  1
#define CH2  2
#define CH3  3
#define CH4  4
#define CH5  5
#define CH6  6
#define CH7  7

#define AREF 0
#define AVCC 1
#define INTERNAL 3

#define ADC_DREQ_DIV_128 7
#define ADC_DREQ_DIV_64 6
#define ADC_DREQ_DIV_32 5
#define ADC_DREQ_DIV_16 4
#define ADC_DREQ_DIV_8 3
#define ADC_DREQ_DIV_4 2
#define ADC_DREQ_DIV_2 1


void ADC_select_ch(char ch);
void ADC_select_ref(char ref);
void ADC_select_freq(char freq);
void ADC_start_conv();
void ADC_enable();
void ADC_enable_int();




#endif	/* MYADC_H */

