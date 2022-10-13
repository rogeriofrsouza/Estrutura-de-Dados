/*
  Exercício 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
  char info[31];
  struct no *ant, *prox;
} No;

typedef struct lista
{
  No *inicio, *final;
  int qtde;
} Lista;

int main()
{
  Lista conj[2];
  No *aux, *p;

  int i, cont;
  char str[31];

  for (i = 0; i < 2; i++)
  {
    /* inicializando a lista */
    conj[i].inicio = NULL;
    conj[i].final = NULL;
    conj[i].qtde = 0;
    
    printf("\nConjunto %d:\n", i+1);

    while (1)
    {
      scanf("%s", str);

      if (str[0] == '*')
        break;

      /* alocando um novo nó dinamicamente */
      aux = (No *) malloc(sizeof(No));

      /* inicializando os campos do nó */
      aux->ant = NULL;
      aux->prox = NULL;
      strcpy(aux->info, str);
      
      /* cuidando do encadeamento */
      if (conj[i].inicio == NULL)
        conj[i].inicio = aux;
      else
      {
        conj[i].final->prox = aux;
        aux->ant = conj[i].final;
      }
      
      /* atualizando descritores */
      conj[i].final = aux;
      conj[i].qtde++;
    }

    /* checando se conjunto vazio */
    if (conj[i].inicio == NULL)
      printf("\nConjunto %d vazio", i+1);
  }

  /* imprimindo conjuntos */
  for (i = 0; i < 2; i++)
  {
    printf("\nConjunto %d:\n", i+1);
    printf("{ ");

    for (aux = conj[i].inicio; aux != NULL; aux = aux->prox)
      printf("%s ", aux->info);
    
    printf("}\n");
  }

  /* união dos conjuntos */
  printf("\nUnião dos Conjuntos:\n");
  printf("{ ");

  conj[0].final->prox = conj[1].inicio;

  for (aux = conj[0].inicio; aux != NULL; aux = aux->prox)
    printf("%s ", aux->info);
  
  printf("}\n");
  conj[0].final->prox = NULL;

  /* intersecção dos conjuntos */
  printf("\nIntersecção dos Conjuntos:\n");
  printf("{ ");

  for (aux = conj[0].inicio; aux != NULL; aux = aux->prox)
  {
    cont = 0;

    for (p = conj[1].inicio; p != NULL; p = p->prox)
    {
      if (strcmp(aux->info, p->info) == 0)
        cont++;
    }
    if (cont)
      printf("%s ", aux->info);
  }
  printf("}\n");

  /* diferença Conjunto1 – Conjunto2: */
  printf("\nDiferença Conjunto 1 - Conjunto 2:\n");
  printf("{ ");

  for (aux = conj[0].inicio; aux != NULL; aux = aux->prox)
  {
    cont = 0;

    for (p = conj[1].inicio; p != NULL; p = p->prox)
    {
      if (strcmp(aux->info, p->info) == 0)
        cont++;
    }
    if (cont == 0)
      printf("%s ", aux->info);
  }
  printf("}\n");

  /* diferença Conjunto2 – Conjunto1: */
  printf("\nDiferença Conjunto 2 - Conjunto 1:\n");
  printf("{ ");

  for (aux = conj[1].inicio; aux != NULL; aux = aux->prox)
  {
    cont = 0;

    for (p = conj[0].inicio; p != NULL; p = p->prox)
    {
      if (strcmp(aux->info, p->info) == 0)
        cont++;
    }
    if (cont == 0)
      printf("%s ", aux->info);
  }
  printf("}\n");

  return 0;
}
