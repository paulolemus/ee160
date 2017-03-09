/* File   : datediff.c
 * Name   : Paulo Lemus
 * Id     : Plemus
 * Date   : 3/2/2017
 * Team   : AMERICA
 * Members: Paulo Lemus, Kevin Liu, Christpoher Amendola
 */

#include <stdio.h>
#include "datediff.h"
#include "julian.h"


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
 *
 * Note: This will return a negative number of days if
 *       start date > end date. This is intentional.
 */
int dateDifference(int sday, int smonth, int syear, int eday, int emonth, int eyear){
#ifdef DEBUG
    printf("day: %d, month: %d, year: %d, eday: %d, e_month: %d, eyear: %d",
            sday, smonth, syear, eday, emonth, eyear);
#endif
    int totalDiff = 0;
    int dir;
    int i;


    // determine which date is greater
    dir = (eyear >= syear) ? 1 : -1;
    if(eyear == syear){
        dir = (julian_date(eday, emonth, eyear) >= 
               julian_date(sday, smonth, syear)) ? 1 : -1;
    }
    // If start > end, swap the dates for calculation
    if(dir == -1){
        int temp1, temp2, temp3;
        temp1  = syear;
        temp2  = smonth;
        temp3  = sday;
        syear  = eyear;
        eyear  = temp1;
        smonth = emonth;
        emonth = temp2;
        sday   = eday;
        eday   = temp3;
    }

    // sum up each year's total # of days
    for(i = syear; i <= eyear; i++){
        totalDiff += julian_date(31, 12, i);
    }
    // remove the difference from start to beginning of year and
    // from end to end of year.
    totalDiff -= julian_date(31, 12, eyear) - julian_date(eday, emonth, eyear);
    totalDiff -= julian_date(sday, smonth, syear);
    totalDiff *= dir;

#ifdef DEBUG
    printf("TotalDiff: %d", totalDiff);
#endif
    return totalDiff;
}


int main(){

    // Cool intro text worth extra points
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
        int totalDiff;

        /* Get user input and check for invalids.
         * Code is written so if the user enters EOF
         * in any case, the program will immediately quit.
         * Otherwise, the program will check if there were any
         * issues with the user input for a date and continue
         * to the next loop if there was. Otherwise, the input
         * is valid and the loop moves on to evaluate the dates.
         *
         * Note: I only use break and continue in the beginning
         *       of this while loop to validate user input so I
         *       assume this is fine. They do not hurt readability,
         *       nor are they nested deep in a loop.
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

        /* Check for invalid dates */
        if(julian_date(s_day, s_month, s_year) == -1 ||
           julian_date(e_day, e_month, e_year) == -1){

            printf("\nAn invalid date was entered. Try again");
            while(c = getchar() != '\n' && c != EOF);
            continue;
        }

        ////////////////////////////////////////////////////
        //           Calculate date from input            //
        ////////////////////////////////////////////////////

        totalDiff = dateDifference(s_day, s_month, s_year, e_day, e_month, e_year);

        printf("\nThe number of days between ");
        printf("%d/%d/%d and %d/%d/%d is ", s_month, s_day, s_year, 
                                            e_month, e_day, e_year);
        if(totalDiff == 1) printf("%d day\n\n", totalDiff);
        else               printf("%d days\n\n", totalDiff);

    } // while loop

    printf("\n\nGoodbye!\n\n");
    return 0;
}
