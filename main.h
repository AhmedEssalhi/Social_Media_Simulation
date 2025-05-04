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
typedef struct {
    unsigned int day;
    unsigned int month;
    unsigned int year;
}Date;

/**
 * AdjListNode - La structure du noeud (user)
 * 
 * @nom_complet - chaine de character du nom complet
 * @identifiant - identifiant d'utilisateur
 * @dateNaissance - structure represente la date de naissance
 * @next - Pointeur sur l'element suivant
 */
typedef struct AdjListNode AdjListNode;
struct AdjListNode {
    int dest;
    char nom_complet[100];
    int identifiant;
    Date dateNaissance;
    AdjListNode *next;
};

/**
 * struct AdjList - Structure represente la list d'adjacence
 *
 * @head - Pointeur vers le premier element de la liste d'adjacence
 */
typedef struct {
    AdjListNode *head;
}AdjList;

/**
 * Graph - structure represente le graph
 *
 * @array - pointeur sur un tableau des listes d'adjacence
 * @pos - définie la position du nouveau user ajouter
 */
typedef struct {
    AdjList *array;
    int pos;
}Graph;

/**
 * Les prototypes des fonction utiliser à  l'implementation
 */
Graph* createGraph();
void createUser(Graph *);
void addFriend(Graph *);
void printUserInfos(Graph);
int IdGenerator(AdjListNode);
unsigned int randomNumber();
int printFriends(Graph, int);
void printLinkedList(AdjList *);
int searchUserId(Graph, int);
AdjListNode *searchFriend(AdjList *, int);
AdjListNode *findCommonFriends(Graph, int, int);
void printNodeInfo(AdjListNode *);
int degreSeparation(Graph*, int, int);
void freeGraph(Graph*);

#endif

