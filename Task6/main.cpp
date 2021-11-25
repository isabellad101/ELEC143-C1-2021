#include "uop_msb.h"
using namespace uop_msb;


// You are to use these ojects to read the switch inputs
DigitalIn SW1(USER_BUTTON);
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);
DigitalInOut SW4(BTN3_PIN,PIN_INPUT,PullDown,0);
DigitalInOut SW5(BTN4_PIN,PIN_INPUT,PullDown,0);


// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

//Use this to sound an error
Buzzer alarm;

int main()
{
    while (true)
    {
        leds = 0;

        //Beep
        alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
        wait_us(250000);
        alarm.rest();

        //Wait for the blue button using a while loop
        while (SW1==0);

        
        // For full marks, debounce the switches with suitable delays

        // This is a "combination lock" activity. Write some code to detect the following sequence of press-and-release inputs
        // SW1 and SW2, SW5, SW4, SW2 and SW3
        // If the full sequence is entered, correctly, the green LED should flash 3 times
        // If a sequence of inputs was entered incorrectly, the red LED should light and the buzzer should sound for 5 seconds
        // For full marks, debounce the switches and use flow control structures and arrays to avoid deep nesting of code

        // ***** MODIFY THE CODE BELOW HERE *****

     int sw1State = 0;
        sw1State = SW1;
        int sw2State = 0;
        sw2State = SW2;
        int sw3State = 0;
        sw3State = SW3;
        int sw4State = 0;
        sw4State = SW4;
        int sw5State = 0;
        sw5State = SW5;
        sequence[]={(sw1State & sw2State),(sw5State),(sw4State),(sw2State & sw3State)}
        wait_us(500000);
        while(sw1StateC = 0 && sw2State = 0 && sw3State = 0 && sw4State = 0 && sw5State = &&){
        }
        wait_us(500000);

        //sw1&sw2
        wait_us(500000);
        while(sw1State = 0 && sw2State = 0 && sw3State = 0 && sw4State = 0 && sw5State = 0){
            if(sw1State = 1 && sw2State = 1 && sw3State = 0 && sw4State = 0 && sw5State = 0){
                sequence[1] = 1;
            }
        }
        wait_us(500000);

        //debounce
        wait_us(500000);
        while(sw1State = 0 && sw2State = 0 && sw3State = 0 && sw4State = 0 && sw5State = &&){
        }
        wait_us(500000);

        //sw5
        wait_us(500000);
        while(sw1State = 0 && sw2State = 0 && sw3State = 0 && sw4State = 0 && sw5State = 0){
            if(sw1State = 0 && sw2State = 0 && sw3State = 0 && sw4State = 0 && sw5State = 1){
                sequence[2]=1;
            }
        }

        //debounce
        wait_us(500000);
        while(sw1State = 0 && sw2State = 0 && sw3State = 0 && sw4State = 0 && sw5State = &&){
        }
        wait_us(500000);

        //sw4
        wait_us(500000);
        while(sw1State = 0 && sw2State = 0 && sw3State = 0 && sw4State = 0 && sw5State = 0){
            if(sw1State = 0 && sw2State = 0 && sw3State = 0 && sw4State = 1 && sw5State = 0){
                sequence[3]=1;
            }
        }

        //debounce
        wait_us(500000);
        while(sw1State = 0 && sw2State = 0 && sw3State = 0 && sw4State = 0 && sw5State = &&){
        }
        wait_us(500000);

        //sw2&sw3
        wait_us(500000);
        while(sw1State = 0 && sw2State = 0 && sw3State = 0 && sw4State = 0 && sw5State = 0){
            if(sw1State = 0 && sw2State = 1 && sw3State = 1 && sw4State = 0 && sw5State = 0){
                sequence[4]=1;
            }
        }

         //debounce
        wait_us(500000);
        while(sw1State = 1 && sw2State = 1 && sw3State = 1 && sw4State = 1 && sw5State = 1){
        }
        wait_us(500000);

        for(int n = 0 ; n<4 ; n ++){
            total += sequence[n];
        }
        if(totsl == 4){
            for(int t = 0 ; t <= 2 ; t++){
                leds[2] = 1;
                wait_us(50000000);
                leds[2] = 0;
                wait_us(50000000);
            }
        }
        else{
            leds[0] = 1;
            alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
            alarm.rest();
            wait_us(50000000);

        }


       
       
 

       // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


       

    
    



