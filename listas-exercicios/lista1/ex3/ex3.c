/*
  Exercício 3
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct regItem
{
  int valor;
  struct regItem *ant, *prox;
} TItem;

typedef struct regLista
{
  TItem *inicio, *final;
} TLista;

void IncluiItem(TLista *, int);
void ImprimeListas(TLista *, char *);
void ExcluiItem(TLista *);

int main()
{
  TLista lista[2];

  int i, num;

  for (i = 0; i < 2; i++)
  {
    /* inicializando os campos da lista */
    lista[i].inicio = NULL;
    lista[i].final = NULL;

    printf("\nLista %d\n", i + 1);
    
    while (1)
    {
      scanf("%d", &num);

      if (num == -999)
        break;
      
      IncluiItem(&lista[i], num); 
    }
  }

  /* imprime listas */
  ImprimeListas(lista, "Situação inicial:");
  
  /* exclui elementos da lista */
  ExcluiItem(lista);

  /* imprime listas */
  ImprimeListas(lista, "Situação final:");
  printf("\n\n");

  return 0;
}

void IncluiItem(TLista *lista, int num)
{
  TItem *aux;

  /* alocando um nó da lista dinamicamente */
  aux = (TItem *) malloc(sizeof(TItem));

  /* inicializando os campos do nó */
  aux->valor = num;
  aux->ant = NULL;
  aux->prox = NULL;

  /* cuidando do encadeamento */
  if (lista->inicio == NULL)
    lista->inicio = aux;
  else
  {
    lista->final->prox = aux;
    aux->ant = lista->final;
  }

  /* atualizando descritor */
  lista->final = aux;
}

void ImprimeListas(TLista *lista, char *cabec)
{
  TItem *aux;
  int i;

  printf("\n\n%s", cabec);

  for (i = 0; i < 2; i++)
  { 
    printf("\nLista %d:", i + 1);

    if (lista[i].inicio == NULL)
    {
      printf(" vazia");
      continue;
    }

    for (aux = lista[i].inicio; aux != NULL; aux = aux->prox)
      printf(" %d", aux->valor);
  }
}

void ExcluiItem(TLista *lista)
{
  TItem *aux, *p;

  for (aux = lista[0].inicio; aux != NULL; aux = aux->prox)
  {
    while (1)
    {
      p = lista[1].inicio;
      
      while ((p != NULL) && (p->valor != aux->valor))
        p = p->prox;

      /* saindo do loop */
      if (p == NULL)
        break;
          
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
  }
}
