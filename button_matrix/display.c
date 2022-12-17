#include "display.h"

char* label[7] = {"PH","SS", "COD", "NH4", "NO3", "TMP", "FLW"};

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
            LcdPrintStringS(0,0,"1.SEE VALUE SS <");
            LcdPrintStringS(1,0,"2.SET TH.HOLD   ");
            break;
        case 2:
            LcdPrintStringS(0,0,"1.SEE VALUE SS  ");
            LcdPrintStringS(1,0,"2.SET TH.HOLD  <");
            break;
        case 3:
            LcdPrintStringS(0,0,"3.SET ADC      <");
            LcdPrintStringS(1,0,"4.SET ALARM     ");      
            break;
        case 4:
            LcdPrintStringS(0,0,"3.SET ADC       ");
            LcdPrintStringS(1,0,"4.SET ALARM    <");      
            break;
        case 5:
            LcdPrintStringS(0,0,"5.SEE WARNING  <");
            LcdPrintStringS(1,0,"6.DISPLAY TIME  ");      
            break;
        case 6:
            LcdPrintStringS(0,0,"5.SEE WARNING   ");
            LcdPrintStringS(1,0,"6.DISPLAY TIME <");      
            break;
        case 7: 
            LcdPrintStringS(0,0,"7.ADJUST TIME  <");
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
            LcdPrintStringS(1,0,"5: INC    6: DEC");
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
            LcdPrintStringS(1,0,"5: INC     6:DEC");
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

void display_input_val(int option, int index, int cursor) {
    LcdClearS();
    timeBlink = (timeBlink+1)%10;
    //threshold
    if(option == 1) {
        LcdClearS();
        LcdPrintStringS(0,0,label[index]);
        LcdPrintStringS(0,4,"TH MX: ");
        LcdPrintNumS(0,11,threshold[index]);
        if(timeBlink < 5 && enableBlink() && cursor == 0 && threshold[index] >= 10000)
            LcdPrintStringS(0,11,"_____");
        else if(timeBlink < 5 && enableBlink() && cursor == 0 && threshold[index] >= 1000)
            LcdPrintStringS(0,11,"____");
        else if(timeBlink < 5 && enableBlink() && cursor == 0 && threshold[index] >= 100)
            LcdPrintStringS(0,11,"___");
        else if(timeBlink < 5 && enableBlink() && cursor == 0 && threshold[index] >= 0)
            LcdPrintStringS(0,11,"__");
        LcdPrintStringS(1,0,label[index]);
        LcdPrintStringS(1,4,"TH MI: ");
        LcdPrintNumS(1,11,threshold_min[index]);
        if(timeBlink < 5 && enableBlink() && cursor == 1 && threshold_min[index] >= 10000)
            LcdPrintStringS(1,11,"_____");
        else if(timeBlink < 5 && enableBlink() && cursor == 1 && threshold_min[index] >= 1000)
            LcdPrintStringS(1,11,"____");
        else if(timeBlink < 5 && enableBlink() && cursor == 1 && threshold_min[index] >= 100)
            LcdPrintStringS(1,11,"___");
        else if(timeBlink < 5 && enableBlink() && cursor == 1 && threshold_min[index] >= 0)
            LcdPrintStringS(1,11,"___");
    }
    // adc value
    if(option == 2) {
        LcdClearS();
        LcdPrintStringS(0,0,label[index]);
        LcdPrintStringS(0,4,"ADC MX: ");
        LcdPrintNumS(0,11,adc_max[index]);
        if(timeBlink < 5 && enableBlink() && cursor == 0 && adc_max[index] >= 10000)
            LcdPrintStringS(0,11,"_____");
        else if(timeBlink < 5 && enableBlink() && cursor == 0 && adc_max[index] >= 1000)
            LcdPrintStringS(0,11,"____");
        else if(timeBlink < 5 && enableBlink() && cursor == 0 && adc_max[index] >= 100)
            LcdPrintStringS(0,11,"___");
        else if(timeBlink < 5 && enableBlink() && cursor == 0 && adc_max[index] >= 0)
            LcdPrintStringS(0,11,"__");
        LcdPrintStringS(1,0,label[index]);
        LcdPrintStringS(1,4,"ADC MI: ");
        LcdPrintNumS(1,11,adc_min[index]);
        if(timeBlink < 5 && enableBlink() && cursor == 1 && adc_min[index] >= 10000)
            LcdPrintStringS(1,11,"_____");
        else if(timeBlink < 5 && enableBlink() && cursor == 1 && adc_min[index] >= 1000)
            LcdPrintStringS(1,11,"____");
        else if(timeBlink < 5 && enableBlink() && cursor == 1 && adc_min[index] >= 100)
            LcdPrintStringS(1,11,"___");
        else if(timeBlink < 5 && enableBlink() && cursor == 1 && adc_min[index] >= 0)
            LcdPrintStringS(1,11,"__");
    }
}

