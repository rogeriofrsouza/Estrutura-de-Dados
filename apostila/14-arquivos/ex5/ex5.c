#include <stdio.h>

int main(void) 
{
  char linha[121];
  FILE * fp;

  fp = fopen("file.txt", "wt");

  /* escrevendo linha */
  fputs("Nós estamos em 2023\nFeliz ano novo!!\n", fp);

  /* fechando arquivo */
  fclose(fp);

  fp = fopen("file.txt", "rt");

  /* lendo conteúdo do arquivo */
  while ((fscanf(fp, "%[^\n]", linha)) != EOF)
  {
    fgetc(fp); // move o ponteiro do arquivo após o '\n' caractere
    printf("%s\n", linha);
  }

  /* fechando arquivo */
  fclose(fp);
  
  return(0);
}
