#include"main.h"
int main(void) 
{
    struct Graph* graph = createGraph();
    int choix;

    do
    {
        printf("\nMenu :\n");
        printf("1. Ajouter un utilisateur\n");
        printf("2. Afficher la liste\n");
        printf("3. Creer ami(e)\n");
        printf("4. Afficher les degres de separation\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) 
	{
            case 1:
                createUser(graph);
                break;
            case 2:
	        printUserInfos(*graph);
                break;
	    case 3:
        	addFriend(graph);
		break;
	    case 4: 
	    {
		 int id1, id2;
	         printf("Entrez l'ID du premier utilisateur : ");
                 scanf("%d", &id1);
	         printf("Entrez l'ID du second utilisateur : ");
	         scanf("%d", &id2);
	         int deg = degreSeparation(graph, id1, id2);
		 if (deg == -1)
		     printf("Il n'y a pas de chemin entre ces utilisateurs.\n");
	         else
	             printf("Le degre de separation separation entre %d et %d est: %d", id1, id2, deg);
	         break;
	    }
            case 5:
		 printf("Quitter le programme\n");
                 break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
    } while (choix != 5);

    return 0;
}