void display_Warning() {
    LcdClearS();
    if(index_warning == 0) {
        if(pH_value > threshold[0]) {
            LcdPrintStringS(0,0,"PH=  ");
            LcdPrintNumPercentS(0,6,pH_value);
            LcdPrintStringS(1,0,"PH CAO ");
        } else if (pH_value < threshold_min[0]) {
            LcdPrintStringS(0,0,"PH=  ");
            LcdPrintNumPercentS(0,6,pH_value);
            LcdPrintStringS(1,0,"PH THAP ");
        } else {
            LcdPrintStringS(0,0,"PH ON DINH");
        }
    }
    if(index_warning == 1) {
        if (SS_value > threshold[1]) {
            LcdPrintStringS(0,0,"SS=  ");
            LcdPrintNumPercentS(0,6,SS_value);
            LcdPrintStringS(1,0,"SS CAO ");
        } else if (SS_value < threshold_min[1]) {
            LcdPrintStringS(0,0,"SS=  ");
            LcdPrintNumPercentS(0,6,SS_value);
            LcdPrintStringS(1,0,"SS THAP ");
        } else {
            LcdPrintStringS(0,0,"SS ON DINH");
        }
    }
    if(index_warning == 2) {
        if (COD_value > threshold[2]) {
            LcdPrintStringS(0,0,"COD=  ");
            LcdPrintNumPercentS(0,6,COD_value);
            LcdPrintStringS(1,0,"COD CAO ");
        } else if (COD_value < threshold_min[2]) {
            LcdPrintStringS(0,0,"COD=  ");
            LcdPrintNumPercentS(0,6,COD_value);
            LcdPrintStringS(1,0,"COD THAP ");
        } else {
            LcdPrintStringS(0,0,"COD ON DINH");
        }
    }
    if(index_warning == 3) {
        if (NH4_value > threshold[3]) {
            LcdPrintStringS(0,0,"NH4=  ");
            LcdPrintNumPercentS(0,6,NH4_value);
            LcdPrintStringS(1,0,"NH4 CAO ");
        } else if (NH4_value < threshold_min[3]) {
            LcdPrintStringS(0,0,"NH4=  ");
            LcdPrintNumPercentS(0,6,NH4_value);
            LcdPrintStringS(1,0,"NH4 THAP ");
        } else {
            LcdPrintStringS(0,0,"NH4 ON DINH");
        }
    }
    if(index_warning == 4) {
        if (NO3_value > threshold[4]) {
            LcdPrintStringS(0,0,"NO3=  ");
            LcdPrintNumPercentS(0,6,NO3_value);
            LcdPrintStringS(1,0,"NO3 CAO ");
        } else if (NO3_value < threshold_min[4]) {
            LcdPrintStringS(0,0,"NO3=  ");
            LcdPrintNumPercentS(0,6,NO3_value);
            LcdPrintStringS(1,0,"NO3 THAP ");
        } else {
            LcdPrintStringS(0,0,"NO3 ON DINH");
        }
    }
    if(index_warning == 5) {
        if (TMP_value > threshold[5]) {
            LcdPrintStringS(0,0,"TMP=  ");
            LcdPrintNumPercentS(0,6,TMP_value);
            LcdPrintStringS(1,0,"TMP CAO ");
        } else if (TMP_value < threshold_min[5]) {
            LcdPrintStringS(0,0,"TMP=  ");
            LcdPrintNumPercentS(0,6,TMP_value);
            LcdPrintStringS(1,0,"TMP THAP ");
        } else {
            LcdPrintStringS(0,0,"TMP ON DINH");
        }
    }
    if(index_warning == 6) {
        if (FLOW_value > threshold[6]) {
            LcdPrintStringS(0,0,"SS=  ");
            LcdPrintNumPercentS(0,6,FLOW_value);
            LcdPrintStringS(1,0,"FLOW MANH ");
        } else if (FLOW_value < threshold_min[6]) {
            LcdPrintStringS(0,0,"SS=  ");
            LcdPrintNumPercentS(0,6,FLOW_value);
            LcdPrintStringS(1,0,"FLOW YEU ");
        } else {
            LcdPrintStringS(0,0,"FLOW ON DINH");
        }
    }
    if(flag_timer1 == 1) {
        SetTimer1_ms(5000);
        index_warning = (index_warning+1)%7;
    }
}

