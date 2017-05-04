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

static const char* file1 = "leg1.txt";
static const char* file2 = "leg2.txt";
static const char* file3 = "leg3.txt";


/* parseGraph:
 *
 * This function will read in data from the three data files
 * and populate a list with the corresponding information
 */
struct Node** parseGraph(int listSize);

#endif // AMERICA_FILEIO_H_
