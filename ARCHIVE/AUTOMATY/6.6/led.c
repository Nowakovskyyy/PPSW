#include <LPC21xx.H>
#include "led.h"

#define LED0_bm (1 << 16)
#define LED1_bm (1 << 17)
#define LED2_bm (1 << 18)
#define LED3_bm (1 << 19)

enum eStepDir {RIGHT, LEFT};

void LedInit(void) {
	IO1DIR |= LED0_bm | LED1_bm | LED2_bm | LED3_bm ;
}

void LedOn(unsigned char ucLedIndeks) {
	
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	
	switch(ucLedIndeks){
		case 0:
			IO1SET = LED0_bm;
			break;
		case 1:
			IO1SET = LED1_bm;
			break;
		case 2:
			IO1SET = LED2_bm;
			break;
		case 3:
			IO1SET = LED3_bm;
			break;
		case 4:
			IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
		default:
			break;
	}
}
unsigned char ucLedIndeks = 0;

void LedStep(enum eStepDir Step){
	
	if(Step == RIGHT) {
		ucLedIndeks ++;
	} else if (Step== LEFT) {
		ucLedIndeks --;
	}
	LedOn(ucLedIndeks % 4);
}

void LedStepLeft(void) {
	LedStep(LEFT);
}

void LedStepRight(void) {
	LedStep(RIGHT);
}

unsigned char ucGetCurrentIndeks(void) {
	return (unsigned char)(ucLedIndeks%4);
}
