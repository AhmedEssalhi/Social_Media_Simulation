#include "main.h"

int degreSeparation(Graph* graph, int id1, int id2)
{
    if(id1 == id2) return 0; // Si l'utilisateur courant est la cible, degré = 0.

    int visited[MAX_ARRAY] = {0}; // Marquer chaque sommet comme non visité
    int level[MAX_ARRAY];         // Stocker la distance depuis le sommet de départ
    int file[MAX_ARRAY];          // File pour l'algorithme BFS
    int front = 0, rear = 0;      // Pointeurs de la file
    int start = -1, end = -1;     // Indices des utilisateurs dans le tableau

    // Initialiser les niveaux à -1
    for(int i = 0; i < MAX_ARRAY; ++i)
        level[i] = -1;

    // Trouver les indices correspondants aux id
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

    visited[start] = 1;    // Marquer le sommet de départ comme visité
    level[start] = 0;      // Son niveau est 0 (point de départ)
    file[rear++] = start;  // Ajouter l'utilisateur source dans la file

    while(front < rear) // Tant que la file n'est pas vide
    {
        int current = file[front++]; // Retirer un élément de la file

        // Parcours de ses amis
        struct AdjListNode* temp = graph->array[current].head->next; // Pointeur sur chaque ami

        while(temp != NULL)
        {
            int neighbor = -1; // L'indice de l'ami courant

            // Chercher dans le tableau le sommet correspondant à l'Id du cible
            for(int i = 0; i < graph->pos; ++i)
            {
                if(graph->array[i].head && graph->array[i].head->identifiant == temp->identifiant)
                {
                    neighbor = i;
                    break;
                }
            }

            // Marquer le voisin comme visité et calculer sa distance
            if(neighbor != -1 && !visited[neighbor])
            {
                visited[neighbor] = 1;
                level[neighbor] = level[current] + 1; // Incrémenter le niveau

                if(neighbor == end)
                    return level[neighbor];

                if(rear >= MAX_ARRAY)
                {
                    printf("Queue overflow.\n");
                    return -1;
                }

                file[rear++] = neighbor; // Ajouter ce voisin à la file
            }

            temp = temp->next; // Passer à l'ami suivant
        }
    }

    return -1; // Si aucun chemin n'est trouvé
}
