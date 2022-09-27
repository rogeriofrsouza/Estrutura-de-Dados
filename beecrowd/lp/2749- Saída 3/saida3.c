/*
  O seu professor de programação gostaria de fazer uma tela com as seguintes características:

  1- Ter 39 traços (-) na primeira linha;
  2- Ter uma | embaixo do primeiro traço e do trigésimo nono traço da primeira linha, embaixo do 2o traço deve começar a escrever "x = 35" e o restante preencher com espaço em branco;
  3- Ter uma | embaixo do primeiro traço e do trigésimo nono traço da primeira linha, preencher no meio com espaço em branco;
  4- Ter uma | embaixo do primeiro traço e do trigésimo nono traço da primeira linha, embaixo do 17o traço deve começar a escrever "x = 35" e o restante preencher com espaço em branco;
  Repita o procedimento 3;
  5- Ter uma | embaixo do primeiro traço e do trigésimo nono traço da primeira linha, embaixo do 33o traço deve começar a escrever "x = 35" e o restante preencher no meio com espaço em branco;
  Repita o procedimento 1.
*/
#include <stdio.h>

/* protótipo das funções */
void ImprimeBorda();
void ImprimeVariavel(int);
void ImprimeEspacos();

int main() 
{
  /* primeira linha */
  ImprimeBorda();

  /* segunda linha */
  ImprimeVariavel(1);

  /* terceira linha */
  ImprimeEspacos();

  /* quarta linha */
  ImprimeVariavel(16);

  /* quinta linha */
  ImprimeEspacos();

  /* sexta linha */
  ImprimeVariavel(32);

  /* primeira linha */
  ImprimeBorda();

  return 0;
}

void ImprimeBorda()
{
  int i;

  for (i = 0; i < 39; i++)
    printf("-");
  
  printf("\n");
}

void ImprimeVariavel(int x)
{
  int i;

  for (i = 0; i < 39; i++)
  {
    if (i == 0 || i == 38)
      printf("|");
    else if (i == x)
    {
      printf("x = 35");
      i = x + 5;
    }
    else
      printf(" ");
  }

  printf("\n");
}

void ImprimeEspacos()
{
  int i;

  for (i = 0; i < 39; i++)
  {
    if (i == 0 || i == 38)
      printf("|");
    else
      printf(" ");
  }

  printf("\n");
}
