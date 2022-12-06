/* 
 * File:   clock.h
 * Author: DELL
 *
 * Created on December 5, 2022, 4:03 PM
 */

#ifndef CLOCK_H
#define	CLOCK_H

#include <p18f4620.h>
#include "i2c.h"

#define     ADDRESS_SECOND  0x00
#define     ADDRESS_MINUTE  0x01
#define     ADDRESS_HOUR    0x02
#define     ADDRESS_DAY     0x03
#define     ADDRESS_DATE    0x04
#define     ADDRESS_MONTH   0x05
#define     ADDRESS_YEAR    0x06

extern char second, minute, hour, day, date, month, year;
void Set_Time();
void Read_time();

#endif	/* CLOCK_H */

