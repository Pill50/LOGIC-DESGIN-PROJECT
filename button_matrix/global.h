/* 
 * File:   global.h
 * Author: DELL
 *
 * Created on December 5, 2022, 3:14 PM
 */

#ifndef GLOBAL_H
#define	GLOBAL_H

#include "button_matrix/button.h"

#define INIT 0
#define MODE_1 1
#define MODE_2 2
#define MODE_3 3
#define MODE_4 4
#define MODE_5 5
#define MODE_6 6
#define MODE_7 7
#define MODE_8 8
#define MODE_9 9
#define MODE_10 10

#define SET_HOUR 12
#define SET_MINUTE 13
#define SET_DAY 14
#define SET_DATE 15
#define SET_MONTH 16
#define SET_YEAR 17

extern int input;
extern int status;
extern int numberOfPushButton;
extern int statusSetTime;
extern int index_set;
extern int index_adc;
extern int index_threshold;
extern int index_menu;
extern int index_sensor;
extern int index_warning;
extern int alarm_flag;
//extern int threshold_flag;
extern int threshold_max_flag;
extern int threshold_min_flag;
extern int adc_max_flag;
extern int adc_min_flag;
extern int day_of_month[12];
extern char hour_alarm, minute_alarm, hour_alarm1, minute_alarm1;
extern int timeBlink;
extern unsigned char enableBlink(void);

extern unsigned int simulateCnt;
extern unsigned int simulateValue;
extern unsigned int pH_value;
extern unsigned int SS_value;
extern unsigned int COD_value;
extern unsigned int NH4_value;
extern unsigned int NO3_value;
extern unsigned int TMP_value;
extern unsigned int FLOW_value;

/////////////////START////////////
extern unsigned int dataOfSensorPH[50];
extern unsigned long averageSensor[7];
extern unsigned long rawSensor[7];
//char statusSensor = GET_DATA ;
extern char indexOfData_10[7];
extern char indexOfData[7];
//extern unsigned long averageSensor_0;
/////////////////END////////////

extern unsigned int pH_value_min;
extern unsigned int pH_adc_min;

extern unsigned int SS_value_min;
extern unsigned int COD_value_min;
extern unsigned int NH4_value_min;
extern unsigned int NO3_value_min;
extern unsigned int FLOW_value_min;

extern unsigned int TMP_value_min;
extern unsigned int TMP_adc_min;
extern unsigned int TMP_value_max;
extern unsigned int TMP_adc_max;



extern unsigned int pH_value_max;
extern unsigned int pH_adc_max;

extern unsigned int SS_value_max;
extern unsigned int COD_value_max;
extern unsigned int NH4_value_max;
extern unsigned int NO3_value_max;

extern unsigned int FLOW_value_max;

//extern unsigned int pH_value_threshold;
//extern unsigned int SS_value_threshold_1;
//extern unsigned int COD_value_threshold_1;
//extern unsigned int NH4_value_threshold_1;
//extern unsigned int NO3_value_threshold_1;
//extern unsigned int TMP_value_threshold_1;
//extern unsigned int FLOW_value_threshold_1;
extern unsigned int threshold[7];
extern unsigned int threshold_min[7];
extern unsigned int adc_max[7];
extern unsigned int adc_min[7];

#endif	/* GLOBAL_H */

