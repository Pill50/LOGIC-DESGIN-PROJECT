#ifndef SYSTEM_H
#define	SYSTEM_H
#include <p18f4620.h>

#define     ON      1
#define     OFF     0

// Noi khai bao bien toan cuc
extern unsigned char arrayMapOfOutput [8];
extern unsigned char statusOutput[8];
// Khai bao cac ham co ban IO
void init_system(void);
void delay_ms(int value);
void OpenOutput(int index);
void CloseOutput(int index);
void TestOutput(void);
void ReverseOutput(int index);

#endif	/* SYSTEM_H */

