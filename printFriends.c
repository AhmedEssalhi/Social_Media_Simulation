#include "main.h"


/**
 * printLinkedList - print a friend list for a specefic user
 * 
 * @head: pointer to the user whose friends list to be printed
 */
void printLinkedList(AdjList *head)
{
    AdjListNode *listNode = head->head;
    printf("\n-------Les amis de %s------\n", listNode->nom_complet);
    listNode = listNode->next;
    while (listNode)
    {
        printf("Nome complet: %s\n", listNode->nom_complet);
        printf("Date de naissance: %.2d/%.2d/%d\n", 
                listNode->dateNaissance.day,
                listNode->dateNaissance.month,
                listNode->dateNaissance.year);
        printf("Identifiant: %d\n", listNode->identifiant);
        printf("------------------------\n");
        listNode = listNode->next;
    }
    printf("------------------------------------------\n");
}

/**
 * printFriends - search and print a specefic user friends list if found
 * 
 * @graph: structure variable contains the pointer to the adjencency list
 * @id: id of the user to search for and print their friends list if found
 * 
 * Return: 1 in case of success (user found). -1 otherwise
 */
int printFriends(Graph graph, int id)
{
    if (searchUserId(graph, id) == -1)
        return -1;
    for (int i = 0; i < graph.pos; i++)
    {
        if (id == graph.array[i].head->identifiant)
        {
            printLinkedList(&graph.array[i]);
            return 1;
        }
    }
}