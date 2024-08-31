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

#define ADC_STEP 4.887585532746823069403714565

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


/**
 * @brief Initialize the ADC with specified parameters.
 * 
 * @param ch   ADC channel (0-7).
 * @param ref  Reference voltage selection (see ADMUX register settings).
 * @param freq ADC clock frequency (see ADCSRA register settings).
 */
void init_ADC(char ch, char ref, char freq);

/**
 * @brief Selects the ADC channel.
 * 
 * @param ch ADC channel (0-7).
 */
void ADC_select_ch(char ch);

/**
 * @brief Selects the reference voltage for the ADC.
 * 
 * @param ref Reference voltage selection (see ADMUX register settings).
 */
void ADC_select_ref(char ref);

/**
 * @brief Selects the ADC clock frequency.
 * 
 * @param freq ADC clock frequency (see ADCSRA register settings).
 */
void ADC_select_freq(char freq);

/**
 * @brief Starts an ADC conversion.
 */
void ADC_start_conv(void);

/**
 * @brief Enables the ADC.
 */
void ADC_enable(void);

/**
 * @brief Enables ADC interrupt.
 */
void ADC_enable_int(void);

/**
 * @brief Enables ADC auto-triggering.
 */
void ADC_auto_trig_enable(void);

/**
 * @brief Enables left-adjusted ADC result.
 * 
 * Left-adjusted results are useful when the interval between values is significantly large.
 */
void ADC_enable_leftAdj(void);

/**
 * @brief Waits for ADC conversion to complete.
 */
void ADC_wait_conv(void);

/**
 * @brief Reads the ADC result.
 * 
 * @return The ADC result, either 10-bit or 8-bit depending on ADLAR setting.
 */
int ADC_read(void);

/**
 * @brief Reads the ADC result quickly.
 * 
 * For left-adjusted results, this returns the 8 most significant bits directly from ADCH. 
 * For right-adjusted results, this returns the 8 least significant bits from ADCL and reads ADCH to complete the process.
 * 
 * @return The ADC result.
 */
int ADC_read_fast(void);
#endif	/* MYADC_H */

