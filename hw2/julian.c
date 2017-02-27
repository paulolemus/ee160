
/*	file   : julian.c
 *	by     : Paulo Lemus
 *	login  : Plemus
 *	date   : 2/23/2017
 *	team   : AMERICA
 *	members: Paulo Lemus, Kevin Liu, Christopher Amadola
 */

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
 * 3. Return sum
 *
 */
int julian_date(int day, int month, int year){  
    int sum = 0;
    int i;

    sum += day;
    for(i = 1; i < month; i++){
        sum += days_in_month(i, year);
    }

    if(day > days_in_month(month, year)) return -1;
    return sum;
}
