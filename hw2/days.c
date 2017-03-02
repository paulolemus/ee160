/* File   : days.c
 * By     : Kevin Liu
 * login  : liukevin
 * Team   : AMERICA
 * Members: Paulo, Christopher
 * Date   : 02/21/17
 */

/* Function Definiton to get numbers of days in that month
 * 
 * ALGORITHM:
 * 1. Return error value if the month given is out of bounds
 * 2. Assign days using even months = 30 and odd months = 31
 *    This covers months 1-7 except for 2
 * 3. Assign days for months greater than 7 months, where case
 *    switches, as evens = 31 and odds = 30.
 * 4. Lastly, check if the month is february. If it is,
 *    then assign days the number of days in feb. checking
 *    if it is in a leap year.
 */

#include "days.h"
#include "leap.h"

int days_in_month(int month, int year){
    int days = 0;

    // check bounds
    if(month > 12) return -1;
    
    // Figure out number of days
    if(month % 2 == 1 && month < 8) days = 31;
    else days = 30;
    if(month % 2 != 0 && month > 7) days = 30;
    if(month % 2 == 0 && month > 7) days = 31;
    if(month == 2) days = 28 + is_leap(year);

    return days;
}
