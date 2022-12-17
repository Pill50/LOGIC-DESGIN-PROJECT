/* 
 * File:   display.h
 * Author: DELL
 *
 * Created on December 5, 2022, 3:42 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include <p18f4620.h>
#include "global.h"
#include "button.h"
#include "clock.h"
#include "../lcd/lcd.h"
#include "../timer/timer.h"

void display_Time();
void display_Menu();
void display_Set_Threshold();
void display_input_val(int option, int index, int cursor);
void display_Warning();
void display_Alarm();
void display_Setting_Alarm();
void display_set_ADC();
void adjustTime();
void setHour();
void setMinute();
void setDay();
void setDate();
void setMonth();
void setYear();
void display_sensor_val();
void display_detail_sensor_val(int index, int value, int maxVal, int minVal);
void display_menu_detail_sensor_val();

#endif	/* DISPLAY_H */

