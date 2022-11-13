/*
	Arquivo fonte da IMPLEMENTAÇÃO do TDA de listas lineares por ENCADEAMENTO,
	com as definições de tipo de dados e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>
#include "pLista4.h"

void InicializaLista(TLista *lista)
{	
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
	lista->soma = 0;
}

int IncluiItem(TLista *lista, int valor)
{	
	TItem *aux;

	/* criando uma variável TItem dinamicamente */
	aux = (TItem *) malloc(sizeof(TItem));

	if (aux == NULL)
		return FALSE;
		
	/* preenchendo os campos da variável alocada */
	aux->valor = valor;
	aux->prox = NULL;

	/* fazendo o encadeamento do novo nó da lista */
	if (lista->inicio == NULL)
		lista->inicio = aux;
	else
		lista->final->prox = aux;

	/* atualizando os demais descritores da lista */
	lista->final = aux;
	lista->qtde++;
	lista->soma += aux->valor;

	return TRUE;
}

void ImprimeLista(TLista *lista, char * cabec)
{	
	TItem *aux;
	
	if (lista->inicio == NULL)
		puts("\n\nLista vazia");
	else
	{	
		printf("\n\n\n%s\n", cabec);
		aux = lista->inicio;

		while (aux != NULL)
		{	
			printf("%d\n", aux->valor);
			aux = aux->prox;
		}
		
		printf("\nSoma = %d   Média = %.2f\n", lista->soma, lista->soma / (float)lista->qtde);
	}
}

int ExcluiItem(TLista *lista, int valor)
{	
	TItem *aux, *ant;

	/* procurando o item a ser excluído */
	ant = NULL;
	aux = lista->inicio;

	while (aux != NULL && valor != aux->valor)
	{	
		ant = aux;
		aux = aux->prox;
	}
		
	if (aux == NULL)
		return FALSE;

	/* cuidando do encadeamento */
	if (ant == NULL)
		lista->inicio = aux->prox;
	else
		ant->prox = aux->prox;
	
	/* atualizando os demais descritores da lista */
	if (aux == lista->final)
		lista->final = ant;

	lista->qtde--;
	lista->soma -= aux->valor;
	
	/* removendo o item da lista */
	free(aux);

	return TRUE;
}
