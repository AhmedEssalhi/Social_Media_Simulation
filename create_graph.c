#include "main.h"
struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->array = (struct AdjList*)malloc(MAX_ARRAY * sizeof(struct AdjList));
    graph->pos = 0; // Aucune utilisateur ajouté au départ

    // Initialiser les listes d'adjacence pour chaque sommet
    for (int i = 0; i < MAX_ARRAY; ++i) {
        graph->array[i].head = NULL; // Chaque liste d'adjacence commence vide
    }

    return graph;
}
