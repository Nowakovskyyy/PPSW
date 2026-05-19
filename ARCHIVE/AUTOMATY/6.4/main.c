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

	unsigned char ucStepCounter = 0;
	
	LedInit(); 
	KeyboardInit();
	
	while(1){
		Delay(250);
		
		switch(eLedState) {
			case IDLE:
					if (eKeyboardRead() == BUTTON_0) {
						eLedState = LED_STEP;
						ucStepCounter = 0;
					} else {
						eLedState = IDLE;
					}
				break;
			case LED_STEP:
				if (ucStepCounter == 3) {
					eLedState = IDLE;
				} else {
					LedStepRight();
					ucStepCounter++;
					eLedState = LED_STEP;
				}
				break;
		}
	} 
}
