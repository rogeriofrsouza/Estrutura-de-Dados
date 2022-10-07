/*
  O programa a seguir ilustra a implementação completa de uma fila de números inteiros em linguagem C.
  Implementada por CONTIGUIDADE.
  Para testá-lo, adapte-o para imprimir o conteúdo da fila antes e após a exclusão.
*/
#include <stdlib.h>
#include <stdio.h>

#define MAX 50

struct fila 
{
  int inicio, fim;
  int vet[MAX];
};
typedef struct fila Fila;

int main(void)
{
  Fila fila;
  int num, i, aux;

  /* inicializando a fila */
  fila.inicio = 0;
  fila.fim = 0;
  
  while (fila.fim < MAX-1)
  {
    printf("Informe o número:\n");
    scanf("%d", &num);

    if (num < 0)
      break;
    
    /* preenchendo os valores da fila */
    fila.vet[fila.fim] = num;

    /* atualizando o descritor */
    fila.fim++;
  }

  while (fila.inicio != fila.fim)
  {
    /* imprimindo fila */
    printf("\n\nConteúdo da fila:\n");
    
    for (i = fila.inicio; i < fila.fim; i++)
      printf("%d\n", fila.vet[i]);

    printf("\nDigite 1 para excluir ou outra coisa para encerrar:\n");
    scanf("%d", &num);

    if (num != 1)
      exit(2);

    aux = fila.vet[fila.inicio];

    /* excluindo um valor da fila */
    printf("\nExcluindo o valor %d da fila\n", aux);
    fila.inicio++;
  }

  printf("\nA lista está vazia\n");

  return 0;
}
