#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 

DigitalOut red(TRAF_RED1_PIN,1);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

LCD_16X2_DISPLAY lcd;


int main()
{
    while (true) 
    {
        green = 0;
        red = 1;
        amber = 0;
        lcd.puts("RED");
        wait_us(10000000);
        lcd.cls();

        for (int x = 0; x < 4; x++) {
            red = 0;
            amber = 1;
            lcd.puts("Yellow");
            wait_us(1000000);
            amber = 0;
            wait_us(1000000);
            lcd.cls();
        }


        green = 1;
        amber = 0;
        red = 0;
        lcd.cls();
        lcd.puts("Green");
        wait_us(2000000);
        lcd.cls();
    }

}
