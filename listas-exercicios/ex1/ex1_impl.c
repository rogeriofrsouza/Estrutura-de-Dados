/*
	Arquivo fonte da IMPLEMENTACAO do TDA de lista linear por ENCADEAMENTO,
	com as definicoes de tipo de dados e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex1.h"

void InicializaLista(Lista *lista)
{
  lista->inicio = NULL;
  lista->final = NULL;
}

void IncluiItem(Lista *lista, Cidade cidade)
{
  No *aux;

  /* alocando um nó da lista dinamicamente */
  aux = (No *) malloc(sizeof(No));

  /* inicializando os campos do nó */
  aux->ant = NULL;
  aux->prox = NULL;

  /* alocando a estrutura Cidade dinamicamente */
  aux->info = (Cidade *) malloc(sizeof(Cidade));

  /* preenchendo os valores de cidade */
  strcpy(aux->info->nome, cidade.nome);
  aux->info->pop = cidade.pop;
  aux->info->area = cidade.area;
  aux->info->pib = cidade.pib;
  aux->info->idh = cidade.idh;

  /* cuidando do encadeamento */
  if (lista->inicio == NULL)
    lista->inicio = aux;
  else
  {
    aux->ant = lista->final;
    lista->final->prox = aux;
  }

  /* atualizando descritor */
  lista->final = aux;
}

void ImprimeLista(Lista *lista, char *cabec)
{
  No *aux;

  /* imprimindo do início */
  printf("\n\n%s [início]\n", cabec);

  for (aux = lista->inicio; aux != NULL; aux = aux->prox)
  {
    printf("\nCidade: %s", aux->info->nome);
    printf("\nPopulação: %d", aux->info->pop);
    printf("\nÁrea: %.2f", aux->info->area);
    printf("\nPIB: %.2f", aux->info->pib);
    printf("\nIDH: %.2f\n", aux->info->idh);
  }

  /* imprimindo do final */
  printf("\n\n%s [final]\n", cabec);

  for (aux = lista->final; aux != NULL; aux = aux->ant)
  {
    printf("\nCidade: %s", aux->info->nome);
    printf("\nPopulação: %d", aux->info->pop);
    printf("\nÁrea: %.2f", aux->info->area);
    printf("\nPIB: %.2f", aux->info->pib);
    printf("\nIDH: %.2f\n", aux->info->idh);
  }
}

int ExcluiItem(Lista *lista, float num)
{
  No *aux;
  int cont;

  cont = 0;
  while (1)
  {
    aux = lista->inicio;

    /* percorrendo lista */
    while ((aux != NULL) && (aux->info->idh < num))
      aux = aux->prox;

    if (aux == NULL)
      break;
    
    /* cuidando do encadeamento */
    if (aux == lista->inicio)
      lista->inicio = aux->prox;
    else
      aux->ant->prox = aux->prox;
    
    if (aux->prox != NULL)
      aux->prox->ant = aux->ant;
    else
      lista->final = aux->ant;
    
    cont++;
    free(aux);
  }

  return cont;
}
