#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
/**********************************************/

enum LedState{IDLE, STEP_LEFT, STEP_RIGHT};

void Automat(void) {
	
	static enum LedState eLedState;
	
		switch(eLedState) {
        case IDLE:
            if (eKeyboardRead() == BUTTON_0) {
                eLedState = STEP_LEFT;
            } else if (eKeyboardRead() == BUTTON_2) {
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
int main (){
	LedInit(); 
	KeyboardInit();
	
	Timer0Interrupts_Init(20000, &Automat);

	while(1){
	 	
	}
}
