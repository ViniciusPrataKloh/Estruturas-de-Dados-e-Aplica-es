#include <stdlib.h>
#include <stdio.h>

                /* Define the Node struct */
struct node{
  int value;
  struct Node* next;
}; typedef struct node Node;

                /* Define the Stack struct */
struct stack{
  Node* top;
}; typedef struct stack Stack;

              /* Function to create the Stack */
Stack* create_stack(void){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}
              /* Function to create a new Node */
Node* create_new_node(Node* n, int val){
  Node* node_aux = (Node*) malloc(sizeof(Node));
  node_aux->value = val;
  (node_aux)->next = n;
  return node_aux;
}
              /* Function to withdraw a Node */
/*Node* withdraw_node(Node* n){
    Node* node = n->prox; // malloc
    free(n);
    return node;
}*/

              /* Function to verify if the Stack has a Node */
/*int without_node(Stack* s){
    if(!s->top)
      return 0;
    else
      return 1;
}*/
              /* Function to insert a new Node into Stack */
void push(Stack** s, int val){
    (s)->top = create_new_node((s)->top, val);
}
              /* Function to get a Node into Stack */
/*int pop(Stack** s){
    int val = NULL;
    if(!s->top)
      printf("Nothin Node...\n");
    val = s->top->value;
    s->top = withdraw_node(s->top);
    return val;
}*/

/*void free_stack(Stack* s){
  Node* node = s->top;
  while(t){
      Node* aux = s->next;
      free(node);
      node = aux;
  }
  free(node);
}*/

/*void print_stack(Stack* s){
    Node* aux = NULL;
    for(aux=s->top; aux; aux=aux->next)
      printf("%d, " aux->value);
}*/
