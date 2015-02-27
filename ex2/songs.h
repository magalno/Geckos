#ifndef SONGS_H
#define SONGS_H


//TUNES

volatile Note g500ms4 = { .note = 'g', .octave = 4, .time_to_play_ms = 500 };
volatile Note e500ms4 = { .note = 'e', .octave = 4, .time_to_play_ms = 300 };
volatile Note b200ms4 = { .note = 'b', .octave = 4, .time_to_play_ms = 200 };
volatile Note g1000ms5 = { .note = 'b', .octave = 5, .time_to_play_ms = 1000 };

volatile Note g400ms4 = { .note = 'g', .octave = 4, .time_to_play_ms = 400 };
volatile Note e400ms4 = { .note = 'e', .octave = 4, .time_to_play_ms = 400 };
volatile Note c800ms3 = { .note = 'a', .octave = 3, .time_to_play_ms = 800 };

volatile Note b500ms5 = { .note = 'a', .octave = 5, .time_to_play_ms = 800 };
volatile Note d300ms5 = { .note = 'a', .octave = 5, .time_to_play_ms = 800 };
volatile Note a600ms5 = { .note = 'a', .octave = 5, .time_to_play_ms = 800 };
volatile Note a600ms6 = { .note = 'a', .octave = 6, .time_to_play_ms = 800 };

volatile Note g200ms5 = { .note = 'a', .octave = 5, .time_to_play_ms = 800 };
volatile Note a200ms5 = { .note = 'a', .octave = 5, .time_to_play_ms = 800 };

volatile Note d600ms5 = { .note = 'a', .octave = 5, .time_to_play_ms = 800 };
volatile Note c200ms5 = { .note = 'a', .octave = 5, .time_to_play_ms = 800 };
volatile Note b200ms5 = { .note = 'b', .octave = 5, .time_to_play_ms = 200 };
//SONGS
/*
B D A G A B D A 
B D A G D C B A 
B D A G A B D A 
B D A G D 
D C B C B G 
C B A B A E 
D C B C B G C G
*/
// Zeldas lullaby
volatile Note* zeldas_lullaby[9] = {&b500ms5, &d300ms5, &a600ms5, &g200ms5, &a200ms5, &b500ms5, &d300ms5, &a600ms5, 
									&b500ms5, &d300ms5, &a600ms6, g200ms5, &d600ms5, &c200ms5, &b200ms35, &g500ms5};
volatile uint32_t zeldas_lullaby_length = 16;
volatile uint32_t zeldas_lullaby_current_note = 0;
volatile uint8_t use_zeldas_lullaby_fadeout = 0;

//Imperial march
volatile Note* imperial_march[9] = {&g500ms4, &g500ms4, &g500ms4, &e500ms4, &b200ms4, &g500ms4, &e500ms4, &b200ms4, &g500ms4};
volatile uint32_t imperial_march_length = 9;
volatile uint32_t imperial_march_current_note = 0;
volatile uint8_t use_imperial_march_fadeout = 0;
//SOUNDS

//Shoot
volatile Note* shoot[1] = {&g1000ms5};
volatile uint32_t shoot_length = 1;
volatile uint32_t shoot_current_note = 0;
volatile uint8_t use_shoot_fadeout = 0;

//Wallhit
volatile Note* wallhit[3] = {&g400ms4, &e400ms4, &c800ms3};
volatile uint32_t wallhit_length = 3;
volatile uint32_t wallhit_current_note = 0;
volatile uint8_t use_wallhit_fadeout = 1;

//OPTIONS TODO::SET TO UINT8 WHERE POSSIBLE
volatile uint8_t song_to_use = 1;
volatile uint8_t use_fadeout = 0;
volatile uint32_t fade_direction = 1;
volatile uint32_t fade_inc = 10;
volatile uint32_t soundMAX = 200;
volatile uint32_t sound0 = 80;
volatile uint32_t sound1 = 0;

void set_fadeout(uint8_t condition){
    if(condition){
        if(sound0 <= 0){
            fade_direction = 1;
        }
        else if(sound0 >= soundMAX){
            fade_direction = 0;
        }
        if(fade_direction == 1) {
            sound0+=fade_inc;
        }
        else{
            sound0-=fade_inc;
        }
    }
}

#endif
