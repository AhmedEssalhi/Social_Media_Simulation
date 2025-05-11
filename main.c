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
        printf("\n-------------MENU-------------\n");
        printf("1. Ajouter un utilisateur\n");
        printf("2. Afficher la liste des utilisateurs\n");
        printf("3. Creer une amitié\n");
        printf("4. Afficher les amis d'un utilisateur\n");
        printf("5. Trouver amis en commun\n");
        printf("6. Suggerer des amis\n");
        printf("\n---SERVICES SUPPLIMENTAIRES---\n");
        printf("    7. Rechercher pour un ami d'un utilisateur\n");
        printf("    8. Afficher la Degré de séparation entre deux utilisateur\n");
        printf("    9. Rechecher pour un utilisateur\n");
        printf("   -1. Quitter\n");
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
        case -1:
            printf("Au Revoire...\n");
            break;
        case 4:
        {
            printf("\nEntrer L'ID d'utilisateur: ");
            scanf("%d", &id);
            printFriends(*graph, id);
        }
        break;
        case 9:
        {
            printf("Entrer L'ID d'utilisateur: ");
            scanf("%d", &id);
            pos = searchUserId(*graph, id);
            if (pos == -1)
                printf("Aucun utilsateur avec l'ID (%d), n'est trouvée\n", id);
            else
            {
                printf("Un utilisateur avec l'id (%d) est trouvee dans la position %d\n", id, pos);
                printNodeInfo(graph->array[pos - 1].head);
            }
        }
        break;
        case 7:
        {
            AdjListNode *found;
            int friendId;

            printf("Entrer L'ID d'utilisateur: ");
            scanf("%d", &id);
            pos = searchUserId(*graph, id);
            if (pos == -1)
            {
                printf("Aucun utilsateur avec l'ID (%d) n'est trouvée\n", id);
                break;
            }
            printf("L'utilisateur est trouvee dans la position %d\n", pos);
            printf("Entrer L'ID de l'ami(e): ");
            scanf("%d", &friendId);
            found = searchFriend(&graph->array[pos - 1], friendId);
            if (found == NULL)
            {
                printf("Aucun ami(e) avec l'ID (%d) n'est trouvée\n", friendId);
                break;
            }
            printf("\nUn amis avec l'ID\n");
            printNodeInfo(found);
        }
        break;
        case 5:
        {
            int id1, id2;
            AdjList *commonFriend;

            printf("Entrer L'ID du premier utilisateur: ");
            scanf("%d", &id1);
            printf("Entrer L'ID du deuxieme utilisateur: ");
            scanf("%d", &id2);

            commonFriend = findCommonFriends(*graph, id1, id2);
            if (!commonFriend->head)
            {
                printf("Il n'existe aucun amis en commun entre les deux utilisateur entree\n");
                break;
            }

            printf("Ami(s) en commun trouvee\n");
            AdjListNode *tempHeadNode = commonFriend->head;
            printf("\nLes amis en communs trouvee(s) entre %d et %d sont: \n", id1, id2);
            while (tempHeadNode != NULL)
            {
                printNodeInfo(tempHeadNode);
                tempHeadNode = tempHeadNode->next;
            }
        }
        break;
        case 8:
        {
            int id1, id2, degree;

            printf("Entrer L'ID du premier utilisateur: ");
            scanf("%d", &id1);
            printf("Entrer L'ID du deuxieme utilisateur: ");
            scanf("%d", &id2);

            degree = degreSeparation(graph, id1, id2);
            if (degree == -1)
                printf("Pas de lien entre (%d) et (%d)\n", id1, id2);
            else
                printf("Le degre de separation entre (%d) et (%d) est: (%d)\n", id1, id2, degree);
        }
        break;
        case 6:
        {
            int userID;
            AdjList *suggestFriendList;
            AdjListNode *suggestFriendListNode;

            printf("Enter the id: ");
            scanf("%d", &userID);

            suggestFriendList = suggestFriends(*graph, userID);
            suggestFriendListNode = suggestFriendList->head;
            if (suggestFriendListNode == NULL)
            {
                printf("Aucun ami(e) suggerer\n");
                break;
            }
            printf("La list des ami(s) suggerees pour l'utilisateur avec l'ID (%d):\n", userID);
            while (suggestFriendListNode != NULL)
            {
                printNodeInfo(suggestFriendListNode);
                suggestFriendListNode = suggestFriendListNode->next;
            }
            break;
        }
        default:
            printf("Choix invalide, veuillez réessayer.\n");
            break;
        }
    } while (choix != -1);

    return 0;
}
