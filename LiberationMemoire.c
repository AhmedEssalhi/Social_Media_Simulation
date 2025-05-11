#include "main.h"

/**
 * freeGraph - Libère la mémoire allouée pour le graphe.
 *
 * @graph: Pointeur vers le graphe à libérer.
 */
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->pos; i++) {
        AdjListNode* current = graph->array[i].head;
        while (current != NULL) {
            AdjListNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}
