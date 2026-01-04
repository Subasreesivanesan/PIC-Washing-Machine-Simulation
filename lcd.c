#include <xc.h>
#define _XTAL_FREQ 20000000

void lcd_cmd(unsigned char cmd)
{
    PORTD = cmd;
    RD2 = 0; RD3 = 0; RD4 = 1;
    __delay_ms(2);
    RD4 = 0;
}

void lcd_data(unsigned char data)
{
    PORTD = data;
    RD2 = 1; RD3 = 0; RD4 = 1;
    __delay_ms(2);
    RD4 = 0;
}

void lcd_print(char *str)
{
    while(*str)
        lcd_data(*str++);
}

void lcd_init()
{
    __delay_ms(20);
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
}
