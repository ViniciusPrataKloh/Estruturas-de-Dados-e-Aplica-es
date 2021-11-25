#include <stdlib.h>
#include <stdio.h>

struct no{
  int valor;
  struct no* prox;
  struct no* ant;
}; typedef struct no No;

No* inicio = NULL;
No* fim = NULL;

int inserir(int val){
  No* aux = NULL;
  /* Aloca e inicializa novo no */
  No* novo = (No*) malloc(sizeof(No));
  novo->valor = val;
  novo->prox = NULL;
  novo->ant = NULL;

  if(!inicio){    /* Lista vazia */
    inicio = novo;
    fim = novo;
    novo->prox = inicio;
    novo->ant = fim;
    return 0;
  }
  if(inicio->valor > novo->valor){  /* Inserir no inicio */
    novo->prox = inicio;
    novo->ant = fim;
    inicio = novo;
    for(aux=inicio; aux->prox->valor!=inicio->valor; aux=aux->prox);
    fim = aux;
    return 0;
  }

  for(aux=inicio; aux->prox->valor!=inicio->valor && aux->valor<novo->valor; aux=aux->prox);

  if(aux->prox->valor == inicio->valor && aux->valor < novo->valor){ /* Inserir no final */
    novo->prox = inicio;
    novo->ant = aux;
    aux->ant->prox = novo;
    fim = novo;
    return 0;
  } else{ /* Inserir no meio */
    aux->ant->prox = novo;
    novo->ant = aux->ant;
    novo->prox = aux;
    aux->ant = novo;
    return 0;
  }
  return 0;
}

void imprimir(void){
    No* aux = NULL;
    if(!inicio) /* Lista vazia */
      printf("Lista vazia...\n");
    if(fim->valor == inicio->valor){ /* Unico elemento */
      printf("\n\n");
      printf(" <--|*%d| %d |*%d|-->  ", fim->valor, inicio->valor, inicio->prox->valor);
    }
    printf("\n\n");
    for(aux=inicio; aux->valor != fim->valor; aux=aux->prox){   /* Imprimir elementos do meio */
      printf(" <--|*%d| %d |*%d|-->  ", aux->ant->valor, aux->valor, aux->prox->valor );
    }
    if(aux->valor == fim->valor){   /* Imprimir ultimo elemento */
      printf(" <--|*%d| %d |*%d|-->  ", aux->ant->valor, aux->valor, aux->prox->valor);
    }
}
