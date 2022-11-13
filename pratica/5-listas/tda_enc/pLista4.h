/*
  Arquivo de INTERFACE para a implementação TDA de listas lineares por ENCADEAMENTO
*/
#define TRUE 1
#define FALSE	0

typedef struct regItem
{	
  int valor;
	struct regItem *prox;
} TItem;

typedef struct regLista
{	
  TItem *inicio, *final;
	int qtde, soma;
} TLista;

/* protótipos das funções */
void InicializaLista(TLista *);
int IncluiItem(TLista *, int);
void ImprimeLista(TLista *, char *);
int ExcluiItem(TLista *, int);
