/* File: pathplanning.h
 * Name:
 * Date: 4/26/2017
 * Team: AMERICA
 */

/*
 *
 */

#ifndef AMERICA_PATHPLANNING_H_
#define AMERICA_PATHPLANNING_H_

#include "Node.h"

static const char* START = "san_francisco";
static const char* GOAL  = "new_york";

/*
 *
 */
struct Node* shortestPath(struct Node**, int listsize, enum City start, enum City goal);
/*
 *
 */
struct Node* longestPath(struct Node**, int listsize, enum City start, enum City goal);
/*  Given:  Node**, size of list, san_francisco, & new_york
 *  Returns: pointer to a Node with longestPath
 */


#endif // AMERICA_PATHPLANNING_H_
