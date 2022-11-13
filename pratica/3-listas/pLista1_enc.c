/*
	Versão inicial do programa da lista linear de números	implementada por ENCADEAMENTO.
	É a mesma versão encontrada no arquivo 63_ED-ListasLineares.pdf
*/
#include <stdio.h>
#include <stdlib.h>

struct regLista 
{
	int valor;	
	struct regLista *prox;
};
typedef struct regLista TItem;

int main(void)
{
	int numero, qtde, soma;
	TItem *inicio, *aux, *ant;

	/* inicializando a variável inicio com um endereço vazio */
	inicio = NULL;

	while (1)
	{	
		printf("\nInforme o número: ");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		/* criando uma variável TItem dinamicamente */
		aux = (TItem *) malloc(sizeof(TItem));

		/* preenchendo os campos da variável alocada */
		aux->valor = numero;
		aux->prox = NULL;

		/* fazendo o encadeamento do novo nó da lista */
		if (inicio == NULL)
			inicio = aux;
		else
			ant->prox = aux;

		ant = aux;
	}

	/* imprimindo os valores da lista */
	if (inicio == NULL)
		puts("\n\nLista vazia");
	else
	{	
		soma = 0;
		qtde = 0;
		printf("\n\n\nConteúdo da lista:\n");

		aux = inicio;

		while (aux != NULL)
		{	
			printf("%d\n", aux->valor);

			soma = soma + aux->valor;
			qtde = qtde + 1;
			aux = aux->prox;
		}
		
		printf("\nSoma = %d   Média = %.2f\n", soma, soma / (float)qtde);
	}
	
	while (1)
	{	
		printf("\nInforme o valor a pesquisar: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		aux = inicio;

		while (aux != NULL && numero != aux->valor)
			aux = aux->prox;
	
		if (aux == NULL)
			puts("\nValor não encontrado");
		else
			puts("\nValor existe na lista");
	}
	
	return 0;
}
