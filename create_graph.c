#include "main.h"
// Fonction pour créer un graphe avec V sommets(utilisateurs )
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;//Cela indique combien d'utilisateurs (sommets) seront dans notre graphe
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;//Au début,la liste d'adjacence de chaque sommet (utilisateur) est vide,nous initialisons  head à NULL
        char nom[100];
        int id;
        printf("Saisissez le nom complet de l'utilisateur %d:",i);
        scanf("%s", nom);
        printf("Saisissez l'identifiant de l'utilisateur %d:",i);
        scanf("%d", &id);
       // Ajouter l'utilisateur dans la liste d'adjacence
        struct AdjListNode* newNode = newAdjListNode(i, nom, id);
        graph->array[i].head = newNode;
    }
    return graph;
}
