#include "led.h"
#include "keyboard.h"

enum LedState {IDLE, STEP_RIGHT, STEP_LEFT, PULSE, WAIT_STATE};
enum LedState eLedState = IDLE;

void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 12000 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}

int main() {
	
	unsigned char ucPulseCounter =0;
	unsigned char ucPulseNumber = 8;
	unsigned char ucCurrentIndeks;
	LedInit(); 
	KeyboardInit();
	
	while(1){
		Delay(100);
		
		switch(eLedState) {
			case IDLE:
					if (eKeyboardRead() == BUTTON_0) {
						eLedState = STEP_LEFT;
					} else if(eKeyboardRead() == BUTTON_2) {
						eLedState = STEP_RIGHT;
					}else if(eKeyboardRead() == BUTTON_3) {
						ucCurrentIndeks = ucGetCurrentIndeks();
						ucPulseCounter = 0;
						eLedState = PULSE;
					} else {
						eLedState = IDLE;
					}
				break;
			case STEP_LEFT:
				if (eKeyboardRead() == BUTTON_1) {
					eLedState = IDLE;
				} else {
					LedStepLeft();
					eLedState = STEP_LEFT;
				}
				break;
			case STEP_RIGHT:
				if (eKeyboardRead() == BUTTON_1) {
					eLedState = IDLE;
				} else {
					LedStepRight();
					eLedState = STEP_RIGHT;
				}
				break;
			case PULSE:
				if(ucPulseCounter < ucPulseNumber*2) {
					ucPulseCounter++;
					if(ucPulseCounter%2 == 0) {
						LedOn(ucCurrentIndeks);
					} else {
						LedOn(4);
					}
					eLedState = PULSE;
				} else {
					eLedState = WAIT_STATE;
				}
				break;
			case WAIT_STATE:
				if(eKeyboardRead() == BUTTON_3) {
					eLedState = IDLE;
				} else {
					eLedState = WAIT_STATE;
				}
				break;
		}
	} 
}
