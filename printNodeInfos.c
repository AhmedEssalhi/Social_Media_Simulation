#include "main.h"

/**
 * 
 */
void printNodeInfo(AdjListNode *node)
{
    printf("\n-----User Information----- \n");
    printf("Username: %s\n", node->nom_complet);
    printf("Date de naissance: %.2d/%.2d/%d\n", 
            node->dateNaissance.day,
            node->dateNaissance.month,
            node->dateNaissance.year);
    printf("ID: %d\n", node->identifiant);
    printf("----------------------------\n");
}