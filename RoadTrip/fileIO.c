/* File: fileIO.c
 * Name:
 * Date: 5/3/2017
 * Team: AMERICA
 */

#include <stdlib.h>
#include <stdio.h>
#include "fileIO.h"

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

    printf("Opened files okay\n");
    // Create the list of adjacency lists, initialize each index to null
    struct Node** adjList = malloc(listSize * sizeof(struct Node*));
    for(unsigned int i = 0; i < listSize; ++i) adjList[i] = NULL;
    printf("Allocated adjList\n");

    char startCity[20];
    char endCity[20];
    int  edgeWeight;

    // Scan in all information for fptr1
    while(fscanf(fptr1, "%s %s %d", startCity, endCity, &edgeWeight) == 3) {

        printf("Scanned in line for fptr1\n");
        int startIndex = getEnum(startCity);
        int endIndex   = getEnum(endCity);
        printf("startIndex : %d\n", startIndex);
        printf("endIndex   : %d\n", endIndex);

        // If the start node has never been created before
        if(adjList[startIndex] == NULL) {
            printf("entered list is empty\n");

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
            printf("appending to end\n");
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

        printf("Scanned in line for fptr2\n");
        int startIndex = getEnum(startCity);
        int endIndex   = getEnum(endCity);
        printf("startIndex : %d\n", startIndex);
        printf("endIndex   : %d\n", endIndex);

        // If the start node has never been created before
        if(adjList[startIndex] == NULL) {
            printf("entered list is empty\n");

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
            printf("appending to end\n");
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

        printf("Scanned in line for fptr3\n");
        int startIndex = getEnum(startCity);
        int endIndex   = getEnum(endCity);
        printf("startIndex : %d\n", startIndex);
        printf("endIndex   : %d\n", endIndex);

        // If the start node has never been created before
        if(adjList[startIndex] == NULL) {

            printf("entered list is empty\n");
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
            printf("appending to end\n");
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

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    return adjList;
}
