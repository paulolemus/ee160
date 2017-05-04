/* File: fileIO.c
 * Name:
 * Date: 5/3/2017
 * Team: AMERICA
 */

#include <stdlib.h>
#include <stdio.h>
#include "fileIO.h"

struct Node** parseGraph(int* listSize) {

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
    struct Node* file1;
    struct Node* file2;
    struct Node* file3;

    fscanf(fptr1, "%s %s %d", &file1->city, &file1->next, &file1->edge);
    fscanf(fptr2, "%s %s %d", &file2->city, &file2->next, &file2->edge);
    fscanf(fptr2, "%s %s %d", &file3->city, &file3->next, &file3->edge);

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
}
