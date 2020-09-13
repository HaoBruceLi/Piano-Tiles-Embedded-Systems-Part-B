/** @file   navswitch_task.c
    @author Narottam Royal， Hao Li
    @date   16 October 2018
*/

#include "display_task.h"
#include "navswitch_task.h"
#include "navswitch.h"


enum {UP, LEFT, PUSH, RIGHT, DOWN};


void navswitch_task_init()
{
  // Initialise driver
  navswitch_init();
}


void navswitch_task_update(__unused__ void *data)
{
  navswitch_update();

  if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
    display_task_check_button(UP);
  }

  if (navswitch_push_event_p(NAVSWITCH_WEST)) {
    display_task_check_button(LEFT);
  }

  if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
    display_task_check_button(PUSH);

    /*
    display_task_check_button(UP);
    display_task_check_button(LEFT);
    display_task_check_button(RIGHT);
    display_task_check_button(DOWN);*/
  }

  if (navswitch_push_event_p(NAVSWITCH_EAST)) {
    display_task_check_button(RIGHT);
  }

  if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
    display_task_check_button(DOWN);
  }
}
