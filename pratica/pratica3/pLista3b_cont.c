/*
	Versão inicial do programa da lista linear de números
	implementada por CONTIGUIDADE.
	Faz a exclusão de elementos da lista.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 50

typedef int TItem;
TItem lista[MAXIMO];

void imprimeLista(int f);

int main(void)
{
	int numero, final, cont;

	/* Inicializando a variável de controle do fim da lista */
	final = 0;
	
	while (1)
	{
		printf("Informe o número: ");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		lista[final] = numero;
		final++;
	}

	if (final == 0)
		puts("Lista vazia");
	else
		imprimeLista(final);
	
	/* Procurando o item a ser excluído */
	while (1)
	{
		printf("Informe o valor a excluir: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		cont = 0;
		while ((cont < final) && (numero != lista[cont]))
			cont++;
	
		if (cont == final)
			puts("Valor não encontrado\n");
		else
		{
			/* Remover o item lista[cont] */
			while (cont < final)
			{
				lista[cont] = lista[cont+1];
				
				if (cont == final-1)
					break;
				
				cont++;
			}
			final = cont;

			if (final != 0)
				imprimeLista(final);
			else
				break;
		}
	}

	return 0;
}

/* Imprimindo os valores da lista */
void imprimeLista(int f)
{
	int cont, soma, qtde;
	cont = soma = qtde = 0;

	printf("\n\n\nConteúdo da lista:\n");

	while (cont < f)
	{
		printf("%d\n", lista[cont]);
		soma += lista[cont];
		qtde++;

		cont++;
	}
	
	/* Uso do cast (float) */
	printf("Soma = %d   Média = %.2f\n", soma, soma / (float)qtde);
}
