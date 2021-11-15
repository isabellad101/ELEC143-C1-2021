#include "uop_msb.h"
using namespace uop_msb;

// You are to ONLY use this object to control the LEDs
PortOut traffic(PortC, 0b0000000001001100);

//The default flash rate is once per second for all tasks

int main()
{

    //1. Flash the red led 3 times
    int count=0; 
    traffic=0b0000000000000000;
    while (count <3){
    traffic = 0b0000000000000100;
    wait_us(500000);
    traffic = 0b0000000000000000;
    wait_us(500000);
    count = count + 1;
    }
    //2. Using the bitwise OR and AND operators (|,&), flash the green LED on and off 3 times
    count=0; 
    traffic=0b0000000000000000;
    while (count <3){
    traffic = traffic | 0b0000000001000000;
    wait_us(500000);
    traffic = traffic & 0b0000000000000000;
    wait_us(500000);
    count = count + 1;
    }
    //3. Using the bitwise XOR operator (^), flash the yellow LED on and off 3 times
    count=0; 
    traffic=0b0000000000000000;
    while (count <3){
    traffic = traffic ^ 0b0000000000001000;
    wait_us(500000);
    traffic = traffic ^ 0b0000000000001000;
    wait_us(500000);
    count = count + 1;
    }
    //4. Using only bitwise operators, display the traffic light sequence red, red+yellow, green, yellow. Leave a 1s gap between each
    count=0; 
    traffic=0b0000000000000000;
    traffic = traffic | 0b000000000000100;
    wait_us(500000);
    traffic = traffic | 0b000000000001100;
    wait_us(500000);
    traffic = traffic ^ 0b000000001001100;
    wait_us(500000);
    traffic = traffic ^ 0b000000001001000;
    wait_us(500000);

    while (true){

    }
}


