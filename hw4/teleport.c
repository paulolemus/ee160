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

    // Select a random point that is not on any row
    // or column as any of the game objects
    do {
        place(&xNew, &yNew);
    } while(xNew == *xTim || yNew == *yTim ||
            xNew == xSnek || yNew == ySnek ||
            xNew == xJuju || yNew == yJuju);

    int i, j;
    for() {


    }


}
