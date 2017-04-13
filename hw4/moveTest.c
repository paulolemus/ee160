/*
 * file    : moveTest.c
 * by      : Paulo Lemus
 * login   : Plemus
 * date    : 4/12/2017
 * team    : AMERICA
 * members : Paulo L, Kevin L, Christopher A
*/

/* Test file for move module */

#include <stdio.h>
#include "display.h"
#include "move.h"

int main()
{
    int timX = 0;
    int timY = 0;
    char cmd = 't'; // random

    char* text[10];
    text[1] = "Welcome! This is a move test program";
    text[2] = "Press w, a, s, or d to move.";
    text[3] = "Alternatively, use the i, j, k, l control scheme";

    draw_map();
    debug_wds(1, text[1]);
    debug_wds(2, text[2]);
    debug_wds(3, text[3]);
    draw_symbol(timX, timY, TIMMY);
    display_pos(timX, timY);
    display_score(-999);

    while(cmd != 'q') {
        cmd = move(&timX, &timY);
        display_pos(timX, timY);
        display_score(-999);
    }

    clear_screen();
	return 0;
}
