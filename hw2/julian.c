/*     File:    julian.c
 *     By:      Kevin Liu
 *     login:   liukevin
 *     Date:    03/03/17
 *     Team:    AMERICAC
 *     Members: Paulo, Christopher, Kevin  */

/*  function to compute julian date from days, months, and years  */

#include "julian.h"

int julian_date(int day, int month, int year)
{
        int julian;

        /*  add all the days in previous month(s)  */
        while(month > 0)
        {
                month--; //get previous month
                julian += days_in_month(month, year); //get days in previous month
        }
        /*  add current days passed to julian number  */
        julian += day;

        return julian;
}
