/*
 * file     : attack.c
 * by       : Paulo Lemus
 * login    : Plemus
 * date     : 4/12/2017
 * team     : AMERICA
 * members  : Paulo L, Christopher A, Kevin L
*/

#include <stdlib.h>
#include "display.h"
#include "attack.h"


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
    int select = rand() % 2;

    if(select) {

        if(diffx > 0) *ax = *ax + 1;
        else if(diffx < 0) *ax = *ax - 1;
        else {
            if(diffy > 0) *ay = *ay + 1;
            else if(diffy < 0) *ay = *ay - 1;
        }
    }
    else {

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

    return ALIVE;
}


/* The Mook will attack by either taking an optimal path towards the user,
 * or under certain conditions, will guard the juju. The additional input,
 * jx and jy, are the x and y positions of the juju.
 */
int attack_hard(int mx, int my, int jx, int jy, int* ax, int* ay) {

    return ALIVE;
}




