#include "main.h"

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

int printFriends(Graph graph, int id)
{
    for (int i = 0; i < graph.pos; i++)
    {
        if (id == graph.array[i].head->identifiant)
        {
            printLinkedList(&graph.array[i]);
            return 1;
        }
    }
    return -1;
}