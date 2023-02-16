/*
 * lcdApp.c
 *
 * Created: 11/14/2022 1:17:19 AM
 *  Author: LOGO
 */ 
#include "lcd.h"


void LCD_INIT(void){
	INIT_LCD_PINS();
	LCD_write_command(0x3);
	_delay_ms(100);
	LCD_write_command(0x3);
	_delay_ms(100);
	LCD_write_command(0x3);
	_delay_ms(100);
	
	LCD_write_command(0x2);
	LCD_write_command(0x28);
	LCD_write_command(0x1);
	LCD_write_command(0x06);
	LCD_write_command(0xC);
	_delay_ms(200);	
}


void LCD_write_char(uint8_t data){
	RS_lcd(1);
	D7( READBIT(data,7) );
	D6( READBIT(data,6) );
	D5( READBIT(data,5) );
	D4( READBIT(data,4) );
	EN_LCD(1);
	_delay_ms(10);
	EN_LCD(0);
	_delay_ms(10);
	D7( READBIT(data,3) );
	D6( READBIT(data,2) );
	D5( READBIT(data,1) );
	D4( READBIT(data,0) );
	_delay_ms(10);
	EN_LCD(1);
	_delay_ms(10);
	EN_LCD(0);
	
	
	
	
}


void LCD_write_command(uint32_t cmd){
		RS_lcd(0);
		D7( READBIT(cmd,7) );
		D6( READBIT(cmd,6) );
		D5( READBIT(cmd,5) );
		D4( READBIT(cmd,4) );
		EN_LCD(1);
		_delay_ms(10);
		EN_LCD(0);
		_delay_ms(10);
		D7( READBIT(cmd,3) );
		D6( READBIT(cmd,2) );
		D5( READBIT(cmd,1) );
		D4( READBIT(cmd,0) );
		_delay_ms(10);
		EN_LCD(1);
		_delay_ms(10);
		EN_LCD(0);
		
		
		
	
	
	
}
	uint8_t a,y,num;

void LCD_write_string(uint8_t * p_data){
	
	for(a=0;p_data[a]!='\0'; a++);
	
	y=0;
	while(y<a){
		RS_lcd(1);
		D7( READBIT( (*p_data),7) );
		D6( READBIT( (*p_data),6) );
		D5( READBIT( (*p_data),5) );
		D4( READBIT( (*p_data),4) );
		EN_LCD(1);
		_delay_ms(10);
		EN_LCD(0);
		_delay_ms(10);
		D7( READBIT(  (*p_data),3) );
		D6( READBIT(  (*p_data),2) );
		D5( READBIT(  (*p_data),1) );
		D4( READBIT(  (*p_data),0) );
		_delay_ms(10);
		EN_LCD(1);
		_delay_ms(10);
		EN_LCD(0);
		p_data++;
		y++;
		
	}
}

void LCD_write_number(uint32_t num){
	int8_t i = 0;
	uint8_t num_arr[10];
	
	if(num == 0) {
		LCD_write_char('0');
		return;
	}
	
	for(i = 0; num != 0 ;i++){ // 6,5,2,1
		num_arr[i] = num % 10 + '0';
		num /= 10;
	}
	i--;
	while (i >= 0){
		LCD_write_char(num_arr[i]);
		i--;
	}
}



