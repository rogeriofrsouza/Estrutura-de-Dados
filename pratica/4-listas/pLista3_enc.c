/*
	Versao inicial do programa da lista linear de números
	implementada por ENCADEAMENTO.
	Faz a exclusão de elementos da lista. Utiliza subrotina para 
	impressao.
*/
#include <stdio.h>
#include <stdlib.h>

struct regLista {
	int valor;
	struct regLista *prox;
};
typedef struct regLista TItem;

void ImprimeLista(TItem *, char *);

int main(void)
{	
	int numero;
	TItem *inicio, *aux, *ant;

	/* inicializando a variável inicio com um endereco vazio */
	inicio = NULL;
	while (1)
	{	
		printf("Informe o numero:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		/* criando uma variável struct regLista dinamicamente */
		aux = (TItem *) malloc(sizeof(TItem));
		if (aux == NULL)
		{	
			puts("Memoria insuficiente para esta operacao");
			return 2;
		}
		
		/* preenchendo os campos da variável criada dinamicamente */
		aux->valor = numero;
		aux->prox = NULL;

		/* fazendo o encadeamento do novo nó da lista */
		if (inicio == NULL)
			inicio = aux;
		else
			ant->prox = aux;

		ant = aux;
	}

	ImprimeLista(inicio, "Conteudo da lista:");
		
	while (1)
	{	
		printf("Informe o valor a excluir: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		/* Procurando o item a ser excluido */
		ant = NULL;
		aux = inicio;
		while (aux != NULL && numero != aux->valor)
		{	
			ant = aux;
			aux = aux->prox;
		}
		
		if (aux == NULL)
			puts("Valor nao encontrado");
		else
		{	
			/* Cuidando do encadeamento */
			if (ant == NULL)
				inicio = aux->prox;
			else
				ant->prox = aux->prox;
			
			/* Removendo o item da lista */
			free(aux);

			ImprimeLista(inicio, "Novo conteudo da lista:");
		}
	}
	
	return 0;
}

void ImprimeLista(TItem *lista, char *cabec)
{	
	/* imprimindo os valores da lista */
	int soma, qtde;
	TItem *aux;
	
	if (lista == NULL)
		puts("Lista vazia");
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
		
		printf("Soma = %d   Media = %.2f\n", soma, soma / (float)qtde);
	}
}
