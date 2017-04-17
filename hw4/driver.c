/*
 * file    : driver.c
 * by      : Paulo Lemus
 * login   : Plemus
 * date    : 4/16/2017
 * team    : AMERICA
 * members : Paulo L, Kevin L, Christopher A
*/

/* This is the main driver for the gsnake game.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "display.h"
#include "move.h"
#include "place.h"
#include "attack.h"

int main()
{
    srand(time(NULL));

    int xTim,  yTim;            // Timmy!
    int xSnek, ySnek;           // Snek! (the Mook)
    int xJuju, yJuju;           // Juju!
    int state = ALIVE;          // Timmy starts alive, duh
    int score = 0;              // Score goes up with each Juju
    char cmd  = 'v';            // Store user input
    int difficulty = EASY_MODE; // Game starts in easy mode

    place(&xTim, &yTim); // place Timmy somewhere random to start
    // Place snek and Juju somewhere NOT on Timmy's axes.
    do place(&xSnek, &ySnek); while(xSnek == xTim || ySnek == yTim);
    do place(&xJuju, &yJuju); while(xJuju == xTim || yJuju == yTim);

    // Draw everything to screen
    draw_map();

    draw_symbol(xTim,  yTim,  TIMMY);
    draw_symbol(xJuju, yJuju, JUJU);
    draw_symbol(xSnek, ySnek, MOOK);

    display_pos(xTim, yTim);
    display_score(score);

    // Main game logic while loop
    while(cmd != 'q' && state == ALIVE) {

        // Draw juju in case the snek moved over it
        draw_symbol(xJuju, yJuju, JUJU);

        // Move Timmy
        cmd = move(&xTim, &yTim);

        // Snek attack
        if(difficulty == HARD_MODE) {
            state = attack_hard(xTim, yTim, xJuju, yJuju, &xSnek, &ySnek);
        }
        else if(difficulty == MEDIUM_MODE) {
            state = attack_medium(xTim, yTim, &xSnek, &ySnek);
            if(score > 20) difficulty = HARD_MODE;
        }
        else {
            state = attack_easy(xTim, yTim, &xSnek, &ySnek);
            if(score > 10) difficulty = MEDIUM_MODE;
        }

        // Juju logic
        if(xTim == xJuju && yTim == yJuju) {
            score++;
            do {
                place(&xJuju, &yJuju);
            } while(xJuju == xTim || xJuju == xSnek || 
                    yJuju == yTim || yJuju == ySnek);
            draw_symbol(xJuju, yJuju, JUJU);
        }

        // Update counters || Strings
        display_pos(xTim, yTim);
        display_score(score);
    }

	clear_screen();
    if(state == DEAD) printf("Timmy has tragically died in College\n");
    else              printf("You da man Timmy. You are a SURVIVOR OF COLLEGE\n");
	return 0;
}
