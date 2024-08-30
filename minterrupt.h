/* 
 * File:   interrupt.h
 * Author: LapStore
 *
 * Created on August 16, 2024, 8:38 PM
 */
#ifndef MINERRUPT_H
#define MINERRUPT_H

#include <avr/io.h>
#include "DIO.h"
#include <avr/interrupt.h>
/** 
 * @brief Interrupt mode definitions for INT0 and INT1.
 */
#define INT_LOW_LEVEL      0   ///< Low level generates an interrupt request.
#define INT_TOGGLE         1   ///< Any logical change generates an interrupt request.
#define INT_FALLING_EDGE   2   ///< Falling edge generates an interrupt request.
#define INT_RISING_EDGE    3   ///< Rising edge generates an interrupt request.

/** 
 * @brief Interrupt mode definitions for INT2.
 */
#define INT2_FALLING_EDGE  0   ///< Falling edge generates an interrupt request.
#define INT2_RISING_EDGE   1   ///< Rising edge generates an interrupt request.

/**
 * @brief Sets the mode of External Interrupt Request 0 (INT0).
 * 
 * @param mode The mode to be set for INT0. It should be one of the predefined modes:
 * - INT_LOW_LEVEL: Low level of INT0 generates an interrupt request.
 * - INT_TOGGLE: Any logical change on INT0 generates an interrupt request.
 * - INT_FALLING_EDGE: The falling edge of INT0 generates an interrupt request.
 * - INT_RISING_EDGE: The rising edge of INT0 generates an interrupt request.
 */
void INT0_selectMode(char mode);

/**
 * @brief Initializes External Interrupt Request 0 (INT0) with the specified mode.
 * 
 * @param mode The mode to initialize INT0. Refer to the `INT0_selectMode` function for mode options.
 */
void init_INT0(char mode);

/**
 * @brief Disables External Interrupt Request 0 (INT0).
 */
void INT0_disable(void);

/**
 * @brief Changes the mode of External Interrupt Request 0 (INT0).
 * 
 * @param mode The new mode to be set for INT0. Refer to the `INT0_selectMode` function for mode options.
 */
void INT0_changeMode(char mode);

/**
 * @brief Sets the mode of External Interrupt Request 1 (INT1).
 * 
 * @param mode The mode to be set for INT1. It should be one of the predefined modes:
 * - INT_LOW_LEVEL: Low level of INT1 generates an interrupt request.
 * - INT_TOGGLE: Any logical change on INT1 generates an interrupt request.
 * - INT_FALLING_EDGE: The falling edge of INT1 generates an interrupt request.
 * - INT_RISING_EDGE: The rising edge of INT1 generates an interrupt request.
 */
void INT1_selectMode(char mode);

/**
 * @brief Initializes External Interrupt Request 1 (INT1) with the specified mode.
 * 
 * @param mode The mode to initialize INT1. Refer to the `INT1_selectMode` function for mode options.
 */
void init_INT1(char mode);

/**
 * @brief Disables External Interrupt Request 1 (INT1).
 */
void INT1_disable(void);

/**
 * @brief Changes the mode of External Interrupt Request 1 (INT1).
 * 
 * @param mode The new mode to be set for INT1. Refer to the `INT1_selectMode` function for mode options.
 */
void INT1_changeMode(char mode);

/**
 * @brief Sets the mode of External Interrupt Request 2 (INT2).
 * 
 * @param mode The mode to be set for INT2:
 * - INT2_FALLING_EDGE: The falling edge of INT2 generates an interrupt request.
 * - INT2_RISING_EDGE: The rising edge of INT2 generates an interrupt request.
 */
void INT2_selectMode(char mode);

/**
 * @brief Initializes External Interrupt Request 2 (INT2) with the specified mode.
 * 
 * @param mode The mode to initialize INT2. Refer to the `INT2_selectMode` function for mode options.
 */
void init_INT2(char mode);

/**
 * @brief Disables External Interrupt Request 2 (INT2).
 */
void INT2_disable(void);

/**
 * @brief Changes the mode of External Interrupt Request 2 (INT2).
 * 
 * @param mode The new mode to be set for INT2. Refer to the `INT2_selectMode` function for mode options.
 */
void INT2_changeMode(char mode);

/**
 * @brief Enables global interrupts by setting the I-bit in the SREG register.
 */
void global_interrupt_enable(void);

#endif // MINERRUPT_H
#endif // MINERRUPT_H