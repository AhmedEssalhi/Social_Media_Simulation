#include "main.h"

/**
 * main - Fonction de test
 *
 * Return - 0 en cas de succes
 */
int main(void)
{
    Graph *graph = createGraph();
    int choix, id, pos;

    do
    {
        printf("\nMenu :\n");
        printf("1. Ajouter un utilisateur\n");
        printf("2. Afficher la liste\n");
        printf("3. Creer ami(e)\n");
        printf("4. Quitter\n");
        printf("5. Afficher les amis\n");
        printf("6. Rechecher un utilisateur\n");
        printf("7. Rechercher un amis\n");
        printf("8. Trouver amis en commun\n");
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
        {
            printf("L'identifiant: ");
            scanf("%d", &id);
            printFriends(*graph, id);
        }
            break;
        case 6:
        {
            printf("L'identifiant: ");
            scanf("%d", &id);
            pos = searchUserId(*graph, id);
            if (pos == -1)
                printf("User id (%d), Not Found\n", id);
            else   
                printf("User id (%d) Found in position %d\n", id, pos);
        }
            break;
        case 7:
        {
            AdjListNode *found;
            int friendId;

            printf("User ID: ");
            scanf("%d", &id);
            pos = searchUserId(*graph, id);
            if (pos == -1)
            {
                printf("User ID not found\n");
                break;
            }
            printf("pos-> %d\nFriend ID: ", pos);
            scanf("%d", &friendId);
            found = searchFriend(&graph->array[pos - 1], friendId);
            if (found == NULL)
            {
                printf("Friend not found\n");
                break;
            }
            printf("\nNode found\n");
            printNodeInfo(found);
        }
            break;
        case 8:
        {
            int id1, id2;
            AdjList *commonFriend;

            printf("ID1: ");
            scanf("%d", &id1);
            printf("ID2: ");
            scanf("%d", &id2);

            commonFriend = findCommonFriends(*graph, id1, id2);
            
            if (!commonFriend->head)
            {
                printf("No common friends between IdUser %d and IdUser %d\n", id1, id2);
                break;
            }

            printf("Common friend found\n");
            AdjListNode *tempHeadNode = commonFriend->head;
            printf("\nLes amis en communs entre %d et %d sont: \n", id1, id2);
            while (tempHeadNode != NULL)
            {
                printf("Sir/Mis ID: %d\n", tempHeadNode->identifiant);
                tempHeadNode = tempHeadNode->next;
            }
            //printNodeInfo(commonFriend->head);
        }
            break;
        default:
            printf("Choix invalide, veuillez réessayer.\n");
            break;
        }
    } while (choix != 4);

    return 0;
}