#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 4000000

#define D4 RC0
#define D5 RC1
#define D6 RC2
#define D7 RC3
#define RS_D TRISC5
#define EN_D TRISC4
#define RS RC5
#define EN RC4 
#define en_delay 500

void lcd_data(unsigned char);
void lcd_cmd(unsigned char);
void lcd_init(void);
void lcd_clear(void);
void lcd_set_cursor(unsigned char,unsigned char);
void lcd_write(unsigned char);
void lcd_string(char*);
void lcd_SR(void);
void lcd_SL(void); 

/*
void lcd_data(unsigned char data){
	if(D4 & 1)
		D4 = 1;
	else
		D4 = 0;
	if(D5 & 2)
		D5 = 1;
	else 
		D5 = 0;
	if(D6 & 3)
		D6 = 1;
	else 
		D6 = 0;
	if(D7 & 1)
		D7 = 1;
	else 
		D7 = 0;
}
void lcd_cmd(unsigned char cmd){
	RS = 0;
	lcd_data(cmd);
	EN = 1;
	__delay_us(en_delay);
	EN = 0;
}
void lcd_init(void){
	TRISC = 0x00;
	lcd_data(0x00);
	__delay_ms(15);
	lcd_cmd(0x03);
	__delay_ms(5);
	lcd_cmd(0x03);
	__delay_us(150);
	lcd_cmd(0x03);
	lcd_cmd(0x02);
	lcd_cmd(0x02);
	lcd_cmd(0x08);
	lcd_cmd(0x00);
	lcd_cmd(0x08);
	lcd_cmd(0x00);
	lcd_cmd(0x01);   // Khaled Magdy set it as 0x0C unlike datasheet why ??? don't know.
	lcd_cmd(0x00);
	lcd_cmd(0x06);
}

void lcd_clear(void){
	lcd_cmd(0);
	lcd_cmd(1);
}

void lcd_set_cursor(unsigned char row,unsigned char c){
	unsigned char high4,low4,temp;
	if(row == 1){
		temp = 0x80 + c - 1;
		high4 = temp >> 4;
		low4 = temp & 0x0F;
		lcd_cmd(high4);
		lcd_cmd(low4);
		__delay_us(37);
	}
	if(row == 2){
		temp = 0xC0 + c - 1;
		high4 = temp >> 4;
		low4 = temp & 0x0F;
		lcd_cmd(high4);
		lcd_cmd(low4);
		__delay_us(37);
	}
}

void lcd_write(unsigned char data){
	unsigned char high4,low4; // In order to not spoil the data
	high4 = data & 0xF0;
	low4 = data & 0xF0;
	RS = 1;
	lcd_data(high4 >> 4);
	EN = 1;
	__delay_us(en_delay);
	EN = 0;
	__delay_us(en_delay);
	lcd_data(low4);
	EN = 1;
	__delay_us(en_delay);
	EN = 0;
	__delay_us(en_delay);
}

void lcd_string(char *str){
	for(int i= 0; str[i]!='\0' ; i++){
		lcd_write(str[i]);
	}
}

/*** Move entire display to the right ===> send (0x1C) command 
void lcd_SR(void){
	lcd_cmd(0x01);
	lcd_cmd(0x0C);
}

/*** Move entire display to the left ===> send (0x18) command 
void lcd_SL(void){
	lcd_cmd(0x01);
	lcd_cmd(0x08);
}**/

void lcd_data(unsigned char data){
	if(D4 & 1)
		D4 = 1;
	else
		D4 = 0;
	if(D5 & 2)
		D5 = 1;
	else 
		D5 = 0;
	if(D6 & 3)
		D6 = 1;
	else 
		D6 = 0;
	if(D7 & 1)
		D7 = 1;
	else 
		D7 = 0;
}
void lcd_cmd(unsigned char cmd){
	RS = 0;
	lcd_data(cmd);
	EN = 1;
	__delay_us(en_delay);
	EN = 0;
}
void lcd_init(void){
	TRISC = 0x00;
	lcd_data(0x00);
	__delay_ms(30);
	lcd_cmd(0x03);
	__delay_ms(5);
	lcd_cmd(0x03);
	__delay_us(150);
	lcd_cmd(0x03);
	lcd_cmd(0x02);
	lcd_cmd(0x02);
	lcd_cmd(0x08);
	lcd_cmd(0x00);
	//lcd_cmd(0x08);      // Khaled Magday doesn't put it why I'don't know but maybe not work right
	//lcd_cmd(0x00);     // Khaled Magday doesn't put it why I'don't know but maybe not work right
	lcd_cmd(0x0C);   // Khaled Magdy set it as (0x0C) unlike datasheet(0x01) why ??? don't know.
	lcd_cmd(0x00);
	lcd_cmd(0x06);
}

void lcd_clear(void){
	lcd_cmd(0);
	lcd_cmd(1);
}

void lcd_set_cursor(unsigned char row,unsigned char c){
	unsigned char high4,low4,temp;
	if(row == 1){
		temp = 0x80 + c - 1;
		high4 = temp >> 4;
		low4 = temp & 0x0F;
		lcd_cmd(high4);
		lcd_cmd(low4);
		__delay_us(37);
	}
	if(row == 2){
		temp = 0xC0 + c - 1;
		high4 = temp >> 4;
		low4 = temp & 0x0F;
		lcd_cmd(high4);
		lcd_cmd(low4);
		__delay_us(37);
	}
}

void lcd_write(unsigned char data){
	unsigned char high4,low4; // In order to not spoil the data
	high4 = data & 0xF0;
	low4 = data & 0xF0;
	RS = 1;
	lcd_data(high4 >> 4);
	EN = 1;
	__delay_us(en_delay);
	EN = 0;
	__delay_us(en_delay);
	lcd_data(low4);
	EN = 1;
	__delay_us(en_delay);
	EN = 0;
	__delay_us(en_delay);
}

void lcd_string(char *str){
	for(int i= 0; str[i]!='\0' ; i++){
		lcd_write(str[i]);
	}
}

/*** Move entire display to the right ===> send (0x1C) command ***/
void lcd_SR(void){
	lcd_cmd(0x01);
	lcd_cmd(0x0C);
}

/*** Move entire display to the left ===> send (0x18) command ***/
void lcd_SL(void){
	lcd_cmd(0x01);
	lcd_cmd(0x08);
}