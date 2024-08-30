/* 
 * File:   Buttons.h
 * Author: LapStore
 *
 * Created on August 7, 2024, 10:48 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

#define Button0    PB0
#define Button1    PD6
#define Button2    PD2

void init_buttons();
int is_pressed(int Button);


#endif	/* BUTTONS_H */

