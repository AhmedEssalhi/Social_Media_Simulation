#include "main.h"

/**
 * 
 */
AdjListNode *searchFriend(AdjList *head, int id)
{
    AdjListNode *foundFriend;

    foundFriend = head->head->next;
    while (foundFriend)
    {
        if (foundFriend->identifiant == id)
            return foundFriend;
        foundFriend = foundFriend->next;
    }
    return NULL;
}