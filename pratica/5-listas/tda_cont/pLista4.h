/*
  Arquivo de INTERFACE para a implementação TDA de listas lineares por CONTIGUIDADE
*/
#define TRUE	1
#define FALSE	0
#define MAXIMO 50

typedef int TItem;

typedef struct regLista
{	
  int inicio, final, qtde, soma;
	TItem vet[MAXIMO];	
} TLista;

/* protótipo das funções */
void InicializaLista(TLista *);
int IncluiItem(TLista *, int);
void ImprimeLista(TLista *, char *);
int ExcluiItem(TLista *, int);
