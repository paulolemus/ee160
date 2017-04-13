/*
 * file    : dispTest.c
 * by      : 
 * login   :
 * date    :
 * team    : AMERICA
 * members : Paulo L, Kevin L, Christopher A
*/

/* Test file for display module */

#include <stdio.h>
#include "display.h"

int main()
{
	draw_map();

	draw_symbol(3,4,'#');

	getchar();//so it doesn't close on you right away

	clear_screen();

	return 0;
}
