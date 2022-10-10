/*
  Organize o programa em arquivo cliente, de interface e de implementação.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cidade
{
  char nome[31];
  int pop;
  float area, pib, idh;
} Cidade;

typedef struct no
{
  Cidade *info;
  struct no *prox, *ant;
} No;

typedef struct lista
{
  No *inicio, *fim;
} Lista;

void InicializaLista(Lista *);
void ImprimeLista(No *);
char * ExcluiItem(Lista);

int main()
{
  No *aux, *ant;
  Lista lista;

  float num;
  char *cid;

  /* inicializando os descritores */
  InicializaLista(&lista);

  while (1)
  {
    /* alocando um nó da lista dinamicamente */
    aux = (No *) malloc(sizeof(No));

    /* inicializando os campos do nó */
    aux->ant = NULL;
    aux->prox = NULL;

    /* alocando a estrutura Cidade dinamicamente */
    aux->info = (Cidade *) malloc(sizeof(Cidade));

    printf("Nome da cidade:\n");
    scanf(" %30[^\n]", aux->info->nome);

    if (*aux->info->nome = "FIM")
      break;

    printf("\nPopulação:\n");
    scanf("%d", aux->info->pop);

    printf("\nÁrea territorial:\n");
    scanf("%f", aux->info->pop);

    printf("\nPIB:\n");
    scanf("%f", aux->info->pib);

    printf("\nIDH:\n");
    scanf("%f", aux->info->idh);

    /* cuidando do encadeamento */
    if (lista.inicio == NULL)
      lista.inicio = aux;
    else
    {
      aux->ant = ant;
      ant->prox = aux;
    }

    /* atualizando descritores */
    ant = aux;
    lista.fim = aux;
  }

  /* checando se lista vazia */
  if (lista.inicio == NULL)
  {
    printf("\nLista vazia");
    exit(1);
  }

  /* imprimindo a lista do início */
  ImprimeLista(lista.inicio);

  /* imprimindo a lista do final */
  ImprimeLista(lista.fim);


  while (1)
  {
    printf("\nInforme um IDH:\n");
    scanf("%f", &num);

    if (num < 0)
      break;

    cid = NULL;
    for (aux = lista.inicio; aux != NULL; aux = aux->prox)
    {
      /* checando se IDH é maior ou igual */
      if (aux->info->idh >= num)
      {
        /* excluindo item da lista */
        cid = ExcluiItem(lista);
        printf("\nRemovendo a cidade %s da lista\n", cid);

        /* imprimindo a lista do início */
        ImprimeLista(lista.inicio);

        /* imprimindo a lista do final */
        ImprimeLista(lista.fim);
      }
    }

    /* emitindo mensagem caso não encontre */
    if (cid == NULL)
      printf("\n\nNão foi encontrada cidade com IDH superior ou igual a %f", num);
  }

  return 0;
}

void InicializaLista(Lista *lista)
{
  lista->inicio = NULL;
  lista->fim = NULL;
}

void ImprimeLista(No *aux)
{
  while (aux != NULL)
  {
    printf("\n\nCidade: %s", aux->info->nome);
    printf("\nPopulação: %d", aux->info->pop);
    printf("\nÁrea: %f", aux->info->area);
    printf("\nPIB: %f", aux->info->pib);
    printf("\nIDH: %f", aux->info->idh);

    if (aux->ant == NULL)
      aux = aux->prox;
    else
      aux = aux->ant;
  }
}

char * ExcluiItem(Lista lista)
{
  No *aux;
  char *c;

  /* excluindo do início da lista */
  if (aux == lista.inicio)
  {
    aux->prox->ant = NULL;
    lista.inicio = aux->prox;
  }

  /* excluindo do meio da lista */
  aux->ant->prox = aux->prox;
  aux->prox->ant = aux->ant;

  /* excluindo do fim da lista */
  if (aux == lista.fim)
  {
    aux->ant->prox = NULL;
    lista.fim = aux->ant;
  }

  c = aux->info->nome;
  free(aux);

  return c;
}
