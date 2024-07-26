#ifndef ADC_FUNC.h
#define ADC_FUNC.h
#include "ADC_CONFIGURTAION.h"
void			ADC_INIT(uint_8 CHANNEL);
uint_16			ADC_READ(void);
void			ADC_INTERRUPT_EN(void);
void			ADC_INTERRUPT_DIS(void);
void			ADC_AUTO_TRIG_CONTROL(uint_8 MODE);
void			ADC_INIT_DIFFERENCTIAL_MODE(void);
#endif