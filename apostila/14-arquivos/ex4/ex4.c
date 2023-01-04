/* Interpreta linhas de um arquivo */

#include <stdio.h>
#include <math.h>

int main(void)
{
  char c, linha[121];
  float v1, v2, area;
  FILE *fp;

  fp = fopen("file.txt", "rt");

  while (fgets(linha, 121, fp))
  {
    int n = sscanf(linha, " %c %f %f", &c, &v1, &v2);

    if (n > 0)
    {
      area = 0.0;

      switch (c)
      {
        case '#':
          /* desprezar linha de comentário */
          break;

        case 'r':
          if (n != 3)
            printf("\nErro de formato do arquivo - Retângulo");
          else
            area = v1 * v2;
          break;

        case 't':
          if (n != 3) 
            printf("\nErro de formato do arquivo - Triângulo");
          else
           area = (v1 * v2) / 2;
          break;

        case 'c':
          if (n != 2)
            printf("\nErro de formato do arquivo - Círculo");
          else
            area = 3.14159 * pow((double) v1, (double) 2);
          break;

        default:
          printf("\nErro de formato do arquivo - Não foi encontrado um polígono");
      }   

      if (area != 0.0)
        printf("\nÁrea do polígono %c = %.2f", c, area);
    }
  }

  return 0;
}
