/* 
  Algoritmo de busca em vetor ORDENADO
  Busca BINÁRIA
  Utiliza algoritmo genérico da biblioteca padrão
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int ComparaInt(const void *, const void *);

int main(void)
{
  int i, *aux, num, vet[MAX];

  for (i = 0; i < MAX; i++)
    vet[i] = rand() % 100 + 1;
  
  /* ordenando vetor */
  qsort(vet, MAX, sizeof(int), ComparaInt);

  printf("Informe um número:\n");
  scanf("%d", &num);

  aux = (int *) bsearch(&num, vet, MAX, sizeof(int), ComparaInt);

  if (aux == NULL)
    printf("\nElemento não encontrado");
  else
    printf("\nEncontrado elemento %d, índice: %ld", num, aux-vet);  /* aritmética de ponteiros */

  return 0;
}

int ComparaInt(const void * a, const void * b)
{
  return (*(int *) a - *(int *) b);
}
