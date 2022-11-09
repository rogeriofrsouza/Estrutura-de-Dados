/* 
  Arquivo de INTERFACE para a implementação TDA de lista linear por ENCADEAMENTO 
*/
typedef struct cidade
{
  char nome[31];
  int pop;
  float area, pib, idh;
} Cidade;

typedef struct no
{
  Cidade *info;
  struct no *prox, *ant;
} No;

typedef struct lista
{
  No *inicio, *final;
} Lista;

/* Protótipos das funções */
void InicializaLista(Lista *);
void IncluiItem(Lista *, Cidade);
void ImprimeLista(Lista *, char *);
void ImprimeCidade(No *aux);
int ExcluiItem(Lista *, float);
