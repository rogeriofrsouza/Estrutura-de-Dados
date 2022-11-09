/*
  Exercício 4
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  char info;
  struct no *prox;
} No;

typedef struct pilha
{
  No *topo;
} Pilha;

void Empilhar(Pilha *, char);
char Desempilhar(Pilha *);
int VerificarDelimitadores(char, char);

int main()
{
  Pilha pilha;
  char d, expr[21];
  int i;

  /* inicializando a pilha */
  pilha.topo = NULL;

  printf("Informe uma expressão matemática:\n");
  scanf("%s", expr);

  /* verificando delimitadores */
  for (i = 0; expr[i] != '\0'; i++)
  {
    if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
    {
      Empilhar(&pilha, expr[i]);
    }
    else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
    {
      d = Desempilhar(&pilha);

      if (VerificarDelimitadores(d, expr[i]) == 0)
      {
        printf("\nErro: delimitadores não compatíveis\n\n");
        exit(1);
      }
    }
  }

  /* verificando pilha */
  if (pilha.topo == NULL)
    printf("\nA expressão é válida e está balanceada\n\n");
  else
  {
    printf("\nA expressão não é válida\n\n");
    return 1;
  }

  return 0;
}

void Empilhar(Pilha *pilha, char d)
{
  No *aux;

  /* alocando um nó dinamicamente */
  aux = (No *) malloc(sizeof(No));

  /* inicializando os campos */
  aux->info = d;

  /* cuidando do empilhamento */
  aux->prox = pilha->topo;
  pilha->topo = aux;
}

char Desempilhar(Pilha *pilha)
{
  No *aux;
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

int VerificarDelimitadores(char d1, char d2)
{
  switch (d1)
  {
    case '(': 
      if (d2 == ')') return 1;
      break;
    case '[':
      if (d2 == ']') return 1;
      break;
    case '{':
      if (d2 == '}') return 1;
      break;
  }

  return 0;
}
