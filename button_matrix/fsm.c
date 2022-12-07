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
            display_Time();
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_2;
                key_code[2] = 0;
            }
            if((key_code[3] >= 10 && key_code[3]%2 == 1)) {
                status = MODE_6;
                key_code[3] = 0;
            }
            break;
        case MODE_2: // display menu
            if((key_code[1] >= 10 && key_code[1]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_1;
                key_code[1] = 0;
            }
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_3;
                key_code[2] = 0;
            }
            if((key_code[3] >= 10 && key_code[3]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_4;
                key_code[3] = 0;
            }
            if((key_code[4] >= 10 && key_code[4]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_5;
                key_code[4] = 0;
            }
            if((key_code[5] >= 10 && key_code[5]%2 == 1)) {
                numberOfPushButton = 0;
                status = MODE_6;
                key_code[4] = 0;
            }
            if((key_code[0] >= 10 && key_code[0]%2 == 1)) {
                numberOfPushButton = (numberOfPushButton+1)%4;
                if(numberOfPushButton == 0) numberOfPushButton = 1;
                key_code[0] = 0;
            }
            display_Menu();
            break;
        case MODE_3: // set threshold
            if((key_code[0] >= 10 && key_code[0]%2 == 1)) {
                numberOfPushButton = (numberOfPushButton+1)%8;
                if(numberOfPushButton == 0) numberOfPushButton = 1;
                key_code[0] = 0;
            }
            if((key_code[1] >= 10 && key_code[1]%2 == 1)) {
                status = MODE_4;
                key_code[1] = 0;
            }
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                status = MODE_2;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            display_Set_Threshold();
            break;
        case MODE_4: // nhap threshold value
            display_input_val();
            if((key_code[1] >= 10 && key_code[1]%2 == 1)) {
                inputThreshold++;
                key_code[1] = 0;
            }
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                //SAVE
                threshold[numberOfPushButton-1] = inputThreshold;
                status = MODE_3;
                key_code[2] = 0;
            }
            break;
        case MODE_5: // display alarm
            display_Alarm();
            if((key_code[2] >= 10 && key_code[2]%2 == 1)) {
                status = MODE_2;
                numberOfPushButton = 0;
                key_code[2] = 0;
            }
            break;
        case MODE_6:
            adjustTime();
            if((key_code[3] >= 10 && key_code[3]%2 == 1)) {
                status = MODE_2;
                numberOfPushButton = 0;
                key_code[3] = 0;
            }
            break;
    }
}