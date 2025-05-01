#include "main.h"

/**
 * findCommonFriends - finds the first common friend between two users
 * 
 * @graph: structure variables contains the pointer to the adjencency list
 * @id1: id of the first user
 * @id2: id of the second user
 * 
 * Return: user node contains the common friend infos. NULL otherwise
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

    commonFriend = NULL;
    while (start1)
    {
        if (searchFriend(user2, start1->identifiant))
            return start1;
        start1 = start1->next;
    }

    return NULL;
}