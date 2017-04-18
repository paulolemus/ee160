/*
 * file: place.c
 * by: Kevin Liu
 * login: liukevin
 * date: 04/12/17
 * team: AMERICA
 * members: Paulo, Chris, Kevin
*/
#include <stdlib.h>
#include "place.h"
#include "display.h"

void place(int *x, int *y)
/* Generates 2 random integers saves them in the pointers given
 * Given: 2 pointers to integers
 * Returns: nothing */
{
    *x = rand() % WIDTH;
    *y = rand() % HEIGHT;
}
