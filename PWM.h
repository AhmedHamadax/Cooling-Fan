/*
 * PWM.h
 *
 * Created: 2/1/2023 9:38:57 PM
 *  Author: Ahmed
 */ 


#ifndef PWM_H_
#define PWM_H_
#include "std_macro.h"

void PWM_init(void );
void PWM_read(uint8_t);
uint16_t PWM_calc(void );



#endif /* PWM_H_ */