/*
	Versão inicial do programa da lista linear de números	implementada por ENCADEAMENTO.
	Faz a exclusão de elementos da lista. Utiliza subrotina para impressão.
	Utiliza descritor estruturado e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE	0

typedef struct regItem
{	
	int valor;
	struct regItem *prox;
} TItem;

typedef struct regLista
{	
	TItem *inicio, *final;
	int qtde, soma;
} TLista;

void InicializaLista(TLista *);
int IncluiItem(TLista *, int);
void ImprimeLista(TLista *, char *);
int ExcluiItem(TLista *, int);

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
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
	lista->soma = 0;
}

int IncluiItem(TLista *lista, int valor)
{	
	TItem *aux;

	/* criando uma variável TItem dinamicamente */
	aux = (TItem *) malloc(sizeof(TItem));

	if (aux == NULL)
		return FALSE;
	
	/* preenchendo os campos da variável alocada */
	aux->valor = valor;
	aux->prox = NULL;

	/* fazendo o encadeamento do novo nó da lista */
	if (lista->inicio == NULL)
		lista->inicio = aux;
	else
		lista->final->prox = aux;

	/* atualizando os demais descritores da lista */
	lista->final = aux;
	lista->qtde++;
	lista->soma += aux->valor;

	return TRUE;
}

void ImprimeLista(TLista *lista, char *cabec)
{	
	TItem *aux;
	
	if (lista->inicio == NULL)
	{
		puts("\nLista vazia");
		exit(1);
	}

	printf("\n\n\n%s\n", cabec);
	aux = lista->inicio;

	while (aux != NULL)
	{	
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
	
	printf("\nSoma = %d   Média = %.2f\n", lista->soma, lista->soma / (float)lista->qtde);
}

int ExcluiItem(TLista *lista, int valor)
{	
	TItem *aux, *ant;

	/* procurando o item a ser excluído */
	ant = NULL;
	aux = lista->inicio;

	while (aux != NULL && valor != aux->valor)
	{	
		ant = aux;
		aux = aux->prox;
	}
		
	if (aux == NULL)
		return FALSE;

	/* cuidando do encadeamento */
	if (ant == NULL)
		lista->inicio = aux->prox;
	else
		ant->prox = aux->prox;
	
	/* atualizando os demais descritores da lista */
	if (aux == lista->final)
		lista->final = ant;

	lista->qtde--;
	lista->soma -= aux->valor;
	
	/* removendo o item da lista */
	free(aux);
	
	return TRUE;
}
