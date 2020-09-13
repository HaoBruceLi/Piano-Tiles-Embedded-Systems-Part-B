/** @file   play_song.h
    @author Narottam Royal
    @date   16 October 2018
*/

#ifndef PLAY_SONG_H
#define PLAY_SONG_H


#include "mmelody.h"
#include "melody_task.h"


#define BUTTON_POLL_RATE 25


// Initialise all modules
void play_song(const uint8_t song, const uint8_t player);


#endif
