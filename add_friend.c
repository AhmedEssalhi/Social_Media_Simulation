#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * addfreind - Établit une amitié entre deux utilisateurs dans le graphe en ajoutant des liens bidirectionnels.
 * @param graph :c  Pointeur vers le graphe contenant les utilisateurs et leurs amitiés.
 */
void addFriend(struct Graph* graph) {
    int id1, id2;
    int index1 = -1, index2 = -1;

    // Saisie des IDs
    printf("Entrez l'ID du premier utilisateur : ");
    scanf("%d", &id1);
    getchar(); // Nettoyer le buffer

    printf("Entrez l'ID du second utilisateur : ");
    scanf("%d", &id2);
    getchar();

    // Recherche des utilisateurs
    for (int i = 0; i < graph->pos; i++) {
        if (graph->array[i].head != NULL) {
            if (graph->array[i].head->identifiant == id1) index1 = i;
            if (graph->array[i].head->identifiant == id2) index2 = i;
        }
    }

    // Vérifications
    if (index1 == -1 || index2 == -1) {
        printf("Erreur : Un ou plusieurs utilisateurs non trouvés\n");
        return;
    }

    if (index1 == index2) {
        printf("Erreur : Un utilisateur ne peut pas être ami avec lui-même\n");
        return;
    }

    // Vérification si amitié existe déjà
    struct AdjListNode* current = graph->array[index1].head->next;
    while (current != NULL) {
        if (current->identifiant == id2) {
            printf("Ces utilisateurs sont déjà amis\n");
            return;
        }
        current = current->next;
    }

    // Création des liens d'amitié (bidirectionnels)
    // Ami 1 -> Ami 2
    struct AdjListNode* newFriend1 = malloc(sizeof(struct AdjListNode));
    newFriend1->dest = index2;
    strcpy(newFriend1->nom_complet, graph->array[index2].head->nom_complet);
    newFriend1->identifiant = graph->array[index2].head->identifiant;
    newFriend1->dateNaissance = graph->array[index2].head->dateNaissance; // Copie toute la structure date
    newFriend1->next = graph->array[index1].head->next;
    graph->array[index1].head->next = newFriend1;

    // Ami 2 -> Ami 1
    struct AdjListNode* newFriend2 = malloc(sizeof(struct AdjListNode));
    newFriend2->dest = index1;
    strcpy(newFriend2->nom_complet, graph->array[index1].head->nom_complet);
    newFriend2->identifiant = graph->array[index1].head->identifiant;
    newFriend2->dateNaissance = graph->array[index1].head->dateNaissance;
    newFriend2->next = graph->array[index2].head->next;
    graph->array[index2].head->next = newFriend2;

    // Confirmation
    printf("Amitié établie entre :\n");
    printf("- %s (ID:%d)\n", graph->array[index1].head->nom_complet, id1);
    printf("- %s (ID:%d)\n", graph->array[index2].head->nom_complet, id2);
}
