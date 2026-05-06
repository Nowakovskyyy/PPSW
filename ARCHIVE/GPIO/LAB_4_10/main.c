#include <LPC21xx.H>

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

int iDelayCounter;


void Delay(iDelayCounter){
	volatile int i;
	for(i = 0; i < (3158*iDelayCounter); i++);
	{
	}
}

int main(){

	IO1DIR = 0x00010000;
	
	while(1){
		IO1SET = LED3_bm;
		Delay(50);
		IO1CLR = LED3_bm;
		Delay(50);
	}	
}