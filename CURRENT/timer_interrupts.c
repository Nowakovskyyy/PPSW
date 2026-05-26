#include <LPC21xx.H>
#include "timer_interrupts.h"


#define COUNTER_ENABLE_bm 0x00000001
#define COUNTER_RESET_bm  0x00000002
#define INTERRUPT_ON_MR0_bm 0x00000001
#define RESET_ON_MR0_bm     0x00000002
#define MR0_INTERRUPT_bm    0x00000001
#define VIC_TIMER0_CHANNEL_NR 4
#define IRQ_SLOT_ENABLE_bm 0x00000020

void (*ptrTimer0InterruptFunction)(void);

__irq void Timer0IRQHandler(){

	T0IR=MR0_INTERRUPT_bm; 	// skasowanie flagi przerwania 
	(*ptrTimer0InterruptFunction)();	// cos do roboty
	VICVectAddr=0x00; 	// potwierdzenie wykonania procedury obslugi przerwania
}

void Timer0Interrupts_Init(unsigned int uiPeriod, void (*ptrInterruptFunction)(void)){ // microseconds

        // interrupts

	ptrTimer0InterruptFunction = ptrInterruptFunction;
	
	VICIntEnable |= (0x1 << VIC_TIMER0_CHANNEL_NR);            // Enable Timer 0 interrupt channel 
	VICVectCntl1  = IRQ_SLOT_ENABLE_bm | VIC_TIMER0_CHANNEL_NR;  // Enable Slot 0 and assign it to Timer 0 interrupt channel
	VICVectAddr1  =(unsigned long)Timer0IRQHandler; 	   // Set to Slot 0 Address of Interrupt Service Routine 

        // match module

	T0MR0 = 15 * uiPeriod;                 	      // value 
	T0MCR |= (INTERRUPT_ON_MR0_bm | RESET_ON_MR0_bm); // action 

        // timer

	T0TCR |=  COUNTER_ENABLE_bm; // start 

}
