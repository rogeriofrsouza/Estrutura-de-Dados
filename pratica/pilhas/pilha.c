/* 
  O  programa  apresentado  a  seguir  implementa  uma  pilha  básica  de  números  inteiros  em linguagem C. Para testá-lo, adapte-o para imprimir o conteúdo da pilha antes e após a exclusão.
*/
#include <stdio.h>
#include <stdlib.h>

struct regLista {
  int valor;
  struct regLista *prox;
};
typedef struct regLista TLista;

struct descrPilha {
  TLista *topo;
  int qtde;
};
typedef struct descrPilha DPilha;

int main(void)
{
  int numero;
  DPilha descritor;
  TLista *aux;

  /* inicializando o descritor da pilha */
  descritor.topo = NULL;
  descritor.qtde = 0;
  
  while (1)
  {
    printf("Informe o número:\n");
    scanf("%d", &numero);
    
    if (numero < 0)
      break;
    
    /* alocando a struct TLista dinamicamente */
    aux = (TLista *) malloc(sizeof(TLista));

    /* preenchendo os valores da struct alocada dinamicamente */
    aux->valor = numero;
    aux->prox = descritor.topo;

    /* atualizando os descritores */
    descritor.topo = aux;
    descritor.qtde++;
  }
   
  while (1)
  {
    printf("\n\nDigite 1 para excluir ou outra coisa para encerrar:\n");
    scanf("%d", &numero);

    if (numero == 1)
    {
      if (descritor.topo != NULL)
      {
        aux = descritor.topo;

        descritor.topo = descritor.topo->prox;
        descritor.qtde--;
        
        /* excluindo um valor da pilha */
        printf("\n\nExcluindo o valor %d da pilha\n", aux->valor);
        free(aux);
      }
      else
      {
        printf("\n\nA lista está vazia\n");
        break;
      }
    }
  }
  
  return 0;
}