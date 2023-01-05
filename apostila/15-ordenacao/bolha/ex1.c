/* Testa algoritmo de ordenação bolha */

#include <stdio.h>

void bsort(int, int *);

int main(void)
{
  int c, vet[8] = {25, 48, 37, 12, 57, 86, 33, 92};

  bsort(8, vet);

  printf("Vetor ordenado: ");

  for (c = 0; c < 8; c++)
    printf("%d ", vet[c]);

  return 0;
}

/* Ordenação bolha (bubble sort) */
void bsort(int n, int *v)
{
  int i, j, troca, temp;

  for (i = n-1; i >= 1; i--)
  {
    troca = 0;

    for (j = 0; j < i; j++)
    {
      if (v[j] > v[j+1])  /* troca */
      {
        temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;

        troca = 1;
      }
    }

    if (troca == 0)  /* não houve troca */
      return;
  }
}
