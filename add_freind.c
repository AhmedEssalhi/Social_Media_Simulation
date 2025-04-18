#include "main.h"

void addFriend(struct Graph* graph) {
    int id1, id2;
    int index1 = -1, index2 = -1;

    // Saisie des IDs
    printf("Entrez l'ID du premier utilisateur : ");
    scanf("%d", &id1);
    getchar();

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
    struct AdjListNode* newFriend1 = newAdjListNode(
        index2,
        graph->array[index2].head->nom_complet,
        graph->array[index2].head->identifiant,
        graph->array[index2].head->dateNaissance.day,
        graph->array[index2].head->dateNaissance.month,
        graph->array[index2].head->dateNaissance.year
    );
    newFriend1->next = graph->array[index1].head->next;
    graph->array[index1].head->next = newFriend1;

    struct AdjListNode* newFriend2 = newAdjListNode(
        index1,
        graph->array[index1].head->nom_complet,
        graph->array[index1].head->identifiant,
        graph->array[index1].head->dateNaissance.day,
        graph->array[index1].head->dateNaissance.month,
        graph->array[index1].head->dateNaissance.year
    );
    newFriend2->next = graph->array[index2].head->next;
    graph->array[index2].head->next = newFriend2;

    printf("Amitié établie entre %s (ID:%d) et %s (ID:%d)\n",
           graph->array[index1].head->nom_complet, id1,
           graph->array[index2].head->nom_complet, id2);
}