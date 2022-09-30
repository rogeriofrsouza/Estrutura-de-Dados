#include <stdio.h>
#include <stdlib.h>

typedef struct regCamisa {
  char nome[121];
  char cor[9];
  char tamanho;
} PCamisa;

typedef struct regLista {
  PCamisa *camisas;
  struct regLista *prox;
  int qtde;
  int final;
} PLista;

void OrdenaPorCor(PLista *);

int main()
{
  int i;
  PLista *inicio, *aux, *ant;

  /* inicializando a variável inicio com um endereco vazio */
  inicio = NULL;

  while (1)
  {
    /* criando uma variável struct regLista dinamicamente */
    aux = (PLista *) malloc(sizeof(PLista));

    /* preenchendo os campos de regLista */
    aux->qtde = 5;
    aux->prox = NULL;

    /* criando um vetor de struct regcamisa dinamicamente */
    aux->camisas = (PCamisa *) malloc(aux->qtde * sizeof(PCamisa));

    /* inserindo registros de camisas */
    *aux->camisas[0].nome = "Maria Jose";
    *aux->camisas[1].nome = "Mangojata Mancuda";
    *aux->camisas[2].nome = "Cezar Torres";
    *aux->camisas[3].nome = "Baka Lhau";
    *aux->camisas[4].nome = "JuJu Mentina";
    
    *aux->camisas[0].cor = "branco";
    *aux->camisas[1].cor = "vermelho";
    *aux->camisas[2].cor = "branco";
    *aux->camisas[3].cor = "vermelho";
    *aux->camisas[4].cor = "branco";
    
    aux->camisas[0].tamanho = "G";
    aux->camisas[1].tamanho = "P";
    aux->camisas[2].tamanho = "G";
    aux->camisas[3].tamanho = "P";
    aux->camisas[4].tamanho = "M";

    /* fazendo o encadeamento do novo nó da lista */
    if (inicio == NULL)
      inicio = aux;
    else
      ant->prox = aux;

    /* atualizando descritores */
    ant = aux;
    aux->final = aux->qtde - 1;
  }

  /* organizando os valores da lista */
  aux = inicio;

  while (aux != NULL)
  {    
    /* por cor */
    OrdenaPorCor(aux);
    
    aux = aux->prox;
  }

  /* imprimindo os valores da lista */
    if (inicio == NULL)
      puts("\n\nLista vazia");
    else
    {    
      printf("\n\n");
      aux = inicio;

    while (aux != NULL)
    {
      for (i = 0; i < aux->qtde; i++)
        printf("%s %c %s\n", aux->camisas[i].cor, 
                             aux->camisas[i].tamanho, 
                             aux->camisas[i].nome);
        printf("\n");
        aux = aux->prox;
      }
    }

  return 0;
}

void OrdenaPorCor(PLista *aux)
{
  PCamisa camisa;
  int i, j;

  for (i = 0; i < aux->final; i++)
  {
    for (j = i+1; j < aux->final; j++)
    {
      if ((int)aux->camisas[i].cor[0] > (int)aux->camisas[j].cor[0])
      {
        camisa = aux->camisas[i];
        aux->camisas[i] = aux->camisas[j];
        aux->camisas[j] = camisa;
      }
    }
  }
}