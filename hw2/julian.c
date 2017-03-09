/*     File:    julian.c
 *     By:      Kevin Liu
 *     login:   liukevin
 *     Date:    03/03/17
 *     Team:    AMERICAC
 *     Members: Paulo, Christopher, Kevin  */

#ifdef DEBUG
#include <stdio.h>
#endif

#include "julian.h"
#include "days.h"

/* This function returns the cardinal day of the month.
 * This uses the days_in_month function to tell how many 
 * days there are in the month considering the year.
 *
 * ALGORIHM:
 * 1. sum up all days in month from month 1 to month n.
 *    These can be taken directly from days_in_month.
 * 2. For the last month, use days-in-month to check that
 *    the "day" field is valid, then add it to the sum.
 * 3. If the day of the month is out of bounds, return -1
 * 4. Return sum
 *
 */
int julian_date(int day, int month, int year){
#ifdef DEBUG
    printf("day: %d, month: %d, year: %d\n", day, month, year);
#endif
    int sum = 0;
    int i;

    sum += day;
    for(i = 1; i < month; i++){
        sum += days_in_month(i, year);
    }

    if(day > days_in_month(month, year)) return -1;
#ifdef DEBUG
    printf("Sum: %d\n", sum);
#endif
    return sum;
}
