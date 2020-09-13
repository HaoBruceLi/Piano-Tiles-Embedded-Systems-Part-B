/** @file   navswitch_task.h
    @author Narottam Royal
    @date   16 October 2018
*/

#ifndef NAVSWITCH_TASK_H
#define NAVSWITCH_TASK_H


#define NAVSWITCH_POLL_RATE 100


void navswitch_task_init(void);


void navswitch_task_update(void *data);


#endif
