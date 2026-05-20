#include "led.h" //stoworzony plik naglowkowy z deklaracjami funkcji do wlaczenia i sterowania ledami
#include "keyboard.h" //plik naglowkowy z deklaracjiami funckji do wlaczenia i odczuty, zawiera typ enum zawierajacy stan klawiatury

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
