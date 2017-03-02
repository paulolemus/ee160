
/*	file   : leap.c
 *	by     : Chris Camendola
 *	login  : camendol
 *	date   : 3/1/2017
 *	team   : AMERICA
 *	members: Paulo Lemus, Kevin Liu, Christopher Amendola
 */

#include "leap.h"

/* Given: a year
 * Returns: TRUE is year is a leap year, FALSE otherwise
 * 
 * ALGORITHM:
 * If year divided by 4 has no remainder and year divided
 * by 100 has a remainder, return 1
 * else if year divided by 400 has no remainder return 1
 * else return 0
 *
 * Status: FINISHED
 */
int is_leap(int year){

    if(year % 4 == 0 && year % 100 != 0) return 1;
    else if(year % 400 == 0) return 1;
    else return 0;
}

