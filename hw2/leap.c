
/*	file   : leap.c
 *	by     : Paulo Lemus
 *	login  : Plemus
 *	date   : 2/22/2017
 *	team   : AMERICA
 *	members: Paulo Lemus, Kevin Liu, Christopher Amedola
 */

#include "leap.h"

/* Given: a year
 * Returns: TRUE is year is a leap year, FALSE otherwise
 * 
 * A year is a leap year if:
 * 1. It is divisible by 400
 * 2. it is divisible by 4 but not 100.
 *
 * Status: FINISHED
 */
int is_leap(int year){
    int answer = 0;

    if(year % 400 == 0) answer = 1;
    if(year % 4   == 0 && year % 100 != 0) answer = 1;
	return answer;
}

