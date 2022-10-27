#include "mbed.h"
#include "uop_msb.h"
#include <cstdio>




// main() runs in its own thread in the OS
int main()
{


    while (true) {
        // check that light turn on
        DigitalOut red(PC_2, 1);
        DigitalOut yellow(PC_3, 1);
        DigitalOut green(PC_6, 1);

        wait_us(1000000);
        red = 0;
        green = 0;
        yellow = 0;
        wait_us(1000000);

        red = 1;
        wait_us(2000000);
        yellow = 1;
        wait_us(2000000);
        red = 0;
        yellow = 0;
        green = 1;
        wait_us(2000000);
        green = 0;

        int flash = 0;
        while(flash < 4) {
            yellow = 1;
            wait_us(1000000);
            yellow = 0;
            wait_us(1000000);
            flash = flash + 1;
        }


    }
}

