/*
 * lcdHeader.h
 *
 * Created: 11/14/2022 1:17:37 AM
 *  Author: LOGO
 */ 


#ifndef LCDHEAD_H_
#define LCDHEAD_H_
#include "std_macro.h"

#define INIT_LCD_PINS()  DDRA |= 0b01111110; 

#define RS_lcd(x) if(x==1) SETBIT(PORTA,1) ; else CLRBIT(PORTA,1);

#define EN_LCD(x) if(x==1) SETBIT(PORTA,2) ; else CLRBIT(PORTA,2);

#define D7(x) if(x==1) SETBIT(PORTA,6) ; else CLRBIT(PORTA,6);
#define D6(x) if(x==1) SETBIT(PORTA,5) ; else CLRBIT(PORTA,5);
#define D5(x) if(x==1) SETBIT(PORTA,4) ; else CLRBIT(PORTA,4);
#define D4(x) if(x==1) SETBIT(PORTA,3) ; else CLRBIT(PORTA,3);



void LCD_write_char(uint8_t);
void LCD_write_string(uint8_t *);
void LCD_write_command(uint32_t);
void LCD_write_number(uint32_t num);
void LCD_INIT(void);



#endif /* LCDHEADER_H_ */