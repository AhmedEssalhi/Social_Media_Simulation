#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
/**< Nombre maximum d'utilisateurs dans le graphe */
#define MAX_ARRAY 10 

/**
 * @struct date
 * Représente une date de naissance avec jour, mois, année.
 */
struct date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

/**
 * @struct AdjListNode
 * Représente un utilisateur ou un ami dans la liste d'adjacence.
 * Chaque noeud contient :
 * - l'identifiant unique
 * - le nom complet
 * - la date de naissance
 * - un pointeur vers l’ami suivant dans la liste chaînée.
 */
struct AdjListNode {
    int dest;                      /**< Index du voisin dans le tableau de sommets */
    char nom_complet[100];         /**< Nom complet de l’utilisateur/ami */
    int identifiant;               /**< Identifiant unique */
    struct date dateNaissance;     /**< Date de naissance */
    struct AdjListNode* next;      /**< Pointeur vers le prochain ami */
};

/**
 * @struct AdjList
 * Représente la liste d’adjacence d’un utilisateur (sommet du graphe).
 */
struct AdjList {
    struct AdjListNode* head; /**< Premier noeud (utilisateur ou ami) */
};

/**
 * @struct Graph
 * Structure principale représentant le réseau social.
 * Contient :
 * - Un tableau de listes d’adjacence (utilisateurs),
 * - Une position (`pos`) indiquant le nombre d’utilisateurs ajoutés.
 */
struct Graph {
    struct AdjList* array;  /**< Tableau des listes d'adjacence */
    int pos;                /**< Position actuelle (nombre d’utilisateurs) */
};

/* ==== Prototypes des fonctions ==== */

/**
 * @brief Initialise et retourne un graphe vide.
 * @return Pointeur vers une structure `Graph` vide.
 */
struct Graph* createGraph();

/**
 * @brief Ajoute un utilisateur au graphe avec nom et date.
 * @param graph Graphe dans lequel l’utilisateur sera ajouté.
 */
void createUser(struct Graph* graph);

/**
 * @brief Crée une amitié bidirectionnelle entre deux utilisateurs existants.
 * @param graph Pointeur vers le graphe.
 */
void addFriend(struct Graph* graph);

/**
 * @brief Affiche les informations de tous les utilisateurs du graphe.
 * @param graph Graphe contenant les utilisateurs.
 */
void printUserInfos(struct Graph graph);

/**
 * @brief Génère un identifiant unique à partir du nom et date de naissance.
 * @param user Utilisateur pour lequel générer l’identifiant.
 * @return Identifiant généré.
 */
int IdGenerator(struct AdjListNode user);

/**
 * @brief Génère un nombre aléatoire positif (0–999).
 * @return Nombre aléatoire.
 */
unsigned int randomNumber();

#endif

