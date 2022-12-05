/*
  Exercício 2
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct regNo
{
  struct regNo *esq;
  int valor;
  struct regNo* dir;
} TNo;

TNo * AchaPai(TNo *, int);
int ContaNos(TNo *);
void ImprimeArvore(TNo *, int);
int MaiorValor(TNo *);
int MenorValor(TNo *);
int ContaFolhas(TNo *);
int AchaAltura(TNo *);
int Pesquisa(TNo *, int);

int main(void)
{
  TNo *raiz = NULL, *aux, *pai;
  int numero;

  printf("Informe os valores:\n");

  while (1)
  {
    scanf("%d", &numero);

    if (numero < 1)
      break;

		/* alocando um nó dinamicamente e inicializando os campos */
    aux = (TNo *) malloc(sizeof(TNo));

    aux->esq = NULL;
    aux->valor = numero;
    aux->dir = NULL;

		/* fazendo o encadeamento do novo nó */
    pai = AchaPai(raiz, numero);

    if (pai == NULL)
      raiz = aux;
    else
    {
      if (numero <= pai->valor)
        pai->esq = aux;
      else
        pai->dir = aux;
    }
  }

  printf("\n\nA árvore possui %d elementos:\n", ContaNos(raiz));
	ImprimeArvore(raiz, 0);

  printf("\nMaior valor contido na árvore: %d", MaiorValor(raiz));
  printf("\nMenor valor contido na árvore: %d", MenorValor(raiz));
  printf("\nQuantidade de folhas da árvore: %d", ContaFolhas(raiz));
  printf("\nAltura da árvore: %d", AchaAltura(raiz));

  /* pesquisando na árvore um valor informado */
  while (1)
  {
    printf("\nInforme um valor para pesquisar:\n");
    scanf("%d", &numero);

    if (numero < 1)
      break;

    if (Pesquisa(raiz, numero) == 0)
      printf("\nValor NÃO encontrado");
    else
      printf("\nValor %d encontrado", numero);
  }

  return 0;
}

TNo * AchaPai(TNo *r, int n)
{
  if (r == NULL)
    return NULL;
  
  if (n <= r->valor)
  {
    /* n é descendente do lado esquerdo de r */
    if (r->esq == NULL)
      return r;
    else
      return AchaPai(r->esq, n);
  }
  else
  {
    /* n é descendente do lado direito de r */
    if (r->dir == NULL)
      return r;
    else
      return AchaPai(r->dir, n);
  }
}

int ContaNos(TNo *r)
{
  if (r == NULL)
    return 0;
  else
    return 1 + ContaNos(r->esq) + ContaNos(r->dir);
}

void ImprimeArvore(TNo *r, int n)
{
  int c;

  if (r != NULL)
  {
    /* in-order */
    ImprimeArvore(r->esq, n + 1);

    for (c = 0; c < n; c++)
      printf("\t");
    
    printf("%d\n", r->valor);

    ImprimeArvore(r->dir, n + 1);
  }
}

int MaiorValor(TNo *r)
{
  if (r->dir == NULL)
    return r->valor;
  else
    return MaiorValor(r->dir);
}

int MenorValor(TNo *r)
{
  if (r->esq == NULL)
    return r->valor;
  else
    return MenorValor(r->esq);
}

int ContaFolhas(TNo *r)
{
  if (r == NULL)
    return 0;
  else
    return (r->dir == NULL && r->esq == NULL) + ContaFolhas(r->esq) + ContaFolhas(r->dir);
}

int AchaAltura(TNo *r)
{
  if (r == NULL)
    return 0;
  else
    return (r->dir != NULL || r->esq != NULL) + AchaAltura(r->esq) + AchaAltura(r->dir);
}

int Pesquisa(TNo *r, int n)
{
  while (r != NULL && n != r->valor)
  {
    if (n <= r->valor)
    {
      /* descendente do lado esquerdo */
      r = r->esq;
    }
    else
    {
      /* descendente do lado direito */
      r = r->dir;
    }
  }

  return r != NULL;
}
