#include <LPC21xx.H>
#include "led.h"

enum LedState {STATE0, STATE1, STATE2, STATE3, STATE4, STATE5};
enum LedState eLedState = STATE0;

void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 12000 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}

int main() {

	LedInit(); 
	
	while(1){
		Delay(250);
		
		switch(eLedState) {
			case STATE0:
				LedStepRight();
				eLedState = STATE1;
				break;
			case STATE1:
				LedStepRight();
				eLedState = STATE2;
				break;
			case STATE2:
				LedStepRight();
				eLedState = STATE3;
				break;
			case STATE3:
				LedStepLeft();
				eLedState = STATE4;
				break;
			case STATE4:
				LedStepLeft();
				eLedState = STATE5;
				break;
			case STATE5:
				LedStepLeft();
				eLedState = STATE0;
				break;
		}
	} 
}
