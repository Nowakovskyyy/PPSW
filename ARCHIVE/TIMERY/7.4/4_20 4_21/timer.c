#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_ENABLE_bm (1 << 0)
#define COUNTER_RESET_bm 	(1 << 1)

#define INTERUPT_ON_MR0_bm 	(1 << 0)
#define RESET_ON_MR0_bm 		(1 << 1)

#define MR0_INTERRUPT_FLAG_bm (1 << 0)

void InitTimer0(void) {
	T0TCR |= COUNTER_ENABLE_bm;
}

void WaitOnTimer0(unsigned int uiTime) {
	
	unsigned int uiTimeInuS = uiTime * 15;
	
	T0TCR |= COUNTER_RESET_bm;
	T0TCR &= ~COUNTER_RESET_bm;
	
	while(T0TC < uiTimeInuS) {}
	
}

void InitTimer0Match0(unsigned int uiDelayTime) {
	
	unsigned int uiTimeInuS = uiDelayTime * 15;
	
	T0MR0 = uiTimeInuS;
	
	T0MCR |= (INTERUPT_ON_MR0_bm | RESET_ON_MR0_bm);
	
	T0TCR |= COUNTER_RESET_bm;
	T0TCR &= ~COUNTER_RESET_bm;
	
	T0TCR |= COUNTER_ENABLE_bm;
}

void WaitOnTimer0Match0(void) {
	while((T0IR & MR0_INTERRUPT_FLAG_bm) == 0) {}
		
	T0IR = MR0_INTERRUPT_FLAG_bm;
}

