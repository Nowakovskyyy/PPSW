#include "led.h"
#include "timer_interrupts.h"
/**********************************************/
int main (){
	LedInit();
	
	Timer0Interrupts_Init(250000, &LedStepLeft);

	while(1){
	 	
	}
}
