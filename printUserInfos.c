#include "main.h"

void printUserInfos(struct Graph graph)
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
		printf("ID: %d\n", graph.array[i].head->identifiant);
		if (graph.pos > 1)
			printf("----------------------------\n");
	}
	printf("---------------------------- \n");
}
