/* 
  Lógica básica para montar o Max-Heap: considerar que os valores informados foram armazenados no vetor na ordem indicada no enunciado. 
  Executar então os passos a seguir para cada elemento do vetor que contém a árvore binária completa, começando do primeiro: 
*/
#include <stdio.h>

#define MAX 50

typedef int TNo;

int main(void)
{
  TNo vet[MAX];
  int i, final = 0, m, f, aux;

  printf("Informe os valores do vetor:\n");

  /* seja V o vetor que contém a árvore completa (com elementos de 1 a N) */
  for (i = 0; i < MAX; i++)
  {
    scanf("%d\n", vet[i]);
    final++;
  }

  /* faça M ser o índice do elemento a ser processado (considere sempre os índices começando em 1) */
  m = 0;

  /* faça F = M + 1 */
  f = m + 1;

  while (f > 1 && vet[f / 2] < vet[f])
  {
    /* trocando os elementos V[F / 2] e V[F] de lugar */
    aux = vet[f / 2];
    vet[f / 2] = vet[f];
    vet[f] = aux;

    /* cortando o valor de f pela metade e incrementando m*/
    f /= 2;
    m++;
  }

  return 0;
}