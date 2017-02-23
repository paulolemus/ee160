//      File:   days.c
//      By:     Kevin Liu
//      login:  liukevin
//      Team:   AMERICA
//      Members:Paulo, Christopher
//      Date:   02/21/17

/*      Function Definiton to get numbers of days in that month */

#include "days.h"

int days_in_month(int month, int year)
{
        if (month <= 7) //when months July and before 
        {
                if (month % 2 != 0) //if odd months (Jan, Mar, May, July)
                        return 31;
                else //if even months (Feb, Apr, June)
                {
                        if (month == 2) //February
                        {
                                if (is_leap(year) == TRUE)
                                        return 29;
                                else
                                        return 28;
                        }
                        else //April & June
                                return 30;
                }
        }
        else //months after July
        {
                if (month % 2 != 0) //if odd months (Sept, Nov)
                        return 30;
                else //if even months (Aug, Oct, Dec)
                        return 31;
        }
}
