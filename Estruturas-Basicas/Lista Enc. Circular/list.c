#include <stdlib.h>
#include <stdio.h>

struct no{
  int valor;
  struct no* prox;
}; typedef struct no No;

No* inicio = NULL;

int inserir(int val){
  No* aux = NULL;
  No* ant = NULL;

  /* Aloca e inicializa o novo no */
  No* novo = (No*) malloc(sizeof(No));
  novo->valor = val;
  novo->prox = NULL;

  if(!inicio){  /* Lista vazia */
    inicio = novo;
    novo->prox = inicio;
    return 0;
  }
  if(inicio->valor > val){ /* Inserir no inicio */
    novo->prox = inicio;
    inicio = novo;
    novo->prox->prox = inicio;
    return 0;
  }

  for(aux=inicio, ant=NULL; aux->prox->valor!=inicio->valor && aux->valor<novo->valor; ant=aux, aux=aux->prox);

  if(aux->prox->valor == inicio->valor && aux->valor < novo->valor){   /* Inserir no final */
    aux->prox = novo;
    novo->prox = inicio;
    return 0;
  }
  if(aux->valor == novo->valor){    /* No repetido */
    printf("No repetido...");
    free(novo);
    return 1;
  } else{   /* Inserir no meio */
      ant->prox = novo;
      novo->prox = aux;
      return 0;
  }
  return 0;
}

int excluir(int val){
  No* aux = NULL;
  No* ant = NULL;
  if(!inicio){    /* Lista vazia */
    printf("Lista vazia...\n");
    return 1;
  }
  if(inicio->valor == val){   /* Excluir no inicio */
    No* aux2 = inicio;
    inicio = inicio->prox;
    for(aux=inicio; aux->prox->valor!=aux2->valor; aux=aux->prox);
    aux->prox = inicio;
    free(aux2);
    return 0;
  }

  for(aux=inicio, ant=NULL; aux->prox->valor!=inicio->valor && aux->valor!=val; ant=aux, aux=aux->prox);

  if(aux->prox->valor == inicio->valor && aux->valor != val){   /* No nao encontrado */
    printf("No nao encontrado...\n");
    return 1;
  }
  if(aux->prox->valor == inicio->valor && aux->valor == val){   /* Excluir no final */
    ant->prox = inicio;
    free(aux);
    return 1;
  } else{ /* Excluir no meio */
      ant->prox = aux->prox;
      free(aux);
      return 0;
  }
  return 0;
}

void imprimir(void){
  No* aux = NULL;
  if(!inicio)
    printf("Lista vazia...\n");
  else if(inicio->prox->valor == inicio->valor){   /* Unico elemento */
    printf("\n\n");
    printf(" | %d |*%d|--> ", inicio->valor, inicio->prox->valor);
  } else{   /* Imprime do primeiro ao penultimo elemento */
      printf("\n\n");
    for(aux=inicio; aux->prox->valor!=inicio->valor; aux=aux->prox){
      printf(" | %d |*%d|--> ", aux->valor, aux->prox->valor);
    }
    if(aux->prox->valor == inicio->valor)   /* Imprime o ultumo elemento */
      printf(" | %d |*%d|--> ", aux->valor, aux->prox->valor);
  }
  printf("\n\n");
}
