/*
  O professor Rolien organizou junto às suas turmas de Ciência da Computação a confecção de uma camiseta polo que fosse ao mesmo tempo bonita e barata. Após algumas conversas, ficou decidido com os alunos que seriam feitas somente camisetas da cor preta, o que facilitaria a confecção. Os alunos poderiam escolher entre o logo do curso e os detalhes em branco ou vermelho. Assim sendo, Rolien precisa de sua ajuda para organizar as listas de quem quer a camiseta em cada uma das turmas, relacionando estas camisetas pela cor do logo do curso, tamanho (P, M ou G) e por último pelo nome.

  Entrada
  A entrada contém vários casos de teste. Cada caso de teste inicia com um valor N, (1 ≤ N ≤ 60) inteiro e positivo, que indica a quantidade de camisetas a serem feitas para aquela turma. As próximas N*2 linhas contém informações de cada uma das camisetas (serão duas linhas de informação para cada camiseta). A primeira linha irá conter o nome do estudante e a segunda linha irá conter a cor do logo da camiseta ("branco" ou "vermelho") seguido por um espaço e pelo tamanho da camiseta "P" "M" ou "G". A entrada termina quando o valor de N for igual a zero (0) e esta valor não deverá ser processado.

  Saída
  Para cada caso de entrada deverão ser impressas as informações ordenadas pela cor dos detalhes em ordem ascendente, seguido pelos tamanhos em ordem descendente e por último por ordem ascendente de nome, conforme o exemplo abaixo.

  Obs.: Deverá ser impressa uma linha em branco entre dois casos de teste.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct regCamiseta 
{
  char nome[121];
  char cor[9];
  char tamanho;
} PCamiseta;

typedef struct regLista 
{
  PCamiseta *camisetas;
  struct regLista *prox;
  int qtde;
} PLista;

int main()
{
  int qtde, i;
  PLista *inicio, *aux, *ant;

  /* inicializando a variável inicio com um endereco vazio */
  inicio = NULL;

  while (1)
  {
    printf("\nInforme a quantidade de camisetas: ");
    scanf("%d", &qtde);

    if (qtde <= 0)
      break;
    
    /* criando uma variável struct regLista dinamicamente */
    aux = (PLista *) malloc(sizeof(PLista));

    /* criando um vetor de struct regCamiseta dinamicamente */
    aux->camisetas = (PCamiseta *) malloc(qtde * sizeof(PCamiseta));

    /* preenchendo os campos da variável criada dinamicamente */
    aux->prox = NULL;
    aux->qtde = 0;

    /* inserindo registros de camisetas */
    for (i = 0; i < qtde; i++)
    {
      printf("\nNome do estudante: ");
      scanf(" %120[^\n]", aux->camisetas[i].nome);

      printf("Cor e tamanho da camiseta: ");
      scanf("%s %c", aux->camisetas[i].cor, &aux->camisetas[i].tamanho);

      aux->qtde++;
    }

	  /* fazendo o encadeamento do novo nó da lista */
    if (inicio == NULL)
      inicio = aux;
    else
      ant->prox = aux;

    ant = aux;
  }

  /* organizando os valores da lista por cor */
  PCamiseta camiseta;
  aux = inicio;

  while (aux != NULL)
  {	
    for (i = 0; i < aux->qtde; i++)
    {
      if (i == aux->qtde - 1)
        break;

      if (aux->camisetas[i].cor[0] == 'v')
      {
        camiseta = aux->camisetas[i];
        aux->camisetas[i] = aux->camisetas[i+1];
        aux->camisetas[i+1] = camiseta;
      }
    }

    aux = aux->prox;
  }

  /* imprimindo os valores da lista */
	if (inicio == NULL)
		puts("\n\nLista vazia");
	else
	{	
		printf("\n\nConteúdo da lista:\n");
		aux = inicio;

		while (aux != NULL)
		{	
      for (i = 0; i < aux->qtde; i++)
			  printf("%s %c %s\n", aux->camisetas[i].cor, aux->camisetas[i].tamanho, aux->camisetas[i].nome);

		  printf("\n");
			aux = aux->prox;
		}
	}

  return 0;
}
