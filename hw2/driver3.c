//      File:   driver3.c
//      By:     Kevin Liu
//      login:  liukevin
//      Team:   AMERICA
//      Members:Paulo, Christopher
//      Date:   03/03/17

/*  main function to calculate julian date of given date  */

#include <stdio.h>
#include "julian.h"

int main()
{
        int day, month, year, julian;

        /*  program description  */
        printf("Starting Julian Date Program...\n");
        /*  ask for user input  */
        printf("Please enter a date (dd mm yy) EOF to exit: ");

        /*  when there are inputs  */
        while (scanf("%d %d %d", &day, &month, &year) != EOF)
        {
                /*  compute julian date  */
                julian = julian_date(day, month, year);
                /*  print julian date  */
                printf("The julian date is: day %d\n", julian);
                /*  get new input  */
                printf("Please enter a date (DD MM YYYY) [EOF to exit]: ");
        }
        /*  close program & exit  */
        printf("\nGoodbye!\n");
}
