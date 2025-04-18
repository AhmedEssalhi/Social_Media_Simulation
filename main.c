#include"main.h"
int main() {
    struct Graph* graph = createGraph();  // Créer un graphe vide
    int choix;
    do {
        printf("\nMenu :\n");
        printf("1. Ajouter un utilisateur\n");
        printf("2. Quitter\n");
	    printf("3. Afficher la liste\n");
        printf("4. creer ami(e)\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                createUser(graph);  // Ajouter un utilisateur
                break;
            case 2:
                printf("Quitter le programme.\n");
                break;
	    case 3:
		printUserInfos(*graph);	
		break;
            case 4:
	        addFriend(graph);
        	break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
    } while (choix != 2);

    return 0;
}


