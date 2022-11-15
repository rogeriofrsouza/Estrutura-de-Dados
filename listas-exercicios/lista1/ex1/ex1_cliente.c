/*
	Arquivo fonte cliente do exercício 1
*/
#include <stdio.h>
#include <string.h>
#include "ex1.h"

int main()
{
  TCidade cidade;
  TLista lista;
  float num;

  /* inicializa os descritores da lista */
  InicializaLista(&lista);

  while (1)
  {
    printf("\nNome da cidade: ");
    scanf(" %30[^\n]", cidade.nome);  // fgets(cidade.nome, 30, stdin)

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
    
    /* inclui novo nó na lista */
    IncluiItem(&lista, cidade);
  }

  /* checando se lista vazia */
  if (lista.inicio == NULL)
    return 1;

  /* imprimindo a lista */
  ImprimeLista(&lista, "Conteúdo da lista:", "inicio");
  ImprimeLista(&lista, "Conteúdo da lista:", "final");

  while (1)
  {
    printf("\n\nInforme um IDH:\n");
    scanf("%f", &num);

    if (num < 0)
      break;

    if (ExcluiItem(&lista, num) == 0)
      printf("\nNão foi encontrada cidade");
    else
    {
      /* checando se lista vazia */
      if (lista.inicio == NULL)
      {
        printf("\nLista vazia");
        return 1;
      }

      /* imprimindo a nova lista */
      ImprimeLista(&lista, "Novo conteúdo da lista:", "inicio");
      ImprimeLista(&lista, "Novo conteúdo da lista:", "final");
    }
  }

  return 0;
}
