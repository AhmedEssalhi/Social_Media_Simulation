#include "main.h"

// Fonction pour ajouter un utilisateur
void createUser(struct Graph* graph) {
    if (graph->pos < MAX_ARRAY) {
	    char nom_complet[100];
	    int identifiant;
	    int jour, mois, annee;
	    struct AdjListNode *newNode;

	    newNode = malloc(sizeof(struct AdjListNode));
	    printf("Entrez le nom complet de l'utilisateur : ");
	    scanf(" %[^\n]", newNode->nom_complet);  /*Lire le nom complet avec espaces*/
	    printf("Entrer la date de naissance: ");
	    scanf("%u-%u-%u", &newNode->dateNaissance.day, 
			    &newNode->dateNaissance.month, 
			    &newNode->dateNaissance.year);
	    newNode->identifiant = IdGenerator(*newNode);  /*Lire l'identifiant*/

	    /*Ajouter ce noeud à la liste d'adjacence au sommet correspondant à 'pos'*/
	    graph->array[graph->pos].head = newNode;
	    /*Incrémenter 'pos' pour le prochain utilisateur*/
	    graph->pos++;
    } else {
	    printf("Le nombre maximum d'utilisateurs a été atteint.\n");
	    /*return -1;*/
    }
}

/**
 * random - Fonction qui retourne un nombre aléatoire positive
 *
 * Return: Nombre aléatoire positive
 */
unsigned int randomNumber(void)
{
        unsigned int randomNum;

        srand(time(0));
        randomNum = rand() + RAND_MAX / 2;
        randomNum %= 1000;
	randomNum = abs(randomNum);

        return (unsigned int)(randomNum);
}

/*
 * IdGenerator - Fonction qui génére un identifiant (ID)
 * pour chaque utilisateur d'aprés leur nom complet
 * @nom: name to generate ID from
 *
 * Return: return the ID generated
 */
int IdGenerator(struct AdjListNode user)
{
	char *nom;
	int date;
	unsigned int randomNum;
	int id;

	randomNum = randomNumber();
	nom = user.nom_complet;
	date = user.dateNaissance.day + user.dateNaissance.month + user.dateNaissance.year;
	id = 0;
	for (int i = 0; i < (int)strlen(nom); i++)
		id += (int)nom[i];
	id = (id * randomNum + date) + strlen(nom);

	return id;
}
