/* File: fileIO.c
 * Name: Paulo Lemus
 * Date: 5/3/2017
 * Team: AMERICA
 */

#include <stdlib.h>
#include <stdio.h>
#include "fileIO.h"

const char* file1 = "leg1.txt";
const char* file2 = "leg2.txt";
const char* file3 = "leg3.txt";

struct Node** parseGraph(int listSize) {

    // Ensure that all files can be opened
    FILE *fptr1, *fptr2, *fptr3;
    if((fptr1 = fopen(file1, "r")) == NULL) {
        printf("Could not open %s\n", file1);
        exit(1);
    }
    if((fptr2 = fopen(file2, "r")) == NULL) {
        printf("Could not open %s\n", file2);
        exit(1);
    }
    if((fptr3 = fopen(file3, "r")) == NULL) {
        printf("Could not open %s\n", file3);
        exit(1);
    }

    // Create the list of adjacency lists and initialize to NULL
    struct Node** adjList = malloc(listSize * sizeof(struct Node*));
    for(int i = 0; i < listSize; ++i) adjList[i] = NULL;


    char startCity[20];
    char endCity[20];
    int  edgeWeight;

    // This loop scans in all data from the dat file and uses it to
    // create adjacency lists that are pushed into a global adjacency list.
    while(fscanf(fptr1, "%s %s %d", startCity, endCity, &edgeWeight) == 3) {

        int startIndex = getEnum(startCity);
        int endIndex   = getEnum(endCity);

        // If the start node has never been created before
        if(adjList[startIndex] == NULL) {

            struct Node* currNode = newNode();
            struct Node* nextNode = newNode();
            currNode->city = startIndex;
            nextNode->city = endIndex;
            currNode->edge = edgeWeight;
            currNode->next = nextNode;
            adjList[startIndex] = currNode;
        }
        // Append the new node at the end of the existing list
        else {
            struct Node* currNode = adjList[startIndex];
            struct Node* nextNode = newNode();
            nextNode->city = endIndex;
            while(currNode->next != NULL) currNode = currNode->next;
            currNode->edge = edgeWeight;
            currNode->next = nextNode;
        }
        startCity[0] = '\0';
        endCity[0]   = '\0';
    }
    // Scan in all information for fptr2
    while(fscanf(fptr2, "%s %s %d", startCity, endCity, &edgeWeight) == 3) {

        int startIndex = getEnum(startCity);
        int endIndex   = getEnum(endCity);

        // If the start node has never been created before
        if(adjList[startIndex] == NULL) {

            struct Node* currNode = newNode();
            struct Node* nextNode = newNode();
            currNode->city = startIndex;
            nextNode->city = endIndex;
            currNode->edge = edgeWeight;
            currNode->next = nextNode;
            adjList[startIndex] = currNode;
        }
        // Append the new node at the end of the existing list
        else {
            struct Node* currNode = adjList[startIndex];
            struct Node* nextNode = newNode();
            nextNode->city = endIndex;
            while(currNode->next != NULL) currNode = currNode->next;
            currNode->edge = edgeWeight;
            currNode->next = nextNode;
        }
        startCity[0] = '\0';
        endCity[0]   = '\0';
    }

    // Scan in all information for fptr3
    while(fscanf(fptr3, "%s %s %d", startCity, endCity, &edgeWeight) == 3) {

        int startIndex = getEnum(startCity);
        int endIndex   = getEnum(endCity);

        // If the start node has never been created before
        if(adjList[startIndex] == NULL) {

            struct Node* currNode = newNode();
            struct Node* nextNode = newNode();
            currNode->city = startIndex;
            nextNode->city = endIndex;
            currNode->edge = edgeWeight;
            currNode->next = nextNode;
            adjList[startIndex] = currNode;
        }
        // Append the new node at the end of the existing list
        else {
            struct Node* currNode = adjList[startIndex];
            struct Node* nextNode = newNode();
            nextNode->city = endIndex;
            while(currNode->next != NULL) currNode = currNode->next;
            currNode->edge = edgeWeight;
            currNode->next = nextNode;
        }
        startCity[0] = '\0';
        endCity[0]   = '\0';
    }

    // Since we are using an adjacency list to calculate the
    // shortest and longest paths, all cities must be in the list,
    // even cities with no children. 
    for(int i = 0; i < listSize; ++i) {
        if(adjList[i] == NULL) {
            struct Node* currNode = newNode();
            currNode->city = i;
            adjList[i] = currNode;
        }
    }

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    return adjList;
}
