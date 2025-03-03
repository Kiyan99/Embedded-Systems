// You need this to use the Module Support Board
#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 
DigitalOut greenLED(TRAF_GRN1_PIN);
Buzzer buzz;
Buttons buttons;

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)

int main()
{
    //Wait for the BLUE button to be pressed (otherwise this becomes super annoying!)
    while (buttons.BlueButton == 0);
    
    //Repeat everything "forever" (until the power is removed or the chip is reset)
    while (true)
    {
        //On for 500ms
        greenLED = 1;
        buzz.playTone("A");
        wait_us(WAIT_TIME_MS * 1000);  //500ms

        greenLED = 1;
        buzz.playTone("B");
        wait_us(WAIT_TIME_MS * 1000);  //500ms
        
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 1000);  //500ms

        //Off for 500ms
        greenLED = 0;
        buzz.playTone("C", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 1000);  //500ms

        greenLED = 0;
        buzz.playTone("E", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 1000);  //500ms

        greenLED = 0;
        buzz.playTone("F", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 1000);  //500ms


        greenLED = 0;
        buzz.playTone("G", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 1000);  //500ms

        greenLED = 0;
        buzz.playTone("H", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 1000);  //500ms

        //Pause
        buzz.rest();
        wait_us(WAIT_TIME_MS * 1000);

    }
}