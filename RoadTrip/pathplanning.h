/* File: pathplanning.h
 * Name: Paulo L, Kevin L
 * Date: 4/26/2017
 * Team: AMERICA
 */

/*
 *
 */

#ifndef AMERICA_PATHPLANNING_H_
#define AMERICA_PATHPLANNING_H_

#include "Node.h"

/*
 *
 */
struct Node* shortestPath(struct Node** adjList, int size, enum City start, enum City goal);
/* Given: Node** (adjacency list), size of list, start city and end city enums
 * Returns: Pointer to a list of the shortest path from start to end.
 */

struct Node* longestPath(struct Node** adjList, int size, enum City start, enum City goal);
/*  Given:  Node**, size of list, san_francisco, & new_york
 *  Returns: pointer to a Node with longestPath
 */


#endif // AMERICA_PATHPLANNING_H_
