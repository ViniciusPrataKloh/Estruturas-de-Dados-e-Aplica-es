/*
 * =====================================================================================
 *
 *  	 Filename:  bi_graph.c
 *
 *  Description:  bidirectional graph implementation
 *
 *        Version:  2.3.3
 *        Created:  May 22 2017 10:26:19 pm
 *    Last Update:  Jun 07 2017 08:49:05 am
 *       Compiler:  cc
 *         Author:  Vinicius Prata Kloh
 *   Organization:  Comcidis/LNCC
 *
 * =====================================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

struct graph{
  struct node* first;
};typedef struct graph Graph;

struct neighbor{
  int cost;
  struct node* node;
  struct neighbor* next;
};typedef struct neighbor Neighbor;

struct node{
  int isVisited;
  char name;
  struct neighbor* first;
  struct node* next;
};typedef struct node Node;


/*
  auxiliar functions
*/
int insert_neighbors(Graph** graph, Node* source, char neighbor, int cost);
int check_neighbor(Graph** graph, char name);
int delete_neighbors(Node** node);
int check_visited(Graph** graph, char name);
int check_out(Graph** graph);
int print_visited(Graph** graph);
int set_visited(Graph** graph);
/*
  end auxiliar functions
*/

int create_graph(Graph** graph){
  (*graph) = (Graph*) malloc(sizeof(Graph));
  if(!(*graph))
    return 0;
  (*graph)->first = NULL;
  return 1;
}

int check_neighbor(Graph** graph, char name){
  Node* aux = (Node*) malloc(sizeof(Node));
  if(!aux)
    return -1;
  for(aux = (*graph)->first; aux && aux->name != name; aux = aux->next);
  if(!aux)
    return 0;
  else if(aux->name == name)
    return 1;

  return 2;
}

int insert(Graph** graph, char name, char* neighbors, int* costs){
  int count = 0;
  int lenght = strlen(neighbors);
  Node* new_node = (Node*) malloc(sizeof(Node));

  if(!(*graph)->first)
    lenght = 1;

  if(!new_node)
    return 0;

  if(check_neighbor(graph, name)){
    return 0;
  }

  new_node->name = name;
  new_node->first = NULL;
  new_node->next = NULL;
  new_node->isVisited = 0;

  if(!(*graph)){
    free(new_node);
    return -1;
  }

  new_node->next = (*graph)->first;
  (*graph)->first = new_node;

  while(count < lenght){
    insert_neighbors(&(*graph), new_node, neighbors[count], costs[count]);
    count++;
  }

  return 1;
}

int insert_neighbors(Graph** graph, Node* source, char neighbor, int cost){
  Neighbor* new_neighbor = (Neighbor*) malloc(sizeof(Neighbor));
  Neighbor* new_neighbor2 = (Neighbor*) malloc(sizeof(Neighbor));

  Node* aux = (Node*) malloc(sizeof(Node));
  Node* aux2 = (Node*) malloc(sizeof(Node));

  if(!new_neighbor)
    return -2;
  if(!aux)
    return -2;
  if(!aux2)
    return -2;
  if(!(*graph))
    return -1;

  if(!check_neighbor(graph, neighbor))
    return -1;

  new_neighbor->cost = cost;
  new_neighbor->node = NULL;
  new_neighbor->next = NULL;
  new_neighbor2->cost = cost;
  new_neighbor2->node = NULL;
  new_neighbor2->next = NULL;

  for(aux = (*graph)->first; aux && aux->name != source->name; aux = aux->next);

  new_neighbor->next = aux->first;
  aux->first = new_neighbor;

  for(aux2 = (*graph)->first; aux && aux2->name != neighbor; aux2 = aux2->next);

  if(aux2->name != aux->name){
    new_neighbor->node = aux2;
    new_neighbor2->next = aux2->first;
    aux2->first = new_neighbor2;
    new_neighbor2->node = aux;
  } else{
    new_neighbor->node = aux2;
  }

  return 0;
}

int delete(Graph** graph, char name){
  Node* aux = NULL;
  Node* aux2 = NULL;

  for(aux = (*graph)->first, aux2 = (*graph)->first; aux && aux->name != name; aux2 = aux, aux = aux->next);
  if(!aux){
    return 0;
  } else if(aux->name == (*graph)->first->name && !(*graph)->first->next){
    delete_neighbors(&aux);
    free(aux);
    (*graph)->first = NULL;
  } else if(aux->name == (*graph)->first->name && (*graph)->first->next){
      delete_neighbors(&aux);
      (*graph)->first = aux->next;
      free(aux);
    } else if(aux->name == name){
      delete_neighbors(&aux);
      aux2->next = aux->next;
      free(aux);
    }
  return 1;
}

