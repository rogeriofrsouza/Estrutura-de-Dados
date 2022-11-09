/*
	Arquivo fonte da IMPLEMENTACAO do TDA de lista linear por CONTIGUIDADE,
	com as definições de tipo de dados e subrotinas.
*/
#include <stdio.h>
#include <string.h>
#include "ex2.h"

void InicializaLista(Lista *lista)
{
  lista->inicio = 0;
  lista->final = 0;
}

void IncluiItem(Lista *lista, Cidade cidade)
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
  lista->final += 1;
}

void ImprimeLista(Lista *lista, char *cabec)
{
  int i;

  /* imprimindo do início */
  printf("\n\n%s [início]\n", cabec);

  for (i = lista->inicio; i < lista->final; i++)
    ImprimeCidade(lista->vet[i]);

  /* imprimindo do final */
  printf("\n\n%s [final]\n", cabec);

  for (i = lista->final-1; i >= lista->inicio; i--)
    ImprimeCidade(lista->vet[i]);
}

void ImprimeCidade(Cidade cidade)
{
  printf("\nCidade: %s", cidade.nome);
  printf("\nPopulação: %d", cidade.pop);
  printf("\nÁrea: %.2f", cidade.area);
  printf("\nPIB: %.2f", cidade.pib);
  printf("\nIDH: %.2f\n", cidade.idh);
}

int ExcluiItem(Lista *lista, float num)
{
  int cont, idx;

  cont = 0;
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
