
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> 
#include <avr/io.h>
#include "DIO.h"


#define TIMER0_NO_CLK 0 //This acts as a Disable for the timer
#define TIMER0_CLK 1
#define TIMER0_CLK_8 2
#define TIMER0_CLK_64 3
#define TIMER0_CLK_256 4
#define TIMER0_CLK_1024 5
#define TIMER0_EXT_CLK_FALLING 6 
#define TIMER0_EXT_CLK_RISING 7 

#define TIMER0_NORMAL_MODE 0
#define TIMER0_PWM_MODE 1
#define TIMER0_CTC_MODE 2
#define TIMER0_FAST_PWM_MODE 3

#define TIMER0_CTC0_DEFAULT_VALUE 255

#define TIMER2_NO_CLK 0 //This acts as a Disable for the timer
#define TIMER2_CLK 1
#define TIMER2_CLK_8 2
#define TIMER2_CLK_32 3
#define TIMER2_CLK_64 4
#define TIMER2_CLK_128 5
#define TIMER2_CLK_256 6 
#define TIMER2_CLK_1024 7 

#define TIMER2_NORMAL_MODE 0
#define TIMER2_PWM_MODE 1
#define TIMER2_CTC_MODE 2
#define TIMER2_FAST_PWM_MODE 3

#define TIMER2_CTC2_DEFAULT_VALUE 255

/**
 * @brief Selects the clock source for Timer0.
 * 
 * @param clk_mode Clock source selection (bits 0-2) for Timer0. Possible values:
 *         - TIMER0_NO_CLK 0 //This acts as a Disable for the timer
 *         - TIMER0_CLK
 *         - TIMER0_CLK_8
 *         - TIMER0_CLK_64
 *         - TIMER0_CLK_256
 *         - TIMER0_CLK_1024
 *         - TIMER0_EXT_CLK_FALLING 
 *         - TIMER0_EXT_CLK_RISING
 */
void Timer0_clk_select(char clk_mode);

/**
 * @brief Selects the mode of operation for Timer0.
 * 
 * @param mode Mode to select for Timer0. Possible values:
 *             - TIMER0_NORMAL_MODE
 *             - TIMER0_PWM_MODE
 *             - TIMER0_CTC_MODE
 *             - TIMER0_FAST_PWM_MODE
 */
void Timer0_mode_select(char mode);

/**
 * @brief Enables the overflow interrupt for Timer0.
 */
void Timer0_OVF_int_en();

/**
 * @brief Enables the output compare match interrupt for Timer0.
 */
void Timer0_OCM_int_en();

/**
 * @brief Initializes Timer0 with the specified mode and clock source.
 * 
 * @param mode Mode of operation for Timer0. Use predefined macros.
 * @param clk_mode Clock source selection for Timer0.
 */
void init_Timer0(char mode, char clk_mode);

/**
 * @brief Sets the output compare register value for Timer0.
 * 
 * @param OCR_value Value to set in OCR0 register.
 */
void Timer0_OCR_set(char OCR_value);

/**
 * @brief Resets the Timer0 preScaler.
 */
void Timer0_reset_prescaler();

/**
 * @brief Reads the current count value of Timer0.
 * 
 * @return Current count value of Timer0.
 */
char Timer0_get_count();

// #############################    TIMER2     #################################

/**
 * @brief Selects the clock source for Timer2.
 * 
 * @param clk_mode Clock source selection (bits 0-2) for Timer2. Possible values:
 *         - TIMER2_NO_CLK //This acts as a Disable for the timer
 *         - TIMER2_CLK
 *         - TIMER2_CLK_8
 *         - TIMER2_CLK_32
 *         - TIMER2_CLK_64
 *         - TIMER2_CLK_128
 *         - TIMER2_CLK_256
 *         - TIMER2_CLK_1024
 */
void Timer2_clk_select(char clk_mode);

/**
 * @brief Selects the mode of operation for Timer2.
 * 
 * @param mode Mode to select for Timer2. Possible values:
 *             - TIMER2_NORMAL_MODE
 *             - TIMER2_PWM_MODE
 *             - TIMER2_CTC_MODE
 *             - TIMER2_FAST_PWM_MODE
 */
void Timer2_mode_select(char mode);

/**
 * @brief Enables the overflow interrupt for Timer2.
 */
void Timer2_OVF_int_en();

/**
 * @brief Enables the output compare match interrupt for Timer2.
 */
void Timer2_OCM_int_en();

/**
 * @brief Sets the output compare register value for Timer2.
 * 
 * @param OCR_value Value to set in OCR2 register.
 */
void Timer2_OCR_set(char OCR_value);

/**
 * @brief Initializes Timer2 with the specified mode and clock source.
 * 
 * @param mode Mode of operation for Timer2. Use predefined macros.
 * @param clk_mode Clock source selection for Timer2.
 */
void init_Timer2(char mode, char clk_mode);

/**
 * @brief Resets the Timer2 preScaler.
 */
void Timer2_reset_prescaler();

/**
 * @brief Disables all interrupts for Timer2.
 */
void Timer2_disable_ints();

/**
 * @brief Enables asynchronous operation mode for Timer2.
 */
void Timer2_async_en();

/**
 * @brief Enables synchronous operation mode for Timer2.
 */
void Timer2_sync_en();

/**
 * @brief Waits until Timer2 registers are updated.
 */
void Timer2_wait_busy();

/**
 * @brief Switches Timer2 to asynchronous mode.
 */
void Timer2_SwitchToAsync(char mode, char clk);

/**
 * @brief Switches Timer2 to synchronous mode.
 */
void Timer2_SwitchToSync(char mode, char clk);


#endif	/* XC_HEADER_TEMPLATE_H */

