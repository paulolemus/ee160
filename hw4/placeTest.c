/*
 * file: placeTest.c
 * by: Kevin Liu
 * login: liukevin
 * date: 03/25/17
 * team: AMERICA
 * members: Paulo, Christopher, Kevin
*/

/* Test file for display module 
 * 
 * Status: FINISHED
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "place.h"

#define FLUSH while(getchar() != '\n');

int main()
{
    // Seed the rand function with current time
    // to ensure that the rand is different each time
    srand(time(NULL));

    int x,y; // x and y that gets randomized

    printf("Do you want a random coordinate (y/n)? ");
    while(getchar() == 'y')
    {
        place(&x,&y);
        printf("(%d, %d)\n", x, y);
        FLUSH;
        printf("Do you want a random coordinate (y/n)? ");
    }

	printf("Goodbye!\n");
    return 0;
}
