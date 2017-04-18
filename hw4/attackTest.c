/* File     : attackTest.c
 * Name     : Paulo Lemus
 * Login    : Plemus
 * Date     : 4/12/2017
 * Team     : AMERICA
 * Members  : Christopher A, Paulo L, Kevin L
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"
#include "move.h"
#include "place.h"
#include "attack.h"

int main() {

    // seed rand so we get different values each time
    srand(time(NULL));

    int timX  = 0, timY  = 0;
    int snekX = 0, snekY = 0;
    int xJuju = WIDTH / 2, yJuju = HEIGHT / 2;

    char cmd  = 'v'; // random
    char diff = 'e'; // Difficulty of snek
    int state;

    // Place the snek at a random location
    while(snekX == timX && snekY == timY) place(&snekX, &snekY);

    // All text we will render to screen
    char* text[10];
    text[1] = "Welcome! This is a attack test for the snek.";
    text[2] = "Use the a, s, d, f control scheme to move.";
    text[3] = "Alternatively, use the i, j, k, l scheme.";
    text[5] = "The snek has 3 difficulty levels: easy, medium, hard.";
    text[6] = "Press e for easy, r for medium, and t for hard.";
    text[7] = "The snek's position is shown in the lower left corner.";

    // Draw everything prior to the first loop
    draw_map();
    debug_wds(1, text[1]);
    debug_wds(2, text[2]);
    debug_wds(3, text[3]);
    debug_wds(5, text[5]);
    debug_wds(6, text[6]);
    debug_wds(7, text[7]);
    debug_wds(8, "easy");

    draw_symbol(timX,  timY,  TIMMY);
    draw_symbol(snekX, snekY, MOOK);
    draw_symbol(xJuju, yJuju, JUJU);
    display_pos(snekX, snekY);
    display_score(-999);

    while(cmd != 'q') {
        cmd = move(&timX, &timY);

        // get difficulty of applicable
        if(cmd == 'e' || cmd == 'r' || cmd == 't')
            diff = cmd;
        
        // Snake attack with given difficulty
        if(diff == 'e') {
            state = attack_easy(timX, timY, &snekX, &snekY);
            debug_wds(8, "easy");
        }
        else if(diff == 'r') {
            state = attack_medium(timX, timY, &snekX, &snekY);
            debug_wds(8, "medium");
        }
        else if(diff == 't') {
            state = attack_hard(timX, timY, xJuju, yJuju, &snekX, &snekY);
            debug_wds(8, "hard");
        }
        else exit(-1);

        // Update position tracker
        display_pos(snekX, snekY);
        draw_symbol(xJuju, yJuju, JUJU);

        // Quit if player is dead
        if(state == DEAD) cmd = 'q';
    }

    clear_screen();
    if(state == DEAD) printf("You have died!\n");
    else              printf("You made it out!!\n");
    return 0;
}
