// 4) Declare um vetor chamado produtos, com 10 elementos do tipo TProd conforme definido no exercício anterior. Depois escreva as instruções para:

#include <stdio.h>
#include <stdlib.h>

void main() 
{
  typedef struct {int num; 
                  char descr[25]; 
                  double valor; 
                  int qtdes[12];} TProd;
                  
  TProd produtos[10];

  // a) Atribuir o valor 4368 para o membro num do elemento 5 do vetor.
  produtos[5].num = 4368;
  printf("%d\n", produtos[5].num);

  // b) Atribuir o valor 182 para o elemento 7 do membro qtdes do elemento 8 do vetor de produtos.
  produtos[8].qtdes[7] = 182;
  printf("%d\n\n", produtos[8].qtdes[7]);

  // c) Zerar todos os valores do membro qtdes do elemento 3 do vetor de produtos.
  for (int i = 0; i < 12; i++) 
  {
    produtos[3].qtdes[i] = 0;
    printf("[%d] - %d\n", i, produtos[3].qtdes[i]);
  }

  // d) Produzir o valor total das quantidades do produto contido no elemento 4 do vetor de produtos. 
  // Considere que esse valor total é o resultado da multiplicação do membro valor pela soma dos valores contidos no membro qtdes.
  int somaValores = 0, valorTotal;
  produtos[4].valor = 53.78;

  for (int i = 0; i < 12; i++) 
  {
    produtos[4].qtdes[i] = rand() % 100;
    somaValores += produtos[4].qtdes[i];
  }

  valorTotal = produtos[4].valor * somaValores;
  printf("\nSoma valores: %i", somaValores);
  printf("\nValor total: %li", valorTotal);
}
