/* 
  Algoritmo de busca em vetor ORDENADO
  Busca BINÁRIA
  Implementação recursiva
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int BuscaBinRec(int, int *, int);
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

  res = BuscaBinRec(MAX, vet, num);

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

int BuscaBinRec(int n, int *vet, int elem)
{
  /* testa condição de contorno: parte com tamanho zero */
  if (n <= 0)
    return -1;

  /* deve buscar o elemento entre os índices 0 e n-1 */
  int meio = (n - 1) / 2;

  if (elem < vet[meio])
    return BuscaBinRec(meio, vet, elem);
  else if (elem > vet[meio])
  {
    int r = BuscaBinRec(n-1-meio, &vet[meio+1], elem);

    if (r < 0) 
      return -1;
    else 
      return meio + 1 + r;
  }
  else
    return meio;  /* elemento encontrado */
}
