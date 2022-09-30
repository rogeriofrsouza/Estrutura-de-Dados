/*
  O professor Rolien organizou junto às suas turmas de Ciência da Computação a confecção de uma camisa polo que fosse ao mesmo tempo bonita e barata. Após algumas conversas, ficou decidido com os alunos que seriam feitas somente camisas da cor preta, o que facilitaria a confecção. Os alunos poderiam escolher entre o logo do curso e os detalhes em branco ou vermelho. Assim sendo, Rolien precisa de sua ajuda para organizar as listas de quem quer a camisa em cada uma das turmas, relacionando estas camisas pela cor do logo do curso, tamanho (P, M ou G) e por último pelo nome.

  Entrada
  A entrada contém vários casos de teste. Cada caso de teste inicia com um valor N, (1 ≤ N ≤ 60) inteiro e positivo, que indica a quantidade de camisas a serem feitas para aquela turma. As próximas N*2 linhas contém informações de cada uma das camisas (serão duas linhas de informação para cada camisa). A primeira linha irá conter o nome do estudante e a segunda linha irá conter a cor do logo da camisa ("branco" ou "vermelho") seguido por um espaço e pelo tamanho da camisa "P" "M" ou "G". A entrada termina quando o valor de N for igual a zero (0) e esta valor não deverá ser processado.

  Saída
  Para cada caso de entrada deverão ser impressas as informações ordenadas pela cor dos detalhes em ordem ascendente, seguido pelos tamanhos em ordem descendente e por último por ordem ascendente de nome, conforme o exemplo abaixo.

  Obs.: Deverá ser impressa uma linha em branco entre dois casos de teste.
*/
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
void OrdenaPorTamanho(PLista *, char *);
void OrdenaPorNome(PLista *, char *, char *);

int main()
{
  char tamanhos[3] = {'P', 'M', 'G'};
  char cores[2] = {'b', 'v'};

  int i;
  PLista *inicio, *aux, *ant;

  /* inicializando a variável inicio com um endereco vazio */
  inicio = NULL;

  while (1)
  {
    /* criando uma variável struct regLista dinamicamente */
    aux = (PLista *) malloc(sizeof(PLista));

    /* preenchendo os campos de regLista */
    printf("\nInforme a quantidade de camisas: ");
    scanf("%d", &aux->qtde);

    aux->prox = NULL;

    if (aux->qtde <= 0)
      break;

    /* criando um vetor de struct regcamisa dinamicamente */
    aux->camisas = (PCamisa *) malloc(aux->qtde * sizeof(PCamisa));

    /* inserindo registros de camisas */
    for (i = 0; i < aux->qtde; i++)
    {
      printf("\nNome do estudante: ");
      scanf(" %120[^\n]", aux->camisas[i].nome);

      while (1)
      {
        printf("Cor e tamanho da camisa: ");
        scanf("%s %c", aux->camisas[i].cor, &aux->camisas[i].tamanho);

        /* validando entrada do usuário */
        if ((aux->camisas[i].cor[0] == 'b' || aux->camisas[i].cor[0] == 'v') && 
            (aux->camisas[i].tamanho == 'P' || aux->camisas[i].tamanho == 'M' || aux->camisas[i].tamanho == 'G'))
          break;
        else
          printf("\nCores: branco, vermelho\nTamanhos: P, M, G\n\n");
      }
    }

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

    /* por tamanho */
    OrdenaPorTamanho(aux, cores);

    /* por nome */
    OrdenaPorNome(aux, cores, tamanhos);
    
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

void OrdenaPorTamanho(PLista *aux, char *cores)
{
  PCamisa camisa;
  int i, j, c;

  for (c = 0; c < 2; c++)
  {
    for (i = 0; i < aux->final; i++)
    {
      for (j = 1; j < aux->final-1; j++)
      {
        /* branco, vermelho */
        if ((aux->camisas[i].cor[0] == cores[c]) && (aux->camisas[j].cor[0] == cores[c]))
        {
          if ((int)aux->camisas[i].tamanho > (int)aux->camisas[j].tamanho)
          {
            camisa = aux->camisas[i];
            aux->camisas[i] = aux->camisas[j];
            aux->camisas[j] = camisa;
          }
        }
      }
    }
  }
}

void OrdenaPorNome(PLista *aux, char *cores, char *tamanhos)
{
  PCamisa camisa;
  int i, j, c, t;
 
  for (c = 0; c < 2; c++)
  {
    for (t = 0; t < 3; t++)
    {
      for (i = 0; i < aux->final; i++)
      {
        for (j = 1; j < aux->final-1; j++)
        {
          if ((aux->camisas[i].cor[0] == cores[c]) && (aux->camisas[j].cor[0] == cores[c]))
          {
            if ((aux->camisas[i].tamanho == tamanhos[t]) && (aux->camisas[j].tamanho == tamanhos[t]))
            {
              if ((int)aux->camisas[i].nome[0] > (int)aux->camisas[j].nome[0])
              {
                camisa = aux->camisas[i];
                aux->camisas[i] = aux->camisas[j];
                aux->camisas[j] = camisa;
              }
            }
          }
        }
      }
    }
  }
}
