
/*	file   : julian.c
 *	by     :
 *	login  :
 *	date   : 2/17/2017
 *	team   : AMERICA
 *	members: Paulo Lemus, Kevin Liu, Christopher Amadola
 */

#include "julian.h"

int julian_date(int day, int month, int year)
/* Given: a day, month and year year
   Returns: the julian date for that day.
 */
{  
/* this the stub version of julian_date().  it just
	always returns the same answer, 31 (31 Jan of any year)  */
 
	#ifdef DEBUG
	printf("debug:Enter julian_date: day = %d, month = %d, year = %d\n",
		day, month, year);
	#endif

	#ifdef DEBUG
	printf("debug:Exit julian_date: stub says 31\n");
	#endif

	return 31;
}

