/* File   : days.c
 * By     : Kevin Liu, Paulo Lemus
 * login  : liukevin
 * Team   : AMERICA
 * Members: Paulo, Christopher
 * Date   : 02/21/17
 */

/* Function Definiton to get numbers of days in that month
 *
 * Status: FINISHED, needs comments
 */

#include "days.h"
#include "leap.h"

int days_in_month(int month, int year){
    int days = 0;
    
    days = (month % 2 == 1 && month < 8) ? 31 : 30;
    if(month % 2 != 0 && month > 7) days = 30;
    if(month % 2 == 0 && month > 7) days = 31;
    if(month == 2) days = 28 + is_leap(year);
    return days;
}
