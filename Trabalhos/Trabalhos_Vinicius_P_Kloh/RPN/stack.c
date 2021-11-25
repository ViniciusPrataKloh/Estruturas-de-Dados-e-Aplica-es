/*
 * =====================================================================================
 *
 *	  Filename:  stack.c
 *
 * Description:  stack implementation
 *
 *       Version:  2.0
 *       Created:  May 18 2017 11:23:00 am
 *   Last update:  May 21 2017 11:41:00 am
 *      Compiler:  cc
 *        Author:  Vinicius Prata Kloh
 *  Organization:  Comcidis/LNCC
 *
 * =====================================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct stackc{
  char value;
  struct stackc* next;
};
struct stackd{
  double value;
  struct stackd* next;
};

/*
  push function
*/
int pushc(Stackc** stackc, char val){
  Stackc* node_aux = (Stackc*) malloc(sizeof(Stackc));
  if(!node_aux)
    return -1;
  node_aux->value = val;
  node_aux->next = NULL;
  if(!(*stackc)){
    (*stackc) = node_aux;
  } else{
    node_aux->next = (*stackc);
    (*stackc) = node_aux;
  }
  return 0;
}
int pushd(Stackd** stackd, double val){
  Stackd* node_aux = (Stackd*) malloc(sizeof(Stackd));
  if(!node_aux)
    return -1;
  node_aux->value = val;
  node_aux->next = NULL;
  if(!(*stackd)){
    (*stackd) = node_aux;
  } else{
    node_aux->next = (*stackd);
    (*stackd) = node_aux;
  }
  return 0;
}
/*
  end push function
*/

/*
  pop function
*/
int popc(Stackc** stackc, char *val){
  Stackc* node_aux = NULL;
  if(!(*stackc))
    return 1;
  if(!(*stackc)->next){
    *val = (*stackc)->value;
    (*stackc) = NULL;
  } else{
    node_aux = (*stackc);
    (*stackc) = (*stackc)->next;
    *val = node_aux->value;
  }
  free(node_aux);
  return 0;
}
int popd(Stackd** stackd, double *val){
  Stackd* node_aux = NULL;
  if(!(*stackd))
    return 1;
  if(!(*stackd)->next){
    *val = (*stackd)->value;
    (*stackd) = NULL;
  } else{
    node_aux = (*stackd);
    (*stackd) = (*stackd)->next;
    *val = node_aux->value;
  }
  free(node_aux);
  return 0;
}
/*
  end pop function
*/

/*
  print function
*/
int print_stackc(Stackc *stackc){
  Stackc* node_aux = (Stackc*) malloc(sizeof(Stackc));
  if(!stackc)
    return -1;
  printf("\n +    + \n");
  for(node_aux=stackc; node_aux; node_aux=node_aux->next){
    printf(" | %c  | \n", node_aux->value);
    printf(" +----+ \n");
  }
  return 0;
}
int print_stackd(Stackd *stackd){
  Stackd* node_aux = (Stackd*) malloc(sizeof(Stackd));
  if(!stackd)
    return -1;
  printf(" +    + \n");
  for(node_aux=stackd; node_aux; node_aux=node_aux->next){
    printf(" | %f  | \n", node_aux->value);
    printf(" +----+ \n");
  }
  return 0;
}
/*
  end print function
*/

int free_stack(Stackc** stackc){
  Stackc* node_aux = (*stackc);
  if(!(*stackc))
    return -1;
  while(!node_aux){
    Stackc* node_aux2 = (*stackc)->next;
    free(node_aux);
    node_aux = node_aux2;
  }
  free((*stackc));
  return 0;
}

/*
  get_stack_top functions
*/
int get_stackc_top(Stackc* stackc, char *val){
  if(!stackc)
    return 0;
  *val = stackc->value;
  return 1;
}
int get_stacd_top(Stackd* stackd, double *val){
  if(!stackd)
    return 0;
  *val = stackd->value;
  return 1;
}
/*
  end get_stack_top functions
*/
