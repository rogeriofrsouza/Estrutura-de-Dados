/*
	Programa de construção e impressão de uma árvore binária ordenada.
	É o mesmo programa existente em 66_ED-Arvores.pdf
	Faz a exclusão de nós.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct regNo
{
	struct regNo *esq;
	int valor;
	struct regNo *dir;
} TNo;

TNo * AchaPai(TNo *, int);
int ContaNos(TNo *);
void ImprimeArvore(TNo *, int);
int SomaNos(TNo *);
int ContaPares(TNo *);
int ExcluiNo(TNo *, int );
int AchaMenor(TNo *);

int main(void)
{
	TNo *raiz = NULL, *aux, *pai;
	int numero;

	printf("Informe os valores:\n");

	while (1)
	{
		scanf("%d", &numero);

		if (numero < 1)
			break;

		/* alocando um nó dinamicamente e inicializando os campos */
		aux = (TNo *) malloc(sizeof(TNo));

		aux->esq = NULL;
		aux->valor = numero;
		aux->dir = NULL;

		/* fazendo o encadeamento do novo nó */
		pai = AchaPai(raiz, numero);

		if (pai == NULL)
			raiz = aux;
		else
		{
			if (numero <= pai->valor)
				pai->esq = aux;
			else
				pai->dir = aux;
		}
	}
	
	printf("\n\nA árvore possui %d elementos:\n", ContaNos(raiz));
	ImprimeArvore(raiz, 0);

	printf("\n\nSoma: %d", SomaNos(raiz));
	printf("\nPares: %d\n\n", ContaPares(raiz));

	while (1)
	{
		printf("\nInforme o valor a excluir:\n");
		scanf("%d", &numero);

		if (numero < 1)
			break;

		if (ExcluiNo(raiz, numero) == 0)
			printf("\nValor não encontrado");
		else
		{
			printf("\nValor %d excluído da árvore\n", numero);

			if (ContaNos(raiz) == 0)
				break;

			ImprimeArvore(raiz, 0);
		}
	}
	
	return 0;
}

TNo * AchaPai(TNo *r, int n)
{
	if (r == NULL)
		return NULL;
	
	if (n <= r->valor)
	{
		/* n é descendente do lado esquerdo de r */
		if (r->esq == NULL)
			return r;
		else
			return AchaPai(r->esq, n);
	}
	else
	{
		/* n é descendente do lado direito de r */
		if (r->dir == NULL)
			return r;
		else
			return AchaPai(r->dir, n);
	}
}

int ContaNos(TNo *r)
{
	if (r == NULL)
		return 0;
	else
		return 1 + ContaNos(r->esq) + ContaNos(r->dir);
}

void ImprimeArvore(TNo *r, int n)
{
	int c;

	if (r != NULL)
	{
		/* in-order */
		ImprimeArvore(r->esq, n + 1);

		for (c = 0; c < n; c++)
			printf("\t");

		printf("%d\n", r->valor);

		ImprimeArvore(r->dir, n + 1);
	}
}

int SomaNos(TNo *r)
{
	if (r == NULL)
		return 0;
	else
		return r->valor + SomaNos(r->esq) + SomaNos(r->dir);
}

int ContaPares(TNo *r)
{
	if (r == NULL)
		return 0;
	else
		return (r->valor % 2 == 0) + ContaPares(r->esq) + ContaPares(r->dir);
}

int ExcluiNo(TNo *r, int n)
{
	TNo *ant = NULL;
	int aux;
	
	while (r != NULL && n != r->valor)
	{
		ant = r;

		if (n < r->valor)
		{
			/* n é descendente do lado esquerdo de r */
			r = r->esq;
		}
		else
		{
			/* n é descendente do lado direito de r */
			r = r->dir;
		}
	}

	if (r == NULL)
		return 0;

	/* 1. excluindo uma folha */
	if (r->esq == NULL && r->dir == NULL)
	{
		if (ant != NULL)
		{
			if (r->valor <= ant->valor)
				ant->esq = NULL;
			else
				ant->dir = NULL;
		}
	}
	/* 2. excluindo nó com dois descendentes */
	else if (r->esq != NULL && r->dir != NULL)
	{
		aux = AchaMenor(r->dir);

		if (ExcluiNo(r, aux))
		{
			r->valor = aux;
			return 2;
		}
	}
	/* 3. excluindo nó com um descendente */
	else
	{
		if (ant != NULL)
		{
			
			if (r->valor <= ant->valor)
			{
				/* r descendente do lado esquerdo */
				ant->esq = r->esq != NULL ? r->esq : r->dir;
			}
			else
			{
				/* r descendente do lado direito */
				ant->dir = r->esq != NULL ? r->esq : r->dir;
			}
		}
		/* últimos 2 nós da árvore */
		else
		{
			ant = r;
			
			if (ant->esq != NULL)
			{
				r = ant->esq;
				ant->esq = NULL;
			}
			else
			{
				r = ant->dir;
				ant->dir = NULL;
			}

			ant->valor = r->valor;
		}
	}

	/* excluindo nó da árvore */
	free(r);
	
	return 1;
}

int AchaMenor(TNo *r)
{
	if (r->esq == NULL)
		return r->valor;
	else
		return AchaMenor(r->esq);
}
