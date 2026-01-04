#include <xc.h>
#include <stdio.h>

#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF

#define _XTAL_FREQ 20000000

#define SW1 RB0   // Door status
#define SW4 RB1   // Menu select
#define SW5 RB2   // Power / Start
#define SW6 RB3   // Pause / Stop

void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_print(char *);

void main()
{
    TRISB = 0x0F;   // RB0-RB3 as input
    TRISD = 0x00;   // LCD output

    lcd_init();

    // Power ON Screen
    lcd_print("Press SW5");
    lcd_cmd(0xC0);
    lcd_print("Power ON");
    while(SW5);

    lcd_cmd(0x01);
    lcd_print("Powering ON");
    __delay_ms(1500);

    // Program Selection
    lcd_cmd(0x01);
    lcd_print("Program:");
    lcd_cmd(0xC0);
    lcd_print("Heavy");
    while(SW4);

    // Water Level Selection
    lcd_cmd(0x01);
    lcd_print("Water Level:");
    lcd_cmd(0xC0);
    lcd_print("Medium");
    while(SW4);

    // Start Screen
    lcd_cmd(0x01);
    lcd_print("SW5:START");
    lcd_cmd(0xC0);
    lcd_print("SW6:STOP");
    while(SW5);

    // Washing Screen
    lcd_cmd(0x01);
    lcd_print("WASH MODE");
    lcd_cmd(0xC0);
    lcd_print("TIME: 00:50");

    // Door Safety
    if(SW1 == 0)
    {
        lcd_cmd(0x01);
        lcd_print("DOOR OPEN");
        lcd_cmd(0xC0);
        lcd_print("Please Close");
        while(SW1 == 0);
    }

    __delay_ms(3000);

    // Completion
    lcd_cmd(0x01);
    lcd_print("Program Done");
    lcd_cmd(0xC0);
    lcd_print("Remove Clothes");

    while(1);
}
