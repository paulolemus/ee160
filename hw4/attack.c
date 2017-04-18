/*
 * file     : attack.c
 * by       : Paulo Lemus
 * login    : Plemus
 * date     : 4/12/2017
 * team     : AMERICA
 * members  : Paulo L, Christopher A, Kevin L
*/

#include <stdlib.h>
#include "attack.h"
#include "display.h"


/* Updates the position of the attacker to move towards the mote.
 * Displays attacker at the new position.
 * Given: position of the mote (mx,my) and pointers to position of attacker
 * 		(ax,ay)
 * Returns: ALIVE if mote was not eaten
 * 		DEAD if the mote was eaten
 */
int attack_easy(int mx, int my, int* ax, int* ay) {

    // Clear the snek's current position
    draw_symbol(*ax, *ay, ' ');

    /* If diffx > 0, timmy is to the right of snek.
     * If diffx < 0, timmy is to the left of snek.
     *
     * If diffy > 0, timmy is below snek.
     * If diffy < 0, timmy is above snek.
     */
    int diffx  = mx - *ax;
    int diffy  = my - *ay;
    int select = rand() % 5;

    // snek will occasionally not move
    if(select == 0) {
        // Do not move
    }
    else if(select % 2 == 0) {

        if(diffx > 0) *ax = *ax + 1;
        else if(diffx < 0) *ax = *ax - 1;
        else {
            if(diffy > 0) *ay = *ay + 1;
            else if(diffy < 0) *ay = *ay - 1;
        }
    }
    else if(select % 2 == 1) {

        if(diffy > 0) *ay = *ay + 1;
        else if(diffy < 0) *ay = *ay - 1;
        else {
            if(diffx > 0) *ax = *ax + 1;
            else if(diffx < 0) *ax = *ax - 1;
        }
    }

    // Draw the snek
    draw_symbol(*ax, *ay, MOOK);

    // Check if snek has eaten timmy
    if(*ax == mx && *ay == my) return DEAD;
    else                       return ALIVE;
}


/* A slightly harder difficulty version of the above function.
 * This function takes any path that moves closer to target, 
 * although this path pay be non-optimal. This function also
 * takes into consideration how close timmy is across walls.
 */
int attack_medium(int mx, int my, int* ax, int* ay) {

    // Clear the snek's current position
    draw_symbol(*ax, *ay, ' ');

    // If the snek has not eaten Timmy,
    // then one of these variables will != 0.
    int horizontal = 0, vertical = 0;

    /* Figure out which direction has the shortest
     * distance to Timmy.
     */
    int xShort  = mx - *ax;
    int xDiff   = (mx - WIDTH) - *ax;
    xShort = (abs(xDiff) < abs(xShort)) ? xDiff : xShort;
    xDiff  = (mx + WIDTH) - *ax;
    xShort = (abs(xDiff) < abs(xShort)) ? xDiff : xShort;

    int yShort  = my - *ay;
    int yDiff   = (my - HEIGHT) - *ay;
    yShort = (abs(yDiff) < abs(yShort)) ? yDiff : yShort;
    yDiff  = (my + HEIGHT) - *ay;
    yShort = (abs(yDiff) < abs(yShort)) ? yDiff : yShort;
   
    if(xShort < 0)      horizontal = -1;
    else if(xShort > 0) horizontal = 1;
    if(yShort < 0)      vertical   = -1;
    else if(yShort > 0) vertical   = 1;


    // Move snek only one direction towards Timmy
    // with a random priority in either direction 
    // possible.
    int select = rand() % 2;
    if(select) {
        if(horizontal != 0) *ax = *ax + horizontal;
        else                *ay = *ay + vertical;
    }
    else {
        if(vertical != 0) *ay = *ay + vertical;
        else              *ax = *ax + horizontal;
    }

    // Teleport snek if boundary crossed
    if     ( *ax >= WIDTH )  *ax = 0;
    else if( *ay >= HEIGHT ) *ay = 0;
    else if( *ax < 0 )       *ax = WIDTH - 1;
    else if( *ay < 0 )       *ay = HEIGHT - 1;

    // Draw the snek
    draw_symbol(*ax, *ay, MOOK);

    // Check if snek has eaten timmy
    if(*ax == mx && *ay == my) return DEAD;
    else                       return ALIVE;
}

/* This mode is not necessarily hard, just different.
 * The snek will attempt to stay inbetween Timmy and the Juju
 * and will occasionally attack Timmy if it is currently in a good
 * position to defend.
 */
