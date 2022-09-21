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

int main(void)
{	
	int numero;
	struct regLista *inicio, *aux, *ant;

	/* inicializando a variável inicio com um endereco vazio */
	inicio = NULL;
	while (1)
	{	
		printf("Informe o numero:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		/* criando uma variável struct regLista dinamicamente */
		aux = (struct regLista *) malloc(sizeof(struct regLista));

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
	printf("\n\n\nConteudo da lista:\n");
	aux = inicio;
	while (aux != NULL)
	{	
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
	
	return 0;
}
