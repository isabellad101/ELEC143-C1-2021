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
      int sw3State= 0;
       sw3State = SW3;
      int sw4State = 0;
       sw4State = SW4;
      int sw5State = 0;
      sw5State = SW5;
      int count = 0;
      int combinations = 0;

   
    while(1){
        sw1State = SW1;
        sw2State = SW2;
        sw3State = SW3;
        sw4State = SW4;
        sw5State = SW5;
    while( sw1State==0 && sw2State==0 && sw3State == 0 && sw4State == 0 && sw5State ==0){

    }
      //sw1&sw2
      if(sw1State==1 && sw2State==1 && sw3State == 0 && sw4State == 0 && sw5State ==0){
          wait_us(5000000);
          count ++;
          combinations ++;
          

      }




       
       
 

       // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


       

    
    



