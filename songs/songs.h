/** @file   songs.h
    @author Narottam Royal
    @date   16 October 2018
*/

#ifndef SONGS_H
#define SONGS_H


#include <stdint.h>


#define NUM_SONGS 2


typedef struct
{
  const char *melody;
  const uint8_t octave;
  const uint8_t tweeter_period;
} song_melody_t;


typedef struct
{
  const char *song_name;
  const uint8_t bpm;
  song_melody_t melody1;
  song_melody_t melody2;
} song_t;


extern song_t songs[NUM_SONGS];


#endif
