#include "main.h"

/**
 * 
 */
AdjListNode *findCommonFriends(Graph graph, int id1, int id2)
{
    AdjList *user1, *user2;
    AdjListNode *start1, *start2, *commonFriend;
    int posUser1, posUser2;

    posUser1 = searchUserId(graph, id1);
    posUser2 = searchUserId(graph, id2);
    if (posUser1 == -1 || posUser2 == -1)
        return NULL;

    user1 = &graph.array[posUser1 - 1];
    user2 = &graph.array[posUser2 - 1];
    commonFriend = NULL;
    start1 = user1->head->next;
    start2 = user2->head->next;
    printNodeInfo(start1);
    printNodeInfo(start2);
    
    commonFriend = NULL;
    while (start1)
    {
        if (searchFriend(user2, start1->identifiant))
            return start1;
        start1 = start1->next;
    }

    return NULL;
}