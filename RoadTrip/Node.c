/* File: Node.c
 * Name: Paulo Lemus
 * Date: 5/3/2017
 * Team: AMERICA
 */

#include <stdlib.h>
#include <string.h>
#include "Node.h"

// Using this function when creating nodes ensures
// that we do not forget to initialize any of its fields
struct Node* newNode() {
    struct Node* nodePtr = malloc(sizeof(struct Node));
    nodePtr->city = CITY_ERROR;
    nodePtr->edge = -1;
    nodePtr->next = NULL;
    return nodePtr;
}

// Delete an entire linked list.
// This saves a pointer to the next node, then
// deletes the current node if it is not NULL.
// This is done in a loop, so it continues to delete nodes
// until the next pointer becomes NULL, indicating end of list.
void deleteList(struct Node* nodePtr) {

    struct Node* nextPtr;
    if(nodePtr == NULL);
    else {
        do {
            nextPtr = nodePtr->next;
            free(nodePtr);
            nodePtr = nextPtr;
        } while(nodePtr != NULL);
    }
}

// Here we have two functions used for converting a enum
// to its corresponding string and vice versa

enum City getEnum(const char* cityStr) {

    if(strcmp(cityStr, "san_francisco")       == 0) return SAN_FRAN;
    else if(strcmp(cityStr, "las_vegas")      == 0) return LAS_VEGAS;
    else if(strcmp(cityStr, "tuscon")         == 0) return TUSCON;
    else if(strcmp(cityStr, "salt_lake_city") == 0) return SALT_LAKE;
    else if(strcmp(cityStr, "chicago")        == 0) return CHICAGO;
    else if(strcmp(cityStr, "nashville")      == 0) return NASHVILLE;
    else if(strcmp(cityStr, "indianapolis")   == 0) return INDIANAPOLIS;
    else if(strcmp(cityStr, "new_york")       == 0) return NEW_YORK;
    else                                            return CITY_ERROR;
}

char* getCity(enum City city) {
    switch(city) {
        case SAN_FRAN:     return "san_francisco";
        case LAS_VEGAS:    return "las_vegas";
        case TUSCON:       return "tuscon";
        case SALT_LAKE:    return "salt_lake_city";
        case CHICAGO:      return "chicago";
        case NASHVILLE:    return "nashville";
        case INDIANAPOLIS: return "indianapolis";
        case NEW_YORK:     return "new_york";
        default:           return "error";
    }
}
