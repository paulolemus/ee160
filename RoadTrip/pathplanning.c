/*  File:   pathplanning.c
 *  Date:   05/03/17
 *  Team:   AMERICA
 *  Members:Paulo, Chris, Kevin */

/*  pathplanning function   */
struct Node* shortestPath(struct Node** adjList, char* start, char* goal)
{

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
