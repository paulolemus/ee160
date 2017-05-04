/* File: RoadTrip.c
 * Name:
 * Date:
 * Team:
 */

#include <stdio.h>
#include "fileIO.h"
#include "Node.h"
#include "pathplanning.h"



int main() {

    int listSize = 8;
    struct Node** adjList = parseGraph(listSize);

    
    int index = 0;
    struct Node* shortPath = shortestPath(adjList, listSize, enum City start, enum City goal);
    struct Node* longPath  = longestPath(adjList, listSize, enum City start, enum City goal);
    


    return 0;
}
