/* File: Node.h
 * Name: Paulo Lemus
 * Date: 5/3/2017
 * Team: Sandwich
 */

/* The purpose of this file is to provide data structures for 
 * storing graph information.
 */

#ifndef AMERICA_NODE_H_
#define AMERICA_NODE_H_

enum City {
    ERROR = -1,
    SAN_FRAN,
    LAS_VEGAS,
    TUSCON,
    SALT_LAKE,
    CHICAGO,
    NASHVILLE,
    INDIANAPOLIS,
    NEW_YORK
};

struct Node {
    City         city;
    double       edge;
    struct Node* next;
};

int 

#endif // AMERICA_NODE_H_
