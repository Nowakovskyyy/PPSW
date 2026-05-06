#include <LPC21xx.H>

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

#define BUT0_bm 0x00000010
#define BUT1_bm 0x00000040
#define BUT2_bm 0x00000020
#define BUT3_bm 0x00000080

int iDelayCounter;


void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 12000 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}

void LedInit() {
	IO1DIR |= LED0_bm | LED1_bm | LED2_bm | LED3_bm ;
}

void KeyboardInit() { 
	IO0DIR &= ~(BUT0_bm | BUT1_bm | BUT2_bm | BUT3_bm );
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
		default:
			break;
	}
}
enum eStepDir {RIGHT, LEFT};

void LedStep(enum eStepDir Step){
	
	static unsigned int uiLedIndeks = 0;
	
	if(Step == RIGHT) {
		uiLedIndeks ++;
	} else if (Step== LEFT) {
		uiLedIndeks --;
	}
	LedOn(uiLedIndeks % 4);
}

void LedStepLeft(void) {
	LedStep(LEFT);
}

void LedStepRight(void) {
	LedStep(RIGHT);
}


enum eKeyboardState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

enum eKeyboardState eKeyboardRead(){
	if ((IO0PIN & BUT0_bm) == 0) {
        return BUTTON_0;
    } else if ((IO0PIN & BUT1_bm) == 0) {
        return BUTTON_1;
    } else if ((IO0PIN & BUT2_bm) == 0) {
        return BUTTON_2;
    } else if ((IO0PIN & BUT3_bm) == 0) {
        return BUTTON_3;
    } else {
		return RELEASED;
	}
}
int main() {
  KeyboardInit();
	LedInit(); 
	
	while(1){
		Delay(250);
		
		switch(eKeyboardRead()) {
			case BUTTON_1:
				LedStepRight();
				break;
			case BUTTON_2:
				LedStepLeft();
				break;
			case RELEASED:
				break;
			default:
				break;
		}
	} 
}
