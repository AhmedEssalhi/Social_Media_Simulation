int degreSeparation(Graph* graph, int id1, int id2) //j'ai pris les id chaque utilisateur a son id spécifique ce qui permet d'eviter les erreurs de collision
{
	if(id1 == id2) return 0; //si l'utilisateur courant est toujours la cible alors pas de changement donc le degré vaut 0.
	
	int visited[MAX_ARRAY]; //tableau pour marquer chaque sommet comme déjà visité afin de ne plus revenir sur le même utilisateur
	int level[MAX_ARRAY]; //tableau pour stocker la distance depuis le sommet de départ
	
	//Initialiser les deux tableaux précédents
	int i;
	for(i = 0; i < MAX_ARRAY; ++i)
	{
		visited[i] = 0; //marquer tous les noeuds comme non visités
		level[i] = -1; //on a encore aucune information sur la distance entre 2 sommets	donc initialiser à -1.
	}	
	
	int file[MAX_ARRAY]; //file pour l'algorithme BFS
	int front = 0, rear = 0; //pointeurs de la file
		
	int start = -1, end = -1; //pour stocker les indices des urilisateurs dans le tableau
		
	//Trouver les indices correspondants aux id
	for(i = 0; i < graph->pos; ++i)
	{
		if(graph->array[i].head->identifiant == id1)
		{
			start = i; //indice de l'utilisateur source
		}
		if(graph->array[i].head->identifiant == id2)
		{
			end = i; //indice de l'utilisateur cible
		}
	} 
	
	if (start == -1 || end == -1) 
	{
        // Si l'un des deux identifiants n'existe pas, afficher un message d'erreur
        printf("Id invalide.\n");
        return -1;
    }
    
    visited[start] = 1;    // Marquer le sommet de départ comme visité
    level[start] = 0;      // Son niveau est 0 (point de départ)
    file[rear++] = start; //Ajout de l'utilisateur source dans la file
    
    while(front < rear)//Tant que la file n'est pas vide
    {
    	int current = file[front++]; //Retirer un élément de la file
    	
    	//Parcours de ses amis
    	struct AdjListNode* temp = graph->array[current].head->next;//un pointeur qui pointe sur chaque ami
    	
    	while(temp != NULL)
    	{
    		int neighbor = -1; //l'indice de l'ami courant
    		
    		//On cherche dans le tableau, le sommet qui correspond à l'Id du cible 
    		for(i = 0; i < graph->pos; ++i)
    		{
    			if(graph->array[i].head->identifiant == temp->identifiant)
    			{
    				neighbor = i;
    				break;
				}
			}
			//Marquer le voisin comme visité et calculer sa distance
			if(neighbor != -1 && !visited[neighbor])
			{
				visited[neighbor] =  1;
				level[neighbor] = level[current] + 1;//incrémenter le courant après chaque passage tant que la cible n'a pas encore été atteinte
				
				if(neighbor == end)
					return level[neighbor]; 
				
				file[rear++] = neighbor; //Ajouter ce voisin à la file pour visiter ses propres voisins
				temp = temp->next; //Passer à l'ami suivant
			}
		}
	}
	return -1; // Si on sort de la boucle sans avoir trouvé l'autre utilisateur, pas de chemin
}
