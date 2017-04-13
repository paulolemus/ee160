/* File: move.c
 * Name:
 * Login: 
 * Date: 4/12/2017
 * Team: AMERICA
 */

#include <stdio.h>
#include "display.h"
#include "move.h"


/* ALGORITHM:
 * Get player command
 * Update timmy's position
 * display Timmy at new position
 * return command entered
 */
char move(int* x, int* y) {
    // Get player command
    char cmd = getchar();
    draw_symbol(*x, *y, ' ');
    
    switch(cmd) {
        case 'w':
        case 'i':
            *y = *y - 1;
            if(*y < 0) *y = HEIGHT - 1;
            break;

        case 'a':
        case 'j':
            *x = *x - 1;
            if(*x < 0) *x = WIDTH - 1;
            break;

        case 's':
        case 'k':
            *y = *y + 1;
            if(*y >= HEIGHT) *y = 0;
            break;

        case 'd':
        case 'l':
            *x = *x + 1;
            if(*x >= WIDTH ) *x = 0;
            break;

        default: break;
    }
    // Draw timmy to screen
    draw_symbol(*x, *y, TIMMY);
    return cmd;
}

