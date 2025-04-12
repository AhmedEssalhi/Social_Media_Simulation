#include "main.h"

void printArrayList(struct Graph graph, int size)
{
	int i;
	
	printf("\nUser Information: \n");
	for (i = 0; i < 2; i++)
	{
		printf("Username: %s\n", graph.array[i].head->nom_complet);
		printf("ID: %d\n", graph.array[i].head->identifiant);
	}
}
