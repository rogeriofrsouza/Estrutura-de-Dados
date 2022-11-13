/*
  O professor Rolien organizou junto às suas turmas de Ciência da Computação a confecção de uma camisa polo que fosse ao mesmo tempo bonita e barata. Após algumas conversas, ficou decidido com os alunos que seriam feitas somente camisas da cor preta, o que facilitaria a confecção. Os alunos poderiam escolher entre o logo do curso e os detalhes em branco ou vermelho. Assim sendo, Rolien precisa de sua ajuda para organizar as listas de quem quer a camisa em cada uma das turmas, relacionando estas camisas pela cor do logo do curso, tamanho (P, M ou G) e por último pelo nome.

  Entrada
  A entrada contém vários casos de teste. Cada caso de teste inicia com um valor N, (1 ≤ N ≤ 60) inteiro e positivo, que indica a quantidade de camisas a serem feitas para aquela turma. As próximas N*2 linhas contém informações de cada uma das camisas (serão duas linhas de informação para cada camisa). A primeira linha irá conter o nome do estudante e a segunda linha irá conter a cor do logo da camisa ("branco" ou "vermelho") seguido por um espaço e pelo tamanho da camisa "P" "M" ou "G". A entrada termina quando o valor de N for igual a zero (0) e este valor não deverá ser processado.

  Saída
  Para cada caso de entrada deverão ser impressas as informações ordenadas pela cor dos detalhes em ordem ascendente, seguido pelos tamanhos em ordem descendente e por último por ordem ascendente de nome, conforme o exemplo abaixo.

  Obs.: Deverá ser impressa uma linha em branco entre dois casos de teste.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct regCamisa 
{
  char nome[121];
  char cor[9];
  char tamanho;
} TCamisa;

typedef struct regLista {
  TCamisa *camisas;
  struct regLista *prox;
  int qtde, final;
} TLista;

void OrdenaPorCor(TLista *);
void OrdenaPorTamanho(TLista *, char *);
void OrdenaPorNome(TLista *, char *, char *);

int main()
{
  char cores[2] = {'b', 'v'};
  char tamanhos[3] = {'P', 'M', 'G'};

  int i;
  TLista *inicio, *aux, *ant;

  /* inicializando a variável inicio com um endereço vazio */
  inicio = NULL;

  while (1)
  {
    /* criando uma variável TLista dinamicamente */
    aux = (TLista *) malloc(sizeof(TLista));

    /* preenchendo os campos da variável */
    printf("\nInforme a quantidade de camisas: ");
    scanf("%d", &aux->qtde);

    aux->prox = NULL;

    if (aux->qtde <= 0)
      break;

    /* criando um vetor de TCamisa dinamicamente */
    aux->camisas = (TCamisa *) malloc(aux->qtde * sizeof(TCamisa));

    /* inserindo registros de camisas */
    for (i = 0; i < aux->qtde; i++)
    {
      printf("\nNome do estudante: ");
      scanf(" %120[^\n]", aux->camisas[i].nome);  // fgets(aux->camisas[i].nome, 120, stdin)
                                                  // gets(aux->camisas[i].nome)

      while (1)
      {
        printf("Cor e tamanho da camisa: ");
        scanf("%s %c", aux->camisas[i].cor, &aux->camisas[i].tamanho);

        /* validando entrada do usuário */
        if ((strcmp(aux->camisas[i].cor, "branco") || strcmp(aux->camisas[i].cor, "vermelho")) && 
            (aux->camisas[i].tamanho == 'P' || aux->camisas[i].tamanho == 'M' || aux->camisas[i].tamanho == 'G'))
          break;
        
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

  /* ordenando os valores da lista */
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

void OrdenaPorCor(TLista *lista)
{
  TCamisa aux;
  int i, j;

  for (i = 0; i <= lista->final-1; i++)
  {
    for (j = i+1; j <= lista->final; j++)
    {
      /* ordena cores: branco, vermelho */
      if ((int)lista->camisas[i].cor[0] > (int)lista->camisas[j].cor[0])
      {
        aux = lista->camisas[i];
        lista->camisas[i] = lista->camisas[j];
        lista->camisas[j] = aux;
      }
    }
  }
}


void OrdenaPorTamanho(TLista *lista, char *cores)
{
  TCamisa aux;
  int i, j, c;

  for (c = 0; c < 2; c++)
  {
    for (i = 0; i <= lista->final-1; i++)
    {
      for (j = i+1; j <= lista->final; j++)
      {
        /* compara a cor das camisas */
        if (lista->camisas[i].cor[0] == cores[c] && lista->camisas[j].cor[0] == cores[c])
        {
          /* ordena tamanhos: P, M, G */
          if ((int)lista->camisas[i].tamanho < (int)lista->camisas[j].tamanho)
          {
            aux = lista->camisas[i];
            lista->camisas[i] = lista->camisas[j];
            lista->camisas[j] = aux;
          }
        }
      }
    }
  }
}

void OrdenaPorNome(TLista *lista, char *cores, char *tamanhos)
{
  TCamisa aux;
  int i, j, c, t;
 
  for (c = 0; c < 2; c++)
  {
    for (t = 0; t < 3; t++)
    {
      for (i = 0; i <= lista->final-1; i++)
      {
        for (j = i+1; j <= lista->final; j++)
        {
          /* compara a cor das camisas */
          if (lista->camisas[i].cor[0] == cores[c] && lista->camisas[j].cor[0] == cores[c])
          {
            /* compara o tamanho das camisas */
            if (lista->camisas[i].tamanho == tamanhos[t] && lista->camisas[j].tamanho == tamanhos[t])
            {
              /* ordena nomes em ordem alfabética */
              if ((int)lista->camisas[i].nome[0] > (int)lista->camisas[j].nome[0])
              {
                aux = lista->camisas[i];
                lista->camisas[i] = lista->camisas[j];
                lista->camisas[j] = aux;
              }
            }
          }
        }
      }
    }
  }
}
