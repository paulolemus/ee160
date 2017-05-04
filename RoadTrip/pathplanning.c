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
    //while(adjList->City != '\0')
    //{
    //    for(int i = 0; i < listsize; i++)
    //        adjList->edge = longestPath(currNode, listsize, start, goal);
    //    currNode = next;
    //}

    /* declare start and potential paths variables */
    struct Node* adjStart = adjList[start];
    struct Node** potPaths[7];

    /* initialize potential paths */
    for(int i = 0; i < 7; i++)
        potPaths[i] = NULL;

    while(adjStart->next != NULL)
    {
        adjStart = adjStart->next;
        potPaths[adjStart->city] = 
            longestPath(struct Node** adjList, listsize, enum City adjStart->city, enum City goal);
    }

    /* stop when reached New York */
    if(City == GOAL)
        return;
}
