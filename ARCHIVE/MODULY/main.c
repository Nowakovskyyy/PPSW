#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 12000 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
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
