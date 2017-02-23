/* File  : driver2.c
 * By    : Kevin Liu
 * login : liukevin
 * Team  : AMERICA
 * Member: Paulo, Christopher
 * Date  : 02/21/17
 */

/* returns number of days in that month
 *
 * Status: Finished, needs comments
 */

#include <stdio.h>
#include "days.h"

int main(){
    int month, year;

    printf("Starting Days in a Month Program...");
    printf("\nEnter a month and a year (mm yy): ");

    while (scanf("%d %d", &month, &year) != EOF){
        printf("There are %d days in that month.", days_in_month(month, year));
        printf("\nEnter a month and a year (mm yy): ");
    }
    return (printf("\n\nGoodbye!\n\n"));
}