void SetHour()
{     
    // increase hour value
    if(key_code[5]>=5 && key_code[5]%2==1) {
        hour = hour + 1;
        if(hour > 23)
            hour = 0;  
        write_ds1307(ADDRESS_HOUR, hour);
        key_code[5] = 0;
    }
    // decrease hour value
    if(key_code[6]>=5 && key_code[6]%2==1)
    {
        hour = hour - 1;
        if(hour < 0)
            hour = 23;
        write_ds1307(ADDRESS_HOUR, hour);
        key_code[6] = 0;
    }    
}

void setMinute()
{
    // increase minute value
    if(key_code[5]>=5 && key_code[5]%2==1) {
        minute = minute + 1;
        if(minute > 59)
            minute = 0;  
        write_ds1307(ADDRESS_MINUTE, minute);
        key_code[5] = 0;
    }
    // decrease minute value
    if(key_code[6]>=5 && key_code[6]%2==1) {
        minute = minute - 1;
        if(minute < 0)
            minute = 59;
        write_ds1307(ADDRESS_MINUTE, minute);
        key_code[6] = 0;
    }    
}

void setDay() {
    // increase day value
    if(key_code[5]>=5 && key_code[5]%2==1) {
        day = day + 1;
        if(day > 7)
            day = 1;  
        write_ds1307(ADDRESS_DAY, day);
        key_code[5] = 0;
    }
    // decrease day value
    if(key_code[6]>=5 && key_code[6]%2==1) {
        day = day - 1;
        if(day < 1)
            day = 7;
        write_ds1307(ADDRESS_DAY, day);
        key_code[6] = 0;
    }    
}
void setDate() {  
    // increase date value
    if(key_code[5]>=5 && key_code[5]%2==1) {
        date = date + 1;
        if(date > 31)
            date = 1;  
        write_ds1307(ADDRESS_DATE, date);
        key_code[5] = 0;
    }
    // decrease date value
    if(key_code[6]>=5 && key_code[6]%2==1) {
        date = date - 1;
        if(date < 1)
            date = 31;
        write_ds1307(ADDRESS_DATE, date);
        key_code[6] = 0;
    }    
}
void setMonth() {
    // increase month value
    if(key_code[5]>=5 && key_code[5]%2==1) {
        month = month + 1;
        if(month > 12)
            month = 1;  
        write_ds1307(ADDRESS_MONTH, month);
        key_code[5] = 0;
    }
    // decrease month value
    if(key_code[6]>=5 && key_code[6]%2==1) {
        month = month - 1;
        if(month < 1)
            month = 12;
        write_ds1307(ADDRESS_MONTH, month);
        key_code[6] = 0;
    }    
}
void setYear() {    
    // increase year value
    if(key_code[5]>=5 && key_code[5]%2==1) {
        year = year + 1;
        if(year > 99)
            year = 0;  
        write_ds1307(ADDRESS_YEAR, year);
        key_code[5] = 0;
    }
    // decrease year value
    if(key_code[6]>=5 && key_code[6]%2==1) {
        year = year - 1;
        if(year < 0)
            year = 99;
        write_ds1307(ADDRESS_YEAR, year);
        key_code[6] = 0;
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
    LcdPrintNumS(0,2,hour_alarm/10);
    LcdPrintNumS(0,3,hour_alarm%10);
    if(timeBlink < 5 && enableBlink() && index_set == 0){
        LcdPrintStringS(0,2,"_");
        LcdPrintStringS(0,3,"_");
    }
    LcdPrintStringS(0,4,":");
    LcdPrintNumS(0,5,minute_alarm/10);
    LcdPrintNumS(0,6,minute_alarm%10);
    if(timeBlink < 5 && enableBlink() && index_set == 1){
        LcdPrintStringS(0,5,"_");
        LcdPrintStringS(0,6,"_");
    }
    LcdPrintStringS(0,7,"->");
    LcdPrintNumS(0,9,hour_alarm1/10);
    LcdPrintNumS(0,10,hour_alarm1%10);
    if(timeBlink < 5 && enableBlink() && index_set == 2){
        LcdPrintStringS(0,9,"_");
        LcdPrintStringS(0,10,"_");
    }
    LcdPrintStringS(0,11,":");
    LcdPrintNumS(0,12,minute_alarm1/10);
    LcdPrintNumS(0,13,minute_alarm1%10);
    if(timeBlink < 5 && enableBlink() && index_set == 3){
        LcdPrintStringS(0,12,"_");
        LcdPrintStringS(0,13,"_");
    }
    LcdPrintStringS(1,0,"4.Save  2.Cancel");
}

void display_Alarm(){
    if (key_code[0] >= 5 && key_code[0]%2 == 1){
        index_set = (index_set+1)%4;
        key_code[0] = 0;
    }
   
    // increase alarm value
    if (key_code[8] >= 5 && key_code[8]%2 == 1){
        if(index_set == 0) hour_alarm = (hour_alarm+1)%24;
        if(index_set == 1) minute_alarm = (minute_alarm+1)%60;
        if(index_set == 2) hour_alarm1 = (hour_alarm1+1)%24;
        if(index_set == 3) minute_alarm1 = (minute_alarm1+1)%60;
        key_code[8] = 0;
    }
    
    // decrease alarm value
    if (key_code[9] >= 5 && key_code[9]%2 == 1){
        if(index_set == 0) hour_alarm--;
        if(index_set == 1) minute_alarm--;
        if(index_set == 2) hour_alarm1--;
        if(index_set == 3) minute_alarm1--;
        if(hour_alarm < 0) hour_alarm = 23;
        if(hour_alarm1 < 0) hour_alarm1 = 23;
        if(minute_alarm < 0) minute_alarm = 59;
        if(minute_alarm1 < 0) minute_alarm1 = 59;
        key_code[9] = 0;
    }
    
    // save alarm value and switch to MODE1
    if (key_code[4] >= 5 && key_code[4]%2 == 1){
        status = MODE_1;
        key_code[4] = 0;
    }
    display_Setting_Alarm();   
} 

void display_sensor_val() {
    LcdClearS();
    if(index_sensor == 0) {
        LcdPrintStringS(0,0,"PH:");
        LcdPrintNumPercentS(0,3,pH_value);  
        LcdPrintStringS(1,0,"SS:");
        LcdPrintNumPercentS(1,3,SS_value);
    } 
    if(index_sensor == 1) {
         LcdPrintStringS(0,0,"COD:");
        LcdPrintNumPercentS(0,4,COD_value);
        LcdPrintStringS(1,0,"NH4:");
        LcdPrintNumPercentS(1,4,NH4_value);
    }
    if(index_sensor == 2) {
        LcdPrintStringS(0,0,"N03:");
        LcdPrintNumPercentS(0,4,NO3_value);
        LcdPrintStringS(1,0,"TMP:");
        LcdPrintNumPercentS(1,4,TMP_value);
    } 
    if(index_sensor == 3) {
        LcdPrintStringS(0,0,"FLOW:");
        LcdPrintNumPercentS(0,5,FLOW_value);
    } 
    if(flag_timer1 == 1) {
        SetTimer1_ms(10000);
        index_sensor = (index_sensor+1)%4;
    }
}

void display_detail_sensor_val(int index, int value, int maxVal, int minVal) {
    LcdClearS();
    LcdPrintStringS(0,0,label[index]);
    LcdPrintStringS(0,3,":");
    LcdPrintNumPercentS(0,4,value);
    LcdPrintStringS(0,11,"MIN:");
    LcdPrintStringS(1,0,"MX:");
    LcdPrintNumPercentS(1,3,maxVal);
    LcdPrintNumPercentS(1,10,minVal);
}

void display_menu_detail_sensor_val() {
    LcdClearS();
    switch(numberOfPushButton) {
        case 0: 
            LcdPrintStringS(0,0,"   SEE DETAIL   ");
            LcdPrintStringS(1,0,"  SENSOR VALUE  ");
            break;
        case 1: 
            LcdPrintStringS(0,0,"PH DETAIL      <");
            LcdPrintStringS(1,0,"SS DETAIL       ");
            break;
        case 2: 
            LcdPrintStringS(0,0,"PH DETAIL       ");
            LcdPrintStringS(1,0,"SS DETAIL      <");
            break;
        case 3:
            LcdPrintStringS(0,0,"COD DETAIL     <");
            LcdPrintStringS(1,0,"NH4 DETAIL      ");
            break;
        case 4:
            LcdPrintStringS(0,0,"COD DETAIL      ");
            LcdPrintStringS(1,0,"NH4 DETAIL     <");
            break;
        case 5:
            LcdPrintStringS(0,0,"NO3 DETAIL     <");
            LcdPrintStringS(1,0,"TMP DETAIL      ");
            break;
        case 6:
            LcdPrintStringS(0,0,"NO3 DETAIL      ");
            LcdPrintStringS(1,0,"TMP DETAIL     <");
            break;
        case 7:
            LcdPrintStringS(0,0,"FLOW DETAIL    <");
            break;
        default: 
            // overflow & underflow
            numberOfPushButton = 0;
            break;
    }  
}