/*
	Programa de construção e impressão de uma árvore binária ordenada.
	É o mesmo programa existente em 66_ED-Arvores.pdf
*/
#include <stdio.h>
#include <stdlib.h>

struct regNo
{
	struct regNo *esq;
	int valor;
	struct regNo *dir;
};
typedef struct regNo TNo;

TNo * AchaPai(TNo *, int);
void ImprimeArvore(TNo *, int);
int ContaNos(TNo *);
int SomaNos(TNo *);
int ContaPares(TNo *);

int main(void)
{
	TNo *raiz = NULL, *aux, *pai;
	int num;

	while (1)
	{
		printf("\nInforme o valor:\n");
		scanf("%d", &num);

		if (num < 0) break;
		
		/* alocando um nó dinamicamente e inicializando os campos */
		aux = (TNo *) malloc(sizeof(TNo));
		aux->esq = NULL;
		aux->valor = num;
		aux->dir = NULL;

		/* fazendo o encadeamento do novo nó */
		pai = AchaPai(raiz, num);

		if (pai == NULL)
			raiz = aux;
		else
		{
			if (num <= pai->valor)
				pai->esq = aux;
			else
				pai->dir = aux;
		}
	}
	
	printf("\n\nA árvore possui %d elementos:\n", ContaNos(raiz));
	ImprimeArvore(raiz, 0);
	
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
		for (c = 0; c < n; c++) 
			printf("\t");

		printf("%d\n", r->valor);
		ImprimeArvore(r->esq, n + 1);
		ImprimeArvore(r->dir, n + 1);
	}
}
