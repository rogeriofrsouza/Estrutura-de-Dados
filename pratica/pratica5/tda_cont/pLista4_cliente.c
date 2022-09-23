/*
	Versao inicial do programa da lista linear de números
	implementada por CONTIGUIDADE.
	Faz a exclusão de elementos da lista. 
	Utiliza descritor estruturado e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>
#include "pLista4.h"

int main(void)
{	
	int numero;
	TLista lista;
	
	InicializaLista(&lista);
	while (TRUE)
	{	
		printf("Informe o numero:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		if (IncluiItem(&lista, numero) == FALSE)
		{	
			puts("Memoria insuficiente para esta operacao");
			return 2;
		}
	}

	ImprimeLista(&lista, "Conteudo da lista:");
		
	while (TRUE)
	{	
		printf("Informe o valor a excluir: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		if (ExcluiItem(&lista, numero) == FALSE)
			puts("Valor nao encontrado");
		else
			ImprimeLista(&lista, "Novo conteudo da lista:");			
	}
	
	return 0;
}
