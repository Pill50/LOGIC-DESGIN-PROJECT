#include "main.h"
#include "stdio.h"
#include "button_matrix/clock.h"
#include "button_matrix/global.h"
#include "button_matrix/datasensor.h"
#include "button_matrix/datasensor1.h"

//Noi khai bao hang so
#define     LED     PORTD
#define     ON      1
#define     OFF     0

// Noi khai bao bien toan cuc
unsigned char arrayMapOfOutput [8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char statusOutput[8] = {0,0,0,0,0,0,0,0};
unsigned int dataOfSensorSS[50];
unsigned int dataOfSensorCOD[50];

// Khai bao cac ham co ban IO
void init_system(void);
void delay_ms(int value);
void OpenOutput(int index);
void CloseOutput(int index);
void TestOutput(void);
void ReverseOutput(int index);

void CalibTemp(void);


void GetSensorPH(void);
void GetSensorSS(void);
void GetSensorCOD(void);
void GetSensorNH4(void);
void GetSensorNO3(void);
void GetSensorTMP(void);
void GetSensorFLOW(void);
void SimulateFull_Gimat(void);

void main(void)
{
	unsigned int k = 0;
	init_system();
    init_i2c();
    lcd_clear();
    LcdClearS();
    CloseOutput(0);
    delay_ms(1000);
    Set_Time();
	while (1)
	{       
        GetSensorPH();
        GetSensorSS();
        GetSensorCOD();
        GetSensorNH4();
        GetSensorNO3();
        GetSensorTMP();
        GetSensorFLOW();
                             
        if(hour == hour_alarm && minute == minute_alarm)
            OpenOutput(0);
        else CloseOutput(0);
            
        if(flag_timer3 == 1) {
            SetTimer3_ms(50);
            scan_key_matrix();
            fsm();
            SimulateFull_Gimat();     
        }
        
        DisplayLcdScreen();
	}
}

void delay_ms(int value)
{
	int i,j;
	for(i=0;i<value;i++)
		for(j=0;j<238;j++);
}

void init_system(void)
{
    TRISB = 0x00;		//setup PORTB is output
    TRISA = 0x00;
    init_lcd();
    TRISD = 0x00;
    LED = 0x00;
    init_interrupt();
    delay_ms(1000);
    init_timer0(4695);//dinh thoi 1ms sai so 1%
    init_timer1(9390);//dinh thoi 2ms
    init_timer3(46950);//dinh thoi 10ms
    SetTimer0_ms(2);
    SetTimer1_ms(10);
    SetTimer3_ms(50); //Chu ky thuc hien viec xu ly input,proccess,output
    init_key_matrix_with_uart();
    init_uart();
    init_adc();
}

void OpenOutput(int index)
{
	if (index >= 0 && index <= 7)
	{
		LED = LED | arrayMapOfOutput[index];
	}

}

void CloseOutput(int index)
{
	if (index >= 0 && index <= 7)
	{
		LED = LED & ~arrayMapOfOutput[index];
	}
}

void ReverseOutput(int index)
{
    if (statusOutput[index]  == ON)
    {
        CloseOutput(index);
        statusOutput[index] = OFF;
    }
    else
    {
        OpenOutput(index);
        statusOutput[index] = ON;
    }
}

void TestOutput(void)
{
	int k;
	for (k=0;k<=7 ;k++ )
	{
		OpenOutput(k);
		delay_ms(500);
		CloseOutput(k);
		delay_ms(500);
	}
}

unsigned char isButtonSetTempMin()
{
    if (key_code[1] == 1)
        return 1;
    else
        return 0;
}

unsigned char isButtonSetTempMax()
{
    if (key_code[0] == 1)
        return 1;
    else
        return 0;
}

//////////////////////////////
/////////////////////////////////
void GetSensorPH(void)
{
    int i;
    rawSensor[0] = get_adc_value(0);
    dataOfSensorPH[indexOfData[0]] = rawSensor[0];
    indexOfData[0] = (indexOfData[0] + 1)%50;
        //giai thuat lay 10 frame
    indexOfData_10[0] = indexOfData[0];
    averageSensor[0] = 0;
    for (i=0;i<50;i++)
    {
        averageSensor[0] = averageSensor[0] + dataOfSensorPH[indexOfData_10[0]];
        if (indexOfData_10[0] == 0)
            indexOfData_10[0] = 50 - 1;
        else
            indexOfData_10[0] --;   
    }
    averageSensor[0] = averageSensor[0]/50;
}

void GetSensorSS(void){
    int i;
    rawSensor[1] = get_adc_value(1);
    dataOfSensorSS[indexOfData[1]] = rawSensor[1];
    indexOfData[1] = (indexOfData[1] + 1)%50;
    //giai thuat lay 10 frame
    indexOfData_10[1] = indexOfData[1];
    averageSensor[1] = 0;
    for (i=0;i<50;i++)
    {
        averageSensor[1] = averageSensor[1] + dataOfSensorSS[indexOfData_10[1]];
        if (indexOfData_10[1] == 0)
            indexOfData_10[1] = 50 - 1;
        else
            indexOfData_10[1] --;   
    }
    averageSensor[1] = averageSensor[1]/50;
}

void GetSensorCOD(void){
    int i;
    rawSensor[2] = get_adc_value(2);
    dataOfSensorCOD[indexOfData[2]] = rawSensor[2];
    indexOfData[2] = (indexOfData[2] + 1)%50;
    //giai thuat lay 10 frame
    indexOfData_10[2] = indexOfData[2];
    averageSensor[2] = 0;
    for (i=0;i<50;i++)
    {
        averageSensor[2] = averageSensor[2] + dataOfSensorCOD[indexOfData_10[2]];
        if (indexOfData_10[2] == 0)
            indexOfData_10[2] = 50 - 1;
        else
            indexOfData_10[2] --;   
    }
    averageSensor[2] = averageSensor[2]/50;
}

void GetSensorTMP(void){
    int i;
    rawSensor[3] = get_adc_value(3);
    dataOfSensorTMP[indexOfData[3]] = rawSensor[3];
    indexOfData[3] = (indexOfData[3] + 1)%50;
    //giai thuat lay 10 frame
    indexOfData_10[3] = indexOfData[3];
    averageSensor[3] = 0;
    for (i=0;i<50;i++)
    {
        averageSensor[3] = averageSensor[3] + dataOfSensorTMP[indexOfData_10[3]];
        if (indexOfData_10[3] == 0)
            indexOfData_10[3] = 50 - 1;
        else
            indexOfData_10[3] --;   
    }
    averageSensor[3] = averageSensor[3]/50;
}

void GetSensorNH4(void){
    int i;
    rawSensor[4] = get_adc_value(4);
    dataOfSensorNH4[indexOfData[4]] = rawSensor[4];
    indexOfData[4] = (indexOfData[4] + 1)%50;
    //giai thuat lay 10 frame
    indexOfData_10[4] = indexOfData[4];
    averageSensor[4] = 0;
    for (i=0;i<50;i++)
    {
        averageSensor[4] = averageSensor[4] + dataOfSensorNH4[indexOfData_10[4]];
        if (indexOfData_10[4] == 0)
            indexOfData_10[4] = 50 - 1;
        else
            indexOfData_10[4] --;   
    }
    averageSensor[4] = averageSensor[4]/50;    
}

void GetSensorNO3(void){
    int i;
    rawSensor[5] = get_adc_value(5);
    dataOfSensorNO3[indexOfData[5]] = rawSensor[5];
    indexOfData[5] = (indexOfData[5] + 1)%50;
    //giai thuat lay 10 frame
    indexOfData_10[5] = indexOfData[5];
    averageSensor[5] = 0;
    for (i=0;i<50;i++)
    {
        averageSensor[5] = averageSensor[5] + dataOfSensorNO3[indexOfData_10[5]];
        if (indexOfData_10[5] == 0)
            indexOfData_10[5] = 50 - 1;
        else
            indexOfData_10[5] --;   
    }
    averageSensor[5] = averageSensor[5]/50;
}

void GetSensorFLOW(void){
    int i;
    rawSensor[6] = get_adc_value(6);
    dataOfSensorFLOW[indexOfData[6]] = rawSensor[6];
    indexOfData[6] = (indexOfData[6] + 1)%50;
    //giai thuat lay 10 frame
    indexOfData_10[6] = indexOfData[6];
    averageSensor[6] = 0;
    for (i=0;i<50;i++)
    {
        averageSensor[6] = averageSensor[6] + dataOfSensorFLOW[indexOfData_10[6]];
        if (indexOfData_10[6] == 0)
            indexOfData_10[6] = 50 - 1;
        else
            indexOfData_10[6] --;   
    }
    averageSensor[6] = averageSensor[6]/50;
}

//////////////

void SimulateFull_Gimat(void)
{
    int i,adcValue;        
    simulateCnt = (simulateCnt + 1)%40;
    if (simulateCnt == 0)
    {
//        adcValue = averageSensor_0;
        //temp = yMin + (long)(adcValue - 0) * (yMax - yMin) / (1023 - 0);

        pH_value = pH_value_min + (long)(averageSensor[0] - 0) * (pH_value_max - pH_value_min) / (1023 - 0);
        SS_value = 0 + (long)(averageSensor[1] - 0) * (10000 - 0) / (1023 - 0);
        COD_value = 0 + (long)(averageSensor[2] - 0) * (2000 - 0) / (1023 - 0);
        TMP_value = TMP_value_min + (long)(averageSensor[3] - TMP_adc_min) * (TMP_value_max - TMP_value_min) / (TMP_adc_max - TMP_adc_min);
        NH4_value = 1000 + (long)(averageSensor[4] - 0) * (5000 - 1000) / (1023 - 0);
        NO3_value = 2000 + (long)(averageSensor[5] - 0) * (10000 - 2000) / (1023 - 0);
        FLOW_value = 0 + (long)(averageSensor[6] - 0) * (36000 - 0) / (1023 - 0);
        
        UartSendString("20.04.16 09:12:07  pH=  ");
        UartSendNumPercent(pH_value);
        UartSendString(" pH SS= ");
        UartSendNumPercent(SS_value);
        UartSendString(" mg/l CSB= ");
        UartSendNumPercent(COD_value);
        UartSendString(" mg/l TMP= ");	
        UartSendNumPercent(TMP_value);
        UartSendString(" C NH4= ");	
        UartSendNumPercent(NH4_value);
        UartSendString(" mg/l NO3= ");	
        UartSendNumPercent(NO3_value);
        UartSendString(" mg/l FLOW= ");	
        UartSendNumPercent(FLOW_value);
        UartSendString(" m3/h \r\n");		
    }
}

void CalibTemp(void)
{
    if (isButtonSetTempMin())
    {
        TMP_adc_min = averageSensor[0];
        //TMP_value_min = 2500; 
    }
    
    if (isButtonSetTempMax())
    {
        TMP_adc_max = averageSensor[0];
        //TMP_value_max = 5000; 
    }
}
