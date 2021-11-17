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
    BusIn buttons(USER_BUTTON,BTN1_PIN,BTN2_PIN,BTN3_PIN,BTN4_PIN);
    buttons[2].mode(PullDown);
    buttons[3].mode(PullDown);
    int sequence[4]{0,0,0,0};
    int total;
    //debounce
    wait_us(10000);
    while(buttons == 31) {
    }
    wait_us(10000);
    //bt1 and bt2
    while (buttons == 0) {
        if (buttons == 3){
            sequence[0]=1;
        }
        
    }
    //debounce
    wait_us(10000); 
    while(buttons == 31){
    }
    wait_us(10000);
    //bt5
    while (buttons == 0){
        if (buttons == 16){
        sequence[1]=1;
        }
    }
    //debounce
    wait_us(10000);
    while(buttons == 31){
    }
    wait_us(10000);
    //bt4
    while (buttons == 0){
        if (buttons == 8){
            sequence[2]=1;
        }
        
    }
    //debounce
    wait_us(10000);
    while(buttons == 31){
    }
    wait_us(10000);
    //bt2 and bt3 
    while (buttons == 0){
        if (buttons == 6){
        sequence[3]=1;
        }
    } 
    //debounce
    wait_us(10000);
    while(buttons == 31){
    }
    wait_us(10000);
    //checking only 4 inputs 
    for(int i=0;i<=3;i++){
        total+=sequence[i];
    }
    // if 4 inputs flash green led 3 times 
    if(total==4){
        for(int x=0;x<3;x++){
        leds[2]=1;
        wait_us(500000);
        leds[2]=0;
        wait_us(500000);
        }
       
    }
    // else play buzzer and turn on red led for 5 seconds
    else {
    leds[0]=1;
    alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
    wait_us(5000000);
    alarm.rest();

    }

        // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


  




       

    
    



