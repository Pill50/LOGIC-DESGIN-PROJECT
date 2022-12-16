#include "display.h"

void display_Time() {
//    LcdClearS();
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
    switch(index_menu) {
        case 0: 
            LcdPrintStringS(0,0,"**** MENU ******");
            LcdPrintStringS(1,0,"****************");
            break;
        case 1: 
            LcdPrintStringS(0,0,"1.DISPLAY TIME <");
            LcdPrintStringS(1,0,"2.ADJUST TIME   ");
            break;
        case 2: 
            LcdPrintStringS(0,0,"1.DISPLAY TIME  ");
            LcdPrintStringS(1,0,"2.ADJUST TIME  <");
            break;
        case 3:
            LcdPrintStringS(0,0,"3.SET TH.HOLD  <");
            LcdPrintStringS(1,0,"4.SET ADC       ");
            break;
        case 4:
            LcdPrintStringS(0,0,"3.SET TH.HOLD   ");
            LcdPrintStringS(1,0,"4.SET ADC      <");
            break;
        case 5:
            LcdPrintStringS(0,0,"5.SEE WARNING  <");
            LcdPrintStringS(1,0,"6.SET ALARM     ");
            break;
        case 6:
            LcdPrintStringS(0,0,"5.SEE WARNING   ");
            LcdPrintStringS(1,0,"6.SET ALARM    <");
            break;
        default: 
            index_menu = 0;
            break;
    }   
}

void display_Set_Threshold() {
    LcdClearS();
    switch(numberOfPushButton) {
        case 0: 
            LcdPrintStringS(0,0," SET THRESHOLD  ");
            LcdPrintStringS(1,0,"5: MAX    6: MIN");
            break;
        case 1: 
            LcdPrintStringS(0,0,"SET PH T.H     <");
            LcdPrintStringS(1,0,"SET SS T.H      ");
            break;
        case 2: 
            LcdPrintStringS(0,0,"SET PH T.H      ");
            LcdPrintStringS(1,0,"SET SS T.H     <");
            break;
        case 3:
            LcdPrintStringS(0,0,"SET COD T.H    <");
            LcdPrintStringS(1,0,"SET NH4 T.H     ");
            break;
        case 4:
            LcdPrintStringS(0,0,"SET COD T.H     ");
            LcdPrintStringS(1,0,"SET NH4 T.H    <");
            break;
        case 5:
            LcdPrintStringS(0,0,"SET NO3 T.H    <");
            LcdPrintStringS(1,0,"SET TMP T.H     ");
            break;
        case 6:
            LcdPrintStringS(0,0,"SET NO3 T.H     ");
            LcdPrintStringS(1,0,"SET TMP T.H    <");
            break;
        case 7:
            LcdPrintStringS(0,0,"SET FLOW T.H   <");
            break;
        default: 
            // overflow & underflow
            numberOfPushButton = 0;
            break;
    }  
}

