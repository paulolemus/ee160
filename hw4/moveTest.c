/*
file: moveTest.c
by: Kevin Liu
login: liukevin
date: 03/25/17
team: AMERICA
members: Paulo, Christopher, Kevin
*/

/* Test file for display module */

#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "move.h"

int main()
{
    char ch;
    int x,y;
    x = y = 10;

	draw_map();
    display_pos(x,y);

    draw_symbol(x,y,TIMMY); //place Timmy in a random spot  */

    move(&x,&y);//move Timmy around

	clear_screen();

	return 0;
}
