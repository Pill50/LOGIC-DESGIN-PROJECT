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
            Read_time();           
            // switch to menu
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_2;
                key_code[2] = 0;
            }
            // display alarm watering
            if(hour == hour_alarm && minute == minute_alarm && second <= 20 && alarm_flag == 1){
                LcdClearS();
                LcdPrintStringS(0,4,"DEN GIO TUOI CAY");
                if(blink == 1) {
                   LcdPrintStringS(1,0,"***************");
                }
                if(second == 0) {
                    alarm_flag = 0;
                }
            } else {
                display_Time();
            }
            break;
        case MODE_2: // display menu
            // see time
            if((key_code[1] >= 10 && key_code[1]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_1;
                key_code[1] = 0;
            }
            // adjust time
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_3;
                key_code[2] = 0;
            }
            // set threshold
            if((key_code[3] >= 10 && key_code[3]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_4;
                key_code[3] = 0;
            }
            // set adc
            if((key_code[5] >= 10 && key_code[5]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_5;
                key_code[5] = 0;
            }
            // see warning
            if((key_code[6] >= 10 && key_code[6]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_6;
                key_code[6] = 0;
            }
            // set alarm
            if((key_code[7] >= 10 && key_code[7]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_7;
                key_code[7] = 0;
            }
            // increase mode
            if((key_code[0] >= 10 && key_code[0]%2 == 1)) {
                numberOfPushButton = (numberOfPushButton+1)%4;
                if(numberOfPushButton == 0) numberOfPushButton = 1;
                key_code[0] = 0;
            }
            display_Menu();
            break;
        case MODE_3: // adjust time
            adjustTime();
            // swtich to menu
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                status = MODE_2;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            break;
        case MODE_4: // set threshold
            // increase index option
            if((key_code[0] >= 10 && key_code[0]%2 == 1)) {
                numberOfPushButton = (numberOfPushButton+1)%8;
                if(numberOfPushButton == 0) numberOfPushButton = 1;
                key_code[0] = 0;
            }
            // switch to enter innput value
            if((key_code[3] >= 10 && key_code[3]%2 == 1)) {
                threshold_flag = 1;
                status = MODE_8;
                key_code[3] = 0;
            }
            // swtich to menu
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                status = MODE_2;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            display_Set_Threshold();
            break;
        case MODE_5: // set adc
            display_set_ADC();
            // switch to menu
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                status = MODE_2;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            // increase index option
            if((key_code[0] >= 10 && key_code[0]%2 == 1)) {
                numberOfPushButton = (numberOfPushButton+1)%8;
                if(numberOfPushButton == 0) numberOfPushButton = 1;
                key_code[0] = 0;
            }
            // choose set max adc 
            if((key_code[3] >= 10 && key_code[3]%2 == 1)) {
                adc_max_flag = 1;
                status = MODE_8;
                key_code[3] = 0;
            }
            // choose set min adc
            if((key_code[4] >= 10 && key_code[4]%2 == 1)) {
                adc_min_flag = 1;
                status = MODE_8;
                key_code[4] = 0;
            }
            break;
            break;
        case MODE_6: // display warning
            display_Warning();
            // switch to menu
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                status = MODE_2;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            break;
        case MODE_7:
            display_Alarm();
            // switch to menu
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                status = MODE_2;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            break;
        case MODE_8: // enter input value
            display_input_val();
            // increase input value
            if((key_code[0] >= 10 && key_code[0]%2 == 1)) {
                input++;
                key_code[0] = 0;
            }
            // enter to save and switch to menu
            if((key_code[3] >= 10 && key_code[3]%2 == 1)) {
                // SAVE
                if(threshold_flag == 1) {
                    threshold[numberOfPushButton-1] = input;
                    threshold_flag = 0;
                }
                if(adc_max_flag == 1) {
                    adc_max[numberOfPushButton-1] = input;
                    adc_max_flag = 0;
                }
                if(adc_min_flag == 1) {
                    adc_min[numberOfPushButton-1] = input;
                    adc_min_flag = 0;
                }
                status = MODE_2;
                key_code[3] = 0;
            }
            break;
        default: 
            status = INIT;
            break;
    }
}