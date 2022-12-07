#include "display.h"

void display_Time() {
    LcdClearS();
    switch(day)
    {
        case 1:
            LcdPrintStringS(0,0,"SUN");
            break;
        case 2:
            LcdPrintStringS(0,0,"MON");
            break;
        case 3:
            LcdPrintStringS(0,0,"TUE");
            break;
        case 4:
            LcdPrintStringS(0,0,"WED");
            break;
        case 5:
            LcdPrintStringS(0,0,"THU");
            break;
        case 6:
            LcdPrintStringS(0,0,"FRI");
            break;
        case 7:
            LcdPrintStringS(0,0,"SAT");
            break;
        default:
            LcdPrintStringS(0,0,"ERR");
            break;    
    }
    LcdPrintNumS(0,4,hour/10);
    LcdPrintNumS(0,5,hour%10);
    LcdPrintStringS(0,6,":");
    LcdPrintNumS(0,7,minute/10);
    LcdPrintNumS(0,8,minute%10);
    LcdPrintStringS(0,9,":");
    LcdPrintNumS(0,10,second/10);
    LcdPrintNumS(0,11,second%10);
    
    switch(month)
    {
        case 1:
            LcdPrintStringS(1,2,"JAN");
            break;
        case 2:
            LcdPrintStringS(1,2,"FEB");
            break;
        case 3:
            LcdPrintStringS(1,2,"MAR");
            break;
        case 4:
            LcdPrintStringS(1,2,"APR");
            break;
        case 5:
            LcdPrintStringS(1,2,"MAY");
            break;
        case 6:
            LcdPrintStringS(1,2,"JUN");
            break;
        case 7:
            LcdPrintStringS(1,2,"JUL");
            break;
        case 8:
            LcdPrintStringS(1,2,"AUG");
            break;
        case 9:
            LcdPrintStringS(1,2,"SEP");
            break;
        case 10:
            LcdPrintStringS(1,2,"OCT");
            break;
        case 11:
            LcdPrintStringS(1,2,"NOV");
            break;
        case 12:
            LcdPrintStringS(1,2,"DEC");
            break;
        default:
            LcdPrintStringS(1,2,"ERR");
            break;    
    }

    LcdPrintStringS(1,5," ");
    LcdPrintNumS(1,6,date/10);
    LcdPrintNumS(1,7,date%10);
    LcdPrintStringS(1,8," ");
    LcdPrintNumS(1,9,20);
    LcdPrintNumS(1,11,year/10);
    LcdPrintNumS(1,12,year%10);
}

void display_Menu() {
    LcdClearS();
    switch(numberOfPushButton) {
        case 0: 
            LcdPrintStringS(0,0,"**** MENU ****");
            LcdPrintStringS(1,0,"**************");
            break;
        case 1: 
            LcdPrintStringS(0,0,"1. DISPLAY TIME");
            LcdPrintStringS(1,0,"2. SET TH.HOLD");
            break;
        case 2:
            LcdPrintStringS(0,0,"3. SET ADC");
            LcdPrintStringS(1,0,"4. SEE ALARM");
            break;
        case 3:
            LcdPrintStringS(0,0,"5. ADJUST TIME");
//            LcdPrintStringS(1,0,"4. SEE ALARM");
            break;
        default: 
            numberOfPushButton = 0;
            break;
    }   
}

void display_Set_Threshold() {
    LcdClearS();
    switch(numberOfPushButton) {
        case 0: 
            LcdPrintStringS(0,0," SET THRESHOLD ");
            LcdPrintStringS(1,0,"****MODE****");
            break;
        case 1: 
            LcdPrintStringS(0,0,"->SET TMP T.H");
            LcdPrintStringS(1,0,"  SET COD T.H");
            break;
        case 2: 
            LcdPrintStringS(0,0,"  SET TMP T.H");
            LcdPrintStringS(1,0,"->SET COD T.H");
            break;
        case 3:
            LcdPrintStringS(0,0,"->SET PH T.H");
            LcdPrintStringS(1,0,"  SET SS T.H");
            break;
        case 4:
            LcdPrintStringS(0,0,"  SET PH T.H");
            LcdPrintStringS(1,0,"->SET SS T.H");
            break;
        case 5:
            LcdPrintStringS(0,0,"->SET NH4 T.H");
            LcdPrintStringS(1,0,"  SET NO3 T.H");
            break;
        case 6:
            LcdPrintStringS(0,0,"  SET NH4 T.H");
            LcdPrintStringS(1,0,"->SET NO3 T.H");
            break;
        case 7:
            LcdPrintStringS(0,0,"->SET FLOW T.H");
            break;
        default: 
            // overflow & underflow
            numberOfPushButton = 0;
            break;
    }  
}

