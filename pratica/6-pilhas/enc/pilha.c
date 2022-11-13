/* 
  O programa apresentado a seguir implementa uma pilha básica de números inteiros em linguagem C. 
  Implementada por ENCADEAMENTO. 
  Para testá-lo, adapte-o para imprimir o conteúdo da pilha antes e após a exclusão.
*/
#include <stdio.h>
#include <stdlib.h>

struct regItem 
{
  int valor;
  struct regItem *prox;
};
typedef struct regItem TItem;

struct regPilha 
{
  TItem *topo;
  int qtde;
};
typedef struct regPilha TPilha;

int main(void)
{
  TItem *aux;
  TPilha pilha;
  int num;

  /* inicializando a pilha */
  pilha.topo = NULL;
  pilha.qtde = 0;
  
  while (1)
  {
    printf("\nInforme o número: ");
    scanf("%d", &num);
    
    if (num < 0)
      break;
    
    /* criando uma variável TItem dinamicamente */
    aux = (TItem *) malloc(sizeof(TItem));

    /* preenchendo os valores da variável alocada */
    aux->valor = num;
    aux->prox = pilha.topo;

    /* atualizando os descritores*/
    pilha.topo = aux;
    pilha.qtde++;
  }

  while (pilha.topo != NULL)
  {
    /* imprimindo os valores da pilha */
    printf("\n\nConteúdo da pilha:\n");

    for (aux = pilha.topo; aux != NULL; aux = aux->prox)
      printf("%d\n", aux->valor);

    printf("\nDigite 1 para excluir ou outra coisa para encerrar:\n");
    scanf("%d", &num);

    if (num != 1)
      return 1;
    
    /* excluindo um valor da pilha */
    printf("\nExcluindo o valor %d da pilha\n", pilha.topo->valor);

    aux = pilha.topo;
    pilha.topo = pilha.topo->prox;
    pilha.qtde--;

    free(aux);
  }
  
  printf("\nA pilha está vazia\n");

  return 0;
}
