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
Buzzer player;

// Note array. The string "-" is a rest
typedef struct {
    char note[3]; //Space for 2 characters and a zero (end of string character)
    Buzzer::OCTAVE_REGISTER octave;
    unsigned int time_ms;
} NOTE;

// https://en.wikipedia.org/wiki/List_of_musical_symbols
#define SEMIBREVE 1200          //Whole beat
#define MINIM (SEMIBREVE >> 1)  //Half
#define CROTCHET (MINIM >> 1)   //Quarter
#define QUAVER (CROTCHET >> 1)  //Eighth
#define SEMIQUAVER (QUAVER >> 1) //Sixteenth

//Triplets
#define SEMIBREVE_TRIP 900          //Whole beat
#define MINIM_TRIP (SEMIBREVE_TRIP >> 1)  //Half
#define CROTCHET_TRIP (MINIM_TRIP >> 1)   //Quarter
#define QUAVER_TRIP (CROTCHET_TRIP >> 1)  //Eighth
#define SEMIQUAVER_TRIP (QUAVER_TRIP >> 1) //Sixteenth

NOTE notes[] = {
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},    
    {.note="C", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="G", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="G", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=CROTCHET},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},

    {.note="C", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET}, 
    {.note="G", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET}, 
    {.note="E", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=QUAVER+CROTCHET},
    {.note="A", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="B", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="A#", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="A", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},

    {.note="G", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=CROTCHET_TRIP},
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET_TRIP},
    {.note="G", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET_TRIP},
    {.note="A", .octave=Buzzer::HIGHER_OCTAVE, .time_ms=CROTCHET},
    {.note="F", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="G", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},

    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER}, 
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="C", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="D", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="B", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER+CROTCHET},    

    // Repeat

    {.note="C", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET}, 
    {.note="G", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET}, 
    {.note="E", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=QUAVER+CROTCHET},
    {.note="A", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="B", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="A#", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="A", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},

    {.note="G", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=CROTCHET_TRIP},
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET_TRIP},
    {.note="G", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET_TRIP},
    {.note="A", .octave=Buzzer::HIGHER_OCTAVE, .time_ms=CROTCHET},
    {.note="F", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="G", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},

    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER}, 
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="C", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="D", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="B", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER+CROTCHET},    

};


int main()
{
    //Play an A for 

    player.playTone("A", Buzzer::MIDDLE_OCTAVE);
    wait_us(QUAVER*1000);
    player.rest();


    while (true)
    {   
        //Wait for the blue button
        while (SW1==0);

        // ***** MODIFY THE CODE BELOW HERE *****
        // 1. Write a loop to play the tune in the array `notes`
        //    You may recognise the tune :)
        //    Use player.playTone followed by a player.rest() to get the right duration of note as shown above
        wait_us(500000) ;
        for(int count = 0; count < 51; count ++){ // 51 notes in the errays
            player.playTone(notes[count].note, notes[count].octave);
            wait_us(notes[count].time_ms * 1000); // plays not for the set amount of time
            player.rest(); // buzzer stops
        }
        // 2. Write a nested loop to play the tune twice. Avoid replicating any code where possible.
        for(int loop2 = 0; loop2 < 2; loop2 ++){ //nested loop to play the tune twice 
            for(int count = 0; count < 51; count ++){ // 51 notes in the errays
                player.playTone(notes[count].note, notes[count].octave);
                wait_us(notes[count].time_ms * 1000); // plays not for the set amount of time
                player.rest(); // buzzer stops
            }
        }
        // ***** MODIFY THE CODE ABOVE HERE *****
        
    }
}


