/* 
  O programa apresentado a seguir implementa uma pilha básica de números inteiros em linguagem C.
  Implementada por CONTIGUIDADE. 
  Para testá-lo, adapte-o para imprimir o conteúdo da pilha antes e após a exclusão.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct pilha 
{
  int topo, qtde;
  int vet[MAX];
};
typedef struct pilha Pilha;

int main(void)
{
  Pilha pilha;
  int num, i, aux;

  /* inicializando a pilha */
  pilha.topo = 0;
  pilha.qtde = 0;

  for (i = 0; i < MAX; i++)
  {
    printf("Informe o número:\n");
    scanf("%d", &num);

    if (num < 0)
      break;
    
    /* preenchendo os valores da pilha */
    pilha.vet[i] = num;

    /* atualizando os descritores */
    pilha.topo = i;
    pilha.qtde++;
  }

  while (pilha.qtde > 0)
  {
    /* imprimindo pilha */
    printf("\n\nConteúdo da pilha:\n");
    
    for (i = pilha.topo; i >= 0; i--)
      printf("%d\n", pilha.vet[i]);

    printf("\nDigite 1 para excluir ou outra coisa para encerrar:\n");
    scanf("%d", &num);

    if (num != 1)
      exit(1);
    
    aux = pilha.vet[pilha.topo];
    
    /* excluindo um valor da pilha */
    printf("\nExcluindo o valor %d da pilha\n", aux);
    pilha.topo--;
    pilha.qtde--;
  }

  printf("\nA lista está vazia\n");

  return 0;
}
