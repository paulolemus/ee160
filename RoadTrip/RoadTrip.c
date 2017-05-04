/* File: RoadTrip.c
 * Name: Paulo L, Kevin L, Chris A
 * Date: May 3rd 2017
 * Team: AMERICA
 */

#include <stdio.h>
#include "fileIO.h"
#include "Node.h"
#include "pathplanning.h"


// These can be changed. Keep in mind that they can
// only be changed to already existing cities in the 
// City enum.
// Also, keep in mind that the adjacency list we use
// is a DIRECTED graph.
static const enum City START = SAN_FRAN;
static const enum City GOAL  = NEW_YORK;

int main() {

    // This is equal to the number of unique cities
    int listSize = 8;
    
    // Get the adjacency list that was created from the parser,
    // then give it to the pathplanning functions that return
    // a list of nodes equal to the shortest and longest paths 
    // from start to goal.
    struct Node** adjList  = parseGraph(listSize);
    struct Node* shortPath = shortestPath(adjList, START, GOAL);
    struct Node* longPath  = longestPath (adjList, START, GOAL);

    // Display short path information
    printf("----------short path information----------\n");
    if(shortPath == NULL) {
        printf("Unfortunately, there are no paths from %s to %s\n\n",
               getCity(START), getCity(GOAL));
    }
    else {
        printf("Path: ");
        struct Node* currNode = shortPath;
        int distance = 0;
        while(currNode) {
            if(currNode->edge >= 0) distance += currNode->edge;
            printf("%s ", getCity(currNode->city));
            currNode = currNode->next;
            if(currNode) printf("-> ");
        }
        printf("\nDistance: %dmi\n\n", distance);
    }

    // Display long path information
    printf("----------long path information----------\n");
    if(longPath == NULL) {
        printf("Unfortunately, there are no paths from %s to %s\n\n",
               getCity(START), getCity(GOAL));
    }
    else {
        printf("Path: ");
        struct Node* currNode = longPath;
        int distance = 0;
        while(currNode) {
            if(currNode->edge >= 0) distance += currNode->edge;
            printf("%s ", getCity(currNode->city));
            currNode = currNode->next;
            if(currNode) printf("-> ");
        }
        printf("\nDistance: %dmi\n\n", distance);
    }
    return 0;
}
