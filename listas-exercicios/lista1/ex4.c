/*
  Exercício 4
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct regItem
{
  char info;
  struct regItem *prox;
} TItem;

typedef struct regPilha
{
  TItem *topo;
} TPilha;

void EmpilhaItem(TPilha *, char);
char DesempilhaItem(TPilha *);
int VerificaDelimitadores(char, char);

int main()
{
  TPilha pilha;
  char expr[21], d;
  int i;

  /* inicializando a pilha */
  pilha.topo = NULL;

  printf("Informe uma expressão matemática:\n");
  fgets(expr, 21, stdin);

  /* verificando delimitadores */
  for (i = 0; expr[i] != '\0'; i++)
  {
    if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
    {
      EmpilhaItem(&pilha, expr[i]);
    }
    else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
    {
      d = DesempilhaItem(&pilha);

      if (VerificaDelimitadores(d, expr[i]) == 0)
      {
        printf("\nDelimitadores não compatíveis\n\n");
        exit(1);
      }
    }
  }

  /* verificando pilha */
  if (pilha.topo == NULL)
    printf("\nA expressão é válida e está balanceada\n\n");
  else
    printf("\nA expressão não é válida\n\n");

  return 0;
}

void EmpilhaItem(TPilha *pilha, char d)
{
  TItem *aux;

  /* alocando um nó dinamicamente */
  aux = (TItem *) malloc(sizeof(TItem));

  /* inicializando os campos */
  aux->info = d;

  /* cuidando do empilhamento */
  aux->prox = pilha->topo;
  pilha->topo = aux;
}

char DesempilhaItem(TPilha *pilha)
{
  TItem *aux;
  char d;

  aux = pilha->topo;

  /* verificando pilha vazia */
  if (aux == NULL)
    return '\0';

  d = aux->info;
  pilha->topo = aux->prox;

  free(aux);

  return d;
}

int VerificaDelimitadores(char d1, char d2)
{
  char delimit[6] = {'(', ')', '[', ']', '{', '}'};
  int i;

  for (i = 0; i < 6; i += 2)
  {
    if ((d1 == delimit[i]) && (d2 == delimit[i + 1]))
      return 1;
  }

  return 0;
}
