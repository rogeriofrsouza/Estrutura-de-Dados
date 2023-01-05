/* 
  Testa algoritmo de ordenação rápida 
  Utiliza algoritmo genérico da biblioteca padrão
  Tipo float
*/

#include <stdio.h>
#include <stdlib.h>

int ComparaFloat(const void *, const void *);

int main(void)
{
  int c;
  float vet[8] = {25.6, 48.3, 37.7, 12.1, 57.4, 86.6, 33.3, 92.8};

  qsort(vet, 8, sizeof(float), ComparaFloat);

  printf("Vetor ordenado: ");

  for (c = 0; c < 8; c++)
    printf("%.1f  ", vet[c]);

  return 0;
}

int ComparaFloat(const void *p1, const void *p2)
{
  /* dados os ponteiros de float, faz a comparação */
  return (*(float *) p1 - *(float *) p2);
}
