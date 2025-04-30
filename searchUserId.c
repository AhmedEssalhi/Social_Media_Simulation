#include "main.h"

/**
 * searchUserId - 
 * 
 * @graph:
 * @id:
 * Return:
 */
int searchUserId(Graph graph, int id)
{
    int i, pos;

    pos = 1;
    for (i = 0; i < graph.pos; i++)
    {
        if (graph.array[i].head->identifiant == id)
            return pos;
        pos++;
    }
    return -1;
}