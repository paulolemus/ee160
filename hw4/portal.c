/*  File:   portal.c
 *  By:     Kevin Liu
 *  Login:  liukevin
 *  Team:   AMERICA     */

/*  Function Definition for portal_print    */

#include "portal.h"
#include "display.h"


void portal_print(int x, int y)
/*  Given: last Juju's position
 *  Prints a rectangle around it as a portal    */
{
    /*  left of Juju    */
    for(int i = -1; i < 2; i++)
    {
        draw_symbol(x-1,y+i,'x');
        draw_symbol(x+1,y+i,'x');
    }

    /*  top/bottom of Juju  */
    draw_symbol(x,y-1,'x');
    draw_symbol(x,y+1,'x');
}
