/*
  O programa a seguir ilustra a implementação completa de uma fila de números inteiros representada por encadeamento em 
  linguagem C. Para testá-lo, adapte-o para imprimir o conteúdo da fila antes e após a exclusão.
*/
#include <stdlib.h>
#include <stdio.h>

struct regLista 
{
  int valor;
  struct regLista *prox;
};
typedef struct regLista TLista;

struct descrFila 
{
  TLista *inicio;
  TLista *final;
  int qtde;
};
typedef struct descrFila DFila;

int main(void)
{
  TLista *aux;
  DFila descr;
  int numero;

  /* inicializando o descritor da fila */
   descr.inicio = NULL;
   descr.final = NULL;
   descr.qtde = 0;
  
  while (1)
  {
    printf("Informe o número:\n");
    scanf("%d", &numero);
    
    if (numero < 0)
      break;
    
    /* alocando a struct TLista dinamicamente */
    aux = (TLista *) malloc(sizeof(TLista));

    /* preenchendo os valores da struct alocada */
    aux->valor = numero;
    aux->prox = NULL;
    
    /* cuidando do encadeamento do novo nó na fila */
    if (descr.inicio == NULL)
      descr.inicio = aux;
    else
      descr.final->prox = aux;
    
    /* atualizando os descritores */
    descr.final = aux;
    descr.qtde++;
  }
  
  while (1)
  {
    /* imprime fila */
    printf("\n\nConteúdo da fila:\n");

    for (aux = descr.inicio; aux != NULL; aux = aux->prox)
      printf("%d\n", aux->valor);

    printf("\nDigite 1 para excluir ou outra coisa para encerrar:\n");
    scanf("%d", &numero);
    
    if (numero != 1)
      break;
    
    /* verifica se a fila está vazia */
    if (descr.inicio != NULL)
    {
      aux = descr.inicio;
      descr.inicio = descr.inicio->prox;
      descr.qtde--;
      
      if (descr.inicio == NULL)
        descr.final = NULL;
      
      /* excluindo um valor da fila */
      printf("\nExcluindo o valor %d da lista\n", aux->valor);
      free(aux);
    }
    else
    {
      printf("\nA lista está vazia\n");
      break;
    }
  }
  
  return 0;
}
