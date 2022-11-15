/* 
  Arquivo de INTERFACE para a implementação TDA de lista linear por ENCADEAMENTO 
*/
typedef struct regCidade
{
  char nome[31];
  int pop;
  float area, pib, idh;
} TCidade;

typedef struct regNo
{
  TCidade *info;
  struct regNo *prox, *ant;
} TNo;

typedef struct regLista
{
  TNo *inicio, *final;
} TLista;

/* protótipos das funções */
void InicializaLista(TLista *);
void IncluiItem(TLista *, TCidade);
void ImprimeLista(TLista *, char *, char *);
int ExcluiItem(TLista *, float);
