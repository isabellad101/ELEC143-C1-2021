#include "uop_msb.h"
using namespace uop_msb;

DigitalIn BlueButton(USER_BUTTON);
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
LCD_16X2_DISPLAY display;

int main()
{

    // ***** MODIFY THE CODE BELOW HERE *****

    //1. Use a while loop to wait for the blue button to be pressed, then released. For full marks, account for switch bounce.
   while (BlueButton == 0){
       
    }
   while (BlueButton == 1){
       
       wait_us(500000);
    }
    //2. Using a while-loop, flash the yellow LED on and off 5 times. Each flash should last 0.5s. 
int count=0; 
leds =0b000;
 while (count <5){
leds = 0b010;
wait_us(500000);
leds = 0b000;
wait_us(500000);
count = count + 1;
 }
    //3. Using a while-loop, flash the green LED on and off 10 times. Each flash should last 0.25s. 
count = 0;
leds =0b000;
 while (count <10){
leds = 0b100;
wait_us(250000);
leds = 0b000;
wait_us(250000);
count = count + 1;
 }
    //4. Using a while-loop, flash the red LED on and off 20 times. Each flash should last 0.125s. 
count=0; 
leds =0b000;
 while (count <20){
leds = 0b001;
wait_us(125000);
leds = 0b000;
wait_us(125000);
count = count + 1;
 }
    //5. Using a while-loop, count from 50 downto -50 in steps of 10 - print the results on row 1 of the LCD screen every 0.5 second 
count = 50;

 
leds =0b000;
while (count >=-50){
display.locate(0, 0);
display.printf("count=%d\n",count);
wait_us(500000);
count = count - 10;
 }

    // ***** MODIFY THE CODE ABOVE HERE *****

    
    
while (true) {

    }
}



