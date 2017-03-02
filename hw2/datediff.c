/* File   : datediff.c
 * Name   : Paulo Lemus
 * Id     : Plemus
 * Team   : AMERICA
 * Members: Paulo Lemus, Kevin Liu, Christpoher Amedola
 */

#include <stdio.h>
#include "julian.h"


int main(){

    // Cool intro text worth extra points
    printf("                 __  __  ___  __            \n");
    printf("  /\\   |\\    /| |   |  |  |  |     /\\    \n");
    printf(" /--\\  | \\  / | |-- |__|  |  |    /--\\   \n");
    printf("/    \\ |  \\/  | |__ | \\  _|_ |__ /    \\ \n\n");
    printf("Welcome to TEAM AMERICA's date difference premier experience!");
    printf("\nThis program will calculate the difference between two dates.");
    printf("\nYou can enter your starting and ending dates below.\n");

    while(1){
        char c;
        int s_day, s_month, s_year;
        int e_day, e_month, e_year;
        int chk1, chk2, chk3, chk4, chk5, chk6;

        /* Get user input and check for invalids.
         * Code is written so if the user enters EOF
         * in any case, the program will immediately quit.
         * Otherwise, the program will check if there were any
         * issues with the user input for a date and continue
         * to the next loop if there was. Otherwise, the input
         * is valid and the loop moves on to evaluate the dates.
         */
        printf("\nEnter starting date (mm dd yyyy): ");
        if((chk1 = scanf("%d", &s_month)) == EOF) break;
        if((chk2 = scanf("%d", &s_day))   == EOF) break;
        if((chk3 = scanf("%d", &s_year))  == EOF) break;
        if(!chk1 || !chk2 || !chk3){
            printf("An invalid value was entered. Try again");
            while(c = getchar() != '\n' && c != EOF);
            continue;
        }

        printf("Enter ending date (mm dd yyyy): ");
        if((chk4 = scanf("%d", &e_month)) == EOF) break;
        if((chk5 = scanf("%d", &e_day))   == EOF) break;
        if((chk6 = scanf("%d", &e_year))  == EOF) break;
        if(!chk4 || !chk5 || !chk6){
            printf("\nAn invalid value was entered. Try again");
            while(c = getchar() != '\n' && c != EOF);
            continue;
        }

        ////////////////////////////////////////////////////
        //           Calculate date from input            //
        ////////////////////////////////////////////////////

        /* Algorithm:
         * 1. Determine which date is greater.
         *    If the end date is less than start, swap the dates
         *    and remember they are swapped.
         * 2. Add up each year's total number of days
         * 3. For start, remove the days between the start and 
         *    the beginning of the year.
         * 4. For end, remove the days between the end date and
         *    the end of the year.
         * 5. If the dates were swapped, make the diff negative.
         */
        int totalDiff = 0;
        int dir;
        int i;

        // determine which date is greater
        dir = (e_year >= s_year) ? 1 : -1;
        if(e_year == s_year){
            dir = (julian_date(e_day, e_month, e_year) >= 
                   julian_date(s_day, s_month, s_year)) ? 1 : -1;
        }
        // If start > end, swap the dates for calculation
        if(dir == -1){
            int temp1, temp2, temp3;
            temp1   = s_year;
            temp2   = s_month;
            temp3   = s_day;
            s_year  = e_year;
            e_year  = temp1;
            s_month = e_month;
            e_month = temp2;
            s_day   = e_day;
            e_day   = temp3;
        }

        // sum up each year's total # of days
        for(i = s_year; i <= e_year; i++){
            totalDiff += julian_date(31, 12, i);
        }
        // remove the difference from start to beginning of year and
        // from end to end of year.
        totalDiff -= julian_date(31, 12, e_year) - julian_date(e_day, e_month, e_year);
        totalDiff -= julian_date(s_day, s_month, s_year);
        totalDiff *= dir;

        printf("\nThe number of days between the ");
        printf("start and end is %d days\n\n", totalDiff);
    }
    printf("\n\nGoodbye!\n\n");
    return 0;
}