void display_set_ADC() {
    LcdClearS();
    switch(numberOfPushButton) {
        case 0: 
            LcdPrintStringS(0,0,"  SET ADC MODE  ");
            LcdPrintStringS(1,0,"5: MAX     6:MIN");
            break;
        case 1: 
            LcdPrintStringS(0,0,"SET PH ADC     <");
            LcdPrintStringS(1,0,"SET SS ADC      ");
            break;
        case 2: 
            LcdPrintStringS(0,0,"SET PH ADC      ");
            LcdPrintStringS(1,0,"SET SS ADC     <");
            break;
        case 3:
            LcdPrintStringS(0,0,"SET COD ADC    <");
            LcdPrintStringS(1,0,"SET NH4 ADC     ");
            break;
        case 4:
            LcdPrintStringS(0,0,"SET COD ADC     ");
            LcdPrintStringS(1,0,"SET NH4 ADC    <");
            break;
        case 5:
            LcdPrintStringS(0,0,"SET NO3 ADC    <");
            LcdPrintStringS(1,0,"SET TMP ADC     ");
            break;
        case 6:
            LcdPrintStringS(0,0,"SET NO3 ADC     ");
            LcdPrintStringS(1,0,"SET TMP ADC    <");
            break;
        case 7:
            LcdPrintStringS(0,0,"SET FLOW ADC   <");
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
    LcdPrintNumS(0,7,input);
    LcdPrintStringS(1,0,"4. Save");
}

void display_Warning() {
    LcdClearS();
    if(pH_value > threshold[0]) {
        LcdPrintStringS(0,0,"PH=  ");
        LcdPrintNumPercentS(0,6,pH_value);
        LcdPrintStringS(1,0,"PH CAO ");
    } else if (pH_value < threshold_min[0]) {
        LcdPrintStringS(0,0,"PH=  ");
        LcdPrintNumPercentS(0,6,pH_value);
        LcdPrintStringS(1,0,"PH THAP ");
    } else if (SS_value > threshold[1]) {
        LcdPrintStringS(0,0,"SS=  ");
        LcdPrintNumPercentS(0,6,SS_value);
        LcdPrintStringS(1,0,"SS CAO ");
    } else if (SS_value < threshold_min[1]) {
        LcdPrintStringS(0,0,"SS=  ");
        LcdPrintNumPercentS(0,6,SS_value);
        LcdPrintStringS(1,0,"SS THAP ");
    } else if (COD_value > threshold[2]) {
        LcdPrintStringS(0,0,"COD=  ");
        LcdPrintNumPercentS(0,6,COD_value);
        LcdPrintStringS(1,0,"COD CAO ");
    } else if (COD_value < threshold_min[2]) {
        LcdPrintStringS(0,0,"COD=  ");
        LcdPrintNumPercentS(0,6,COD_value);
        LcdPrintStringS(1,0,"COD THAP ");
    } else if (NH4_value > threshold[3]) {
        LcdPrintStringS(0,0,"NH4=  ");
        LcdPrintNumPercentS(0,6,NH4_value);
        LcdPrintStringS(1,0,"NH4 CAO ");
    } else if (NH4_value < threshold_min[3]) {
        LcdPrintStringS(0,0,"NH4=  ");
        LcdPrintNumPercentS(0,6,NH4_value);
        LcdPrintStringS(1,0,"NH4 THAP ");
    } else if (NO3_value > threshold[4]) {
        LcdPrintStringS(0,0,"NO3=  ");
        LcdPrintNumPercentS(0,6,NO3_value);
        LcdPrintStringS(1,0,"NO3 CAO ");
    } else if (NO3_value < threshold_min[4]) {
        LcdPrintStringS(0,0,"NO3=  ");
        LcdPrintNumPercentS(0,6,NO3_value);
        LcdPrintStringS(1,0,"NO3 THAP ");
    } else if (TMP_value > threshold[5]) {
        LcdPrintStringS(0,0,"TMP=  ");
        LcdPrintNumPercentS(0,6,TMP_value);
        LcdPrintStringS(1,0,"TMP CAO ");
    } else if (TMP_value < threshold_min[5]) {
        LcdPrintStringS(0,0,"TMP=  ");
        LcdPrintNumPercentS(0,6,TMP_value);
        LcdPrintStringS(1,0,"TMP THAP ");
    } else if (FLOW_value > threshold[6]) {
        LcdPrintStringS(0,0,"SS=  ");
        LcdPrintNumPercentS(0,6,FLOW_value);
        LcdPrintStringS(1,0,"FLOW MANH ");
    } else if (FLOW_value < threshold_min[6]) {
        LcdPrintStringS(0,0,"SS=  ");
        LcdPrintNumPercentS(0,6,FLOW_value);
        LcdPrintStringS(1,0,"FLOW YEU ");
    } else {
        LcdPrintStringS(0,0,"KHONG CANH BAO");
    }
}

void SetHour()
{     
    // increase hour value
    if(key_code[0]>=5 && key_code[0]%2==1) {
        hour = hour + 1;
        if(hour > 23)
            hour = 0;  
        write_ds1307(ADDRESS_HOUR, hour);
        key_code[0] = 0;
    }
    // decrease hour value
    if(key_code[1]>=5 && key_code[1]%2==1)
    {
        hour = hour - 1;
        if(hour < 0)
            hour = 23;
        write_ds1307(ADDRESS_HOUR, hour);
        key_code[1] = 0;
    }    
}

void setMinute()
{
    // increase minute value
    if(key_code[0]>=5 && key_code[0]%2==1) {
        minute = minute + 1;
        if(minute > 59)
            minute = 0;  
        write_ds1307(ADDRESS_MINUTE, minute);
        key_code[0] = 0;
    }
    // decrease minute value
    if(key_code[1]>=5 && key_code[1]%2==1) {
        minute = minute - 1;
        if(minute < 0)
            minute = 59;
        write_ds1307(ADDRESS_MINUTE, minute);
        key_code[1] = 0;
    }    
}

void setDay() {
    // increase day value
    if(key_code[0]>=5 && key_code[0]%2==1) {
        day = day + 1;
        if(day > 7)
            day = 1;  
        write_ds1307(ADDRESS_DAY, day);
        key_code[0] = 0;
    }
    // decrease day value
    if(key_code[1]>=5 && key_code[1]%2==1) {
        day = day - 1;
        if(day < 1)
            day = 7;
        write_ds1307(ADDRESS_DAY, day);
        key_code[1] = 0;
    }    
}
void setDate() {  
    // increase date value
    if(key_code[0]>=5 && key_code[0]%2==1) {
        date = date + 1;
        if(date > 31)
            date = 1;  
        write_ds1307(ADDRESS_DATE, date);
        key_code[0] = 0;
    }
    // decrease date value
    if(key_code[1]>=5 && key_code[1]%2==1) {
        date = date - 1;
        if(date < 1)
            date = 31;
        write_ds1307(ADDRESS_DATE, date);
        key_code[1] = 0;
    }    
}
void setMonth() {
    // increase month value
    if(key_code[0]>=5 && key_code[0]%2==1) {
        month = month + 1;
        if(month > 12)
            month = 1;  
        write_ds1307(ADDRESS_MONTH, month);
        key_code[0] = 0;
    }
    // decrease month value
    if(key_code[1]>=5 && key_code[1]%2==1) {
        month = month - 1;
        if(month < 1)
            month = 12;
        write_ds1307(ADDRESS_MONTH, month);
        key_code[1] = 0;
    }    
}
void setYear() {    
    // increase year value
    if(key_code[0]>=5 && key_code[0]%2==1) {
        year = year + 1;
        if(year > 99)
            year = 0;  
        write_ds1307(ADDRESS_YEAR, year);
        key_code[0] = 0;
    }
    // decrease year value
    if(key_code[1]>=5 && key_code[1]%2==1) {
        year = year - 1;
        if(year < 0)
            year = 99;
        write_ds1307(ADDRESS_YEAR, year);
        key_code[1] = 0;
    }    
}

void adjustTime() {
    LcdClearS();
    Read_time();
    timeBlink = (timeBlink+1)%10;
    switch(statusSetTime) {
        case INIT:         
            display_Time();
            statusSetTime = SET_DAY;
            break;
        case SET_DAY:     
            setDay();
            display_Time();
            if(timeBlink < 5 && enableBlink())
                LcdPrintStringS(0,0,"___");
            if(key_code[4]>=5 && key_code[4]%2==1) {
                statusSetTime = SET_HOUR;
                key_code[4] = 0;
            }               
            break;
        case SET_HOUR:
            SetHour();
            display_Time();
            if(timeBlink < 5 && enableBlink())
               LcdPrintStringS(0,4,"__");
            if(key_code[4]>=5 && key_code[4]%2==1) {
                statusSetTime = SET_MINUTE; 
                key_code[4] = 0;
            }              
            break;
        case SET_MINUTE:            
            setMinute();
            display_Time();
            if(timeBlink < 5 && enableBlink())
                LcdPrintStringS(0,7,"__");
            if(key_code[4]>=5 && key_code[4]%2==1) {
                statusSetTime = SET_MONTH;      
                key_code[4] = 0;
            }                 
            break;
         case SET_MONTH:
            setMonth();
            display_Time();
            if(timeBlink < 5 && enableBlink())
                LcdPrintStringS(1,2,"___");
            if(key_code[4]>=5 && key_code[4]%2==1) {
                statusSetTime = SET_DATE;
                key_code[4] = 0;
            }               
            break;
        case SET_DATE:
            setDate();
            display_Time();
            if(timeBlink < 5 && enableBlink())
                LcdPrintStringS(1,6,"__");
            if(key_code[4]>=5 && key_code[4]%2==1) {
                statusSetTime = SET_YEAR;
                key_code[4] = 0;
            }               
            break;      
        case SET_YEAR:
            setYear();
            display_Time();
            if(timeBlink < 5 && enableBlink())
                LcdPrintStringS(1,11,"__");
            if(key_code[4]>=5 && key_code[4]%2==1) {
                statusSetTime = SET_DAY;
                key_code[4] = 0;
            }                
            break;   
        default:
            break;
    }
}

void display_Setting_Alarm() {
    LcdClearS();
    timeBlink = (timeBlink+1)%10;
    LcdPrintNumS(0,5,hour_alarm/10);
    LcdPrintNumS(0,6,hour_alarm%10);
    if(timeBlink < 5 && enableBlink() && index_set == 0){
        LcdPrintStringS(0,5,"_");
        LcdPrintStringS(0,6,"_");
    }
    LcdPrintStringS(0,7,":");
    LcdPrintNumS(0,8,minute_alarm/10);
    LcdPrintNumS(0,9,minute_alarm%10);
    if(timeBlink < 5 && enableBlink() && index_set == 1){
        LcdPrintStringS(0,8,"_");
        LcdPrintStringS(0,9,"_");
    }
    LcdPrintStringS(1,0,"4.Save  2.Cancel");
}

void display_Alarm(){
    if (key_code[0] >= 5 && key_code[0]%2 == 1){
        index_set = (index_set+1)%2;
        key_code[0] = 0;
    }
   
    // increase alarm value
    if (key_code[5] >= 5 && key_code[5]%2 == 1){
        if(index_set == 0) hour_alarm = (hour_alarm+1)%24;
        if(index_set == 1) minute_alarm = (minute_alarm+1)%60;
        key_code[5] = 0;
    }
    
    // decrease alarm value
    if (key_code[6] >= 5 && key_code[6]%2 == 1){
        if(index_set == 0) hour_alarm--;
        if(index_set == 1) minute_alarm--;
        if(hour_alarm < 0) hour_alarm = 23;
        if(minute_alarm < 0) minute_alarm = 59;
        key_code[6] = 0;
    }
    
    // save alarm value and switch to MODE1
    if (key_code[4] >= 5 && key_code[4]%2 == 1){
        status = MODE_1;
        key_code[4] = 0;
    }
    display_Setting_Alarm();   
} 