void display_input_val() {
    LcdClearS();
    LcdPrintStringS(0,0,"Input: ");
    LcdPrintNumS(0,7,inputThreshold);
    LcdPrintStringS(1,0,"3. Save");
}

void display_Warning() {
    LcdClearS();
    if(pH_value > threshold[0]) {
        LcdPrintStringS(0,0,"PH=  ");
        LcdPrintNumPercentS(0,6,pH_value);
        LcdPrintStringS(1,0,"PH CAO ");
    } else if (COD_value > threshold[1]) {
        LcdPrintStringS(0,0,"COD=  ");
        LcdPrintNumPercentS(0,6,COD_value);
        LcdPrintStringS(1,0,"COD CAO ");
    } else if (SS_value > threshold[2]) {
        LcdPrintStringS(0,0,"SS=  ");
        LcdPrintNumPercentS(0,6,SS_value);
        LcdPrintStringS(1,0,"SS CAO ");
    } else if (NH4_value > threshold[3]) {
        LcdPrintStringS(0,0,"NH4=  ");
        LcdPrintNumPercentS(0,6,NH4_value);
        LcdPrintStringS(1,0,"NH4 CAO ");
    } else if (NO3_value > threshold[4]) {
        LcdPrintStringS(0,0,"NO3=  ");
        LcdPrintNumPercentS(0,6,NO3_value);
        LcdPrintStringS(1,0,"NO3 CAO ");
    } else if (TMP_value > threshold[5]) {
        LcdPrintStringS(0,0,"TMP=  ");
        LcdPrintNumPercentS(0,6,TMP_value);
        LcdPrintStringS(1,0,"TMP CAO ");
    } else if (FLOW_value > threshold[6]) {
        LcdPrintStringS(0,0,"SS=  ");
        LcdPrintNumPercentS(0,6,FLOW_value);
        LcdPrintStringS(1,0,"FLOW CAO ");
    } else {
        LcdPrintStringS(0,0,"KHONG CANH BAO");
    }
}

unsigned char enableBlink(void)
{
    if (key_code[5] == 0 && key_code[9] == 0)
        return 1;
    else 
        return 0;
}

void SetHour()
{
    timeBlink = (timeBlink + 1)%10;
    if(timeBlink < 5 && enableBlink())
        LcdPrintStringS(0,4,"  ");
    if((key_code[0] >= 5 && key_code[0]%2 == 1))
    {
        hour = hour + 1;
        if(hour > 23)
            hour = 0;  
        write_ds1307(ADDRESS_HOUR, hour);
    }
    if((key_code[1] >= 10 && key_code[1]%2 == 1))
    {
        hour = hour - 1;
        if(hour < 0)
            hour = 23;
        write_ds1307(ADDRESS_HOUR, hour);
    }    
}
void setMinute()
{
    timeBlink = (timeBlink + 1)%10;
    if(timeBlink < 5 && enableBlink())
        LcdPrintStringS(0,7,"  ");
    if((key_code[0] >= 10 && key_code[0]%2 == 1))
    {
        minute = minute + 1;
        if(minute > 59)
            minute = 0;  
        write_ds1307(ADDRESS_MINUTE, minute);
    }
    if((key_code[1] >= 10 && key_code[1]%2 == 1))
    {
        minute = minute - 1;
        if(minute < 0)
            minute = 59;
        write_ds1307(ADDRESS_MINUTE, minute);
    }    
}
void setDay()
{
    timeBlink = (timeBlink + 1)%10;
    if(timeBlink < 5 && enableBlink())
        LcdPrintStringS(0,0,"   ");
    if((key_code[0] >= 10 && key_code[0]%2 == 1))
    {
        day = day + 1;
        if(day > 7)
            day = 1;  
        write_ds1307(ADDRESS_DAY, day);
    }
    if((key_code[1] >= 10 && key_code[1]%2 == 1))
    {
        day = day - 1;
        if(day < 1)
            day = 7;
        write_ds1307(ADDRESS_DAY, day);
    }    
}
void setDate()
{
    timeBlink = (timeBlink + 1)%10;
    if(timeBlink < 5 && enableBlink())
        LcdPrintStringS(1,6,"  ");
    if((key_code[0] >= 10 && key_code[0]%2 == 1))
    {
        date = date + 1;
        if(date > 31)
            date = 1;  
        write_ds1307(ADDRESS_DATE, date);
    }
    if((key_code[1] >= 10 && key_code[1]%2 == 1))
    {
        date = date - 1;
        if(date < 1)
            date = 31;
        write_ds1307(ADDRESS_DATE, date);
    }    
}
void setMonth()
{
    timeBlink = (timeBlink + 1)%10;
    if(timeBlink < 5 && enableBlink())
        LcdPrintStringS(1,2,"   ");
    if((key_code[0] >= 10 && key_code[0]%2 == 1))
    {
        month = month + 1;
        if(month > 12)
            month = 1;  
        write_ds1307(ADDRESS_MONTH, month);
    }
    if((key_code[1] >= 10 && key_code[1]%2 == 1))
    {
        month = month - 1;
        if(month < 1)
            month = 12;
        write_ds1307(ADDRESS_MONTH, month);
    }    
}
void setYear()
{
    timeBlink = (timeBlink + 1)%10;
    if(timeBlink < 5 && enableBlink())
        LcdPrintStringS(1,11,"  ");
    if((key_code[0] >= 10 && key_code[0]%2 == 1))
    {
        year = year + 1;
        if(year > 99)
            year = 0;  
        write_ds1307(ADDRESS_YEAR, year);
    }
    if((key_code[1] >= 10 && key_code[1]%2 == 1))
    {
        year = year - 1;
        if(year < 0)
            year = 99;
        write_ds1307(ADDRESS_YEAR, year);
    }    
}

