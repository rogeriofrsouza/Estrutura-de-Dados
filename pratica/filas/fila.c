/*
  O  programa  a  seguir  ilustra  a  implementação  completa  de  uma  fila  de  números  inteiros representada  por  encadeamento  em  
  linguagem  C. Para  testá-lo,  adapte-o  para  imprimir  o conteúdo da fila antes e após a exclusão.
*/
#include <stdlib.h>
#include <stdio.h>

struct regLista {
  int valor;
  struct regLista *prox;
};
typedef struct regLista TLista;

struct descrFila {
  TLista *inicio;
  TLista *final;
  int qtde;
};
typedef struct descrFila DFila;

int main(void)
{
  int numero;
  DFila descritor;
  TLista *aux;

  /* inicializando o descritor da fila */
  descritor.inicio = NULL;
  descritor.final  = NULL;
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
    aux->prox = NULL;
    
    /* cuidando do encadeamento do novo nó na lista */
    if (descritor.inicio == NULL)
      descritor.inicio = aux;
    else 
      descritor.final->prox = aux;
    
    /* atualizando os descritores */
    descritor.final = aux;
    descritor.qtde++;
  }
  
  while (1)
  {
    printf("\n\nDigite 1 para excluir ou outra coisa para encerrar:\n");
    scanf("%d", &numero);
    
    if (numero == 1)
    {
      if (descritor.inicio != NULL)
      {
        aux = descritor.inicio;

        descritor.inicio = descritor.inicio->prox;
        descritor.qtde--;
        
        if (descritor.qtde == 0)
          descritor.final = NULL;
        
        /* excluindo um valor da fila */
        printf("\n\nExcluindo o valor %d da lista\n", aux->valor);
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