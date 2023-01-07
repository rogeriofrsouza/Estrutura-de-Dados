/*
	Algoritmo de árvore binária de busca.
	Faz a inserção e remoção de nós.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct regNo
{
	struct regNo *esq;
	int valor;
	struct regNo *dir;
} TNo;

void InsereNo(TNo **, int);
TNo * AchaPai(TNo *, int);
int ContaNos(TNo *);
void ImprimeArvore(TNo *, int);
TNo * BuscaNo(TNo *, int);
int ExcluiNo(TNo *, int );
int AchaMenor(TNo *);

int main(void)
{
	TNo *raiz = NULL;
	int num, opcao;

	printf("Informe os valores:\n");

	while (1)
	{
		scanf("%d", &num);

		if (num < 1)
			break;

    InsereNo(&raiz, num);
	}

	system("clear");  /* limpa o console */

	while (1)
	{
    printf("A árvore possui %d elementos:\n", ContaNos(raiz));
    ImprimeArvore(raiz, 0);

    /* escolhendo operação a ser executada */
		printf("\nOPERAÇÕES");
		printf("\n[1] Buscar valor");
		printf("\n[2] Inserir novo valor");
		printf("\n[3] Remover valor");
		printf("\n[0] Sair\n");

		do
		{
			scanf("%d", &opcao);
		} while (opcao > 3);
	
    if (opcao <= 0)
      break;
    
    printf("\nInforme o valor:\n");
		scanf("%d", &num);

		system("clear");

    switch (opcao)
    {
      case 1:
        if (BuscaNo(raiz, num) == NULL) 
          printf("Valor não encontrado\n\n");
        else 
          printf("Valor %d encontrado\n\n", num);

        break;
      
      case 2:
				if (num > 0)
				{
					if (BuscaNo(raiz, num) == NULL)
						InsereNo(&raiz, num);
					else
						printf("Valor já existente\n\n");
				}
				else
					printf("Informe um número inteiro positivo\n\n");

        break;
      
      case 3:
				if (ExcluiNo(raiz, num))
					printf("Valor %d excluído da árvore\n\n", num);
        break;
    }
	}
	
	return 0;
}

void InsereNo(TNo **r, int n)
{
  TNo *aux, *pai;

  /* alocando um nó dinamicamente e inicializando os campos */
  aux = (TNo *) malloc(sizeof(TNo));

  aux->esq = NULL;
  aux->valor = n;
  aux->dir = NULL;

  /* fazendo o encadeamento do novo nó */
  pai = AchaPai(*r, n);

  if (pai == NULL)
    *r = aux;
  else
  {
    if (n <= pai->valor)
      pai->esq = aux;
    else
      pai->dir = aux;
  }
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

TNo * BuscaNo(TNo *r, int n)
{
  if (r == NULL)
		return NULL;
	
	if (n < r->valor)
		return BuscaNo(r->esq, n);
	else if (n > r-> valor)
    return BuscaNo(r->dir, n);
  else
    return r;
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
