/*
 * file    : dispTest.c
 * by      : Paulo Lemus
 * login   : Plemus
 * date    : 4/12/2017
 * team    : AMERICA
 * members : Paulo L, Kevin L, Christopher A
*/

/* Test file for display module */

#include <stdio.h>
#include "display.h"

int main()
{
    int startX = 3;     // top left corner of rect
    int startY = 4;     // top left corner of rect
    int width  = 10;
    int height = 5;
    char sym   = 'x';

    // Array of string, sorted by position on sidebar
    char* text[10];
    text[1] = "Welcome! This is a display test program";
    text[2] = "Press 'q' to quit";

    // Draw everything
	draw_map();
    display_pos(-99, -99);
    display_score(-999);
    debug_wds(1, text[1]);
    debug_wds(2, text[2]);

    // Draw the rectangle to the board
    int i;
    for(i = 0; i < width; ++i) {
        // draw top line
        draw_symbol(startX + i, startY, sym);
        // draw bottom line
        draw_symbol(startX + i, startY + height - 1, sym);
    }
    for(i = 0; i < height; ++i) {
        // draw left line
        draw_symbol(startX, startY + i, sym);
        // draw right line
        draw_symbol(startX + width - 1, startY + i, sym);
    }

    // Quit only when the user enters 'q'
	while(getchar() != 'q');
	clear_screen();
	return 0;
}
