/* Conta número de linhas de um arquivo */

#include <stdio.h>

int main(void)
{
  int c, nlinhas = 1;
  FILE *fp;

  /* abrindo arquivo para leitura */
  fp = fopen("entrada.txt", "rt");

  if (fp == NULL)
  {
    printf("Não foi possível abrir arquivo");
    return 1;
  }

  /* lendo caractere a caractere */
  while ((c = fgetc(fp)) != EOF)
  {
    if (c == '\n') 
      nlinhas++;
  }

  /* fechando arquivo */
  fclose(fp);

  /* exibindo resultado na tela */
  printf("Número de linhas = %d", nlinhas);

  return 0;
}
