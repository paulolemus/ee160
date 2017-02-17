
/*	file   : leap.c (stub version)
 *	by     : 
 *	login  :
 *	date   : 2/17/2017
 *	team   : AMERICA
 *	members: Paulo Lemus, Kevin Liu, Christopher Amedola
 */

#include "leap.h"

int is_leap(int year)
/* Given: a year
   Returns: TRUE is year is a leap year, FALSE otherwise
 */
{  int answer;
 
/* this the stub version of isleap().  it justs asks
	the user for the answer  */

	printf("Is %d a leap year? (1 for yes, 0 for no):");
	scanf("%d", &answer);

	return answer;
}

