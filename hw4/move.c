/*
file: move.c
by: Kevin Liu
login: liukevin
date: 04/12/17
team: AMERICA
members: Paulo, Chris, Kevin
*/
#include <stdio.h>
#include "display.h"
#include "move.h"

char move(int *x, int *y)
    /* Gets input from player updates the motes posistion and moves 
     * the mote accordingly
     * Given: pointers to the position of the mote
     * Returns: command entered */
{
    char ch;

    while((ch = getchar()) != 'q')
    {
        draw_symbol(*x,*y,' '); //remove Timmy from current position
        switch(ch) //update Timmy's position (via pointer)
        {
            case 'w': //up
            case 'k':
                (*y)--;
                break;
            case 's': //down
            case 'j':
                (*y)++;
                break;
            case 'a': //left
            case 'h':
                (*x)--;
                break;
            case 'd': //right
            case 'l':
                (*x)++;
                break;
        }

        /*  reset position back to grid  */
        if(*x < 0)
            *x = *x +40;
        if(*y < 0)
            *y = *y + 40;
        *x = *x % 40;
        *y = *y % 20;

        draw_symbol(*x,*y,TIMMY); //display Timmy's position
        display_pos(*x,*y);
    }
    return ch;
}

