#include"main.h"
// Fonction pour ajouter un utilisateur
void createUser(struct Graph* graph) {
    if (graph->pos < MAX_ARRAY) {
	    char nom_complet[100];
	    int identifiant;

	    printf("Entrez le nom complet de l'utilisateur : ");
	    scanf(" %[^\n]", nom_complet);  /*Lire le nom complet avec espaces*/
	    printf("Entrez l'identifiant de l'utilisateur : ");
	    scanf("%d", &identifiant);  /*Lire l'identifiant*/

	    /*Créer un noeud d'adjacence pour cet utilisateur*/
	    struct AdjListNode* newNode;

	    newNode = newAdjListNode(graph->pos, nom_complet, identifiant);
	    /*Ajouter ce noeud à la liste d'adjacence au sommet correspondant à 'pos'*/
	    graph->array[graph->pos].head = newNode;
	    /*Incrémenter 'pos' pour le prochain utilisateur*/
	    graph->pos++;
    } else {
	    printf("Le nombre maximum d'utilisateurs a été atteint.\n");
    }
}
