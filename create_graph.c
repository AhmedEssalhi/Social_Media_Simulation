#include "main.h"
/**
 * createGraph - Crée et initialise un graphe vide avec une capacité maximale prédéfinie.
 *
 * @return Pointeur vers le graphe nouvellement créé.
 */

Graph* createGraph() {
    Graph* graph = (Graph *)malloc(sizeof(Graph));
    graph->array = (AdjList *)malloc(MAX_ARRAY * sizeof(AdjList));
    graph->pos = 0; // Aucune utilisateur ajouté au départ

    // Initialiser les listes d'adjacence pour chaque sommet
    for (int i = 0; i < MAX_ARRAY; ++i) {
        graph->array[i].head = NULL; // Chaque liste d'adjacence commence vide
    }

    return graph;
}
