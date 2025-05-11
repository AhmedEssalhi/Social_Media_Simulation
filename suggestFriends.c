#include "main.h"

/**
 * suggestFriends - Afficher la list des amis suggerer pour un utilisateur
 * 
 * @graph: pointeur sur graph
 * @id: l'identifiant d'utilisateur visé
 */
AdjList *suggestFriends(Graph graph, int id)
{
    if (graph.pos == 0)
        return NULL;

    AdjList *suggestFriendList = createEmptyList();
    if (!suggestFriendList)
        return NULL;

    int userPosition = searchUserId(graph, id);
    if (userPosition == -1)
        return NULL;

    for (int i = 0; i < graph.pos; i++)
    {
        AdjListNode *currentFriend = graph.array[i].head;
        if (currentFriend->identifiant != id &&
            degreSeparation(&graph, currentFriend->identifiant, id) == 2 &&
            searchFriend(&graph.array[userPosition - 1], currentFriend->identifiant) == NULL)
        {
            AdjListNode *newNode = malloc(sizeof(AdjListNode));
            if (!newNode)
                return NULL;

            strcpy(newNode->nom_complet, currentFriend->nom_complet);
            newNode->dateNaissance = currentFriend->dateNaissance;
            newNode->identifiant = currentFriend->identifiant;
            newNode->next = NULL;

            addFriendNodeAtHead(suggestFriendList, newNode);
        }
        currentFriend = currentFriend->next;
    }

    return suggestFriendList;
}
