#include <stdlib.h>
#include <stdio.h>

struct no{
  int valor;
  struct no* ant;
  struct no* prox;
}; typedef struct no No;

No* inicio = NULL;

int inserir(int val){
  No* aux = NULL;

  /* Aloca e inicaliza novo no */
  No* novo = (No*) malloc(sizeof(No));
  novo->valor = val;
  novo->ant = NULL;
  novo->prox = NULL;

  if(!inicio){  /* Lista vazia */
    inicio = novo;
    return 0;
  }
  if(novo->valor < inicio->valor){ /* Inserir no inicio */
    aux = inicio;
    inicio = novo;
    inicio->prox = aux;
    aux->ant = inicio;
    return 0;
  }

  for(aux=inicio; aux->prox && aux->prox->valor<novo->valor; aux=aux->prox);

  if(!aux->prox){ /* Inserir no final */
    aux->prox = novo;
    novo->ant = aux;
    return 0;
  }
  if(aux->valor == novo->valor){  /* No repetido */
    printf("No repetido...\n");
    free(novo);
    return 1;
  } else{   /* Inserir no meio */
    aux->prox->ant = novo;
    novo->prox = aux->prox;
    aux->prox = novo;
    novo->ant = aux;
    return 0;
  }
}

int excluir(int val){
  No* aux = NULL;
  if(!inicio){    /* Lista vazia */
      printf("Lista vazia...\n");
      return 1;
  }
  if(inicio->valor == val){   /* Excluir no inicio */
    aux = inicio;
    free(aux);
    inicio = inicio->prox;
    return 0;
  }

  for(aux=inicio; aux->prox && aux->prox->valor!=val; aux=aux->prox);

  if(!aux->prox){
    printf("No |*| %d |*| nao encontrado...\n", val);
    return 1;
  }
  if(!aux->prox->prox){   /* Excluir no final */
    aux->prox = NULL;
    free(aux->prox);
  } else{   /* Excluir no meio */
      aux->prox = aux->prox->prox;
      free(aux->prox->ant);
      aux->prox->ant = aux;
  }
  return 0;
}

void imprimir(void){
    No* aux = NULL;
    if(!inicio)
      printf("Lista vazia...\n");
    printf("\n\n");
    for(aux=inicio; aux; aux=aux->prox){
        printf(" <--|*| %d |*|--> ",aux->valor);
    }
    printf("\n\n");
}
