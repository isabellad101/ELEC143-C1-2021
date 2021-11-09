#include "uop_msb.h"
using namespace uop_msb;

BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
LCD_16X2_DISPLAY display;

int main()
{
    leds = 0;
    display.cls();
    display.locate(0, 0);       //Row 0, column 0
    display.printf("Task 2");
    // ***** MODIFY THE CODE BELOW HERE *****

    // Using a do-while-loop, count from 0 to +50 in steps of 5 - print the results on row 2 of the LCD screen every 1 second 
    int n = 0;
    do{
      
       printf("n=%d\n",n);
        n=n+1;
    }while (n<50);
    // ***** MODIFY THE CODE ABOVE HERE *****
    leds = 7;

    while (true) {

    }
}