void adjustTime() {
    LcdClearS();
    Read_time();
    switch(statusSetTime)
    {
        case INIT:         
            display_Time();
            statusSetTime = SET_DAY;
            break;
        case SET_DAY:
            display_Time();
            setDay();
            if((key_code[2] >= 10 && key_code[2]%2 == 1))
                statusSetTime = SET_HOUR;
            break;
        case SET_HOUR:
            display_Time();
            SetHour();
            if((key_code[2] >= 10 && key_code[2]%2 == 1))
                statusSetTime = SET_MINUTE;        
            break;
        case SET_MINUTE:
            display_Time();
            setMinute();
            if((key_code[2] >= 10 && key_code[2]%2 == 1))
                statusSetTime = SET_DATE;        
            break;
        case SET_DATE:
            setDate();
            display_Time();
            if((key_code[2] >= 10 && key_code[2]%2 == 1))
                statusSetTime = SET_MONTH;
            break;
        case SET_MONTH:
            setMonth();
            display_Time();
            if((key_code[2] >= 10 && key_code[2]%2 == 1))
                statusSetTime = SET_YEAR;
            break;
        case SET_YEAR:
            setYear();
            display_Time();
            if((key_code[2] >= 10 && key_code[2]%2 == 1))
                statusSetTime = SET_DAY;
            break;   
        default:
            break;
    }
}

void increase(){
    switch(index_set){
        case 1: 
            hour++;
            if (hour > 23){
                hour = 0;
            }
            break;
        case 2:
            minute++;
            if (minute > 59){
                minute = 0;
            }
            break;
        case 3:
            second++;
            if (second > 59){
                second = 0;
            }
            break;
        case 4:
            day++;
            if (day > 7){
                day = 1;
            }
            break;
        case 5:
            date = date+1;
            if(date > day_of_month[month-1]){
                date = 1;
            }
            break;
        case 6:
            month++;
            if (month > 12){
                month = 1;
            }
            break;
        case 7:
            year++;
            break;
        default:
            break;
    }
}


void decrease(){
    switch(index_set){
        case 1: 
            hour--;
            if (hour < 0){
                hour = 23;
            }
            break;
        case 2:
            minute--;
            if (minute < 0){
                minute = 59;
            }
            break;
        case 3:
            second--;
            if (second < 0){
                second = 59;
            }
            break;
        case 4:
            day--;
            if (day < 1){
                day = 7;
            }
            break;
        case 5:
            date = date -1;
            if(date < 1 ){
                date = day_of_month[month-1];
            }
            break;
        case 6:
            month--;
            if (month < 1){
                month = 12;
            }
            break;
        case 7:
            year--;
            if (year < 0){
                year = 0;
            }
            break;
        default:
            break;
    }
}



void display_Alarm(){
    if (key_code[0] >= 10 && key_code[0]%2 == 1){
        index_set = (index_set+1)%8;
        if (index_set == 0) index_set++;
            key_code[0] = 0;
    }
   
    if (key_code[6] >= 10 && key_code[6]%2 == 1){
            increase();
            key_code[6] = 0;
    }
    if (key_code[4] >= 10 && key_code[4]%2 == 1){
           decrease();
            key_code[4] = 0;
        }
    if (key_code[1] >= 10 && key_code[1]%2 == 1){
        hour_alarm = hour;
        minute_alarm = minute;
        status = MODE_1;
        alarm_flag = 1;
        key_code[1] = 0;
    }
    LcdClearS();
    LcdPrintStringS(0,0,"Moi dat bao thuc");
//    Display_alarm();
    DisplayLcdScreen();    
} 
