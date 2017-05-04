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
    CITY_ERROR = -1,
    SAN_FRAN = 0,
    LAS_VEGAS = 1,
    TUSCON = 2,
    SALT_LAKE = 3,
    CHICAGO = 4,
    NASHVILLE = 5,
    INDIANAPOLIS = 6,
    NEW_YORK = 7
};

struct Node {
    enum City    city;
    double       edge;
    struct Node* next;
};

enum City getEnum(const char* cityStr);

#endif // AMERICA_NODE_H_
