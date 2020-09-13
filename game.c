/** @file   game.c
    @author Narottam Royal， Hao Li
    @date   16 October 2018
*/

#include "select_song.h"
#include "display_countdown.h"
#include "display_mode.h"
#include "play_song.h"
#include "system.h"


int main (void)
{
	system_init();

	display_mode();

	while (1)
	{
		// Select which song to play and sync the fun kits
		select_song();

		// Displays a countdown from 3 to 1
		display_countdown();

		// Play the previously selected song
		play_song(select_song_index_get(), select_song_player_get());
	}
  return 0;
}
