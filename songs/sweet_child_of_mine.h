/** @file   sweet_child_of_mine.h
    @author Narottam Royal
    @date   16 October 2018
*/

#ifndef SWEET_CHILD_OF_MINE_H
#define SWEET_CHILD_OF_MINE_H


#include "songs.h"


#define SWEET_CHILD_OF_MINE_BPM 120


#define MELODY1_OCTAVE 4
#define MELODY1_PERIOD 1

static const char melody1[] =
{
	"*8<D-DA-G-GA-F#A->2<E-DA-G-GA-F#A->2<G-DA-G-GA-F#A->2<D-DA-G-GA-F#A->2<D-DA-G-GA-F#A->2<E-DA-G-GA-F#A->2<G-DA-G-GA-F#A->2EA-DA-EA-F#A-GA-F#A-EA-DA- "
	//"*8<DD+AGG+AF#+A>2<ED+AGG+AF#+A>2<GD+AGG+AF#+A>2<DD+AGG+AF#+A>2<DD+AGG+AF#+A>2<ED+AGG+AF#+A>2<GD+AGG+AF#+A>2E+AD+AE+AF#+AG+AF#+AE+AD+A"
};


#define MELODY2_OCTAVE 3
#define MELODY2_PERIOD 2

static const char melody2[] =
{
	"*8<D//F#///GA/BAGF#DC///G///CFECF/ECDG-//////DG//////DGF#DG/F#/D////////>2 "
};


static const song_t sweet_child_of_mine =
{
  "Sweet Child of Mine ",
	SWEET_CHILD_OF_MINE_BPM,
  {melody1, MELODY1_OCTAVE, MELODY1_PERIOD},
  {melody2, MELODY2_OCTAVE, MELODY2_PERIOD}
};


#endif
