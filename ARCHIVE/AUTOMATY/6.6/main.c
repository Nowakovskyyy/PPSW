#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

enum LedState {IDLE, STEP_RIGHT, STEP_LEFT};
enum LedState eLedState = IDLE;

void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 12000 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}

int main() {
	
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
		}
	} 
}
