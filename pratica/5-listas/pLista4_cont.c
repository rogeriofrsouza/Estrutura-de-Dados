/*
	Versao inicial do programa da lista linear de números	implementada por CONTIGUIDADE.
	Faz a exclusão de elementos da lista.
	Utiliza descritor estruturado e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE	0
#define MAXIMO 50

typedef int TItem;
typedef struct tLista
{	
	int inicio, final, qtde, soma;
	TItem lista[MAXIMO];
} TLista;

void ImprimeLista(TLista *, char *);
void InicializaLista(TLista *);
int IncluiItem(TLista *, TItem);
int ExcluiItem(TLista *, TItem);

int main(void)
{	
	int num;
	TLista descLista;
	
	InicializaLista(&descLista);

	while (TRUE)
	{	
		printf("Informe o numero:\n");
		scanf("%d", &num);

		if (num < 0)
			break;

		if (IncluiItem(&descLista, num) == FALSE)
		{	
			puts("Memoria insuficiente para esta operacao");
			return 2;
		}
	}

	ImprimeLista(&descLista, "Conteudo da lista:");
		
	while (TRUE)
	{	
		printf("Informe o valor a excluir: ");
		scanf("%d", &num);
	
		if (num < 0)
			break;
		
		if (ExcluiItem(&descLista, num) == FALSE)
			puts("\nValor nao encontrado\n\n");
		else
			ImprimeLista(&descLista, "Novo conteudo da lista:");			
	}
	
	return 0;
}

void InicializaLista(TLista *lista)
{	
	/* inicializando o conjunto de descritores da lista */
	lista->inicio = 0;
	lista->final = 0;
	lista->qtde = 0;
	lista->soma = 0;
}

void ImprimeLista(TLista *descLista, char *cabec)
{	
	/* imprimindo os valores da lista */
	int cont;

	if (descLista->final == 0)
	{
		puts("\nLista vazia");
		exit(1);
	}
	else
	{	
		printf("\n\n\n%s\n", cabec);

		cont = 0;
		while (cont != descLista->final)
		{	
			printf("%d\n", descLista->lista[cont]);
			cont++;
		}
		
		printf("Soma = %d   Media = %.2f\n", descLista->soma, descLista->soma / (float)descLista->qtde);
	}
}

int IncluiItem(TLista *descLista, TItem valor)
{	
	/* verificando se a lista está cheia */
	if (descLista->final == MAXIMO)
		return FALSE;
	
	descLista->lista[descLista->final] = valor;
	descLista->final++;
	descLista->qtde++;
	descLista->soma += valor;

	return TRUE;
}

int ExcluiItem(TLista *descLista, TItem valor)
{	
	int cont;

	/* Procurando o item a ser excluido */
	cont = 0;
	while (cont < descLista->final && valor != descLista->lista[cont])
		cont++;
	
	if (cont == descLista->final)
		return FALSE;
	
	/* trazendo os elementos posteriores ao eliminado para o elemento anterior */
	while (cont < descLista->final)
	{	
		descLista->lista[cont] = descLista->lista[cont+1];
		cont++;
	}
	
	descLista->final--;
	descLista->qtde--;
	descLista->soma -= valor;
	
	return TRUE;
}
