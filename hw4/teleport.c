/*
file    : teleport.c
by      : Paulo Lemus
login   : plemus
date    : 04/12/17
team    : AMERICA
members : Paulo, Chris, Kevin
*/

#include <unistd.h>
#include "teleport.h"
#include "display.h"
#include "place.h"

#define SLEEP_TIME 5000


/* Teleport the player to a random location
 * on the map.
 */
void teleport(int* xTim, int* yTim,
              int xSnek, int ySnek,
              int xJuju, int yJuju)
{
    int xNew = 0, yNew = 0;
    int lineWidth = 2;

    // Select a random point that is not on any row
    // or column as any of the game objects
    do {
        place(&xNew, &yNew);
    } while(xNew == *xTim || yNew == *yTim ||
            xNew == xSnek || yNew == ySnek ||
            xNew == xJuju || yNew == yJuju);

    // Draw a wave that moves from the upper left corner
    // of the screen to the bottom right corner.
    int i, j, k;
    for(i = 0; i < WIDTH + HEIGHT + lineWidth; ++i) {

        // Fill up lines with TIMMYS
        for(j = i, k = 0; j >= 0; --j, ++k) {

            if((j != xSnek || k != ySnek) &&
               (j != xJuju || k != yJuju) &&
               (j < WIDTH)                &&
               (k < HEIGHT)) 
            {
                draw_symbol(j, k, TIMMY);
            }
        }

        // Clear previous lines
        for(j = i - lineWidth, k = 0; j >= 0; --j, ++k) {

            if((j != xNew  || k != yNew)  &&
               (j != xSnek || k != ySnek) &&
               (j != xJuju || k != yJuju) &&
               (j < WIDTH)                &&
               (k < HEIGHT)) 
            {
                draw_symbol(j, k, ' ');
            }
        }
        // Sleep for 5 milliseconds so we can see animation
        usleep(SLEEP_TIME);
    }
    // Set timmy's position to the updated location
    *xTim = xNew;
    *yTim = yNew;
}
