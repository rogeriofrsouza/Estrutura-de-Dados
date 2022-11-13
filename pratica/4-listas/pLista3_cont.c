/*
	Versão inicial do programa da lista linear de números	implementada por CONTIGUIDADE.
	Faz a exclusão de elementos da lista. Utiliza subrotina para impressão.
*/
#include <stdio.h>

#define MAXIMO	50

typedef int TItem;

void ImprimeLista(TItem *, char *, int);

int main(void)
{	
	int numero, final, cont;
	TItem lista[MAXIMO];

	/* inicializando a variável de controle do fim da lista */
	final = 0;
	
	while (1)
	{	
		printf("\nInforme o número: ");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		lista[final] = numero;
		final = final + 1;
	}

	/* imprimindo os valores da lista */
	ImprimeLista(lista, "Conteúdo da lista:", final);
		
	while (1)
	{	
		printf("\nInforme o valor a excluir: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		/* procurando o item a ser excluído */
		cont = 0;

		while (cont < final && numero != lista[cont])
			cont = cont + 1;
	
		if (cont == final)
			puts("\n\nValor não encontrado");
		else
		{	
			/* trazendo os elementos posteriores ao eliminado	para o elemento anterior */
			while (cont < final)
			{	
				lista[cont] = lista[cont + 1];
				cont = cont + 1;
			}
			
			final = final - 1;

			/* imprimindo os valores da lista */
			ImprimeLista(lista, "Novo conteúdo da lista:", final);
		}
	}
	
	return 0;
}

void ImprimeLista(TItem *lista, char *cabec, int final)
{	
	int cont, soma, qtde;

	if (final == 0)
		puts("\n\nLista vazia");
	else
	{	
		soma = 0;
		qtde = 0;
		printf("\n\n\n%s\n", cabec);

		cont = 0;

		while (cont != final)
		{	
			printf("%d\n", lista[cont]);
			
			soma = soma + lista[cont];
			qtde = qtde + 1;
			cont = cont + 1;
		}
		
		printf("\nSoma = %d   Média = %.2f\n", soma, soma / (float)qtde);
	}
}
