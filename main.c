#include <xc.h>
#include "config.h" 
#include "lcd.h"
#define _XTAL_FREQ 4000000

void main(void){
	lcd_init();
	lcd_clear();
	lcd_set_cursor(1,1);
	lcd_string("Hello world\0");
	lcd_set_cursor(2,3);
	lcd_string("AKM\0");
	while(1){
	}
}