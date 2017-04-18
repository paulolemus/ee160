/*
file    : move.c
by      : Kevin Liu
login   : liukevin
date    : 04/12/17
team    : AMERICA
members : Paulo, Chris, Kevin
*/
#include <stdio.h>
#include "display.h"
#include "move.h"


/* ALGORITHM:
 * Get player command
 * Update Timmy's position
 * Teleport Timmy if he is now beyond bounds
 * Draw Timmy
 * Return character
 *
 * Status: FINISHED
 */
char move(int* x, int* y)
    /* Gets input from player updates the motes position and moves 
     * the mote accordingly
     * Given: pointers to the position of the mote
     * Returns: command entered */
{
    char ch = getchar();

    // Clear Timmy's current position
    draw_symbol(*x, *y, ' ');

    switch(ch) //update Timmy's position (via pointer)
    {
        case 'w': //up
        case 'i':
            (*y)--;
            if(*y < 0) *y = HEIGHT - 1;
            break;

        case 's': //down
        case 'k':
            (*y)++;
            if(*y >= HEIGHT) *y = 0;
            break;

        case 'a': //left
        case 'j':
            (*x)--;
            if(*x < 0) *x = WIDTH - 1;
            break;

        case 'd': //right
        case 'l':
            (*x)++;
            if(*x >= WIDTH) *x = 0;
            break;
    }

    draw_symbol(*x ,*y, TIMMY); //display Timmy's position
    return ch;
}

