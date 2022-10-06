/* 
  O programa apresentado a seguir implementa uma pilha básica de números inteiros em linguagem C.
  Implementada por CONTIGUIDADE. 
  Para testá-lo, adapte-o para imprimir o conteúdo da pilha antes e após a exclusão.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct descrPilha 
{
  int topo, qtde;
  int vet[MAX];
};
typedef struct descrPilha DPilha;

int main(void)
{
  DPilha descr;
  int num, i, aux;

  for (i = 0; i < MAX; i++)
  {
    printf("Informe o número:\n");
    scanf("%d", &num);

    if (num < 0)
      break;
    
    /* preenchendo os valores da pilha */
    descr.vet[i] = num;

    /* atualizando o descritor */
    descr.topo = i;
    descr.qtde++;
  }

  while (1)
  {
    /* imprime pilha */
    printf("\n\nConteúdo da pilha:\n");
    
    for (i = descr.topo; i >= 0; i--)
      printf("%d\n", descr.vet[i]);

    printf("\nDigite 1 para excluir ou outra coisa para encerrar:\n");
    scanf("%d", &num);

    if (num != 1)
      break;
    
    /* verifica se a pilha está vazia */
    if (descr.qtde > 0)
    {
      aux = descr.vet[descr.topo];
      descr.topo--;
      descr.qtde--;
      
      /* excluindo um valor da pilha */
      printf("\nExcluindo o valor %d da pilha\n", aux);
    }
    else
    {
      printf("\nA lista está vazia\n");
      break;
    }
  }

  return 0;
}
