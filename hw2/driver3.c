/*	file   : driver3.c
 *	by     : Paulo Lemus
 *	login  : plemus
 *	date   : 2/17/2017
 *	team   : AMERICA
 *	members: Paulo Lemus, Kevin Liu, Christopher Amedola
 */

/* A program to test the validity of int julian_date function.
 *
 * This program asks user to enter a month, day, and year, and 
 * prints the julian date.
 *
 * Status: FINIHSED, needs comments
 */

#include <stdio.h>
#include "julian.h"

int main(){

    int day;
    int month;
    int year;

    printf("Entering Julian date driver...\n\n");
    printf("Enter a month, day, and year (mm dd yyyy): ");

    while(scanf("%d", &month) != EOF &&
          scanf("%d", &day)   != EOF &&
          scanf("%d", &year)  != EOF){

        printf("Julian date of %d/%d in %d: %d",
               month,
               day,
               year,
               julian_date(day, month, year));

        while(getchar() != '\n');
        printf("Enter a month, day, and year (mm dd yyyy): ");
    }

    printf("\nGoodbye!\n\n");
    return 0;
}
