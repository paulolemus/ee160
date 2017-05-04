/* File: fileIO.h
 * Name: Chris A, Paulo L
 * Date: 4/26/2017
 * Team: AMERICA
 */

/* The purpose of all the functions in this file are to
 * read in all information from text files and to populate 
 * a data structure with the information.
 */

#ifndef AMERICA_FILEIO_H_
#define AMERICA_FILEIO_H_

#include "Node.h"

// File names. They are defined in Node.c
extern const char* file1;
extern const char* file2;
extern const char* file3;


/* parseGraph:
 *
 * This function will read in data from the three data files
 * and create an adjacency list from the node information.
 */
struct Node** parseGraph(int listSize);

#endif // AMERICA_FILEIO_H_
