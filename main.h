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
//signature de fonction qui creer le noeud (NewAdjListNode)
struct AdjListNode* createNode(int dest, char nom_complet[], int identifiant);
//signature qui creer le graph 
struct Graph* createGraph(int V);
//signature de fonction createuser 
void createUser(struct Graph* graph, char nom_complet[], int id);
//signature de fonction addfreind 
void addFriend(struct Graph* graph, int user1, int user2);