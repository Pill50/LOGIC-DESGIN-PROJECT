#include "global.h"

int status = 0;
int inputThreshold = 0;
int numberOfPushButton = 0;
int statusSetTime = 0;
int timeBlink = 0;

unsigned int simulateCnt;
unsigned int simulateValue;
unsigned int pH_value;
unsigned int SS_value;
unsigned int COD_value;
unsigned int NH4_value;
unsigned int NO3_value;
unsigned int TMP_value;
unsigned int FLOW_value;

/////////////////START////////////
unsigned int dataOfSensorPH[50];
unsigned long averageSensor[7];
unsigned long rawSensor[7];
char indexOfData_10[7];
char indexOfData[7];
//unsigned long averageSensor_0 =0 ;
/////////////////END////////////

unsigned int pH_value_min = 400;
unsigned int pH_adc_min = 0;

unsigned int SS_value_min = 0;
unsigned int COD_value_min = 0;
unsigned int NH4_value_min = 1000;
unsigned int NO3_value_min = 2000;
unsigned int FLOW_value_min = 0;

unsigned int TMP_value_min = 2500;
unsigned int TMP_adc_min = 0;
unsigned int TMP_value_max = 5000;
unsigned int TMP_adc_max = 1023;



unsigned int pH_value_max = 1000;
unsigned int pH_adc_max = 1000;

unsigned int SS_value_max = 10000;
unsigned int COD_value_max = 20000;
unsigned int NH4_value_max = 5000;
unsigned int NO3_value_max = 10000;

unsigned int FLOW_value_max = 36000;

//unsigned int pH_value_threshold = 800;
//unsigned int SS_value_threshold_1 = 0;
//unsigned int COD_value_threshold_1 = 0;
//unsigned int NH4_value_threshold_1 = 1000;
//unsigned int NO3_value_threshold_1 = 2000;
//unsigned int TMP_value_threshold_1 = 0;
//unsigned int FLOW_value_threshold_1 = 0;
unsigned int threshold[7] = {800,0,0,1000,2000,0,0};