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
    struct Node** potPaths[7];
    struct Node* bestNode = adjList[start];

    /* guard list */
    if(currNode->city == goal)
        return currNode;
    if(currNode == NULL)
        return currNode;

    /* initialize potential paths */
    for(int i = 0; i < 7; i++)
        potPaths[i] = 0;

    /* get potential paths */
    while(currNode->next != NULL)
    {
        currNode = currNode->next;
        potPaths[currNode->city] = 
            longestPath(adjList, listsize, enum City currNode->city, goal);
    }

    /* path computation */
    for(int i = 0; i < 7; i++)
    {
        int sum = 0;
        while(currNode->city != NULL)
        {
            potPaths[i] += currNode->edge;
            currNode = currNode->next;
        }
    }

    /* finds longest index */
    for(int i = 0; i < 7; i++)
    {
        if(bestNode->edge < potPaths[i])
            bestNode = potPaths[i];
    }

    /* stop when reached New York */
    if(City == GOAL)
        return;
}
