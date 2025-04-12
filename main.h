#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARRAY 10 // Nombre maximum de sommets
// Définir la structure pour un noeud
struct AdjListNode {
    int dest;               // index du voisin (ami)
    char nom_complet[100];   // nom de l'ami
    int identifiant;        // identifiant de l'ami
    struct AdjListNode* next;  // prochain ami dans la liste chaînée
};
// Définir la structure pour un graphe
struct AdjList {
    struct AdjListNode* head; //Pointeur vers le premier nœud de la liste d’adjacence du sommet
};
// Définir la structure pour un graphe
struct Graph {
    struct AdjList* array;  // Tableau de listes d'adjacence
    int pos;                // Position actuelle pour l'ajout de nouveaux utilisateurs
};
// Prototypes des fonctions
struct Graph* createGraph(); // Créer un graphe vide
void createUser(struct Graph* graph); // Ajouter un utilisateur
void addFriend(struct Graph* graph, int user1, int user2); // Ajouter un ami
struct AdjListNode* newAdjListNode(int dest, char nom_complet[], int identifiant); // Créer un noeud d'adjacence
void printArrayList(struct Graph graph);

#endif
