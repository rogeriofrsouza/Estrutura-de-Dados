/*
  O programa a seguir ilustra a implementação completa de uma fila de números inteiros em linguagem C.
  Implementada por CONTIGUIDADE.
  Para testá-lo, adapte-o para imprimir o conteúdo da fila antes e após a exclusão.
*/
#include <stdlib.h>
#include <stdio.h>
#define MAX 50

struct descrFila 
{
  int inicio, final;
  int vet[MAX];
};
typedef struct descrFila DFila;

int main(void)
{
  DFila descr;
  int num, i, aux;

  /* inicializando o descritor da fila */
  descr.final = 0;
  
  while (descr.final < MAX)
  {
    printf("Informe o número:\n");
    scanf("%d", &num);

    if (num < 0)
      break;
    
    /* preenchendo os valores da fila */
    descr.vet[descr.final] = num;

    /* atualizando o descritor */
    descr.final++;

    if (descr.final == 1)
      descr.inicio = 0;
  }

  while (1)
  {
    /* imprime fila */
    printf("\n\nConteúdo da fila:\n");
    
    for (i = descr.inicio; i < descr.final; i++)
      printf("%d\n", descr.vet[i]);

    printf("\nDigite 1 para excluir ou outra coisa para encerrar:\n");
    scanf("%d", &num);

    if (num != 1)
      break;
    
    /* verifica se a fila está vazia */
    if (descr.final > 0)
    {
      aux = descr.vet[descr.inicio];

      /* excluindo um valor da fila */
      printf("\nExcluindo o valor %d da fila\n", aux);
      descr.inicio++;

      if (descr.inicio == descr.final)
        descr.final = 0;
    }
    else
    {
      printf("\nA lista está vazia\n");
      break;
    }
  }

  return 0;
}
