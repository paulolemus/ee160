/* File     : placeTest.c
 * Name     :
 * Login    :
 * Date     : 4/12/2017
 * Team     : AMERICA
 * Members  : Kevin L, Christopher A, Paulo L
 */

/* This program will repeatedly print numbers until the user
 * enters any character that is not a 'y'.
 *
 * Status: FINISHED
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "place.h"

int main() {

    // Seed the rand function with the current time to ensure
    // that the rand is different each time
    srand(time(NULL));

    char cmd; // saved character entered by user
    int x, y; // x and y position that get randomized

    printf("Do you want a random coordinate (y/n)? ");

    while((cmd = getchar()) == 'y') {
        place(&x, &y);
        printf("(%d, %d)\n", x, y);
        printf("Do you want a random coordinate (y/n)? ");
        while(getchar() != '\n');
    }

    printf("\n\nGoodbye!\n\n");
    return 0;
}
