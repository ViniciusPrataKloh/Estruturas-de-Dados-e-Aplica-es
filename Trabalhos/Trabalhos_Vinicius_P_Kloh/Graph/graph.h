/*
  *@author Vinícius Prata Klôh
*/

#ifndef GRAPH_H
#define GRAPH_H 1

/*
  defines
*/
typedef struct graph Graph;
typedef struct node Node;
typedef struct neighbors Neighbors;
/*
  end defines
*/

/*
  functions
*/
int create_graph(Graph** graph);
int insert(Graph** graph, char name, char* neighbors, int* costs);
int delete(Graph** graph, char name);
int free_graph(Graph** graph);
int print_graph(Graph** graph);
int greedy(Graph** graph, char name);
int check_convex(Graph** graph);
/*
  end functions
*/

#endif /* GRAPH_H 1 */
