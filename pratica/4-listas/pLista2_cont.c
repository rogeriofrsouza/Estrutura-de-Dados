/*
	Versao inicial do programa da lista linear de números
	implementada por CONTIGUIDADE.
	Faz a exclusão de elementos da lista.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 50

typedef int TItem;

int main(void)
{	
	int numero, final, cont, soma, qtde;
	TItem lista[MAXIMO];

	/* inicializando a variável de controle do fim da lista */
	final = 0;
	
	while (1)
	{	
		printf("Informe o numero:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		lista[final] = numero;
		final = final + 1;
	}

	/* imprimindo os valores da lista */
	if (final == 0)
		puts("Lista vazia");
	else
	{	
		soma = 0;
		qtde = 0;
		printf("\n\n\nConteudo da lista:\n");

		cont = 0;
		while (cont != final)
		{	
			printf("%d\n", lista[cont]);
			soma = soma + lista[cont];
			qtde = qtde + 1;
			
			cont = cont + 1;
		}
		
		printf("Soma = %d   Media = %.2f\n", soma, soma / (float)qtde);
	}
	
	while (1)
	{	
		printf("Informe o valor a excluir: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		cont = 0;
		while (cont < final && numero != lista[cont])
			cont = cont + 1;
	
		if (cont == final)
			puts("Valor nao encontrado");
		else
		{	
			/* trazendo os elementos posteriores ao eliminado
				para o elemento anterior */
			while (cont < final)
			{	
				lista[cont] = lista[cont + 1];
				cont = cont + 1;
			}
			
			final = final - 1;
		}
		
		/* imprimindo os valores da lista */
		if (final == 0)
			puts("Lista vazia");
		else
		{	
			soma = 0;
			qtde = 0;
			printf("\n\n\nConteudo da lista:\n");

			cont = 0;
			while (cont != final)
			{	
				printf("%d\n", lista[cont]);
				soma = soma + lista[cont];
				qtde = qtde + 1;
			
				cont = cont + 1;
			}
		
			printf("Soma = %d   Media = %.2f\n", soma, soma / (float)qtde);
		}
	}
	
	return 0;
}
