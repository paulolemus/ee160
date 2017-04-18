/*
 * file    : driver.c
 * by      : Paulo Lemus
 * login   : Plemus
 * date    : 4/16/2017
 * team    : AMERICA
 * members : Paulo L, Kevin L, Christopher A
 */

/* This is the main driver for the gsnake game.
 * "Teleport is a somewhat hidden feature, in that
 * we do not tell you there is a limit or what button
 * you need to press.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "display.h"
#include "move.h"
#include "place.h"
#include "attack.h"
#include "portal.h"
#include "teleport.h"

int main()
{
    // Seed the rand function once at beginning of game
    srand(time(NULL));

    int xTim,  yTim;            // Timmy!
    int xSnek, ySnek;           // Snek! (the Mook)
    int xJuju, yJuju;           // Juju!
    int state = ALIVE;          // Timmy starts alive, duh
    int score = 23;              // Score goes up with each Juju
    char cmd  = 'v';            // Store user input
    int difficulty = EASY_MODE; // Game starts in easy mode
    int teleports = 0;          // teleportation counter

    // place Timmy somewhere random to start
    place(&xTim, &yTim); 
    // Place snek and Juju somewhere NOT on Timmy's axes.
    do place(&xSnek, &ySnek); while(xSnek == xTim || ySnek == yTim);
    do place(&xJuju, &yJuju); while(xJuju == xTim || yJuju == yTim);

    // All the text we display to the screen
    char* warnings[3];
    warnings[EASY_MODE] = "\"The creature is annoyed but sleepy...\"";
    warnings[MEDIUM_MODE] = "\"Its chasing me through walls!\"";
    warnings[HARD_MODE] = "\"Is it blocking that Juju?!?\"";

    char* text[12];
    text[2] = "I wanna go home!";
    text[4] = "o - Timmy";
    text[5] = "$ - Juju";
    text[6] = "M - Mook";
    text[8] = "A portal! My way home!";
    text[10] = warnings[difficulty];


    // Draw everything to screen once prior while loop
    draw_map();
    draw_symbol(xTim,  yTim,  TIMMY);
    draw_symbol(xJuju, yJuju, JUJU);
    draw_symbol(xSnek, ySnek, MOOK);
    debug_wds(2, text[2]);
    debug_wds(4, text[4]);
    debug_wds(5, text[5]);
    debug_wds(6, text[6]);
    debug_wds(10, text[10]);
    display_pos(xTim, yTim);
    display_score(score);

    // Main game logic while loop
    while(cmd != 'q' && state == ALIVE) 
    {

        // Draw juju in case the snek moved over it
        draw_symbol(xJuju, yJuju, JUJU);

        // Move Timmy
        cmd = move(&xTim, &yTim);

        // Snek attack
        if(difficulty == HARD_MODE) 
        {
            state = attack_hard(xTim, yTim, xJuju, yJuju, &xSnek, &ySnek);
        }
        else if(difficulty == MEDIUM_MODE) 
        {
            state = attack_medium(xTim, yTim, &xSnek, &ySnek);
            if(score >= 20) 
            {
                difficulty = HARD_MODE;
                text[10] = warnings[difficulty];
            }
        }
        else 
        {
            state = attack_easy(xTim, yTim, &xSnek, &ySnek);
            if(score >= 10) 
            {
                difficulty = MEDIUM_MODE;
                text[10] = warnings[difficulty];
            }
        }

        // Juju logic
        if(xTim == xJuju && yTim == yJuju) 
        {
            score++;
            do {
                place(&xJuju, &yJuju);
            } while(xJuju == xTim || xJuju == xSnek || 
                    yJuju == yTim || yJuju == ySnek);
            draw_symbol(xJuju, yJuju, JUJU);
        }
        
        // Process special commands
        // Teleport
        if(cmd == ' ' && teleports < 3) 
        {
            teleports++;
            teleport(&xTim, &yTim, xSnek, ySnek, xJuju, yJuju);
        }

        if(score >= 24) 
        {//1 point away from winning
            debug_wds(8, text[8]);
            portal_print(xJuju, yJuju); //spawns portal around Juju
            draw_symbol(xTim, yTim, TIMMY); //draws Timmy over border of portal
        }

        if(score == 25) 
        { //beats the game!
            state = SURVIVOR;
        }
        // Update counters || Strings
        draw_symbol(xTim, yTim, TIMMY);
        display_pos(xTim, yTim);
        display_score(score);
        debug_wds(10, text[10]);
    }

    clear_screen();
    if(state == DEAD)       printf("Timmy has tragically died in College\n");
    else if(state == ALIVE) printf("Bro you totally quit. No props...\n");
    else                    printf("You da man Timmy. You are a SURVIVOR OF COLLEGE\n");
    return 0;
}
