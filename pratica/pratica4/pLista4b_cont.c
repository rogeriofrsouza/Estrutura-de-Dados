/*
	Versao inicial do programa da lista linear de números	implementada por CONTIGUIDADE.
	Faz a exclusão de elementos da lista.
	Utiliza subrotina para impressao.
	Utiliza descritor estruturado e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 50

typedef int TItem;

typedef struct regLista {
	TItem numeros[MAXIMO];
	int final, soma, qtde;
} TLista;

void ImprimeLista(TLista, char *);
void InicializaLista(TLista *);

int main(void)
{	
	int numero, cont;
	TLista lista;

	InicializaLista(&lista);
	
	while (1)
	{	
		printf("Informe o numero:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		lista.numeros[lista.final] = numero;

		/* atualizando os demais descritores da lista */
		lista.final++;
		lista.soma += numero;
		lista.qtde++;
	}

	ImprimeLista(lista, "Conteudo da lista:");
		
	while (1)
	{	
		printf("Informe o valor a excluir: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		/* Procurando o item a ser excluido */
		cont = 0;
		while (cont < lista.final && numero != lista.numeros[cont])
			cont++;
	
		if (cont == lista.final)
			puts("Valor nao encontrado\n");
		else
		{	
			/* trazendo os elementos posteriores ao eliminado para o elemento anterior */
			while (cont < lista.final)
			{
				lista.numeros[cont] = lista.numeros[cont + 1];
				cont++;
			}
			
			/* atualizando os demais descritores da lista */
			lista.final--;
			lista.soma -= numero;
			lista.qtde--;

			ImprimeLista(lista, "Novo conteudo da lista:");
		}
	}
	
	return 0;
}

void ImprimeLista(TLista lista, char *cabec)
{	
	/* imprimindo os valores da lista */
	int cont;

	if (lista.final == 0)
		puts("\nLista vazia\n");
	else
	{	
		printf("\n\n\n%s\n", cabec);

		cont = 0;
		while (cont != lista.final)
		{	
			printf("%d\n", lista.numeros[cont]);
			cont++;
		}
		
		printf("Soma = %d   Media = %.2f\n", lista.soma, lista.soma / (float)lista.qtde);
	}
}

void InicializaLista(TLista *lista)
{
	/* inicializa o conjunto de descritores da lista */
	lista->final = 0;
	lista->soma = 0;
	lista->qtde = 0;
}
