/*
	Versão inicial do programa da lista linear de números
	implementada por ENCADEAMENTO.
	Faz a exclusão de elementos da lista.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct regLista TItem;
struct regLista {int valor;	TItem *prox;};

int imprimeLista(TItem *i, TItem *a);

int main(void)
{
	int numero, r = 0;
	TItem *inicio, *aux, *ant;

	/* Inicializando a variável inicio com um endereço vazio */
	inicio = NULL;

	while (1)
	{
		printf("Informe o número: ");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		/* Criando uma variável TItem dinamicamente */
		aux = (TItem *) malloc(sizeof(TItem));

		if (aux == NULL)
		{
			puts("Memória insuficiente para esta operação");
			return 2;
		}
		
		/* Preenchendo os campos da variável criada dinamicamente */
		aux->valor = numero;
		aux->prox = NULL;

		/* Fazendo o encadeamento do novo nó da lista */
		if (inicio == NULL)
			inicio = aux;
		else
			ant->prox = aux;

		ant = aux;
	}

	r = imprimeLista(inicio, aux);
	if (r)
		return 1;

	/* Procurando o item a ser excluído */
	while (1)
	{
		printf("Informe o valor a excluir: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		ant = NULL;
		aux = inicio;

		while ((aux != NULL) && (numero != aux->valor))
		{
			ant = aux;
			aux = aux->prox;
		}
		
		if (aux == NULL)
			puts("Valor não encontrado");
		else
		{
			/* Cuidando do encadeamento */
			if (ant == NULL)
				inicio = aux->prox;
			else
				ant->prox = aux->prox;
			
			/* Removendo o item da lista */
			free(aux);
		}

		r =	imprimeLista(inicio, aux);
		if (r)
			break;
	}
	
	return 0;
}

/* Imprimindo os valores da lista */
int imprimeLista(TItem *i, TItem *a)
{
	int soma, qtde;

	if (i == NULL)
	{
		puts("\nLista vazia");
		return 1;
	}

	soma = 0;
	qtde = 0;

	printf("\n\n\nConteúdo da lista:\n");
	a = i;

	while (a != NULL)
	{
		printf("%d\n", a->valor);
		soma += a->valor;
		qtde++;
	
		a = a->prox;
	}

	printf("Soma = %d   Média = %.2f\n", soma, soma / (float)qtde);
	return 0;
}
