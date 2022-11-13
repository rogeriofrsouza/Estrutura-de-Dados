/*
	Arquivo fonte da IMPLEMENTACAO do TDA de listas lineares por CONTIGUIDADE,
	com as definicoes de tipo de dados e subrotinas.
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

void ImprimeLista(TLista *lista, char *cabec)
{	
	/* imprimindo os valores da lista */
	int cont;

	if (lista->final == 0)
		puts("Lista vazia");
	else
	{	
		printf("\n\n\n%s\n", cabec);
		cont = 0;
		while (cont != lista->final)
		{	
			printf("%d\n", lista->lista[cont]);
			
			cont = cont + 1;
		}
		
		printf("Soma = %d   Media = %.2f\n", lista->soma, lista->soma / (float)lista->qtde);
	}
}

int IncluiItem(TLista *lista, int valor)
{	
	if (lista->final == MAXIMO)
		return FALSE;
	
	lista->lista[lista->final] = valor;
	lista->final = lista->final + 1;
	lista->qtde = lista->qtde + 1;
	lista->soma = lista->soma + valor;

	return TRUE;
}

int ExcluiItem(TLista *lista, int valor)
{	
	int cont;

	/* Procurando o item a ser excluido */
	cont = 0;
	while (cont < lista->final && valor != lista->lista[cont])
		cont = cont + 1;
	
	if (cont == lista->final)
		return FALSE;
	else
	{	
		/* trazendo os elementos posteriores ao eliminado
			para o elemento anterior */
		while (cont < lista->final)
		{	
			lista->lista[cont] = lista->lista[cont + 1];
			cont = cont + 1;
		}
			
		lista->final = lista->final - 1;
		lista->qtde = lista->qtde - 1;
		lista->soma = lista->soma - valor;
	}
		
	return TRUE;
}
