#include <LPC21xx.H>
#include "led.h"

enum LedState {STEP_LEFT, STEP_RIGHT};
enum LedState eLedState = STEP_RIGHT;

void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 12000 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}

int main() {

	unsigned char ucStepCounter = 0;
	
	LedInit(); 
	
	while(1){
		Delay(250);
		
		switch(eLedState) {
			case STEP_RIGHT:
				ucStepCounter++;
				LedStepRight();
			
				if (ucStepCounter == 3) {
					eLedState = STEP_LEFT;
					ucStepCounter = 0;
				}
				break;
			case STEP_LEFT:
				ucStepCounter++;
				LedStepLeft();
			
				if (ucStepCounter == 3) {
					eLedState = STEP_RIGHT;
					ucStepCounter = 0;
				}
				break;
		}
	} 
}
