#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARRAY 10 // Nombre maximum de sommets  

// Définir la structure pour un noeud
struct AdjListNode {
    int dest;               // index du voisin (ami)
    char nom_complet[20];   // nom de l'ami
    int identifiant;        // identifiant de l'ami
    struct AdjListNode* next;  // prochain ami dans la liste chaînée
};

// Définir la structure pour un graphe
struct AdjList {
    struct AdjListNode* head; //Pointeur vers le premier nœud de la liste d’adjacence du sommet
};

// Définir la structure pour un graphe
struct Graph {
    int V; //Le nombre de sommets (utilisateurs)
    struct AdjList* array;//Tableau de listes d'adjacence
};

// Fonction pour créer un nouveau noeud de liste d'adjacence
struct AdjListNode* newAdjListNode(int dest, char nom_complet[], int identifiant) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;  // L'index du voisin
    strcpy(newNode->nom_complet, nom_complet);  // Le nom de l'ami
    newNode->identifiant = identifiant;  // L'identifiant de l'ami
    newNode->next = NULL;  // Aucun ami suivant pour l'instant
    return newNode;
}

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
//signature de fonction createuser 
void createUser(struct Graph* graph, char nom_complet[], int id);
//signature de fonction addfreind 
void addFriend(struct Graph* graph, int user1, int user2);


