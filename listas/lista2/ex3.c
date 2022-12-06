/*
  Exercício 3
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
void ImprimeArvore(TNo *);

int main (void)
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

  printf("\n");
  ImprimeArvore(raiz);
  printf("\n");

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

void ImprimeArvore(TNo *r)
{
  /* pre-order */
  printf("<");

  if (r == NULL)
  {
    printf(" >");
    return;
  }

  printf("%d", r->valor);

  ImprimeArvore(r->esq);
  ImprimeArvore(r->dir);
  printf(">");
}
