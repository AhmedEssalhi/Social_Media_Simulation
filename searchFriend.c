#include "main.h"

/**
 * searchFriend - search of a friend in the in a user friends list
 * 
 * @head: pointer to the user to search in their friends list
 * @id: the id searched for
 * 
 * Return: the friend node contains all the user infos. NULL otherwise
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