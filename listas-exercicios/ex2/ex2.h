/* 
  Arquivo de INTERFACE para a implementação TDA de lista linear por CONTIGUIDADE 
*/
#define MAXIMO 10

typedef struct cidade
{
  char nome[31];
  int pop;
  float area, pib, idh;
} Cidade;

typedef struct lista
{
  int inicio, final;
  Cidade vet[MAXIMO];
} Lista;

/* Protótipos das funções */
void InicializaLista(Lista *);
void IncluiItem(Lista *, Cidade);
void ImprimeLista(Lista *, char *);
int ExcluiItem(Lista *, float);
