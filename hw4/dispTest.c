/*
file: dispTest.c
by: Kevin Liu
login: liukevin
date: 03/25/17
team: AMERICA
members: Paulo, Christopher, Kevin
*/

/* Test file for display module */

#include <stdio.h>
#include "display.h"

int main()
{
    int row, column;
    row = column = 5;
	draw_map();

    display_pos(-99,-99);
    display_score(-999);

    for(row = 5; row < 10; row++)
    {
        if(row == 5 || row == 9) //first and last rows
        //{
            for(column = 5; column < 12; column++)
                draw_symbol(row,column,'x');
        //}
        else //in between top and bottom lines
        {
            draw_symbol(row,5,'x');
            draw_symbol(row,11,'x');
        }
    }
    getchar();//so it doesn't close on you right away 

	clear_screen();

	return 0;
}
