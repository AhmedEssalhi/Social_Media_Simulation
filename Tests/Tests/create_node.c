#include"main.h"
// Fonction pour créer un nouveau noeud d'adjacence
struct AdjListNode* newAdjListNode(int dest, char nom_complet[], int identifiant) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));  // Allouer de la mémoire pour un noeud
    newNode->dest = dest;                      // L'index du voisin
    strcpy(newNode->nom_complet, nom_complet); // Le nom de l'utilisateur
    newNode->identifiant = identifiant;       // L'identifiant de l'utilisateur
    newNode->next = NULL;                      // Aucun autre ami pour le moment
    return newNode;                            // Retourner le nouveau noeud créé
}
