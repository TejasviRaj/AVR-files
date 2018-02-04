#include "lcd.h"


void lcd_clear(void)
{
	CPORT &= ~(1 << RS);
	lcd_write(1<<LCD_CLR);
	_delay_ms(2);
}

void lcd_goto(unsigned char pos)
{
	CPORT &= ~(1 << RS);
	lcd_write(0x80|pos);
}


void lcd_gotoxy( unsigned char x, unsigned char y )
{
	lcd_goto( y*64+x );
}

void lcd_init()
{
	DDR(CPORT) |= (1 << RS);
	DDR(CPORT) |= (1 << EN);
	
	DDR(DPORT) |= (1 << D7);
	DDR(DPORT) |= (1 << D6);
	DDR(DPORT) |= (1 << D5);
	DDR(DPORT) |= (1 << D4);
	
	CPORT &= ~(1 << RS);
	CPORT &= ~(1 << EN);
	
	_delay_ms(15);

	DPORT |= (1 << D4);
	DPORT |= (1 << D5);
	DPORT &= ~(1 << D6);
	DPORT &= ~(1 << D7);
	
	LCD_STROBE();
	_delay_ms(5);
	LCD_STROBE();
	_delay_us(200);
	LCD_STROBE();
	_delay_us(200);
	
	
	DPORT &= ~(1 << D4);
	DPORT |=  (1 << D5);
	DPORT &= ~(1 << D6);
	DPORT &= ~(1 << D7);
	
	LCD_STROBE();

	lcd_write(0x28);
	lcd_write(0b00001100);
	lcd_clear();
	lcd_write(0x6);
}

void lcd_puts(const char * s)
{
	CPORT|= (1 << RS);
	while(*s)
	lcd_write(*s++);
}

void lcd_putc(char x)
{
	CPORT|= (1 << RS);
	lcd_write(x);
}

void lcd_num(int in)
{
	int c;
	char temp[100];
	int index=0;
	do
	{
		c=in%10;
		in=in/10;
		temp[index]=c+'0';
		index++;
	}
	while (in!=0);
	for (int i=index-1;i>=0;i--)
	{
		lcd_putc(temp[i]);
	}
}











