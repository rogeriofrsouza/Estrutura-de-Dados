/*
  O programa a seguir ilustra a implementação completa de uma fila de números inteiros em linguagem C.
  Implementada por ENCADEAMENTO.
  Para testá-lo, adapte-o para imprimir o conteúdo da fila antes e após a exclusão.
*/
#include <stdio.h>
#include <stdlib.h>

struct regItem 
{
  int valor;
  struct regItem *prox;
};
typedef struct regItem TItem;

struct regFila 
{
  TItem *inicio, *final;
  int qtde;
};
typedef struct regFila TFila;

int main(void)
{
  TItem *aux;
  TFila fila;
  int numero;

  /* inicializando os descritores da fila */
   fila.inicio = NULL;
   fila.final = NULL;
   fila.qtde = 0;
  
  while (1)
  {
    printf("\nInforme o número: ");
    scanf("%d", &numero);
    
    if (numero < 0)
      break;
    
    /* alocando a variável TItem dinamicamente */
    aux = (TItem *) malloc(sizeof(TItem));

    /* preenchendo os valores da variável alocada */
    aux->valor = numero;
    aux->prox = NULL;
    
    /* cuidando do encadeamento do novo nó na fila */
    if (fila.inicio == NULL)
      fila.inicio = aux;
    else
      fila.final->prox = aux;
    
    /* atualizando os descritores */
    fila.final = aux;
    fila.qtde++;
  }
  
  while (fila.inicio != NULL)
  {
    /* imprimindo os valores da fila */
    printf("\n\nConteúdo da fila:\n");

    for (aux = fila.inicio; aux != NULL; aux = aux->prox)
      printf("%d\n", aux->valor);

    printf("\nDigite 1 para excluir ou outra coisa para encerrar:\n");
    scanf("%d", &numero);
    
    if (numero != 1)
      return 1;
    
    /* excluindo um valor da fila */
    aux = fila.inicio;
    fila.inicio = aux->prox;
    fila.qtde--;
    
    printf("\nExcluindo o valor %d da fila\n", aux->valor);
    free(aux);
  }

  printf("\nA fila está vazia\n");
  
  return 0;
}
