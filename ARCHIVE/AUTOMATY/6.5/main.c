#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

enum LedState {IDLE, LED_STEP};
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
		Delay(250);
		
		switch(eLedState) {
			case IDLE:
					if (eKeyboardRead() == BUTTON_1) {
						eLedState = LED_STEP;
					} else {
						eLedState = IDLE;
					}
				break;
			case LED_STEP:
				if (eKeyboardRead() == BUTTON_0) {
					eLedState = IDLE;
				} else {
					LedStepRight();
					eLedState = LED_STEP;
				}
				break;
		}
	} 
}
