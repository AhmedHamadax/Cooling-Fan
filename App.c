/*
 * App.c
 *
 * Created: 2/5/2023 7:44:41 PM
 *  Author: Ahmed
 */ 
#include "ADC.h"
#include "lcd.h"
#include "PWM.h"
void main(void){
	
	LCD_INIT();
	ADC_init();
	PWM_init();
	while(1){
		
		LCD_write_command(0x80);
		LCD_write_command(0x01);
		LCD_write_string("Duty Cycle:");
		LCD_write_number(ADC_Read(7)/10.23); LCD_write_char('%');
		_delay_ms(1);
		if(ADC_Read(7)<25){  // Because the motor can't rotate at very low speeds and it need a quick push
			uint8_t x= ADC_Read(7);
			PWM_read(  ( 70)  ); // I used the 70% Duty Cycle as a push for the motor
			_delay_ms(10);
			PWM_read(x);
			_delay_ms(10);
	
		}
		else{
			PWM_read(  ( ADC_Read(7) )/11  ); // Duty Cycle will be assigned according to the ADC Reading
		}
		_delay_ms(10);
		
		
	}
	
}