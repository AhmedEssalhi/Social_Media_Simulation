#include "main.h"

/**
 * main - Fonction de test
 *
 * Return - 0 en cas de succes
 */
int main(void)
{
    Graph *graph = createGraph();
    int choix;

    do
    {
        printf("\nMenu :\n");
        printf("1. Ajouter un utilisateur\n");
        printf("2. Afficher la liste\n");
        printf("3. Creer ami(e)\n");
        printf("4. Quitter\n");
        printf("5. Afficher les amis\n");
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
            printf("Quitter le programme\n");
            break;
        case 5:
            printFriends(*graph);
            break;
        default:
            printf("Choix invalide, veuillez réessayer.\n");
            break;
        }
    } while (choix != 4);

    return 0;
}