int delete_neighbors(Node** node){
  Neighbor* aux = NULL;
  Neighbor* aux2 = NULL;
  Neighbor* aux_prev = NULL;

  for(aux = (*node)->first; aux; aux = aux->next){
    for(aux2 = aux->node->first, aux_prev = NULL; aux2 && aux2->node->name != (*node)->name; aux_prev = aux2, aux2 = aux2->next);
    if(!aux_prev && aux2->node->name == (*node)->name && !aux2->next){
      aux->node->first = NULL;
      free(aux2);
    } else if(!aux_prev && aux2->node->name == (*node)->name && aux2->next){
      aux->node->first = aux2->next;
      free(aux2);
    } else if(aux2->node->name == (*node)->name && !aux2->next){
      aux_prev->next = NULL;
      free(aux2);
    } else{
      aux_prev->next = aux2->next;
      free(aux2);
    }
  }

  for(aux = (*node)->first; aux; aux = aux->next){
    (*node)->first = aux->next;
    free(aux);
  }
  return 0;
}

int free_graph(Graph** graph){
  Node* aux = NULL;

  if(!(*graph)->first)
    return 0;

  for(aux = (*graph)->first; aux; aux = aux->next){
    if(!delete(&(*graph), aux->name))
      return 0;
  }
  free((*graph));
  return 1;
}

int check_visited(Graph** graph, char name){
  Node* aux = NULL;
  for(aux = (*graph)->first; aux && aux->name != name; aux = aux->next);
  if(aux->isVisited)
      return 1;
  else
    return 0;
}

int check_out(Graph** graph){
  Node* aux = NULL;
  Neighbor* aux2 = NULL;

  for(aux = (*graph)->first; aux; aux = aux->next){
    if(check_visited(&(*graph), aux->name)){
      for(aux2 = aux->first; aux2; aux2 = aux2->next){
        if(!check_visited(&(*graph), aux2->node->name))
          return 0;
        else
          continue;
      }
    }
  }
  return 1;
}

int set_visited(Graph** graph){
    Node* aux = NULL;

    if(!(*graph))
      return -1;

    for(aux = (*graph)->first; aux; aux = aux->next){
      aux->isVisited = 0;
    }
    return 0;
}

int greedy(Graph** graph, char name){
  Node* aux = NULL;
  Node* aux3 = NULL;
  Neighbor* aux2 = NULL;
  int larger_cost = 0;
  int out = 0;
  char larger_name;

  set_visited(&(*graph));
  for(aux = (*graph)->first; aux && aux->name != name; aux = aux->next);
  if(!aux)
    return 0;

  aux->isVisited = 1;
  //printf("\nStarting on node: %c.\n", aux->name);

  if(!aux->first)
    goto FINISH;

  for(aux2 = aux->first; aux2; aux2 = aux2->next){
    if(aux2->cost > larger_cost){
      larger_cost = aux2->cost;
      larger_name = aux2->node->name;
    }
  }

  for(aux = (*graph)->first; aux && aux->name != larger_name; aux = aux->next);
  aux->isVisited = 1;
  //printf("\t|\n\t+-Largest neighbor: %c. \n", aux->name);

  larger_name = ' ';
  larger_cost = 0;

  while(out == 0){
    for(aux = (*graph)->first; aux; aux = aux->next){
      if(check_visited(&(*graph), aux->name)){
        //printf("\nChecking visited node: %c. \n", aux->name);
        for(aux2 = aux->first; aux2; aux2 = aux2->next){
          //printf("\t|\n\t+-Checking neighbor: %c. \n", aux2->node->name);
          if(!aux2)
            break;
          if(!check_visited(&(*graph), aux2->node->name)){
            //printf("\t|\n\t+---Neighbor %c not yet visited..\n", aux2->node->name);
            if(aux2->cost > larger_cost){
              larger_cost = aux2->cost;
              larger_name = aux2->node->name;
            } else{
              continue;
            }
          } else
            //printf("\t|\n\t+---Neighbor %c already visited.\n", aux2->node->name);
          if(check_out(&(*graph)))
            goto FINISH;
        }
      } else
          continue;
    }
    for(aux3 = (*graph)->first; aux3 && aux3->name != larger_name; aux3 = aux3->next);
    aux3->isVisited = 1;
    printf("\n\t=\n\t+-Largest neighbor: %c. \n", aux3->name);

    larger_name = ' ';
    larger_cost = 0;

    out = check_out(&(*graph));
  }
  FINISH: print_visited(&(*graph));
  return 1;
}

int print_visited(Graph** graph){
  Node* aux = NULL;

  if(!(*graph))
    return -1;

  printf("\n\nVisited Nodes: ");
  for(aux = (*graph)->first; aux; aux = aux->next){
    if(aux->isVisited){
      printf("|| %c ||, ", aux->name);
    }
  }
  printf("\n");
  return 0;
}

int print_graph(Graph** graph){
  Node* aux = NULL;
  Neighbor* aux2 = NULL;

  if(!(*graph)->first)
    return 0;

  printf("\n\n--_--_-- GRAPH --_--_--\n");
  for(aux = (*graph)->first; aux; aux = aux->next){
    printf("\n\nNode => || %c || ", aux->name);
    for(aux2 = aux->first; aux2; aux2 = aux2->next){
      if(!aux2)
        break;
      printf(" Neighbors -> |Node: %c, Cost: %d|, ", aux2->node->name, aux2->cost);
    }
    printf("\n\n");
  }
  return 1;
}

int check_convex(Graph** graph){
  Node* aux = NULL;

  for(aux = (*graph)->first; aux; aux = aux->next){
    if(!aux->isVisited){
      return 0;
    }
    else
      continue;
  }
  return 1;
}
