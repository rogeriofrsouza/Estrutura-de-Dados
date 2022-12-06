/*
	Arquivo fonte da IMPLEMENTAÇÃO do TDA de lista linear por CONTIGUIDADE,
	com as definições de tipo de dados e subrotinas.
*/
#include <stdio.h>
#include <string.h>
#include "ex2.h"

void InicializaLista(TLista *lista)
{
  lista->inicio = 0;
  lista->final = 0;
}

void IncluiItem(TLista *lista, TCidade cidade)
{
  if (lista->final == MAXIMO)
    return;

  /* preenchendo os valores de cidade */
  strcpy(lista->vet[lista->final].nome, cidade.nome);
  lista->vet[lista->final].pop = cidade.pop;
  lista->vet[lista->final].area = cidade.area;
  lista->vet[lista->final].pib = cidade.pib;
  lista->vet[lista->final].idh = cidade.idh;

  /* atualizando descritor */
  lista->final++;
}

void ImprimeLista(TLista *lista, char *cabec, char *op)
{
  int i, aux;

  printf("\n\n%s [%s]\n", cabec, op);

  if (strcmp(op, "inicio") == 0)
  {
    i = lista->inicio;
    aux = lista->final;
  }
  else
  {
    i = lista->final - 1;
    aux = lista->inicio - 1;
  } 

  while (i != aux)
  {
    printf("\nCidade: %s", lista->vet[i].nome);
    printf("\nPopulação: %d", lista->vet[i].pop);
    printf("\nÁrea: %.2f", lista->vet[i].area);
    printf("\nPIB: %.2f", lista->vet[i].pib);
    printf("\nIDH: %.2f\n", lista->vet[i].idh);

    if (strcmp(op, "inicio") == 0)
      i++;
    else
      i--;
  }
}

int ExcluiItem(TLista *lista, float num)
{
  int cont = 0, idx;

  while (1)
  {
    idx = lista->inicio;

    /* percorrendo lista */
    while ((idx < lista->final) && (lista->vet[idx].idh < num))
      idx++;

    if (idx == lista->final)
      break;
    
    /* trazendo os elementos posteriores ao excluído */
    while (idx < lista->final)
    {
      lista->vet[idx] = lista->vet[idx+1];
      idx++;
    }
    
    /* atualizando descritores */
    lista->final--;
    cont++;
  }

  return cont;
}
