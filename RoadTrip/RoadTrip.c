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

    int listSize = 8;
    struct Node** adjList  = parseGraph(listSize);
    struct Node* shortPath = shortestPath(adjList, listSize, SAN_FRAN, NEW_YORK);
    struct Node* longPath  = longestPath (adjList, listSize, SAN_FRAN, NEW_YORK);
    return 0;
}
