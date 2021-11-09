#include "mbed_wait_api.h"
#include "uop_msb.h"
using namespace uop_msb;

BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    leds = 0;
    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Write a for-loop to count from 1 to 100 in steps of 10 - print the results to the serial terminal
   int count = 1;
    while (count <=100)
    { printf("count = %d\n", count);
    wait_us(500000);
    count = count + 10;}
   
    // 2. Write a for-loop to count from 100 down to 10 in steps of 5 - print the results to the serial terminal
    count = 100;
    while (count >=0)
    { printf("count = %d\n", count);
    wait_us(500000);
    count = count - 5;}
    
    // 3. Write some code to demonstrate nested for-loops (one loop within another)
    for (unsigned int t=1; t<=20; t=t+2){
        for (unsigned int y=1; y<=20; y=y+2){
            printf("%d\t",y-t);
        }
        printf("\n");
    }

    
    // ***** MODIFY THE CODE ABOVE HERE *****
    leds = 7;

    while (true) {

    }
}
