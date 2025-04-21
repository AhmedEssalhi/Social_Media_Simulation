#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_ARRAY 10

/**
 * struct date - Présenter la date de naissance
 *
 * @day: le jour de naissance
 * @month: le mois de naissance
 * @year: l'année de naissance
 */
struct date {
        unsigned int day;
        unsigned int month;
        unsigned int year;
};

/**
 * struct AdjListNode - La structure du noeud (user)
 * 
 * @nom_complet - chaine de character du nom complet
 * @identifiant - identifiant d'utilisateur
 * @dateNaissance - structure represente la date de naissance
 * @next - Pointeur sur l'element suivant
 */
struct AdjListNode {
    int dest;
    char nom_complet[100];
    int identifiant;
    struct date dateNaissance;
    struct AdjListNode* next;
};

/**
 * struct AdjList - Structure represente la list d'adjacence
 *
 * @head - Pointeur vers le premier element de la liste d'adjacence
 */
struct AdjList {
    struct AdjListNode* head;
};

/**
 * struct Graph - structure represente le graph
 *
 * @array - pointeur sur un tableau des listes d'adjacence
 * @pos - définie la position du nouveau user ajouter
 */
struct Graph {
    struct AdjList* array;
    int pos;
};

/**
 * Les prototypes des fonction utiliser à  l'implementation
 */
struct Graph* createGraph();
void createUser(struct Graph *);
void addFriend(struct Graph *, int, int);
struct AdjListNode* newAdjListNode(int, char, int, int, int, int);
void printUserInfos(struct Graph);
int IdGenerator(struct AdjListNode);
unsigned int randomNumber();

#endif