int attack_hard(int mx, int my, int jx, int jy, int* ax, int* ay) {

    // Clear the snek's current position
    draw_symbol(*ax, *ay, ' ');

    int horizontal = 0, vertical = 0;

    int xTemp, yTemp;
    int xJuju = jx, yJuju = jy;
   
    // Find midpoint and slope of line connecting nearest Juju and Timmy
    int xMidEst = (mx + xJuju) / 2;
    int yMidEst = (my + yJuju) / 2;
    float slope = (mx - xJuju) * 1.0f / (my - yJuju);
    if(xMidEst >= WIDTH)  xMidEst -= WIDTH;
    else if(xMidEst < 0)  xMidEst += WIDTH;
    if(yMidEst >= HEIGHT) yMidEst -= HEIGHT;
    else if(yMidEst < 0)  yMidEst += HEIGHT;
    
    // Determine if the snek is close to the line
    int closeToLine = 0;
    int i;
    for(i = 0; i < WIDTH / 5; ++i)
    {
        // Check if snek is close in one direction
        int xLine = xMidEst + i;
        if(xLine >= WIDTH) xLine = xLine - WIDTH;
        int yLine = yMidEst + slope * (xLine - xMidEst);
        if(yLine >= HEIGHT) yLine -= HEIGHT;
        else if(yLine < 0)  yLine += HEIGHT;
        int distance = abs(*ax - xLine) + abs(*ay - yLine);

        if(distance < 3) closeToLine = 1;

        // Check if snek is close in other direction
        xLine = xMidEst - i;
        if(xLine < 0) xLine = xLine + WIDTH;
        yLine = yMidEst + slope * (xLine - xMidEst);
        if(yLine >= HEIGHT) yLine -= HEIGHT;
        else if(yLine < 0)  yLine += HEIGHT;
        distance = abs(*ax - xLine) + abs(*ay - yLine);

        if(distance < 3) closeToLine = 1;
    }

    // If snek is close to line, attack Timmy.
    // Otherwise, move towards the middle of the line
    int delTimSnek = 
        abs(abs(mx - jx) + abs(my - jy) - abs(*ax - jx) - abs(*ay - jy));

    if(closeToLine && delTimSnek > 1) {

        // Attack Timmy!
        int xShort  = mx - *ax;
        int xDiff   = (mx - WIDTH) - *ax;
        xShort = (abs(xDiff) < abs(xShort)) ? xDiff : xShort;
        xDiff  = (mx + WIDTH) - *ax;
        xShort = (abs(xDiff) < abs(xShort)) ? xDiff : xShort;

        int yShort  = my - *ay;
        int yDiff   = (my - HEIGHT) - *ay;
        yShort = (abs(yDiff) < abs(yShort)) ? yDiff : yShort;
        yDiff  = (my + HEIGHT) - *ay;
        yShort = (abs(yDiff) < abs(yShort)) ? yDiff : yShort;
       
        if(xShort < 0)      horizontal = -1;
        else if(xShort > 0) horizontal = 1;
        if(yShort < 0)      vertical   = -1;
        else if(yShort > 0) vertical   = 1;

    }
    else if(abs(xJuju - *ax) + abs(yJuju - *ay) < 3) {

        // Move towards midpoint
        int xShort  = xMidEst - *ax;
        int xDiff   = (xMidEst - WIDTH) - *ax;
        xShort = (abs(xDiff) < abs(xShort)) ? xDiff : xShort;
        xDiff  = (xMidEst + WIDTH) - *ax;
        xShort = (abs(xDiff) < abs(xShort)) ? xDiff : xShort;

        int yShort  = yMidEst - *ay;
        int yDiff   = (yMidEst - HEIGHT) - *ay;
        yShort = (abs(yDiff) < abs(yShort)) ? yDiff : yShort;
        yDiff  = (yMidEst + HEIGHT) - *ay;
        yShort = (abs(yDiff) < abs(yShort)) ? yDiff : yShort;
       
        if(xShort < 0)      horizontal = -1;
        else if(xShort > 0) horizontal = 1;
        if(yShort < 0)      vertical   = -1;
        else if(yShort > 0) vertical   = 1;

    }
    else {
        
        // Defend Juju
        int xShort  = xJuju - *ax;
        int xDiff   = (xJuju - WIDTH) - *ax;
        xShort = (abs(xDiff) < abs(xShort)) ? xDiff : xShort;
        xDiff  = (xJuju + WIDTH) - *ax;
        xShort = (abs(xDiff) < abs(xShort)) ? xDiff : xShort;

        int yShort = yJuju - *ay;
        int yDiff  = (yJuju - HEIGHT) - *ay;
        yShort = (abs(yDiff) < abs(yShort)) ? yDiff : yShort;
        yDiff  = (yJuju + HEIGHT) - *ay;
        yShort = (abs(yDiff) < abs(yShort)) ? yDiff : yShort;
       
        if(xShort < 0)      horizontal = -1;
        else if(xShort > 0) horizontal = 1;
        if(yShort < 0)      vertical   = -1;
        else if(yShort > 0) vertical   = 1;
    }

    // Move snek
    int select = rand() % 2;
    if(select) {
        if(horizontal != 0) *ax = *ax + horizontal;
        else                *ay = *ay + vertical;
    }
    else {
        if(vertical != 0) *ay = *ay + vertical;
        else              *ax = *ax + horizontal;
    }

    // Teleport snek if boundary crossed
    if     ( *ax >= WIDTH )  *ax = 0;
    else if( *ay >= HEIGHT ) *ay = 0;
    else if( *ax < 0 )       *ax = WIDTH - 1;
    else if( *ay < 0 )       *ay = HEIGHT - 1;

    // Draw the snek
    draw_symbol(*ax, *ay, MOOK);

    // Check if snek has eaten timmy
    if(*ax == mx && *ay == my) return DEAD;
    else                       return ALIVE;
}




