#include <stdio.h>

struct regLista {
	int valor; 
	struct regLista *prox;
};

int main(void)
{
	int numero;
	struct regLista *inicio, *aux, *ant;
	
	/* Inicializando a variável início com um endereço vazio */
	inicio = NULL;

	while (1)
	{
		printf("Informe o número:\n");
		scanf("%d", &numero);
		
		if (numero < 0)
			break;
		
		/* Criando uma variável struct regLista dinamicamente*/
		aux = (struct regLista *) malloc(sizeof(struct regLista));
		
		/* Preenchendo os campos da variável criada dinamicamente*/
		aux->valor = numero;
		aux->prox = NULL;
		
		/* Fazendo o encadeamento do novo nó da lista */
		if (inicio == NULL)
			inicio = aux;
		else
			ant->prox = aux;
		
		ant = aux;
	}
			
	/* Imprimindo os valores da lista */
	printf("\n\n\nConteúdo da lista:\n");
	aux = inicio;
		
	while (aux != NULL)
	{
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
	
	return 0;
}