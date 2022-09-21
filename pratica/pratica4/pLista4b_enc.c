/*
	Versao inicial do programa da lista linear de números	implementada por ENCADEAMENTO.
	Faz a exclusão de elementos da lista.
	Utiliza subrotina para impressao.
	Utiliza descritor estruturado e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct regLista {
	int valor; 
	struct regLista *prox;
} TItem;

typedef struct lista {
	TItem *inicio, *final; 
	int qtde, soma;
} TLista;

void ImprimeLista(TLista, char *);
void InicializaLista(TLista *);

int main(void)
{	
	int numero;
	TItem *aux, *ant;
	TLista lista;

	InicializaLista(&lista);
	
	while (1)
	{	
		printf("Informe o numero:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		/* criando uma variável struct regLista dinamicamente */
		aux = (TItem *) malloc(sizeof(TItem));

		if (aux == NULL)
		{	
			puts("Memoria insuficiente para esta operacao");
			return 2;
		}
		
		/* preenchendo os campos da variável criada dinamicamente */
		aux->valor = numero;
		aux->prox = NULL;

		/* fazendo o encadeamento do novo nó da lista */
		if (lista.inicio == NULL)
			lista.inicio = aux;
		else
			lista.final->prox = aux;

		/* atualizando os demais descritores da lista */
		lista.final = aux;
		lista.soma += aux->valor;
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
		ant = NULL;
		aux = lista.inicio;
		while (aux != NULL && numero != aux->valor)
		{	
			ant = aux;
			aux = aux->prox;
		}
		
		if (aux == NULL)
			puts("Valor nao encontrado");
		else
		{	
			/* Cuidando do encadeamento */
			if (ant == NULL)
				lista.inicio = aux->prox;
			else
				ant->prox = aux->prox;
			
			/* Atualizando os demais descritores da lista */
			lista.qtde--;
			lista.soma -= aux->valor;
			
			if (aux == lista.final)
				lista.final = ant;
			
			/* Removendo o item da lista */
			free(aux);

			ImprimeLista(lista, "Novo conteudo da lista:");
		}
	}
	
	return 0;
}

void ImprimeLista(TLista lista, char * cabec)
{	
	/* imprimindo os valores da lista */
	TItem *aux;
	
	if (lista.inicio == NULL)
		puts("Lista vazia");
	else
	{	
		printf("\n\n\n%s\n", cabec);
		aux = lista.inicio;

		while (aux != NULL)
		{	
			printf("%d\n", aux->valor);
			
			aux = aux->prox;
		}
		
		printf("Soma = %d   Media = %.2f\n", lista.soma, lista.soma / (float)lista.qtde);
	}
}

void InicializaLista(TLista *lista)
{	
	/* inicializa o conjunto de descritores da lista */
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
	lista->soma = 0;
}
