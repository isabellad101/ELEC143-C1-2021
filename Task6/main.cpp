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

void switchCase(int presses, int* button) {
    switch(presses) {
        case 1:
            button[0] = 1;
        break;

        case 2:
            button[1] = 2;
        break;

        case 3:
            button[2] = 3;
        break;

        case 4: 
            button[3] = 4;
        break;
        }
}

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
        int delay = 500000;
        while (SW1==0);
        wait_us(delay);
        leds = 4;


        
        // For full marks, debounce the switches with suitable delays

        // This is a "combination lock" activity. Write some code to detect the following sequence of press-and-release inputs
        // SW1 and SW2, SW5, SW4, SW2 and SW3
        // If the full sequence is entered, correctly, the green LED should flash 3 times
        // If a sequence of inputs was entered incorrectly, the red LED should light and the buzzer should sound for 5 seconds
        // For full marks, debounce the switches and use flow control structures and arrays to avoid deep nesting of code

        // ***** MODIFY THE CODE BELOW HERE *****
        int timeDelay = 400000;
        int buttons;
        int output;

        int input[4];
        int correctSequence[4] = {1 , 2, 3, 4};

        for(int buttonCount = 0; buttonCount < 4; buttonCount ++, wait_us(timeDelay)){
            while(SW1 == 0 && SW2 == 0 && SW3 == 0 && SW4 == 0 && SW5 == 0){}
            wait_us(timeDelay);
            if (SW1 == 1 & SW2 == 1){ // sw1 and sw2 pressed ande released
                buttons = 1;
                leds = 1; // test led 1 should light 
                switchCase(buttons, input); // goes to switchcase function and carries the two variables
            }
            else if(SW5 == 1){ // sw 5 presses and released
                buttons = 2;
                leds = 2;// test led 2 should light 
                switchCase(buttons, input); // goes to switchcase function and carries the two variables
            }
            else if(SW4 == 1){ // sw4 pressed and released 
                buttons = 3;
                leds = 3;// tests led 3 should light 
                switchCase(buttons, input); // goes to switchcase function and carries the two variables
            }
            else if(SW2 == 1 && SW3 == 1){  // sw2 and sw3 pressed and released
                buttons = 4;
                leds = 4; //test led 4 should light 
                switchCase(buttons, input); // goes to switchcase function and carries the two variables
            }
            
        }
        for(int count = 0; count < 4; count ++ ){
            if(input[count] == correctSequence[count]){
                output ++;
            }
            else{}
        }
        // if sequence is correct light led 4 up for 5 seconds 
        int delaybuzzer = 5000000;
        if(output == 4){
            for(int count = 0; count < 3; count ++){
                leds = 4;
                wait_us(delay);
                leds = 0;
                wait_us(delay);

            }
        }
        // wrong code playing the buzzer for 5 seconds 
        else{
            leds = !1; // toggle led 1 
             alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
            wait_us(delaybuzzer);
            alarm.rest();
        }
    
       
 

       // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


       

    
    



