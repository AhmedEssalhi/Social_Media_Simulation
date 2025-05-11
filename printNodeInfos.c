#include "main.h"

/**
 * printNodeInfo - print the informations of a single user
 * 
 * @node: the user node to print the infos from
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

/**
 * printSuggestNodeInfo - print the informations of a single user
 * 
 * @node: the user node to print the infos from
 */
void printSuggestNodeInfo(AdjListNode *node)
{
    printf("Username: %s\n", node->nom_complet);
    printf("Date de naissance: %.2d/%.2d/%d\n", 
            node->dateNaissance.day,
            node->dateNaissance.month,
            node->dateNaissance.year);
    printf("ID: %d\n", node->identifiant);
    printf("----------------------------\n");
}