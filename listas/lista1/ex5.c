/*
  Exercício 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct regItem
{
  char info[31];
  struct regItem *ant, *prox;
} TItem;

typedef struct regLista
{
  TItem *inicio, *final;
} TLista;

enum operacoes
{
  uniao, intersec, dif1, dif2
};

void OperaConjuntos(TLista *, char *, int op);

int main()
{
  TLista conj[2];
  TItem *aux;

  int i;
  char str[31];

  for (i = 0; i < 2; i++)
  {
    /* inicializando a lista */
    conj[i].inicio = NULL;
    conj[i].final = NULL;
    
    printf("\nConjunto %d:\n", i+1);

    while (1)
    {
      scanf("%s", str);

      if (str[0] == '*')
        break;

      /* alocando um novo nó dinamicamente */
      aux = (TItem *) malloc(sizeof(TItem));

      /* inicializando os campos do nó */
      strcpy(aux->info, str);
      aux->ant = NULL;
      aux->prox = NULL;
      
      /* cuidando do encadeamento */
      if (conj[i].inicio == NULL)
        conj[i].inicio = aux;
      else
      {
        conj[i].final->prox = aux;
        aux->ant = conj[i].final;
      }
      
      /* atualizando descritor */
      conj[i].final = aux;
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
  OperaConjuntos(conj, "União dos Conjuntos:", uniao);

  /* intersecção dos conjuntos */
  OperaConjuntos(conj, "Intersecção dos Conjuntos:", intersec);

  /* diferença Conjunto1 – Conjunto2: */
  OperaConjuntos(conj, "Diferença Conjunto 1 - Conjunto 2:", dif1);

  /* diferença Conjunto2 – Conjunto1: */
  OperaConjuntos(conj, "Diferença Conjunto 2 - Conjunto 1:", dif2);

  return 0;
}

void OperaConjuntos(TLista *conj, char *cabec, int op)
{
  TItem *aux, *p;
  int cont;

  printf("\n%s\n", cabec);
  printf("{ ");

  switch (op)
  {
    /* união */
    case 0:
      conj[0].final->prox = conj[1].inicio;

      for (aux = conj[0].inicio; aux != NULL; aux = aux->prox)
        printf("%s ", aux->info);

      conj[0].final->prox = NULL;
      break;
    
    /* intersecção */
    case 1:
      for (aux = conj[0].inicio; aux != NULL; aux = aux->prox)
      {
        cont = 0;

        for (p = conj[1].inicio; p != NULL; p = p->prox)
          strcmp(aux->info, p->info) == 0 ? cont++ : 0;

        if (cont)
          printf("%s ", aux->info);
      }
      break;

    /* diferença conj 1 - conj 2 */
    case 2:
      for (aux = conj[0].inicio; aux != NULL; aux = aux->prox)
      {
        cont = 0;

        for (p = conj[1].inicio; p != NULL; p = p->prox)
          strcmp(aux->info, p->info) == 0 ? cont++ : 0;
        
        if (cont == 0)
          printf("%s ", aux->info);
      }
      break;
    
    /* diferença conj 2 - conj 1 */
    case 3:
      for (aux = conj[1].inicio; aux != NULL; aux = aux->prox)
      {
        cont = 0;

        for (p = conj[0].inicio; p != NULL; p = p->prox)
          strcmp(aux->info, p->info) == 0 ? cont++ : 0;

        if (cont == 0)
          printf("%s ", aux->info);
      }
      break;
  }

  printf("}\n");
}
