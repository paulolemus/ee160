/*  File:   pathplanning.c
 *  Date:   05/03/17
 *  Team:   AMERICA
 *  Members:Paulo, Chris, Kevin */

/*  pathplanning function   */
struct Node* shortestPath(struct Node** adjList, int size, enum City start, enum City goal) {

    struct Node* currNode = adjList[start];

    // Guard against NULL pointer
    if(currNode == NULL) {
        return NULL;
    }
    // If we have arrived at the destination, return a copy of the destination
    else if(currNode->city == goal) {
        struct Node* copyNode = newNode();
        copyNode->city = currNode->city;
        return copyNode;
    }
    else {
        // count up the number of links
        int childrenCount = 0;
        currNode = currNode->next;
        while(currNode) {
            childrenCount++;
            currNode = currNode->next;
        }

        // Guard against no children
        if(childrenCount < 1) {
            return NULL;
        }

        // Allocate a new array to hold the children lists
        struct Node** pathsList = malloc(childrenCount * sizeof(struct Node*));

        // Save the shortest path from each child to the goal in an array
        currNode = adjList[start];
        for(int i = 0; i < childrenCount; ++i) {
            currNode = currNode->next;
            pathsList[i] = shortestPath(adjList, size, currNode->city, goal);
        }

        // Find the shortest path of the children paths
        for(int i = 0; i < childrenCount; ++i) {
            
        }
    }
}

struct Node* longestPath(struct Node** adjList, int listsize, enum City start, enum City goal)
{
    /* declare start and potential paths variables */
    struct Node* currNode = adjList[start];
    int childrencount = 0;

    /* guard list */
    if(currNode->city == goal) //if currently at destination
    {
        struct Node* copyNode = newNode();
        copyNode->city = currNode->city;
        return copyNode; //return a copy of itself
    }
    if(currNode == NULL) //if at a NULL pointer
        return NULL;

    /* get children count */
    while(currNode->next != NULL)
    {
        currNode = currNode->next;
        childrencount++;
    }
    currNode = adjList[start]; //reset back to start

    /* allocate memory for children list */
    struct Node** pathslist = malloc(childrencount * sizeof(struct Node*));
    /* saves path computation for each child */
    for(int i = 0; i < childrencount; i++)
    {
            currNode = currNode->next;
            pathslist[i] = longestPath(adjList, listsize, currNode->city, goal);
    }

    /* finds longest path index */
    struct Node* bestPath = adjList[start];
    for(int i = 0; i < childrencount; i++)
    {
        if(pathlist[i]->edge > bestPath->edge)
            bestPath = pathlist[i];
    }

    /* return longest path index */
    return bestPath;
}
