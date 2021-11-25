#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "graph.h"

/*
  auxiliar functions
*/
void flush_in();
/*
  end auxiliar function
*/

int main(void){
  char option = 1;
  char node;
  char neighbors[100];
  int lenght_neighbors;
  int costs[100];
  int count = 0;
  Graph* graph;
  create_graph(&graph);

  printf("\n\n\t\t --_--_--_--_--_--_--_--_--_--_--_--\n");
  printf("\t\t\t   Bi-directional Graph\n");
  printf("\t\t --_--_--_--_--_--_--_--_--_--_--_--\n\n\n");

  do{
    printf("\n\n- Enter:\n \'i\' to insert a new node,\n \'d\' to delete a node,\n \'p\' to print the graph,\n \'g\' to use the greedy algorithm,\n \'f\' to free the graph or\n \'e\' to exit.\n");
    scanf("%c", &option);
    flush_in();
    switch(option) {
      case 'i':
        printf("Enter the name of the node.\n");
        scanf("%c", &node);
        flush_in();
        printf("Enter the neighbors of the node, without space (i.e. ABD, not A B D)\n");
        fgets(neighbors, 100, stdin);
        lenght_neighbors = strlen(neighbors);
        for(count = 0; count < lenght_neighbors-1; count++){
          printf("Enter the cost of the %dº neighbor.\n", count+1);
          scanf("%d", &costs[count]);
          flush_in();
        }
        if(insert(&graph, node, neighbors, costs))
          printf("Inserted node: %c\n", node);
        else
          printf("Not inserted node: %c\n", node);
      break;

      case 'd':
        printf("Enter the name of the node.\n");
        scanf("%c", &node);
        flush_in();
        if(delete(&graph, node))
          printf("Deleted node: %c\n", node);
        else
          printf("Not deleted node: %c\n", node);
      break;

      case 'p':
        if(!print_graph(&graph))
          printf("\nEmpty graph.\n");
      break;

      case 'g':
        printf("Enter the name of the node to start.\n");
        scanf("%c", &node);
        flush_in();
        if(greedy(&graph, node)){
          if(check_convex(&graph))
            printf("\n-- Convex graph --\n");
          else
            printf("\n-- Not convex graph --\n");
        } else
          printf("\n-- Node not exist --\n");
      break;

      case 'f':
        if(free_graph(&graph))
          printf("Exiting.\n");
        return 0;
      break;

      case 'e':
        return 0;
      break;

      default:
        printf("Invalid option.\n");
      break;
    }
  } while(option);

  return 0;
}

void flush_in(){
   int ch;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
