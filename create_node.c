#include "main.h"
// Fonction pour créer un nouveau noeud de liste d'adjacence
struct AdjListNode* newAdjListNode(int dest, char nom_complet[], int identifiant) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;  // L'index du voisin
    strcpy(newNode->nom_complet, nom_complet);  // Le nom de l'ami
    newNode->identifiant = identifiant;  // L'identifiant de l'ami
    newNode->next = NULL;  // Aucun ami suivant pour l'instant
    return newNode;
}