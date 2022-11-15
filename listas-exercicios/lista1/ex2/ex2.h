/* 
  Arquivo de INTERFACE para a implementação TDA de lista linear por CONTIGUIDADE 
*/
#define MAXIMO 10

typedef struct regCidade
{
  char nome[31];
  int pop;
  float area, pib, idh;
} TCidade;

typedef struct regLista
{
  int inicio, final;
  TCidade vet[MAXIMO];
} TLista;

/* protótipos das funções */
void InicializaLista(TLista *);
void IncluiItem(TLista *, TCidade);
void ImprimeLista(TLista *, char *, char *);
int ExcluiItem(TLista *, float);
