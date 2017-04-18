/*
 * file     : attack.h
 * by       : Paulo Lemus
 * login    : Plemus
 * date     : 4/12/2017
 * team     : AMERICA
 * members  : Paulo L, Christopher A, Kevin L
*/

#ifndef EE_HW4_ATTACK_H_
#define EE_HW4_ATTACK_H_

#define DEAD 0
#define ALIVE 1
#define SURVIVOR 2
#define POWEROVERWHELLMING 0

#define EASY_MODE   0
#define MEDIUM_MODE 1
#define HARD_MODE   2

int attack_easy(int mx, int my, int* ax, int* ay);
/* Updates the poistion of the attacker to move towards the mote.
 * Displays attacker at the new position.
 * Given: position of the mote (mx,my) and pointers to position of attacker
 * 		(ax,ay)
 * Returns: ALIVE if mote was not eaten
 * 		DEAD if the mote was eaten
 */

int attack_medium(int mx, int my, int* ax, int* ay);
/* A slightly harder difficulty version of the above function.
 * This function takes any path that moves closer to target, 
 * although this path pay be non-optimal
 */

int attack_hard(int mx, int my, int jx, int jy, int* ax, int* ay);
/* The Mook will attack by either taking an optimal path towards the user,
 * or under certain conditions, will guard the juju. The additional input,
 * jx and jy, are the x and y positions of the juju.
 */


#endif // EE_HW4_ATTACK_H_


