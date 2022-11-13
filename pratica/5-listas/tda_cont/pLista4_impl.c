/*
	Arquivo fonte da IMPLEMENTAÇÃO do TDA de listas lineares por CONTIGUIDADE,
	com as definições de tipo de dados e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>
#include "pLista4.h"

void InicializaLista(TLista *lista)
{	
	lista->inicio = 0;
	lista->final = 0;
	lista->qtde = 0;
	lista->soma = 0;
}

int IncluiItem(TLista *lista, int valor)
{	
	if (lista->final == MAXIMO)
		return FALSE;
	
	lista->vet[lista->final] = valor;

	lista->final = lista->final + 1;
	lista->qtde = lista->qtde + 1;
	lista->soma = lista->soma + valor;

	return TRUE;
}

void ImprimeLista(TLista *lista, char *cabec)
{	
	int cont;

	if (lista->final == 0)
		puts("\n\nLista vazia");
	else
	{	
		printf("\n\n\n%s\n", cabec);
		cont = 0;

		while (cont != lista->final)
		{	
			printf("%d\n", lista->vet[cont]);
			cont = cont + 1;
		}
		
		printf("\nSoma = %d   Média = %.2f\n", lista->soma, lista->soma / (float)lista->qtde);
	}
}

int ExcluiItem(TLista *lista, int valor)
{	
	int cont;

	/* procurando o item a ser excluído */
	cont = 0;

	while (cont < lista->final && valor != lista->vet[cont])
		cont = cont + 1;
	
	if (cont == lista->final)
		return FALSE;

	/* trazendo os elementos posteriores ao eliminado para o elemento anterior */
	while (cont < lista->final)
	{	
		lista->vet[cont] = lista->vet[cont + 1];
		cont = cont + 1;
	}
		
	lista->final = lista->final - 1;
	lista->qtde = lista->qtde - 1;
	lista->soma = lista->soma - valor;
		
	return TRUE;
}
