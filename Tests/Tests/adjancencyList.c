#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct adjNode adjNode;
struct adjNode {
	int dest;
	char *name;
	adjNode *next;
};

typedef struct {
	adjNode *head;
}adjList;

typedef struct {
	int V;
	int pos;
	adjList *arrayPtr;
}graph;

graph *createEmptyGraph()
{
	graph *arrayList;
	int i;

	arrayList->arrayPtr = (adjList *)malloc(sizeof(adjList) * MAX);
	arrayList->pos = 0;
	for (i = 0; i < MAX; i++)
		arrayList->arrayPtr[i].head = NULL;
	return arrayList;
}

graph *createUser()
{
	graph *g;
	adjNode *user;
	
	user = malloc(sizeof(adjNode));
	user->next = NULL;
	g->arrayPtr[g->pos].head = user;
	user = g->arrayPtr[g->pos++].head;
	printf("Username: ");
	scanf("%[^\n]s", user->name);

	return g;
}

int main()
{
	adjList *linkedList;
	graph *arrayList;
	adjNode *node;
	int i;

	printf("Hello helberton\n");
	arrayList = createEmptyGraph();
	printf("In the middle of something\n");
	arrayList = createUser();
	/*for (i = 0; i < 2; i++)*/
		printf("Username: %s\n", 
				arrayList->arrayPtr[i].head->name);
	printf("Happy Coding\n");


	return 0;
}
