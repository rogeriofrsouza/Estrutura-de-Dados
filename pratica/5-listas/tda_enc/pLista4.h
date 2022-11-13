/*
  Arquivo de INTERFACE para a implementação TDA de listas lineares por ENCADEAMENTO
*/
#define TRUE	1
#define FALSE	0

typedef struct regLista
{	
  int valor;
	struct regLista *prox;
} TItem;

typedef struct descLista
{	
  TItem *inicio, *final;
	int qtde, soma;
} TLista;

/* Protótipos das funções */
void ImprimeLista(TLista *, char *);
void InicializaLista(TLista *);
int IncluiItem(TLista *, int);
int ExcluiItem(TLista *, int);
