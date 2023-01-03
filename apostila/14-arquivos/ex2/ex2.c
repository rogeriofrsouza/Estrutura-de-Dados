/* Converte arquivo para maiúsculas */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int c;
  char entrada[121], saida[121];
  FILE *e, *s;

  /* pedindo ao usuário os nomes dos arquivos */
  printf("Digite o nome do arquivo de entrada: ");
  scanf("%120s", entrada);

  printf("Digite o nome do arquivo de saída: ");
  scanf("%120s", saida);

  /* abrindo arquivos para leitura e para escrita */
  e = fopen(entrada, "rt");

  if (e == NULL)
  {
    printf("Não foi possível abrir arquivo de entrada");
    return 1;
  }

  s = fopen(saida, "wt");

  if (s == NULL)
  {
    printf("Não foi possível abrir arquivo de saída");
    fclose(e);
    return 1;
  }

  /* lendo entrada e escrevendo na saída */
  while ((c = fgetc(e)) != EOF)
    fputc(toupper(c), s);
  
  /* fechando arquivos */
  fclose(e);
  fclose(s);

  return 0;
}
