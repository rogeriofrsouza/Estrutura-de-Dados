/*
  Arquivo de INTERFACE para a implementação TDA de listas lineares por CONTIGUIDADE
*/
#define TRUE	1
#define FALSE	0
#define MAXIMO	50

typedef int TItem;

typedef struct
{	
  int inicio, final, qtde, soma;
	TItem lista[MAXIMO];	
} TLista;

/* Protótipo das funções */
void ImprimeLista(TLista *, char *);
void InicializaLista(TLista *);
int IncluiItem(TLista *, int);
int ExcluiItem(TLista *, int);
