/*
	Versão inicial do programa da lista linear de números	implementada por ENCADEAMENTO.
	Faz a exclusão de elementos da lista. Utiliza subrotina para impressão.
*/
#include <stdio.h>
#include <stdlib.h>

struct regLista 
{
	int valor;
	struct regLista *prox;
};
typedef struct regLista TItem;

void ImprimeLista(TItem *, char *);

int main(void)
{	
	int numero;
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

		if (aux == NULL)
		{	
			puts("\n\nMemória insuficiente para esta operação");
			return 2;
		}
		
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
	ImprimeLista(inicio, "Conteúdo da lista:");
		
	while (1)
	{	
		printf("\nInforme o valor a excluir: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		/* procurando o item a ser excluído */
		ant = NULL;
		aux = inicio;

		while (aux != NULL && numero != aux->valor)
		{	
			ant = aux;
			aux = aux->prox;
		}
		
		if (aux == NULL)
			puts("\n\nValor não encontrado");
		else
		{	
			/* cuidando do encadeamento */
			if (ant == NULL)
				inicio = aux->prox;
			else
				ant->prox = aux->prox;
			
			/* removendo o item da lista */
			free(aux);

			/* imprimindo os valores da lista */
			ImprimeLista(inicio, "Novo conteúdo da lista:");
		}
	}
	
	return 0;
}

void ImprimeLista(TItem *lista, char *cabec)
{	
	int soma, qtde;
	TItem *aux;
	
	if (lista == NULL)
		puts("\n\nLista vazia");
	else
	{	
		soma = 0;
		qtde = 0;
		printf("\n\n\n%s\n", cabec);

		aux = lista;

		while (aux != NULL)
		{	
			printf("%d\n", aux->valor);

			soma = soma + aux->valor;
			qtde = qtde + 1;
			aux = aux->prox;
		}
		
		printf("\nSoma = %d   Média = %.2f\n", soma, soma / (float)qtde);
	}
}
