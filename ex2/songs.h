#ifndef SONGS_H
#define SONGS_H


typedef enum {
    WIN,
    LOSE,
    HIT,
    MISS,
    IMPERIAL,
    N_TUNES
} Tune_nr;

typedef struct tune{
    Note* melody;
    uint32_t length;
    uint32_t current_note;
    uint32_t use_fadeout;
}tune_t



/* TONES USED */
volatile Note g500ms = { .note = 'g', .octave = 4, .time_to_play_ms = 500 };
volatile Note e500ms = { .note = 'e', .octave = 4, .time_to_play_ms = 300 };
volatile Note b200ms = { .note = 'b', .octave = 4, .time_to_play_ms = 200 };
volatile Note g400ms = { .note = 'b', .octave = 5, .time_to_play_ms = 400 };

volatile Note g400ms = { .note = 'g', .octave = 4, .time_to_play_ms = 400 };
volatile Note e400ms = { .note = 'e', .octave = 4, .time_to_play_ms = 400 };
volatile Note c800ms = { .note = 'a', .octave = 3, .time_to_play_ms = 800 };

/* SONGS */

// Imperial march 
volatile Note* imperial_march[9] = {&g500ms, &g500ms, &g500ms, &e500ms, &b200ms, &g500ms, &e500ms, &b200ms, &g500ms};
volatile uint32_t imperial_march_length = 9;
volatile uint32_t imperial_march_current_note = 0;
volatile uint8_t use_imperial_march_fadeout = 0;


/* SOUNDS */

// Shoot
volatile Note* shoot[1] = {&g400ms};
volatile uint32_t shoot_length = 1;
volatile uint32_t shoot_current_note = 0;
volatile uint8_t use_shoot_fadeout = 0;

// Lose
volatile Note* wallhit[3] = {&g400ms, &e400ms, &c800ms};
volatile uint32_t wallhit_length = 3;
volatile uint32_t wallhit_current_note = 0;
volatile uint8_t use_wallhit_fadeout = 1;


//OPTIONS 
volatile uint8_t song_to_use = 1;
volatile uint8_t use_fadeout = 0;
volatile uint8_t fade_direction = 1;
volatile uint8_t fade_inc = 10;
volatile uint32_t soundMAX = 200;
volatile uint16_t sound0 = 80;
volatile uint16_t sound1 = 0;

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
