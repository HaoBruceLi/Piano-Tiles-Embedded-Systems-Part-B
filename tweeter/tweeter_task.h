/** @file   tweeter_task.h
    @author Narottam Royal
    @date   16 October 2018
*/

#ifndef TWEETER_TASK_H
#define TWEETER_TASK_H


#include "tweeter.h"


#define PIEZO1_PIO PIO_DEFINE (PORT_D, 1)
#define PIEZO2_PIO PIO_DEFINE (PORT_D, 6)
#define TWEETER_TASK_RATE 20000


tweeter_t tweeter;


void tweeter_set_period(const uint8_t period);


// Configures an interrupt to update the tweeter
void tweeter_task_enable(void);


// Disables the tweeter update interrupt
void tweeter_task_disable(void);


// Initialise the tweeter
void tweeter_task_init(void);


#endif
