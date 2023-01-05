/* 
  Testa algoritmo genérico de ordenação bolha 
  Tipo estruturado TAluno
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct regAluno
{
  char nome[81], curso[11], email[41];
} TAluno;

void bsort_gen(int, void *, int, int (*) (void *, void *));
int ComparaAluno(void *, void *);
void * Acessa(void *, int, int);
void Troca(void *, void *, int);

int main(void)
{
  int i;
  TAluno * alunos[3], *aux;

  for (i = 0; i < 3; i++)
  {
    /* alocando estrutura e inicializando os campos */
    aux = (TAluno *) malloc(sizeof(TAluno));

    printf("\nAluno %d", i+1);
    printf("\nNome: ");
    scanf(" %80[^\n]", aux->nome);

    printf("Curso: ");
    scanf("%10s", aux->curso);

    printf("Email: ");
    scanf("%40s", aux->email);

    alunos[i] = aux;
  }

  bsort_gen(3, alunos, sizeof(TAluno *), ComparaAluno);

  printf("\nVetor ordenado:\n\n");

  for (i = 0; i < 3; i++)
  {
    printf("Aluno %d.\n", i+1);
    printf("Nome: %s\n", alunos[i]->nome);
    printf("Curso: %s\n", alunos[i]->curso);
    printf("Email: %s\n\n", alunos[i]->email);
  }

  return 0;
}

/* Ordenação bolha genérica */
void bsort_gen(int n, void *v, int tam, int (*ComparaAluno) (void *, void *))
{
  int i, j, fez_troca;

  for (i = n-1; i > 0; i--)
  {
    fez_troca = 0;

    for (j = 0; j < i; j++)
    {
      void *p1 = Acessa(v, j, tam);
      void *p2 = Acessa(v, j+1, tam);

      if (ComparaAluno(p1, p2))
      {
        Troca(p1, p2, tam);
        fez_troca = 1;
      }
    }

    if (fez_troca == 0)  /* não houve troca */
      return;
  }
}

void * Acessa(void *v, int i, int tam)
{
  char *t = (char *) v;
  t += tam * i;

  return (void *) t;
}

int ComparaAluno(void *a, void *b)
{
  TAluno **p1 = (TAluno **) a;
  TAluno **p2 = (TAluno **) b;

  TAluno *a1 = *p1;
  TAluno *a2 = *p2;

  if (strcmp(a1->nome, a2->nome) > 0)
    return 1;
  else
    return 0;
}


void Troca(void *a, void *b, int tam)
{
  char *v1 = (char *) a;
  char *v2 = (char *) b;

  for (int i = 0; i < tam; i++)
  {
    char temp = v1[i];
    v1[i] = v2[i];
    v2[i] = temp;
  }
}
