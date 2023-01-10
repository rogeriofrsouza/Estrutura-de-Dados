/*
  Algoritmo de tabelas de dispersão (hash tables).
  Insere e busca elementos no vetor.
  Utiliza listas encadeadas para tratamento de colisões.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct regAluno 
{
  long int mat;
  char nome[81], email[41];
  struct regAluno *prox;
} TAluno;

typedef TAluno * THash[N];  /* tipo que representa a tabela de dispersão */

int VerificaTabela(THash);
void ImprimeTabela(THash);
TAluno * Busca(THash, int);
int Insere(THash, TAluno *);
int Hash(int);

int main(void)
{
  THash tab;
  TAluno aluno;
  int i, opcao;
  long int num;

  /* inicializando elementos da tabela */
  for (i = 0; i < N; i++)
    tab[i] = NULL;

  while (1)
  {
    /* escolhendo operação a ser executada */
    printf("\nOPERAÇÕES");
    printf("\n[1] Buscar aluno");
    printf("\n[2] Inserir/atualizar novo aluno");
    printf("\n[3] Exibir lista de alunos");
    printf("\n[0] Sair\n");

    do
    {
      scanf("%d", &opcao);
    } while (opcao > 3);

    if (opcao <= 0)
      break;

    system("clear");  /* limpando console */

    switch (opcao)
    {
      case 1:
        printf("Informe o número da matrícula: ");  /* 9711234 */
        scanf("%ld", &num);

        if (Busca(tab, num) != NULL)
          printf("Aluno %ld encontrado\n", num);
        else
          printf("Aluno NÃO encontrado\n");
        break;
      
      case 2:
        printf("Matrícula (7 dígitos): ");
        scanf("%ld", &aluno.mat);

        printf("Nome: ");
        scanf("%80s", aluno.nome);

        printf("Email: ");
        scanf("%40s", aluno.email);

        system("clear");

        if (Insere(tab, &aluno) == 1)
          printf("Inserido com sucesso\n");
        else
          printf("Atualizado com sucesso\n");

        break;
      
      case 3:
        if (VerificaTabela(tab))
          ImprimeTabela(tab);
        else
          printf("Lista vazia\n");
        break;
    }
  }

  return 0;
}

int VerificaTabela(THash tab)
{
  for (int i = 0; i < N; i++)
  {
    if (tab[i] != NULL)
      return 1;
  }

  return 0;
}

void ImprimeTabela(THash tab)
{
  for (int i = 0; i < N; i++)
  {
    if (tab[i] != NULL)
      printf("%ld | %s | %s\n", tab[i]->mat, tab[i]->nome, tab[i]->email);
  }
}

TAluno * Busca(THash tab, int mat)
{
  int h = Hash(mat);
  TAluno *a = tab[h];

  while (a != NULL)
  {
    if (a->mat == mat)
      return a;

    a = a->prox;
  }

  return NULL;
}

int Insere(THash tab, TAluno *a)
{
  int h, cont;
  TAluno *p = NULL, *aux;

  h = Hash(a->mat);
  aux = tab[h];

  while (aux != NULL)
  {
    if (aux->mat == a->mat)
      break;
    
    p = aux;
    aux = aux->prox;
  }

  if (aux == NULL)  /* não encontrou o elemento */
  {
    aux = (TAluno *) malloc(sizeof(TAluno));
    aux->mat = a->mat;
    aux->prox = NULL;

    /* cuidando do encadeamento */
    if (p == NULL)
      tab[h] = aux;
    else
      p->prox = aux;
    
    cont = 1;
  }
  else
    cont = 2;

  /* atribuindo informações */
  strcpy(tab[h]->nome, a->nome);
  strcpy(tab[h]->email, a->email);

  return cont;
}

int Hash(int mat)
{
  return mat % N;
}
