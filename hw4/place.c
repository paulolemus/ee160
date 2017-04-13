/*
 * file: place.c
 * by:
 * login:
 * date: 4/12/2017
 * team: AMERICA
 * members: Kevin L, Paulo L, Christopher A
 */
#include <stdlib.h>
#include "display.h"
#include "place.h"

/* Generates 2 random integers saves them in the pointers given
 * Given: 2 pointers to intgers
 * Returns: nothing 
 * 
 * ALGORITHM:
 * Generate random coordinate
 * Save coordinate
 */
void place(int *x, int *y) {
    *x = rand() % WIDTH;
    *y = rand() % HEIGHT;
}
