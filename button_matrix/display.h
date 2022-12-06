/* 
 * File:   display.h
 * Author: DELL
 *
 * Created on December 5, 2022, 3:42 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include <p18f4620.h>
#include "button.h"
#include "clock.h"
#include "../lcd/lcd.h"

void display_Time();
void display_Menu();
void display_Set_Threshold();
void display_input_val();
void display_Alarm();

#endif	/* DISPLAY_H */
