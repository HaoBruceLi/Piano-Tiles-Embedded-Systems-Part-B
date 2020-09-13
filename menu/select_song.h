/** @file   select_song.h
    @author Narottam Royal
    @date   16 October 2018
*/

#ifndef SELECT_SONG_H
#define SELECT_SONG_H


#include <stdint.h>
#include <stdbool.h>


enum player_t {NONE, PLAYER1, PLAYER2};


extern bool syncronised;


void select_song_index_set(uint8_t index);


uint8_t select_song_index_get(void);


void select_song_player_set(uint8_t player_num);


uint8_t select_song_player_get(void);


void select_song(void);


#endif
