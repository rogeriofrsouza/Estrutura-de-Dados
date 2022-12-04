/*
  Segundo as páginas 187 e 188 da Introdução a Estruturas de Dados, de Waldemar Celes e outros, 
  "Para descrever árvores binárias, podemos usar a seguinte notação textual: 
  a árvore vazia é representada por < >, e árvores não-vazias, por <raiz sae sad>. 
  Com essa notação, a árvore da Figura 13.4 é representada por: <a<b< ><d< >< >>><c<e< >< >><f< >< >>>>

  Pela definição, uma subárvore de uma árvore binária é sempre especificada como sendo a sae ou a sad de uma árvore maior, e qualquer das duas subárvores pode ser vazia. Assim, as duas subárvores da Figura 13.5 são distintas. Isso também pode ser visto pelas representações textuais das duas árvores que, em pre-order, são, respectivamente: <a<b< >< >>< >> e <a< ><b< >< >>>."

  Faça um programa que recebe uma sequência de inteiros e monta a árvore binária ordenada correspondente. 
  Em seguida, exibir a descrição da árvore na notação textual indicada anteriormente, porém em sentido infixo. 
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
