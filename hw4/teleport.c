/*
file    : teleport.c
by      : Paulo Lemus
login   : plemus
date    : 04/12/17
team    : AMERICA
members : Paulo, Chris, Kevin
*/

#include "teleport.h"
#include "display.h"
#include "place.h"

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

    int i, j, k;
    for(i = 0; i < WIDTH + lineWidth; ++i) {

        // Fill up lines with TIMMYS
        for(j = i, k = 0; j >= 0 && k < HEIGHT; --j, ++k) {
            if((j != xSnek && k != ySnek) &&
               (j != xJuju && k != yJuju)) draw_symbol(j, k, TIMMY);

        }

        // Clear previous lines
        for(j = i - lineWidth, k = 0; j >= 0 && k < HEIGHT; --j, ++k) {
            if((j != *xTim && k != *yTim) &&
               (j != xSnek && k != ySnek) &&
               (j != xJuju && k != yJuju)) draw_symbol(j, k, ' ');
        }
    }
    *xTim = xNew;
    *yTim = yNew;
}
