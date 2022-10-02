/*
  A Universidade Pascal é uma das mais antigas do país e precisa renovar seu edifício da biblioteca, porque depois de todos esses séculos o edifício começou a mostrar os efeitos de suportar o peso da enorme quantidade de livros que abriga.

  Para ajudar na renovação, a Associação de Antigos Alunos da Universidade decidiu organizar uma série de jantares para angariação de fundos, para os quais todos os alunos foram convidados. Estes eventos provaram ser um enorme sucesso e vários foram organizados durante o ano passado. (Uma das razões para o sucesso desta iniciativa parece ser o fato de que os alunos que passaram pelo sistema de ensino Pascal tem boas lembranças daquele tempo e gostariam de ver a Biblioteca da Universidade renovada.)

  Os organizadores mantiveram uma planilha indicando quais alunos participaram de cada jantar. Agora eles querem sua ajuda para determinar se algum aluno ou aluna participou de todos os jantares.

  Entrada
  A entrada contém vários casos de teste. A primeira linha de um caso de teste contém dois inteiros N e D, respectivamente, indicando o número de Alumni e o número de jantares (dinners em inglês) organizados (1 ≤ N ≤ 100 e 1 ≤ D ≤ 500). Alumni são identificados por inteiros de 1 a N. Cada uma das próximas D linhas descreve os participantes de um jantar, e contém N inteiros Xi indicando se o alumnus/alumna participará (Xi = 1) ou não (Xi = 0) daquele jantar. O fim da entrada é determinado por N = D = 0.

  Saída
  Para cada caso de teste da entrada seu programa deve produzir uma linha de saída, contendo ou a palavra ‘yes’, no caso de existir existe pelo menos um alumnus/alumna que participou de todas as jantares, ou a palavra ‘no’ caso contrário. A saída deve ser escrita na saída padrão.

  Alumna: um ex-aluno do sexo feminino de uma escola particular, faculdade ou universidade.
  Alumnus: um ex-aluno do sexo masculino de uma escola particular, faculdade ou universidade.
  Alumni: os ex-alunos de ambos os sexos de uma determinada escola, faculdade ou universidade.
*/
#include <stdio.h>

int main()
{
  int qtde, alumni, jantares, i, j, cont;

  printf("Qtde de casos de teste: ");
  scanf("%d", &qtde);

  while (qtde)
  {
    printf("\nNúmero de Alumni e número de jantares organizados: ");
    scanf("%d %d", &alumni, &jantares);

    if (alumni == 0 && jantares == 0)
      break;

    char mat[jantares][alumni*2];

    /* preenchendo participação dos alunos */
    printf("\nInforme se os alunos participaram (1) ou não (0) do jantar:\n");
    
    for (i = 0; i < jantares; i++)
      scanf(" %100[^\n]", mat[i]);
    
    /* calculando matriz */
    for (j = 0; j < alumni; j+=2)
    {
      cont = 0;
      for (i = 0; i < jantares; i++)
      {
        if (mat[i][j] == '1')
          cont++;
      }

      /* verificando participação aluno */
      if (cont == jantares)
        break;
    }
    if (cont == jantares)
      printf("\nyes\n");
    else
      printf("\nno\n");

    qtde--;
  }

  return 0;
}

/* gerando a matriz de jantares dinamicamente
  mat = (int *) malloc(jantares * sizeof(int *));

  gerando o vetor de alunos dinamicamente
  for (i = 0; i < jantares; i++)
    mat[i] = (int *) malloc(alumni * sizeof(int));

  preenchendo o vetor de alunos
  for (i = 0; i < jantares; i++)
  {
    for (j = 0; j < alumni; j++)
      mat[i][j] = j + 1;
  }

  for (i = 0; i < jantares; i++)  
  {
    printf("\nJantar %d\n", i + 1);

    for (j = 0; j < alumni; j++)
    {
      printf("\nAluno %d: ", j + 1);
      scanf("%d", mat[i][j]);
    }
  }
*/