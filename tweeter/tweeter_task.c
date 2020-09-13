/** @file   tweeter_task.c
    @author Narottam Royal， Hao Li
    @date   16 October 2018
*/

#include <avr/interrupt.h>
#include "pio.h"
#include "tweeter.h"
#include "tweeter_task.h"


static uint8_t tweeter_interrupt_period = 1;


void tweeter_set_period(const uint8_t period)
{
  tweeter_interrupt_period = period;
}


// Configures an interrupt to update the tweeter
void tweeter_task_enable()
{
  cli();  // Temporarily disable interrupts

  // Initialise the TIMER1 COMPA register
  OCR1A = tweeter_interrupt_period;
  // Set TIMER1 COMPA interrupt
	TIMSK1 |= (1 << OCIE1A);

  sei();  // Enable interrupts
}


// Disables the tweeter update interrupt
void tweeter_task_disable()
{
  // Turn off the tweeter
  tweeter_note_play(tweeter, 0, 0);

  cli();  // Temporarily disable interrupts

  // Clear TIMER1 COMPA interrupt
  TIMSK1 &= ~(1 << OCIE1A);

  // Set tweeter pins floating (stops switching noise)
  pio_config_set(PIEZO1_PIO, PIO_INPUT);
  pio_config_set(PIEZO2_PIO, PIO_INPUT);

  sei();  // Enable interrupts
}


// Initialise the task
void tweeter_task_init()
{
  // Initialise the tweeter
  static tweeter_obj_t tweeter_info;
	static tweeter_scale_t scale_table[] = TWEETER_SCALE_TABLE(TWEETER_TASK_RATE);
  tweeter = tweeter_init(&tweeter_info, TWEETER_TASK_RATE, scale_table);

  // Configure the output pins
  pio_config_set(PIEZO1_PIO, PIO_OUTPUT_LOW);
  pio_config_set(PIEZO2_PIO, PIO_OUTPUT_LOW);
}


// Update the tweeter
ISR(TIMER1_COMPA_vect)
{
  uint8_t state = tweeter_update(tweeter);
  pio_output_set(PIEZO1_PIO, state);
  pio_output_set(PIEZO2_PIO, !state);
  OCR1A += tweeter_interrupt_period;
}
