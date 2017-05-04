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

    // Display all path information
    printf("The Shortest Path is:\n");
    if(shortPath == NULL) {
        printf("There is no path to destination\n");
    }
    else {
        struct Node* currNode = shortPath;
        while(currNode) {
            printf("%s ", getCity(currNode->city));
            currNode = currNode->next;
            if(currNode) printf("-> ");
        }
        printf("\n");
    }
    return 0;
}
