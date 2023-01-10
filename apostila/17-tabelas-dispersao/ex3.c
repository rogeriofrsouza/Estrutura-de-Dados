/*
  Algoritmo de tabelas de dispersão (hash tables).
  Registra o número de ocorrências de palavras.
  Utiliza listas encadeadas para tratamento de colisões.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NPAL 64   /* dimensão máxima de cada palavra */
#define NTAB 127  /* dimensão máxima de dispersão */

/* tipo que representa cada palavra */
typedef struct regPalavra 
{
  char palavra[NPAL];
  int n;
  struct regPalavra *prox;
} TPalavra;

/* tipo que representa a tabela de dispersão */
typedef TPalavra * THash[NTAB];

int LePalavra(FILE *, char *);
TPalavra * Acessa(THash, char *);
int Hash(char *);
void Imprime(THash);
int ContaElems(THash);
TPalavra ** CriaVetor(int, THash);
int Compara(const void *, const void *);

int main(int argc, char **argv)
{
  FILE *fp;
  THash tab;
  char s[NPAL];
  int i;

  if (argc != 2)
  {
    printf("Arquivo de entrada não fornecido");
    return 1;
  }

  /* abrindo arquivo para leitura */
  fp = fopen(argv[1], "rt");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo");
    return 2;
  }

  /* inicializando elementos da tabela */
  for (i = 0; i < NTAB; i++)
    tab[i] = NULL;

  /* contando ocorrência das palavras */
  while (LePalavra(fp, s))
  {
    TPalavra *p = Acessa(tab, s);
    p->n++;
  }

  /* Imprimindo ordenado */
  Imprime(tab);

  return 0;
}

int LePalavra(FILE * fp, char *s)
{
  int i = 0, c;

  /* pula caracteres não letras */
  while ((c = fgetc(fp)) != EOF)
  {
    if (isalpha(c))
      break;
  }

  if (c == EOF)
    return 0;
  
  s[i++] = c;  /* primeira letra já foi capturada */

  /* lê os próximos caracteres que são letras */
  while (i < NPAL-1 && (c = fgetc(fp)) != EOF && isalpha(c))
    s[i++] = c;
  
  s[i] = '\0';

  return 1;
}

TPalavra * Acessa(THash tab, char *s)
{
  int h = Hash(s);
  TPalavra *p;

  for (p = tab[h]; p != NULL; p = p->prox)
  {
    if (strcmp(p->palavra, s) == 0)
      return p;
  }

  /* insere nova palavra no início da lista */
  p = (TPalavra *) malloc(sizeof(TPalavra));

  strcpy(p->palavra, s);
  p->n = 0;
  p->prox = tab[h];

  /* cuidando do encadeamento */
  tab[h] = p;

  return p;
}

int Hash(char *s)
{
  int i, total = 0;

  for (i = 0; s[i] != '\0'; i++)
    total += s[i];
  
  return total % NTAB;
}

void Imprime(THash tab)
{
  int i, n;
  TPalavra **vet;

  /* criando e ordenando vetor */
  n = ContaElems(tab);
  vet = CriaVetor(n, tab);
  qsort(vet, n, sizeof(TPalavra *), Compara);

  /* imprimindo ocorrências */
  for (i = 0; i < n; i++)
    printf("%s = %d\n", vet[i]->palavra, vet[i]->n);
  
  /* liberando vetor */
  free(vet);
}

int ContaElems(THash tab)
{
  int i, total = 0;
  TPalavra *p;

  for (i = 0; i < NTAB; i++)
  {
    for (p = tab[i]; p != NULL; p = p->prox)
      total++;
  }

  return total;
}

TPalavra ** CriaVetor(int n, THash tab)
{
  int i, j = 0;
  TPalavra *p;

  TPalavra **vet = (TPalavra **) malloc(n*sizeof(TPalavra *));

  /* percorre tabela preenchendo vetor */
  for (i = 0; i < NTAB; i++)
  {
    for (p = tab[i]; p != NULL; p = p->prox)
      vet[j++] = p;
  }

  return vet;
}

int Compara(const void *v1, const void *v2)
{
  TPalavra **pp1 = (TPalavra **) v1;
  TPalavra **pp2 = (TPalavra **) v2;
  TPalavra *p1 = *pp1;
  TPalavra *p2 = *pp2;

  if (p1->n > p2->n) return -1;
  else if (p1->n < p2->n) return 1;
  else return strcmp(p1->palavra, p2->palavra);
}
