/*
  Exercício 3
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int info;
  struct no *ant, *prox;
} No;

typedef struct lista
{
  No *inicio, *final;
} Lista;

void ImprimeListas(Lista *, char *);

int main()
{
  Lista lista[2];
  No *aux, *p;

  int i, num;

  for (i = 0; i < 2; i++)
  {
    /* inicializando os campos da lista */
    lista[i].inicio = NULL;
    lista[i].final = NULL;

    printf("\nLista %d\n", i+1);
    
    while (1)
    {
      scanf("%d", &num);

      if (num == -999)
        break;
      
      /* alocando um nó da lista dinamicamente */
      aux = (No *) malloc(sizeof(No));

      /* inicializando os campos do nó */
      aux->ant = NULL;
      aux->info = num;
      aux->prox = NULL;

      /* cuidando do encadeamento */
      if (lista[i].inicio == NULL)
        lista[i].inicio = aux;
      else
      {
        lista[i].final->prox = aux;
        aux->ant = lista[i].final;
      }

      /* atualizando descritor */
      lista[i].final = aux;
    }
  }

  /* imprimindo listas */
  ImprimeListas(lista, "Situação inicial:");
  
  /* excluindo elementos */
  for (aux = lista[0].inicio; aux != NULL; aux = aux->prox)
  {
    p = lista[1].inicio;

    while ((p != NULL) && (p->info != aux->info))
      p = p->prox;

    if (p == NULL)
      continue;
        
    /* cuidando do encadeamento */
    if (p == lista[1].inicio)
      lista[1].inicio = p->prox;
    else
      p->ant->prox = p->prox;

    if (p->prox != NULL)
      p->prox->ant = p->ant;
    else
      lista[1].final = p->ant;
    
    /* removendo nó da lista */
    free(p);
  }

  /* imprimindo listas */
  ImprimeListas(lista, "Situação final:");
  printf("\n\n");

  return 0;
}

void ImprimeListas(Lista lista[], char *cabec)
{
  No *aux;
  int i;

  printf("\n\n%s", cabec);

  for (i = 0; i < 2; i++)
  { 
    printf("\nLista %d:", i+1);

    if (lista[i].inicio == NULL)
    {
      printf(" vazia");
      continue;
    }

    for (aux = lista[i].inicio; aux != NULL; aux = aux->prox)
      printf(" %d", aux->info);
  }
}
