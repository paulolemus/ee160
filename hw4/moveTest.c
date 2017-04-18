/*
 * file     : moveTest.c
 * by       : Kevin Liu, Paulo Lemus
 * login    : liukevin, plemus
 * date     : 03/25/17
 * team     : AMERICA
 * members  : Paulo, Christopher, Kevin
 */

/* Test file for display module
 *
 * Status: FINISHED
 */

#include <stdio.h>
#include "display.h"
#include "move.h"

int main()
{

    int xTim = 0, yTim = 0;
    char cmd = 't'; // random

    // Save some informational text to write to screen
    char* text[10];
    text[1] = "Welcome! This is a move test program";
    text[2] = "Press w, a, s, or d to move.";
    text[3] = "Alternatively, use the i, j, k, l control scheme";

    draw_map();
    debug_wds(1, text[1]);
    debug_wds(2, text[2]);
    debug_wds(3, text[3]);

    draw_symbol(xTim, yTim, TIMMY);
    display_pos(xTim, yTim);
    display_score(-999);

    // Continuously move Timmy and update 
    // position counter until user quits with 'q'
    while(cmd != 'q') 
    {
        cmd = move(&xTim, &yTim);
        display_pos(xTim, yTim);
        display_score(-999);
    }

    clear_screen();
	return 0;
}
