/* 
  O programa apresentado a seguir implementa uma pilha básica de números inteiros em linguagem C. 
  Para testá-lo, adapte-o para imprimir o conteúdo da pilha antes e após a exclusão.
*/
#include <stdio.h>
#include <stdlib.h>

struct regLista 
{
  int valor;
  struct regLista *prox;
};
typedef struct regLista TLista;

struct descrPilha 
{
  TLista *topo;
  int qtde;
};
typedef struct descrPilha DPilha;

int main(void)
{
  TLista *aux;
  DPilha descr;
  int num;

  /* inicializando o descritor da pilha */
  descr.topo = NULL;
  descr.qtde = 0;
  
  while (1)
  {
    printf("Informe o número:\n");
    scanf("%d", &num);
    
    if (num < 0)
      break;
    
    /* alocando a struct TLista dinamicamente */
    aux = (TLista *) malloc(sizeof(TLista));

    /* preenchendo os valores da struct alocada */
    aux->valor = num;
    aux->prox = descr.topo;

    /* atualizando os descritores */
    descr.topo = aux;
    descr.qtde++;
  }

  while (1)
  {
    /* imprime pilha */
    printf("\n\nConteúdo da pilha:\n");

    for (aux = descr.topo; aux != NULL; aux = aux->prox)
      printf("%d\n", aux->valor);

    printf("\nDigite 1 para excluir ou outra coisa para encerrar:\n");
    scanf("%d", &num);

    if (num != 1)
      break;
    
    /* verifica se a pilha está vazia */
    if (descr.topo != NULL)
    {
      aux = descr.topo;
      descr.topo = descr.topo->prox;
      descr.qtde--;
      
      /* excluindo um valor da pilha */
      printf("\nExcluindo o valor %d da pilha\n", aux->valor);
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
