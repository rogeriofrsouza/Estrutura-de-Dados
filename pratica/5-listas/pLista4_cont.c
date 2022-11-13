/*
	Versão inicial do programa da lista linear de números	implementada por CONTIGUIDADE.
	Faz a exclusão de elementos da lista. Utiliza subrotina para impressão.
	Utiliza descritor estruturado e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE	0
#define MAXIMO 50

typedef int TItem;

typedef struct regLista
{	
	int inicio, final, qtde, soma;
	TItem vet[MAXIMO];
} TLista;

void InicializaLista(TLista *);
int IncluiItem(TLista *, TItem);
void ImprimeLista(TLista *, char *);
int ExcluiItem(TLista *, TItem);

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

void InicializaLista(TLista *lista)
{	
	lista->inicio = 0;
	lista->final = 0;
	lista->qtde = 0;
	lista->soma = 0;
}

int IncluiItem(TLista *lista, TItem valor)
{	
	/* verificando se a lista está cheia */
	if (lista->final == MAXIMO)
		return FALSE;
	
	lista->vet[lista->final] = valor;

	lista->final++;
	lista->qtde++;
	lista->soma += valor;

	return TRUE;
}

void ImprimeLista(TLista *lista, char *cabec)
{	
	int cont;

	if (lista->final == 0)
	{
		puts("\nLista vazia");
		exit(1);
	}

	printf("\n\n\n%s\n", cabec);
	cont = 0;

	while (cont != lista->final)
	{	
		printf("%d\n", lista->vet[cont]);
		cont++;
	}
	
	printf("\nSoma = %d   Média = %.2f\n", lista->soma, lista->soma / (float)lista->qtde);
}

int ExcluiItem(TLista *lista, TItem valor)
{	
	int cont;

	/* procurando o item a ser excluído */
	cont = 0;

	while (cont < lista->final && valor != lista->vet[cont])
		cont++;
	
	if (cont == lista->final)
		return FALSE;
	
	/* trazendo os elementos posteriores ao eliminado para o elemento anterior */
	while (cont < lista->final)
	{	
		lista->vet[cont] = lista->vet[cont + 1];
		cont++;
	}
	
	lista->final--;
	lista->qtde--;
	lista->soma -= valor;
	
	return TRUE;
}
