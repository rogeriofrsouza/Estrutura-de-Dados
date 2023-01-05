/* 
  Testa algoritmo de ordenação bolha 
  Implementação recursiva
*/

#include <stdio.h>

void BolhaRec(int, int *);

int main(void)
{
  int c, vet[8] = {25, 48, 37, 12, 57, 86, 33, 92};

  BolhaRec(8, vet);

  printf("Vetor ordenado: ");

  for (c = 0; c < 8; c++)
    printf("%d ", vet[c]);

  return 0;
}

/* Ordenação bolha (bubble sort) */
void BolhaRec(int n, int *v)
{
  int i, troca, temp;

  troca = 0;

  for (i = 0; i < n-1; i++)
  {
    if (v[i] > v[i+1])  /* troca */
    {
      temp = v[i];
      v[i] = v[i+1];
      v[i+1] = temp;

      troca = 1;
    }
  }

  if (troca != 0)  /* houve troca */
    BolhaRec(n-1, v);
}
