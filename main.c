#include"main.h"

/**
 * main - Fonction de test
 *
 * Return - 0 en cas de succes
 */
int main(void) 
{
    struct Graph* graph = createGraph();
    int choix;

    do {
        printf("\nMenu :\n");
        printf("1. Ajouter un utilisateur\n");
	printf("2. Afficher la liste\n");
	printf("3. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                createUser(graph);
                break;
            case 2:
		printUserInfos(*graph);
                break;
	    case 3:
		printf("Quiter le programme\n");
		break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
    } while (choix != 2);

    return 0;
}


