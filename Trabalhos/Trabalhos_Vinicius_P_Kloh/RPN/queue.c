/*
 * =====================================================================================
 *
 *   Filename:  queue.c
 *
 * Description:  queue implementation
 *
 *       Version:  1.0
 *       Created:  May 18 2017 11:25:00 am
 *   Last update:  May 18 2017 10:11:00 pm
 *      Compiler:  cc
 *        Author:  Vinicius Prata Kloh
 *  Organization:  Comcidis/LNCC
 *
 * =====================================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct node{
  char value;
  int sig;
  struct node* next;
};

struct queue{
  Node* first;
  Node* last;
};

int create_queue(Queue** queue){
  (*queue) = (Queue*) malloc(sizeof(Queue));
  if(!(*queue))
    return -1;
  (*queue)->first = NULL;
  (*queue)->last = NULL;
  return 0;
}

int insert(Queue** queue, char val){
  Node* node = (Node*) malloc(sizeof(Node));
  if(!node)
    return -1;
  node->value = val;
  node->next = NULL;
  if(!(*queue)->first){
    (*queue)->first = node;
    (*queue)->last = node;
  } else{
    (*queue)->last->next = node;
    (*queue)->last = node;
  }
  return 0;
}

int withdraw(Queue** queue, char *val){
  Node* node_aux = (Node*) malloc(sizeof(Node));
  if(!node_aux)
    return 1;
  if(!(*queue)->first)
    return 1;
  if(!((*queue)->first->next)){
    node_aux = (*queue)->first;
    *val = node_aux->value;
    free(node_aux);
    (*queue)->first = NULL;
    (*queue)->last = NULL;
  } else{
    node_aux = (*queue)->first;
    (*queue)->first = (*queue)->first->next;
    *val = node_aux->value;
    free(node_aux);
  }
  return 0;
}

int print_queue(Queue* queue){
  Node* node_aux = (Node*) malloc(sizeof(Node));
  if(!node_aux)
    return -1;
  if(!queue->first)
    return -1;
    printf("\n");
  for(node_aux=queue->first; node_aux; node_aux=node_aux->next){
    printf(" | %c |--> ", node_aux->value);
  }
  printf("\n");
  return 0;
}

int free_queue(Queue** queue){
  Node* node_aux = NULL;
  node_aux = (*queue)->first;
  if(!(*queue))
    return -1;
  while(!node_aux){
    Node* node_aux2 = node_aux->next;
    free(node_aux);
    node_aux = node_aux2;
  }
  free((*queue));
  return 0;
}
