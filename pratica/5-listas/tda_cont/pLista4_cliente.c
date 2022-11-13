/*
	Arquivo fonte do programa CLIENTE que opera sobre lista linear implementada por CONTIGUIDADE.
	Faz a exclusão de elementos da lista. Utiliza subrotina para impressão.
	Utiliza descritor estruturado e subrotinas.
*/
#include <stdio.h>
#include "pLista4.h"

int main(void)
{	
	int numero;
	TLista lista;
	
	/* inicializa o conjunto de descritores da lista */
	InicializaLista(&lista);

	while (TRUE)
	{	
		printf("\nInforme o número: ");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		if (IncluiItem(&lista, numero) == FALSE)
		{	
			puts("\n\nMemória insuficiente para esta operação");
			return 2;
		}
	}

	/* imprime os valores da lista */
	ImprimeLista(&lista, "Conteúdo da lista:");
		
	while (TRUE)
	{	
		printf("\nInforme o valor a excluir: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		if (ExcluiItem(&lista, numero) == FALSE)
			puts("\nValor não encontrado\n\n");
		else
			ImprimeLista(&lista, "Novo conteúdo da lista:");			
	}
	
	return 0;
}
