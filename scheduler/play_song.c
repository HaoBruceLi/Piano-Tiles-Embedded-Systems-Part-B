/** @file   play_song.c
    @author Narottam Royal， Hao Li
    @date   16 October 2018
*/

#include "button.h"
#include "display_mode.h"
#include "display_score.h"
#include "display_task.h"
#include "melody_task.h"
#include "navswitch_task.h"
#include "pio.h"
#include "play_song.h"
#include "songs.h"
#include "task.h"
#include "tweeter_task.h"


// Stops the scheduler if the button is pressed or the song has finished
static void button_update_task(__unused__ void *data)
{
	button_update();

	// Stop the task scheduler if the button is pressed
	// The next overall state will be the song selection menu
	if (button_push_event_p(0)) {
		task_stop();
	}

	// Stop the task scheduler and display the score if the song has finished
	if (mmelody_reached_end_p(melody)) {
		task_stop();
		if (display_mode_get() == NORMAL) {
			display_score(display_task_score());
		}
	}
}


// Initialise all modules and start the scheduler
void play_song(const uint8_t song_index, const uint8_t player)
{
	song_t song = songs[song_index];
	song_melody_t song_melody = player == 1 ? song.melody1 : song.melody2;
	uint8_t bpm = song.bpm;

	// Increment the display four times every "beat per second"
	uint8_t display_increment_rate = 4 * bpm / 60;

	// Define tasks to run
	task_t tasks[] =
	{
			{.func = tune_task, .period = TASK_RATE / TUNE_TASK_RATE},
			{.func = display_task_increment, .period = TASK_RATE / display_increment_rate},
			{.func = display_task_update, .period = TASK_RATE / DISPLAY_UPDATE_RATE},
			{.func = navswitch_task_update, .period = TASK_RATE / NAVSWITCH_POLL_RATE},
			{.func = button_update_task, .period = TASK_RATE / BUTTON_POLL_RATE}
	};

	// Initialise tasks
	button_init();
	navswitch_task_init();
	tweeter_task_init();
	tune_task_init(song_melody, bpm, tweeter_note_play, display_mode_get());
	display_task_init(song_melody, bpm, display_task_create_note);
	task_init();

	// This task is interrupt driven and must be explicitly enabled and disabled
	tweeter_task_enable();

	// Run the scheduled tasks
	task_schedule(tasks, ARRAY_SIZE(tasks));

	tweeter_task_disable();
}
