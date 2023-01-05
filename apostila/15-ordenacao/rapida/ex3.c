/* 
  Testa algoritmo de ordenação rápida 
  Utiliza algoritmo genérico da biblioteca padrão
  Tipo estruturado TAluno
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct regAluno
{
  char nome[81], curso[11], email[41];
} TAluno;

int ComparaAluno(const void *, const void *);

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

  qsort(alunos, 3, sizeof(TAluno *), ComparaAluno);

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

int ComparaAluno(const void *p1, const void *p2)
{
  /* convertendo ponteiros genéricos para ponteiros de ponteiros de TAluno */
  TAluno **pa1 = (TAluno **) p1;
  TAluno **pa2 = (TAluno **) p2;

  /* acessando ponteiro de TAluno */
  TAluno *a1 = *pa1;
  TAluno *a2 = *pa2;

  /* dados os ponteiros de TAluno, faz a comparação */
  return strcmp(a1->nome, a2->nome);
}
