/*
	Versao inicial do programa da lista linear de números
	implementada por ENCADEAMENTO.
	É a mesma versão encontrada no arquivo 63_ED-ListasLineares.pdf
*/
#include <stdio.h>
#include <stdlib.h>

struct regLista {
	int valor;	
	struct regLista *prox;
};
typedef struct regLista TItem;

int main(void)
{
	int numero, qtde, soma;
	TItem *inicio, *aux, *ant;

	/* inicializando a variável inicio com um endereco vazio */
	inicio = NULL;
	while (1)
	{	
		printf("Informe o numero:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		/* criando uma variável struct regLista dinamicamente */
		aux = (TItem *) malloc(sizeof(TItem));

		/* preenchendo os campos da variável criada dinamicamente */
		aux->valor = numero;
		aux->prox = NULL;

		/* fazendo o encadeamento do novo nó da lista */
		if (inicio == NULL)
			inicio = aux;
		else
			ant->prox = aux;

		ant = aux;
	}

	/* imprimindo os valores da lista */
	if (inicio == NULL)
		puts("Lista vazia");
	else
	{	
		soma = 0;
		qtde = 0;
		printf("\n\n\nConteudo da lista:\n");
		aux = inicio;

		while (aux != NULL)
		{	
			printf("%d\n", aux->valor);
			soma = soma + aux->valor;
			qtde = qtde + 1;
			
			aux = aux->prox;
		}
		
		printf("Soma = %d   Media = %.2f\n", soma, soma / (float)qtde);
	}
	
	while (1)
	{	
		printf("Informe o valor a pesquisar: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		aux = inicio;
		while (aux != NULL && numero != aux->valor)
			aux = aux->prox;
	
		if (aux == NULL)
			puts("Valor nao encontrado");
		else
			puts("Valor existe na lista");
	}
	
	return 0;
}
