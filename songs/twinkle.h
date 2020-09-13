/** @file   twinkle.h
    @author Narottam Royal
    @date   16 October 2018
*/

#ifndef TWINKLE_H
#define TWINKLE_H


#include "songs.h"


#define TWINKLE_BPM 80


#define MELODY1_OCTAVE 4
#define MELODY1_PERIOD 1

static const char twinkle_melody1[] =
{
	"G-G-DDEED/CCB-B-A-A-G-/DDCCB-B-A-/DDCCB-B-A-/G-G-DDEED/CCB-B-A-A-G-/  "
};


#define MELODY2_OCTAVE 3
#define MELODY2_PERIOD 2

static const char twinkle_melody2[] =
{
	"G-G-B-B-CCB-/A-A-G-G-DDG-/GGDDGGD/BBAAGGD/G-G-B-B-CCB-/A-A-G-G-DDG-/  "
};


static const song_t twinkle =
{
  "Twinkle ",
	TWINKLE_BPM,
  {twinkle_melody1, MELODY1_OCTAVE, MELODY1_PERIOD},
  {twinkle_melody2, MELODY2_OCTAVE, MELODY2_PERIOD}
};


#endif
