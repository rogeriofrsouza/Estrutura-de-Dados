/* 
  Exercício 7
*/
#include <stdio.h>

#define MAX 5

typedef struct regDados 
{ 
  int info;
} TDados;

TDados * Pesquisar(TDados *, int);

int main() 
{
  TDados vet[MAX], *x;
  int cont = 0, b;
  
  /* inicializando o vetor */
  vet[0].info = 2;
  vet[1].info = 7;
  vet[2].info = 3;
  vet[3].info = 8;
  vet[4].info = 12;

  /* pesquisando se o valor está na lista */
  x = Pesquisar(vet, 8);

  while (cont < MAX && &vet[cont] != x) 
    cont++;

  b = cont * sizeof(TDados);
  printf("Bytes entre o início do array na memória e o elemento encontrado: %d", b);

  return 0;
}

TDados * Pesquisar(TDados *v, int n)
{
  int i = 0;

  while (i < MAX && v[i].info != n)
    i++;

  if (i == MAX)
    return NULL;

  return &v[i];
}
