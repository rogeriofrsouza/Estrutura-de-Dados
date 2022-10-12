/*
	Arquivo fonte cliente do exercício 2
*/
#include <stdio.h>
#include <string.h>
#include "ex2.h"

int main()
{
  Cidade cidade;
  Lista lista;
  float num;

  /* inicializando os descritores */
  InicializaLista(&lista);

  while (1)
  {
    printf("\nNome da cidade: ");
    scanf(" %30[^\n]", cidade.nome);

    if (strcmp(cidade.nome, "FIM") == 0)
      break;

    printf("População: ");
    scanf("%d", &cidade.pop);

    printf("Área territorial: ");
    scanf("%f", &cidade.area);

    printf("PIB: ");
    scanf("%f", &cidade.pib);

    printf("IDH: ");
    scanf("%f", &cidade.idh);
    
    /* incluindo item na lista */
    IncluiItem(&lista, cidade);
  }

  /* checando se lista vazia */
  if (lista.inicio == lista.final)
    return 1;

  /* imprimindo a lista */
  ImprimeLista(&lista, "Conteúdo da lista:");

  while (1)
  {
    printf("\n\nInforme um IDH:\n");
    scanf("%f", &num);

    if (num < 0)
      break;

    if (ExcluiItem(&lista, num))
    {
      /* checando se lista vazia */
      if (lista.inicio == lista.final)
      {
        printf("\nLista vazia");
        return 1;
      }

      /* imprimindo a nova lista */
      ImprimeLista(&lista, "Novo conteúdo da lista:");
    }
    else
    {
      /* não encontrou */
      printf("\nNão foi encontrada cidade");
      continue;
    }
  }

  return 0;
}
