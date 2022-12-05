/*
  Exercício 5
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
void EliminaNos(TNo *);

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

  /* eliminando todos os nós da árvore */
  printf("\nEliminar todos os nós da árvore?\n[1] SIM\n[0] NÃO\n");
  scanf("%d", &numero);

  if (numero)
  {
    EliminaNos(raiz);
    printf("\nÁrvore vazia\n");
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

void EliminaNos(TNo *r)
{
  if (r != NULL)
  {
    /* pos-order */
    EliminaNos(r->esq);
    EliminaNos(r->dir);

    free(r);
  }
}
