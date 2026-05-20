#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_ENABLE_bm (1 << 0)
#define COUNTER_RESET_bm 	(1 << 1)

#define INTERUPT_ON_MR0_bm 	(1 << 0)
#define RESET_ON_MR0_bm 		(1 << 1)

#define MR0_INTERRUPT_FLAG_bm (1 << 0)

void InitTimer0(void) {
	T0TCR |= COUNTER_ENABLE_bm; //wlaczenie Timer Counter
}

void WaitOnTimer0(unsigned int uiTime) {
	
	unsigned int uiTimeInuS = uiTime * 15;
	
	T0TCR |= COUNTER_RESET_bm; //Resetowanie Timer Counter
	T0TCR &= ~COUNTER_RESET_bm;//Wylaczenie resetu Timer Counter, musimy usunac jedynke
	
	while(T0TC != uiTimeInuS) {} //w wiekszosci przypadkow bedzie dzialac, ale zegar TC jest realizowany sprzetowo, a while zlicza przy zegarze procesora. Mozemy przegapic szukana wartosc, 
		// blokujac sie do momentu przepelnienia TC i doliczenia spowrotem do szukanej wartosci, poniewaz porcesor moze byc zajety np. obsluga innego przerwania
	
}

void InitTimer0Match0(unsigned int uiDelayTime) {
	
	unsigned int uiTimeInuS = uiDelayTime * 15;
	
	T0MR0 = uiTimeInuS;// wpisanie wartosci do porownywania do Match Register 0
	
	T0MCR |= INTERUPT_ON_MR0_bm | RESET_ON_MR0_bm;
	// wlaczenie przerwania od MR0, wlacznenie
	//resetowania Timer Counter gdy zrówna sie z wartoscia w MR0
	
	T0TCR |= COUNTER_RESET_bm; //reset jak w WaitOntimer
	T0TCR &= ~COUNTER_RESET_bm;// -||-
	
	T0TCR |= COUNTER_ENABLE_bm;// wlaczenie timer counter
}

void WaitOnTimer0Match0(void) {
	while((T0IR & MR0_INTERRUPT_FLAG_bm) == 0) {}
		
	T0IR = MR0_INTERRUPT_FLAG_bm;//resetowanie flagi przerwania od MR0, odbywa sie prze wpisanie 1 na bit0.
}

