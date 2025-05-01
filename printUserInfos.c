#include "main.h"

/**
 * printUserInfos -Affiche les informations de tous les utilisateurs présents dans le graphe.
 *
 * @param graph Graphe contenant les utilisateurs à afficher.
 */
void printUserInfos(Graph graph)
{
	int i;
	if (graph.pos == 0)
	{
		printf("Il exist aucun utilisateur a afficher\n");
		return;
	}
	printf("\n-----User Information----- \n");
	for (i = 0; i < graph.pos; i++)
	{
		printf("Username: %s\n", graph.array[i].head->nom_complet);
		printf("Date de naissance: %.2d/%.2d/%.4d\n", 
				graph.array[i].head->dateNaissance.day,
				graph.array[i].head->dateNaissance.month,
				graph.array[i].head->dateNaissance.year);
		printf("ID: %d\n", graph.array[i].head->identifiant);
		printf("----------------------------\n");
	}
}
