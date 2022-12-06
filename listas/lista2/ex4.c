/*
  Exercício 4
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct regNo
{
  struct regNo *esq;
  int valor;
  struct regNo *dir;
} TNo;

TNo * AchaPai(TNo *, int);
int ContaNos(TNo *);
void ImprimeArvore(TNo *, int);
int ChecaArvores(TNo *, TNo *);

int main(void)
{
  TNo *raiz[2] = {NULL, NULL}, *aux, *pai;
  int i, numero;

  for (i = 0; i < 2; i++)
  {
    printf("\nÁrvore %d\nInforme os valores:\n", i + 1);

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
      pai = AchaPai(raiz[i], numero);

      if (pai == NULL)
        raiz[i] = aux;
      else
      {
        if (numero <= pai->valor)
          pai->esq = aux;
        else
          pai->dir = aux;
      }
    }
  }

  for (i = 0; i < 2; i++)
  {
    printf("\n\nA árvore %d possui %d elemento(s):\n", i + 1, ContaNos(raiz[i]));
    ImprimeArvore(raiz[i], 0);
  }

  /* determinando se árvores são equivalentes */
  if (ChecaArvores(raiz[0], raiz[1]) == ContaNos(raiz[0]))
    printf("\nÁrvores equivalentes\n");
  else
    printf("\nÁrvores NÃO equivalentes\n");

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

int ChecaArvores(TNo *r1, TNo *r2)
{
  if (r1 == NULL || r2 == NULL)
    return 0;
  else
    return (r1->valor == r2->valor) + ChecaArvores(r1->esq, r2->esq) + ChecaArvores(r1->dir, r2->dir);
}
