/*  File   : pathplanning.c
 *  Date   : 05/03/17
 *  Team   : AMERICA
 *  Members: Paulo, Chris, Kevin
 */

/* shortestPath Algorithm:
 *
 * This function finds the shortest path from a start node to an end node.
 * It follows a top-down, recursive approach. It calls itself on every
 * child node of the current node until it gets to either the destination
 * or to a node which has no further node. 
 * If on a particular path the destination is not found, it returns NULL.
 * Otherwise, it copies the node and returns a pointer to it. 
 * Every call collects a list of the paths to the destination from itself,
 * then they select the minimal path of the options. When a min path is found, 
 * the current node appends itself to the front of the min path and returns.
 * This happens until the minPath from the start to the end is returned.
 */
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
        // count up the number of nodes the current node is connected to
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

        // Create new list to hold all the potential paths to goal from current
        struct Node* pathsList[childrenCount];
        for(int i = 0; i < childrenCount; ++i) pathsList[i] = NULL;

        // Save the shortest path from each child to the goal in an array
        currNode = adjList[start];
        for(int i = 0; i < childrenCount; ++i) {
            currNode = currNode->next;
            pathsList[i] = shortestPath(adjList, size, currNode->city, goal);
        }

        // This block of code iterates through the list until a non-null
        // node is found. It then sums the length of the path and saves its
        // index and sum into minSum. This is to establish a base
        int shortIndex = -1, currIndex = 0, minSum = -1, currSum;
        while(currIndex < childrenCount && !pathsList[currIndex]) currIndex++;
        if(currIndex < childrenCount && currNode) {
            currNode   = pathsList[currIndex];
            shortIndex = currIndex;
            if(currNode->edge < 0) {
                minSum = currNode->edge;
            }
            else {
                minSum = 0;
                while(currNode && currNode->edge >= 0) {
                    minSum  += currNode->edge;
                    currNode = currNode->next;
                }
            }
        }

        // This block iterates through the list and compares the
        // length of each path to the min path to see if a shorter
        // one exists. If it does, we save the index and min path value
        for(int i = 0; i < childrenCount; ++i) {
            currSum = 0;
            currNode = pathsList[i];
            // If the path is the goal, save index and end loop
            if(currNode && currNode->edge < 0) {
                shortIndex = i;
                i = childrenCount;
            }
            // Otherwise, sum the edge weights of list
            else if(currNode) {
                while(currNode && currNode->edge >= 0) {
                    currSum += currNode->edge;
                    currNode = currNode->next;
                }
                if(currSum < minSum) {
                    minSum = currSum;
                    shortIndex = i;
                }
            }
        }

        // With the shortIndex that was found in the above
        // loop, we either append ourself to the front of the
        // shortest path from the children paths and return,
        // or we return null if there are no paths to goal.
        struct Node* bestPath = NULL;
        if(shortIndex < 0);
        else {
            bestPath = newNode();
            bestPath->city = adjList[start]->city;
            bestPath->edge = adjList[start]->edge;
            bestPath->next = pathsList[shortIndex];
        }

        // Clean up and return
        for(int i = 0; i < childrenCount; ++i) {
            if(i != shortIndex) {
                deleteList(pathsList[i]);
            }
        }
        return bestPath;
    }
}
/*
struct Node* longestPath(struct Node** adjList, int listsize, enum City start, enum City goal)
{
    struct Node* currNode = adjList[start];
    struct Node** potPaths[7];
    struct Node* bestNode = adjList[start];

    if(currNode->city == goal)
        return currNode;
    if(currNode == NULL)
        return currNode;

    for(int i = 0; i < 7; i++)
        potPaths[i] = 0;

    while(currNode->next != NULL)
    {
        currNode = currNode->next;
        potPaths[currNode->city] = 
            longestPath(adjList, listsize, enum City currNode->city, goal);
    }

    for(int i = 0; i < 7; i++)
    {
        int sum = 0;
        while(currNode->city != NULL)
        {
            potPaths[i] += currNode->edge;
            currNode = currNode->next;
        }
    }

    for(int i = 0; i < 7; i++)
    {
        if(bestNode->edge < potPaths[i])
            bestNode = potPaths[i];
    }

    if(City == GOAL)
        return;
}
*/
