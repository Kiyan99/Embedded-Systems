#include "mbed.h"
#define WAIT_TIME_MS 1000 


// DigitalOut redLED(PC_2,1);
// DigitalOut yellowLED(PC_3,1);
// DigitalOut greenLED(PC_6,1);

BusOut lights(PC_2, PC_3, PC_6,PB_0, PB_7, PB_14);
//BusOut lights(PC_2, PC_3, PC_6, PB_0, PB_7, PB_14);

int main()
{
    //All OFF
    lights = 0b000000; 
    // 0b means value after b is in Binary
    //Binary is 0 here but aswe add 1 to it, it increases and turns on the lights in order.
    // from right to left 0 = PC_2, next 0 is PC_3 and PC_6


    while (true)
    {
        int count = 32;
        while (count >= 0) 
        {
            printf("count = %d\n", count);
            lights = count; //as count increases up to 7, it also turns the lights on and of.
            wait_us(1000000);

            count = count - 1;
        }
    }
}