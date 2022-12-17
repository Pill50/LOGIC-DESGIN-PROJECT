#include "fsm.h"
#include "clock.h"
#include "button.h"
#include "display.h"
#include "../timer/timer.h"

#define THRESHOLD 1
#define ADC 2

int option;
int cursor = 0;

void fsm() {
    switch(status) {
        case INIT: 
            LcdClearS();
            display_sensor_val();          
            // swtich to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_1;
                SetTimer1_ms(50000);
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            break;
        case MODE_1:
            LcdClearS();
            // see sensor value
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 1) {
                index_sensor = -1;
                numberOfPushButton = 0;
                status = MODE_2;
                key_code[4] = 0;
            }
            // set threshold
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 2) {
                index_threshold = -1;
                numberOfPushButton = 0;
                status = MODE_3;
                key_code[4] = 0;
            }
            // set adc
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 3) {
                index_adc = -1;
                status = MODE_4;
                numberOfPushButton = 0;
                key_code[4] = 0;
            }
            // set alarm
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 4) {
                status = MODE_5;
                key_code[4] = 0;
            }
            // see warning
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 5) {
                SetTimer1_ms(100);
                index_warning = 0;
                status = MODE_6;
                key_code[4] = 0;
            }
            // see time
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 6) {
                status = MODE_7;
                key_code[4] = 0;
            }
            // adjust time
            if(key_code[4]>=5 && key_code[4]%2==1 && index_menu == 7) {
                status = MODE_8;
                key_code[4] = 0;
            }           
            // increase mode
            if(key_code[0]>=5 && key_code[0]%2==1) {
                index_menu = (index_menu+1)%8;
                if(index_menu == 0) index_menu = 1;
                SetTimer1_ms(50000);
                key_code[0] = 0;
            }
            // if dont do anything after 5s
            if(flag_timer1 == 1) {
                index_sensor = 0;
                SetTimer1_ms(100);
                status = INIT;
            }
            display_Menu();
            break;
        case MODE_2: // display detail sensor
            LcdClearS();
            display_menu_detail_sensor_val();               
            // increase index option
            if(key_code[0]>=5 && key_code[0]%2==1) {
                index_sensor = (index_sensor+1)%7;
                numberOfPushButton = (numberOfPushButton+1)%8;
                if(numberOfPushButton == 0) numberOfPushButton = 1;
                key_code[0] = 0;
            }
            // choose option
            if(key_code[4]>=5 && key_code[4]%2==1 && index_sensor >= 0) {
                status = MODE_10;
                key_code[4] = 0;
            }
            // swtich to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_1;
                SetTimer1_ms(50000);
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            break;
        case MODE_3: // set threshold
            // increase index option
            if(key_code[0]>=5 && key_code[0]%2==1) {
                index_threshold = (index_threshold+1)%8;
                numberOfPushButton = (numberOfPushButton+1)%8;
                if(numberOfPushButton == 0) numberOfPushButton = 1;
                key_code[0] = 0;
            }
            // switch to enter input value
            if(key_code[4]>=5 && key_code[4]%2==1 && index_threshold >= 0) {
                option = THRESHOLD;
                status = MODE_9;
                key_code[4] = 0;
            }
            // swtich to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_1;
                SetTimer1_ms(50000);
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            display_Set_Threshold();
            break;
        case MODE_4: // set adc
            // increase index option
            if(key_code[0]>=5 && key_code[0]%2==1) {
                index_adc = (index_adc+1)%8;
                numberOfPushButton = (numberOfPushButton+1)%8;
                if(numberOfPushButton == 0) numberOfPushButton = 1;
                key_code[0] = 0;
            }
            // switch to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_1;
                SetTimer1_ms(50000);
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            //  switch to enter input value
            if(key_code[4]>=5 && key_code[4]%2==1 && index_adc >= 0) {
                option = ADC;
                status = MODE_9;
                key_code[5] = 0;
            }
            display_set_ADC();
            break;
        case MODE_5: // display_Alarm
            // switch to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_1;
                SetTimer1_ms(50000);
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            display_Alarm();
            break;
        case MODE_6: // display warning
            // switch to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_1;
                SetTimer1_ms(50000);
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            display_Warning();
            break;
        case MODE_7: // see time
            LcdClearS();
            Read_time();           
            // switch to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_1;
                SetTimer1_ms(50000);
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
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
        case MODE_8: // adjust time
            LcdClearS();
            adjustTime();
            // swtich to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_1;
                SetTimer1_ms(50000);
                index_menu = 0;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            break;    
        case MODE_9: // enter input value
            if(option == THRESHOLD) {
                display_input_val(option, index_threshold, cursor);
                //increase 
                if(key_code[5]>=5 && key_code[5]%2==1) {
                    if(cursor == 0) {
                        threshold[index_threshold]++;
                    }
                    if(cursor == 1) {
                        threshold_min[index_threshold]++;
                    }
                    key_code[5] = 0;
                }
                //decrease 
                if(key_code[6]>=5 && key_code[6]%2==1) {
                    if(cursor == 0)
                        threshold[index_threshold]--;
                    if(cursor == 1) 
                        threshold_min[index_threshold]--;
                    if(threshold[index_threshold] < 0) 
                        threshold[index_threshold] = 0;
                    if(threshold_min[index_threshold] < 0) 
                        threshold_min[index_threshold] = 0;
                    key_code[6] = 0;
                }
            }
            if(option == ADC) {
                display_input_val(option, index_adc, cursor);
                //increase 
                if(key_code[5]>=5 && key_code[5]%2==1) {
                    if(cursor == 0)
                        adc_max[index_adc]++;
                    if(cursor == 1) 
                        adc_min[index_adc]++;
                    key_code[5] = 0;
                }
                //decrease 
                if(key_code[6]>=5 && key_code[6]%2==1) {
                    if(cursor == 0)
                        adc_max[index_adc]--;
                    if(cursor == 1) 
                        adc_min[index_adc]--;
                    if(threshold[index_adc] < 0) 
                        adc_max[index_adc] = 0;
                    if(threshold_min[index_adc] < 0) 
                        adc_min[index_adc] = 0;
                    key_code[6] = 0;
                }
            }
            // change option max/min
            if(key_code[0]>=5 && key_code[0]%2==1) {
                cursor = (cursor+1)%2;
                key_code[0] = 0;
            }
            // save and switch to menu
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_1;
                SetTimer1_ms(50000);
                index_menu = 0;
                numberOfPushButton = 0;
                index_threshold = 0;
                index_adc = 0;
                cursor = 0;
                key_code[2] = 0;
            }
            break;
        case MODE_10: // display detail sensor value
            switch(index_sensor) {
                case 0:
                    display_detail_sensor_val(0,pH_value,pH_value_max,pH_value_min);
                    break;
                case 1:
                    display_detail_sensor_val(1,SS_value,SS_value_max,SS_value_min);
                    break;
                case 2:
                    display_detail_sensor_val(2,COD_value,COD_value_max,COD_value_min);
                    break;
                case 3:
                    display_detail_sensor_val(3,NH4_value,NH4_value_max,NH4_value_min);
                    break;
                case 4:
                    display_detail_sensor_val(4,NO3_value,NO3_value_max,NO3_value_min);
                    break;
                case 5:
                    display_detail_sensor_val(5,TMP_value,TMP_adc_max,TMP_value_min);
                    break;
                case 6:
                    display_detail_sensor_val(6,FLOW_value,FLOW_value_max,FLOW_value_min);
                    break;
                default:
                    break;
            }
            if(key_code[2]>=5 && key_code[2]%2==1) {
                status = MODE_2;
                index_sensor = -1;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            break;
        default: 
            status = INIT;
            break;
    }
}