/*
	Arquivo fonte da IMPLEMENTAÇÃO do TDA de lista linear por ENCADEAMENTO,
	com as definições de tipo de dados e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex1.h"

void InicializaLista(TLista *lista)
{
  lista->inicio = NULL;
  lista->final = NULL;
}

void IncluiItem(TLista *lista, TCidade cidade)
{
  TNo *aux;

  /* alocando um nó da lista dinamicamente */
  aux = (TNo *) malloc(sizeof(TNo));

  /* inicializando os campos do nó */
  aux->ant = NULL;
  aux->prox = NULL;

  /* alocando a estrutura TCidade dinamicamente */
  aux->info = (TCidade *) malloc(sizeof(TCidade));

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

void ImprimeLista(TLista *lista, char *cabec, char *op)
{
  TNo *aux;

  printf("\n\n%s [%s]\n", cabec, op);

  aux = strcmp(op, "inicio") == 0 ? lista->inicio : lista->final;

  while (aux != NULL)
  {
    printf("\nCidade: %s", aux->info->nome);
    printf("\nPopulação: %d", aux->info->pop);
    printf("\nÁrea: %.2f", aux->info->area);
    printf("\nPIB: %.2f", aux->info->pib);
    printf("\nIDH: %.2f\n", aux->info->idh);

    aux = strcmp(op, "inicio") == 0 ? aux->prox : aux->ant;
  }
}

int ExcluiItem(TLista *lista, float num)
{
  TNo *aux;
  int cont = 0;

  while (1)
  {
    aux = lista->inicio;

    /* percorrendo a lista */
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
