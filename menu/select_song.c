/** @file   select_song.c
    @author Narottam Royal， Hao Li
    @date   16 October 2018
*/

#include "button.h"
#include "ir_sync.h"
#include "select_song.h"
#include "navswitch.h"
#include "songs.h"
#include "system.h"
#include "timer.h"
#include "display_menu.h"
#include "display_mode.h"


#define DEBOUNCE_DELAY 5000
#define SYNC_DELAY 10000
#define SYNC_TIMOUT 50000


enum player_t player = NONE;
uint8_t song_index = 0;


void select_song_index_set(uint8_t index)
{
  song_index = index;
}


uint8_t select_song_index_get()
{
  return song_index;
}


void select_song_player_set(uint8_t player_num)
{
  player = player_num;
}

uint8_t select_song_player_get()
{
  return (uint8_t) player;
}


static void debounce(void)
{
  uint16_t current_time = timer_get();
  uint16_t previous_time = current_time;
  while (current_time - previous_time < DEBOUNCE_DELAY) {
    current_time = timer_get();
  }
}


static void soft_reset(void)
{
  player = NONE;
  ir_sync_reset();
}


void select_song()
{
  soft_reset();

  display_menu_init(songs[song_index].song_name);
  ir_sync_init();
  button_init();
  navswitch_init();
  timer_init();

  uint16_t current_time = 0;
  uint16_t previous_time = 0;

  while (1)
  {
    current_time = timer_get();

    if (syncronised && current_time > SYNC_DELAY) {
      break;
    }

    if (player != NONE && current_time > SYNC_TIMOUT && !syncronised) {
      soft_reset();
    }

    if (player == NONE) {
      button_update();
      navswitch_update();

      // Begin syncronisation sequence
      if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
        player = 1;
        ir_sync_start();
      }

      // Increment song index
      if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
        display_menu_clear();
        debounce();
        song_index = (song_index + 1) % NUM_SONGS;
        display_menu_update_name(songs[song_index].song_name);
      }

      // Decrement song index
      if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
        display_menu_clear();
        debounce();
        song_index = (song_index - 1 + NUM_SONGS) % NUM_SONGS;
        display_menu_update_name(songs[song_index].song_name);
      }

      if (button_push_event_p(0)) {
        display_menu_clear();
        debounce();
        display_mode();
        display_menu_update_name(songs[song_index].song_name);
      }
    }

    // Update display
    if (current_time - previous_time > TIMER_RATE / UPDATE_RATE) {
      display_menu_update();
      previous_time = current_time;
    }
  }
}
