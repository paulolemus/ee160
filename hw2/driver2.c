//      File:   driver2.c
//      By:     Kevin Liu
//      login:  liukevin
//      Team:   AMERICA
//      Member: Paulo, Christopher
//      Date:   02/21/17

/*      returns number of days in that month    */

#include <stdio.h>
#include "leap.h"
#include "days.h"

int main()
{
        int month, year;
        
        /*  start program and ask for input  */
        printf("Starting Days in a Month Program...\n");
        printf("Enter a month and a year (mm yy): ");

        /*  calculate days in month if EOF not entered  */
        while (scanf("%d %d", &month, &year) != EOF)
        {
                /*  print results and ask for new input  */
                printf("There are %d days in that month\n", days_in_month(month, year));
                printf("Enter a month and a year (mm yy): ");
        }
        /*  clean exit  */
        return (printf("\nGoodbye!\n"));
}
