/* 
  Algoritmo de busca em vetor ORDENADO
  Busca LINEAR
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int Busca(int, int *, int);
int ComparaInt(const void *, const void *);

int main(void)
{
  int i, res, num, vet[MAX];

  for (i = 0; i < MAX; i++)
    vet[i] = rand() % 100 + 1;
  
  /* ordenando vetor */
  qsort(vet, MAX, sizeof(int), ComparaInt);

  printf("Informe um número:\n");
  scanf("%d", &num);

  res = Busca(MAX, vet, num);

  if (res >= 0)
    printf("\nEncontrado elemento %d, índice: %d", num, res);
  else
    printf("\nElemento não encontrado");

  return 0;
}

int ComparaInt(const void * a, const void * b)
{
  return (*(int *) a - *(int *) b);
}

int Busca(int n, int *vet, int elem)
{
  int i;

  for (i = 0; i < n; i++)
  {
    if (elem == vet[i])
      return i;  /* elemento encontrado */
    else if (elem < vet[i])
      break;  /* interrompe busca */  
  }

  /* percorreu todo o vetor e não encontrou elemento */
  return -1;
}
