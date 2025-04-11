#include "main.h"
int main (){
	struct AdjListNode *node;
	struct AdjList *list;
	struct Graph *graph;
	int v;

	printf("Entrer le nombre des utilisateurs: ");
	scanf("%d", &v);
	//newAdjListNode(1, "rida", 99);
	node = createNode(2, "Ahmed Es-salhi", 10);
	printf("%s\nID: %d\nDest: %d\n", 
		node->nom_complet, 
		node->identifiant, 
		node->dest
	);
	printf("Happy Coding\n");

	return 0;
}