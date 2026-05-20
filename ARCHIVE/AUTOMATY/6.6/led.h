#ifndef LED_H
#define LED_H

void LedInit(void);
void LedStepLeft(void);
void LedStepRight(void);
void LedOn(unsigned char);

unsigned char ucGetCurrentIndeks(void);

#endif
