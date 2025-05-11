#include "main.h"

/**
 * 
 */
AdjList *createEmptyList()
{
    AdjList *friendsListHead;

    friendsListHead = (AdjList *)malloc(sizeof(AdjList));
    if (!friendsListHead)
    {
        free(friendsListHead);
        return NULL;
    }
    friendsListHead->head = NULL;

    return friendsListHead;
}

/**
 * 
 */
void addFriendNodeAtHead(AdjList *listHead, AdjListNode *listNode)
{

    if (listHead == NULL)
        return;
    if (listHead->head == NULL)
    {
        listHead->head = listNode;
        listNode->next = NULL;
        return;
    }
    listNode->next = listHead->head;
    listHead->head = listNode;
    return;
}

/**
 * findCommonFriends - finds the first common friend between two users
 * 
 * @graph: structure variables contains the pointer to the adjencency list
 * @id1: id of the first user
 * @id2: id of the second user
 * 
 * Return: user node contains the common friend infos. NULL otherwise
 */
AdjList *findCommonFriends(Graph graph, int id1, int id2)
{
    AdjList *user1, *user2;
    AdjListNode *start1;
    int posUser1, posUser2;
    AdjList *commonFriendsList;

    commonFriendsList = createEmptyList();
    if (!commonFriendsList)
        return NULL;

    posUser1 = searchUserId(graph, id1);
    posUser2 = searchUserId(graph, id2);
    if (posUser1 == -1 || posUser2 == -1)
        return NULL;

    user1 = &graph.array[posUser1 - 1];
    user2 = &graph.array[posUser2 - 1];
    if (user1->head == NULL || user2->head == NULL)
        return NULL;
    
    start1 = user1->head->next;
    while (start1)
    {
        if (searchFriend(user2, start1->identifiant) != NULL)
        {
            AdjListNode *tempNode = malloc(sizeof(AdjListNode));
            if (!tempNode)
                return NULL;

            //tempNode->nom_complet = strcpy(start1->nom_complet, tempNode->nom_complet);
            tempNode->identifiant = start1->identifiant;
            tempNode->next = NULL;
            addFriendNodeAtHead(commonFriendsList, tempNode);
            printf("The common user has been added\n");
        }
        start1 = start1->next;
    }

    return commonFriendsList;
}