/* 
  Algoritmo de busca em vetor ORDENADO
  Busca BINÁRIA
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int BuscaBin(int, int *, int);
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

  res = BuscaBin(MAX, vet, num);

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

int BuscaBin(int n, int *vet, int elem)
{
  /* no início consideramos todo o vetor */
  int ini = 0, fim = n-1, meio;

  /* enquanto a parte restante for maior que zero */
  while (ini <= fim)
  {
    meio = (ini + fim) / 2;

    if (elem < vet[meio])
      fim = meio - 1;  /* ajusta posição final */
    else if (elem > vet[meio])
      ini = meio + 1;  /* ajusta posição inicial */
    else
      return meio;  /* elemento encontrado */
  }

  /* não encontrou: restou parte de tamanho zero */
  return -1;
}
