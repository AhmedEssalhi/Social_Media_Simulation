#include "main.h"

/**
 * degreSeparation - Donner le degree de separation entre deux utilisateur
 * 
 * @graph: pointeur sur le graph
 * @id1: pointer sur l'ID du premier utilisateur
 * @id2: pointer sur l'ID du deuxieme utilisateur
 * 
 * Return: le degree de separation, -1 s'il n'existe pas
 */
int degreSeparation(Graph* graph, int id1, int id2)
{
    if(id1 == id2) return 0;

    int visited[MAX_ARRAY] = {0}; 
    int level[MAX_ARRAY];         
    int file[MAX_ARRAY];          
    int front = 0, rear = 0;      
    int start = -1, end = -1;     

    for(int i = 0; i < MAX_ARRAY; ++i)
        level[i] = -1;

    for(int i = 0; i < graph->pos; ++i)
    {
        if(graph->array[i].head && graph->array[i].head->identifiant == id1)
            start = i;
        if(graph->array[i].head && graph->array[i].head->identifiant == id2)
            end = i;
    }

    if (start == -1 || end == -1)
    {
        printf("Id invalide.\n");
        return -1;
    }

    visited[start] = 1;  
    level[start] = 0;    
    file[rear++] = start;

    while(front < rear) 
    {
        int current = file[front++];

        struct AdjListNode* temp = graph->array[current].head->next;

        while(temp != NULL)
        {
            int neighbor = -1;

            for(int i = 0; i < graph->pos; ++i)
            {
                if(graph->array[i].head && graph->array[i].head->identifiant == temp->identifiant)
                {
                    neighbor = i;
                    break;
                }
            }

            if(neighbor != -1 && !visited[neighbor])
            {
                visited[neighbor] = 1;
                level[neighbor] = level[current] + 1;

                if(neighbor == end)
                    return level[neighbor];

                if(rear >= MAX_ARRAY)
                {
                    printf("Queue overflow.\n");
                    return -1;
                }

                file[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    return -1;
}
