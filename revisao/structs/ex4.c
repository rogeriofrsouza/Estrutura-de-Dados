/* 
  4) Declare um vetor chamado produtos, com 10 elementos do tipo TProd conforme definido no exercício anterior. 
  Depois escreva as instruções para:
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct prod {
  int num; 
  char descr[25]; 
  double valor; 
  int qtdes[12];
} TProd;

int main() 
{
  TProd produtos[10];
  int i;

  /* a) Atribuir o valor 4368 para o membro num do elemento 5 do vetor. */
  produtos[4].num = 4368;
  printf("%d\n", produtos[4].num);

  /* b) Atribuir o valor 182 para o elemento 7 do membro qtdes do elemento 8 do vetor de produtos. */
  produtos[7].qtdes[6] = 182;
  printf("%d\n\n", produtos[7].qtdes[6]);

  /* c) Zerar todos os valores do membro qtdes do elemento 3 do vetor de produtos. */
  for (i = 0; i < 12; i++) 
    produtos[2].qtdes[i] = 0;

  /* 
    d) Produzir o valor total das quantidades do produto contido no elemento 4 do vetor de produtos.
    Considere que esse valor total é o resultado da multiplicação do membro valor pela soma dos valores contidos no membro qtdes.
  */
  int soma, total;
  produtos[3].valor = 53.78;

  for (i = 0; i < 12; i++) 
    produtos[3].qtdes[i] = rand() % 100;

  soma = 0;
  for (i = 0; i < 12; i++) 
    soma += produtos[3].qtdes[i];

  total = produtos[3].valor * soma;

  printf("\nSoma valores: %d", soma);
  printf("\nValor total: %d", total);

  return 0;
}
