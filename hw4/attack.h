/*
file: attack.h
by:
login:
date:
team:
members:
*/

#define DEAD 0
#define ALIVE 1
#define POWEROVERWHELLMING 0

int attack(int mx, int my, int* ax, int* ay);
/* Updates the poistion of the attacker to move towards the mote.
 * Displays attacker at the new position.
 * Given: position of the mote (mx,my) and pointers to position of attacker
 * 		(ax,ay)
 * Returns: ALIVE if mote was not eaten
 * 		DEAD if the mote was eaten */
