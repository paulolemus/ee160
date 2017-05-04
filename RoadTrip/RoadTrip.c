/* File: RoadTrip.c
 * Name: Paulo L, Kevin L, Chris A
 * Date: May 3rd 2017
 * Team: AMERICA
 */

#include <stdio.h>
#include "fileIO.h"
#include "Node.h"
#include "pathplanning.h"

int main() {

    /* declare & initialize variables */
    int listSize = 8;
    
    /* path computations */
    struct Node** adjList  = parseGraph(listSize);
    struct Node* shortPath = shortestPath(adjList, listSize, SAN_FRAN, NEW_YORK);
    struct Node* longPath  = longestPath (adjList, listSize, SAN_FRAN, NEW_YORK);

    printf("The Shortest Path is:\n");
    printf("%s -> %s -> %s -> %s\n", &shortPath->city, &shortPath->city, &shortPath->city);
    printf("The Longest Path is:\n");
    printf("%s -> %s -> %s -> %s\n", &longPath->city, &longPath->city, &longPath->city, &longPath->city);
    printf("%d");

    return 0;
}
