#include "fsm.h"
#include "clock.h"
#include "button.h"
#include "display.h"

void fsm() {
    switch(status) {
        case INIT:
            status = MODE_1;
            Read_time();
            break;
        case MODE_1: // see time
            LcdClearS();
            Read_time();           
            // switch to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                index_menu = 0;
                numberOfPushButton = 0;
                status = MODE_2;
                key_code[2]=0;
            }
            // display alarm watering
            if(hour == hour_alarm && minute == minute_alarm){
//                alarm_flag = 1;
                timeBlink = (timeBlink+1)%10;
                LcdClearS();                
                if(timeBlink < 5 && enableBlink()) {
                   LcdPrintStringS(0,0,"DEN GIO TUOI CAY");
                   LcdPrintStringS(1,0,"****************");
                }
            } else {
//                alarm_flag = 0;
                display_Time();
            }
            break;
        case MODE_2: // display menu
            LcdClearS();
            // see time
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 1) {
                status = MODE_1;
                key_code[4] = 0;
            }
            // adjust time
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 2) {
                status = MODE_3;
                key_code[4] = 0;
            }
            // set threshold
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 3) {
                index_threshold = -1;
                numberOfPushButton = 0;
                status = MODE_4;
                key_code[4] = 0;
            }
            // set adc
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 4) {
                index_adc = -1;
                status = MODE_5;
                numberOfPushButton = 0;
                key_code[4] = 0;
            }
            // see warning
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 5) {
                status = MODE_6;
                key_code[4] = 0;
            }
            // set alarm
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 6) {
                status = MODE_7;
                key_code[4] = 0;
            }
            // increase mode
            if(key_code[0]>=5 && key_code[0]%2==1) {
                index_menu = (index_menu+1)%7;
                if(index_menu == 0) index_menu = 1;
                key_code[0] = 0;
            }
            display_Menu();
            break;
        case MODE_3: // adjust time
            LcdClearS();
            adjustTime();
            // swtich to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_2;
                index_menu = 0;
                key_code[2] = 0;
            }
            break;
        case MODE_4: // set threshold
            // increase index option
            if(key_code[0]>=5 && key_code[0]%2==1) {
                index_threshold = (index_threshold+1)%8;
                numberOfPushButton = (numberOfPushButton+1)%8;
                if(numberOfPushButton == 0) numberOfPushButton = 1;
                key_code[0] = 0;
            }
            // switch to enter innput value
            if(key_code[5]>=5 && key_code[5]%2==1 && index_threshold >= 0) {
                threshold_max_flag = 1;
                input = threshold[index_threshold];
                status = MODE_8;
                key_code[5] = 0;
            }
            if(key_code[6]>=5 && key_code[6]%2==1 && index_threshold >= 0) {
                threshold_min_flag = 1;
                input = threshold_min[index_threshold];
                status = MODE_8;
                key_code[6] = 0;
            }
            // swtich to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_2;
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            display_Set_Threshold();
            break;
        case MODE_5: // set adc
            // increase index option
            if(key_code[0]>=5 && key_code[0]%2==1) {
                index_adc = (index_adc+1)%8;
                numberOfPushButton = (numberOfPushButton+1)%8;
                if(numberOfPushButton == 0) numberOfPushButton = 1;
                key_code[0] = 0;
            }
            // switch to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_2;
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            // choose set max adc 
            if(key_code[5]>=5 && key_code[5]%2==1 && index_adc >= 0) {
                adc_max_flag = 1;
                input = adc_max[index_adc];
                status = MODE_8;
                key_code[5] = 0;
            }
            // choose set min adc
            if(key_code[6]>=5 && key_code[6]%2==1 && index_adc >= 0) {
                adc_min_flag = 1;
                input = adc_min[index_adc];
                status = MODE_8;
                key_code[6]=0;
            }
            display_set_ADC();
            break;
        case MODE_6: // display warning
            // switch to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_2;
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            display_Warning();
            break;
        case MODE_7: // display_Alarm
            // switch to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_2;
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            display_Alarm();
            break;
        case MODE_8: // enter input value
            display_input_val();
            // increase input value
            if(key_code[0]>=5 && key_code[0]%2==1) {
                input++;
                key_code[0] = 0;
            }
            // enter to save and switch to menu
            if(key_code[4]>=5 && key_code[4]%2==1) {
                // SAVE
                if(threshold_max_flag == 1) {
                    threshold[index_threshold] = input;
                    threshold_max_flag = 0;
                }
                if(threshold_min_flag == 1) {
                    threshold_min[index_threshold] = input;
                    threshold_min_flag = 0;
                }
                if(adc_max_flag == 1) {
                    adc_max[index_adc] = input;
                    adc_max_flag = 0;
                }
                if(adc_min_flag == 1) {
                    adc_min[index_adc] = input;
                    adc_min_flag = 0;
                }
                status = MODE_2;
                key_code[4] = 0;
            }
            numberOfPushButton = 0;
            index_menu = 0;
            index_threshold = 0;
            index_adc = 0;
            break;
        default: 
            status = INIT;
            break;
    }
}