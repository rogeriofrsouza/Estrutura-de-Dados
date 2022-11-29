/* 
  Programa de construção e impressão de uma árvore binária completa: Max-Heap.
  Lógica básica para montar o Max-Heap: considerar que os valores informados foram armazenados no vetor na ordem indicada no enunciado. 
  Executar então os passos para cada elemento do vetor.
*/
#include <stdio.h>
#include <math.h>

#define MAX 50

typedef int TNo;

int main(void)
{
  TNo vet[MAX];
  int final, m, f, aux, qtde, nivel, idx;

  printf("Informe os valores:\n");

  for (final = 1; final < MAX; final++)
  {
    scanf("%d", &vet[final]);

    if (vet[final] < 1)
      break;
  }

  /* índice do elemento a ser processado (considere sempre os índices começando em 1) */
  m = 1;

  while (1)
  {
    f = m + 1;

    if (f == final)
      break;

    while (f > 1 && vet[f/2] < vet[f])  /* f = nó, f/2 = ancestral */
    {
      /* trocando os elementos vet[f/2] e vet[f] de lugar */
      aux = vet[f/2];
      vet[f/2] = vet[f];
      vet[f] = aux;

      /* cortando o valor de f pela metade */
      f /= 2;
    }
    
    m++;
  }

  /* imprimindo Max-Heap */
  printf("\n\n");

  qtde = 0;
  nivel = 0;
  idx = 1;

  while (1)
  {
    qtde += (int) pow(2, (double) nivel);

    while (idx <= qtde && idx < final)
    {
      printf("%d ", vet[idx]);
      idx++;
    }
    
    if (idx == final)
      break;

    printf("\n");
    nivel++;
  };
  
  return 0;
}
