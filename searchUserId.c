#include "main.h"

/**
 * searchUserId - search for a user in the application
 * 
 * @graph: structure variable contains pointer to the head of adjencency list
 * @id: user id searching for
 * 
 * Return: The position of the user found. -1 otherwise
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