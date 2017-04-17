/*
file: placeTest.c
by: Kevin Liu
login: liukevin
date: 03/25/17
team: AMERICA
members: Paulo, Christopher, Kevin
*/

/* Test file for display module */

#include <stdio.h>
#include <stdlib.h>
#include "place.h"

#define FLUSH while(getchar() != '\n');

int main()
{
    char ch;
    int x,y;

    printf("Do you want a random coordinate (y/n)? ");
    while(getchar() == 'y')
    {
        place(&x,&y);
        printf("(%d,%d)\n", x, y);
        FLUSH;
        printf("Do you want a random coordinate (y/n)? ");
    }

	return printf("Goodbye!\n");
}
