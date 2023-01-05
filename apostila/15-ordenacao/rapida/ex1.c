/* Testa algoritmo de ordenação rápida */

#include <stdio.h>

void Rapida(int, int *);

int main(void)
{
  int c, vet[8] = {25, 48, 37, 12, 57, 86, 33, 92};

  Rapida(8, vet);

  printf("Vetor ordenado: ");

  for (c = 0; c < 8; c++)
    printf("%d ", vet[c]);

  return 0;
}

void Rapida(int n, int *v)
{
  if (n <= 1)
    return;
  
  int x = v[0];  /* elemento pivô */
  int a = 1, b = n-1, temp;

  do
  {
    while (a < n && v[a] <= x) a++;
    while (v[b] > x) b--;

    if (a < b)  /* faz troca */
    {
      temp = v[a];
      v[a] = v[b];
      v[b] = temp;

      a++; b--;
    }
  } while (a <= b);

  /* trocando pivô */
  v[0] = v[b];
  v[b] = x;

  /* ordenando sub-vetores restantes */
  Rapida(b, v);
  Rapida(n-a, &v[a]);
}
