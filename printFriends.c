#include "main.h"

void printLinkedList(AdjList *head);

void printFriends(Graph graph)
{
    for (int i = 0; i < graph.pos; i++)
    {
        printf("Nom: %s\n", graph.array[i].head->nom_complet);
    }
}