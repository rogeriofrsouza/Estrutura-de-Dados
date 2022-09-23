/*
	Arquivo fonte da IMPLEMENTACAO do TDA de listas lineares por ENCADEAMENTO,
	com as definicoes de tipo de dados e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>
#include "pLista4.h"

void ImprimeLista(TLista *lista, char * cabec)
{	
	/* imprimindo os valores da lista */
	TItem *aux;
	
	if (lista->inicio == NULL)
		puts("Lista vazia");
	else
	{	
		printf("\n\n\n%s\n", cabec);
		aux = lista->inicio;
		while (aux != NULL)
		{	
			printf("%d\n", aux->valor);
			
			aux = aux->prox;
		}
		
		printf("Soma = %d   Media = %.2f\n", lista->soma, lista->soma / (float)lista->qtde);
	}
}

void InicializaLista(TLista *lista)
{	
	/* inicializa o conjunto de descritores da lista */
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
	lista->soma = 0;
}

int IncluiItem(TLista *lista, int valor)
{	
	TItem *aux;

	/* criando uma variável struct regLista dinamicamente */
	aux = (TItem *) malloc(sizeof(TItem));
	if (aux == NULL)
		return FALSE;
		
	/* preenchendo os campos da variável criada dinamicamente */
	aux->valor = valor;
	aux->prox = NULL;

	/* fazendo o encadeamento do novo nó da lista */
	if (lista->inicio == NULL)
		lista->inicio = aux;
	else
		lista->final->prox = aux;

	/* atualizando os demais descritores da lista */
	lista->qtde = lista->qtde + 1;
	lista->soma = lista->soma + aux->valor;
	lista->final = aux;

	return TRUE;
}

int ExcluiItem(TLista *lista, int valor)
{	
	TItem *aux, *ant;

	/* Procurando o item a ser excluido */
	ant = NULL;
	aux = lista->inicio;
	while (aux != NULL && valor != aux->valor)
	{	
		ant = aux;
		aux = aux->prox;
	}
		
	if (aux == NULL)
		return FALSE;
	else
	{	
		/* Cuidando do encadeamento */
		if (ant == NULL)
			lista->inicio = aux->prox;
		else
			ant->prox = aux->prox;
		
		/* Atualizando os demais descritores da lista */
		lista->qtde = lista->qtde - 1;
		lista->soma = lista->soma - aux->valor;
		if (aux == lista->final)
			lista->final = ant;
			
		/* Removendo o item da lista */
		free(aux);
	}
	
	return TRUE;
}