/*	file   : driver1.c
 *	by     : Paulo Lemus
 *	login  : plemus
 *	date   : 2/17/2017
 *	team   : AMERICA
 *	members: Paulo Lemus, Kevin Liu, Christopher Amedola
 */

/* A program to test the validity of int is_leap(int year) function.
 * This program requests user to enter a year, and will
 * print whether or not the year is a leap year.
 * This program continues to run until the user enters 0.
 *
 * Status: FINISHED
 */

#include <stdio.h>
#include "leap.h"

int main(){

    int year;
    int isLeap;

    printf("Enter a year: ");
    scanf("%d", &year);

    while(year != 0){
        // Evaluate if year is a leap year.
        // print answer.
        // reprompt user.
        isLeap = is_leap(year);
        if(isLeap) printf("%d is a leap year.\n", year);
        else       printf("%d is not a leap year.\n", year);

        while(getchar() != '\n');
        printf("Enter a year: ");
        scanf("%d", &year);
    }

    printf("\nGoodbye!\n\n");
    return 0;
}
