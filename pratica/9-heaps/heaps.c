/* 
  Programa de construção e impressão de uma árvore binária completa: Max-Heap.
  Lógica básica para montar o Max-Heap: considerar que os valores informados foram armazenados no vetor na ordem indicada no enunciado. 
  Executar então os passos para cada elemento do vetor.
*/
#include <stdio.h>
#include <math.h>

#define MAX 50

typedef int TNo;

void ImprimeHeap(TNo *, int, int, int);

int main(void)
{
  TNo vet[MAX];
  int final, m, f, aux;

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

  printf("\n\nO Max-Heap possui %d elementos:\n", final - 1);
  ImprimeHeap(vet, 1, 0, final);
  
  return 0;
}

void ImprimeHeap(TNo *vet, int i, int nivel, int final)
{
	int c;

	if (i < final)
	{
    /* descendente lado esquerdo */
		ImprimeHeap(vet, i * 2, nivel + 1, final);

		for (c = 0; c < nivel; c++)
			printf("\t");

		printf("%d\n", vet[i]);

    /* descendente lado direito */
		ImprimeHeap(vet, i * 2 + 1, nivel + 1, final);
	}
}
