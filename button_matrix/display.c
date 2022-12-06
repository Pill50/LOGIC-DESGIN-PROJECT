#include "display.h"
#include "global.h"

void display_Time() {
    LcdClearS();
    LcdPrintStringS(0,0,"H  :  M  :  S");
    LcdPrintNumS(1,0,hour/10);
    LcdPrintNumS(1,1,hour%10);
    
    LcdPrintNumS(1,6,minute/10);
    LcdPrintNumS(1,7,minute%10);
    
    LcdPrintNumS(1,12,second/10);
    LcdPrintNumS(1,13,second%10);
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

void display_Alarm() {
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


