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

  if(!inicio){ /* Lista vazia */
    inicio = novo;
    return 0;
  }
  if(inicio->valor > novo->valor){ /* Inserir no inicio */
    novo->prox = inicio;
    inicio = novo;
    return 0;
  }
  for(aux=inicio, ant=NULL; aux && aux->valor<novo->valor; ant=aux, aux=aux->prox);
  if(aux == NULL){ /* Inserir no final */
    aux = novo;
    ant->prox = novo;
    return 0;
  }
  if(aux->valor == novo->valor){ /* No repetido */
    printf("No repetido...\n");
    free(novo);
    return 1;
  } else{ /* Inserir no meio */
      novo->prox = aux;
      ant->prox = novo;
      return 0;
  }
}

int excluir(int val){
  No* aux = NULL;
  No* ant = NULL;
  if(!inicio) /* Lista vazia */
    return 1;
  if(inicio->valor == val){ /* Excluir no inicio */
    aux = inicio;
    free(aux);
    inicio = inicio->prox;
    return 0;
  }
  for(aux=inicio, ant=NULL; aux && aux->valor!=val; ant=aux, aux=aux->prox);
  if(!aux){
    printf("\nNo |%d|*| nao encontrado...\n", val);
    return 1;
  } else{   /* Excluir no meio ou no final */
    ant->prox = aux->prox;
    free(aux);
    return 0;
  }
}

void imprimir(void){
  No* aux = NULL;
  if(!inicio)
    printf("Lista Vazia...\n");
  printf("\n\n");;
  for(aux=inicio; aux; aux=aux->prox){
    printf("|%d|*|--> ", aux->valor);
  }
  printf("\n\n");
}
