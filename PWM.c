/*
 * PWM.c
 *
 * Created: 2/1/2023 9:38:43 PM
 *  Author: Ahmed
 */ 
#include "PWM.h"
#include "lcd.h"


void PWM_init(void ){
	SETBIT(DDRD,PD5);
	TCCR1A&=0b0;
	TCCR1B&=0b0;
	
	SETBIT(TCCR1A,COM1A1); //non inverting mode 
	CLRBIT(TCCR1A,FOC1A);CLRBIT(TCCR1A,FOC1B);
	SETBIT(TCCR1A,WGM10); SETBIT(TCCR1A,WGM11); SETBIT(TCCR1B,WGM12);
	SETBIT(TCCR1B,CS10); //no prescaling 
	
	
	
	
}

void PWM_read(uint8_t D_cycle){    //   ocra1=512=(x/100)*1024
	
	OCR1A=D_cycle*10.23;
	
	
}

uint16_t PWM_calc(void ){   //16mhz-->1/16us--> 64us
	 uint16_t count1=0,count2=0,T;
	 
	TCNT1=0;
	SETBIT(TIFR,TOV1);
	SETBIT(TCCR1B,ICES1);//rise edge c
	SETBIT(TIFR,ICF1); //setting flag to 0 
	while(READBIT(TIFR,ICF1)<1);
	
	count1=ICR1;
	SETBIT(TIFR,ICF1);
	while(READBIT(TIFR,ICF1)<1);
	if(READBIT(TIFR,TOV1)==1){ count2=1023; LCD_write_char('A'); }
	count2+=ICR1;
	SETBIT(TIFR,TOV1);
	
	
	T=(count2-count1)/16;// 512* (1/16)*us
	return T;
}