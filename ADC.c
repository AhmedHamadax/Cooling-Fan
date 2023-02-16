/*
 * ADC.c
 *
 * Created: 2/5/2023 7:12:32 PM
 *  Author: Ahmed
 */ 
#include "ADC.h"
void ADC_init(void){
	
	
	SETBIT(ADMUX,REFS0); //VCC
	SETBIT(ADCSRA,ADPS1); SETBIT(ADCSRA,ADPS0); //4 prescaler
	SETBIT(ADCSRA,ADEN); // enable
	
	
	
	
	
}
uint16_t ADC_Read(uint8_t ch){
	ADMUX|=ch;  //Selects channel 
	
	SETBIT(ADCSRA,ADSC);// Start conv
	while(READBIT(ADCSRA,ADSC)>0);
	
	return ADC;
	
}