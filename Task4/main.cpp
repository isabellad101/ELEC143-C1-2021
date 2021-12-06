#include "uop_msb.h"
using namespace uop_msb;

// You are to use these ojects to read the switch inputs
DigitalIn sw1(BTN1_PIN);
DigitalIn sw2(BTN2_PIN);


// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    while (true)
    {
    // ***** MODIFY THE CODE BELOW HERE *****
    // For full marks, debounce the switches with suitable delays

    // 1. Wait for sw1 to be pressed and released
    while (sw1 == 0){
    }
    while (sw1 == 1){
       wait_us(500000);
    }
    printf("hello\n");
    // 2. Wait for sw2 to be pressed and released
    while (sw2 == 0){
    }
    while (sw2 == 1){
       wait_us(500000);
    }
    printf("helloworld\n");
    // 3. Wait for sw1 and sw2 to be pressed (together)
    while(sw1==0){
        while(sw2==0){

        }
    }
    // 4. Wait for either sw1 or sw2 to be released
      while((sw1==1)||(sw2==1)){
          while(sw2==1){
          wait_us(500000);
          }
        
    }
     printf("byeworld\n");
    // 5. Turn on only the yellow and green LEDs
    leds= 0b110;
    // 6. Wait for 1s
    wait_us(1000000);
    // 7. Turn on only the red LEDs
    leds= 0b001;
    // ***** MODIFY THE CODE ABOVE HERE *****
    }

    while(true);
}


