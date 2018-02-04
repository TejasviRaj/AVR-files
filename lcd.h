

#ifndef LCD_H
#define LCD_H

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define CPORT PORTA
#define RS 7
#define EN 6


#define DPORT PORTA
#define D7	2
#define DPORT PORTA
#define D6	3
#define DPORT PORTA
#define D5	4
#define DPORT PORTA
#define D4	5

#include<avr/io.h>
#include <util/delay.h>


#define DDR(x) (*(&x - 1))      


#define LCD_CLR 0                  
#define	LCD_STROBE()	((CPORT |= (1 << EN)),(CPORT &= ~(1 << EN)))
static void lcd_write(uint8_t c)
{
	_delay_us(40);

	if(c & 0x80)
	DPORT |=  (1 << D7);
	else
	DPORT &= ~(1 << D7);
	
	if(c & 0x40)
	DPORT |=  (1 << D6);
	else
	DPORT &= ~(1 << D6);
	
	if(c & 0x20)
	DPORT |=  (1 << D5);
	else
	DPORT &= ~(1 << D5);
	
	if(c & 0x10)
	DPORT |=  (1 << D4);
	else
	DPORT &= ~(1 << D4);
	
	LCD_STROBE();
	
	

	if(c & 0x08)
	
	DPORT |=  (1 << D7);
	else
	DPORT &= ~(1 << D7);
	
	if(c & 0x04)
	DPORT |=  (1 << D6);
	else
	DPORT &= ~(1 << D6);
	
	if(c & 0x02)
	DPORT |=  (1 << D5);
	else
	DPORT &= ~(1 << D5);
	
	if(c & 0x01)
	DPORT |=  (1 << D4);
	else
	DPORT &= ~(1 << D4);
	
	LCD_STROBE();
}

void lcd_clear(void);
void lcd_goto(unsigned char pos);
void lcd_gotoxy( unsigned char x, unsigned char y );
void lcd_init();
void lcd_puts(const char * s);
void lcd_putc(char x);
void lcd_num(int in);


#endif









