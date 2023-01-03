/* Procura ocorrência de sub-cadeia no arquivo */

#include <stdio.h>
#include <string.h>

int main(void)
{
  int n = 0, achou = 0;
  char entrada[121], subcadeia[121], linha[121];
  FILE *fp;

  /* pedindo ao usuário o nome do arquivo e a sub-cadeia */
  printf("Digite o nome do arquivo de entrada: ");
  scanf("%120s", entrada);

  printf("Digite a sub-cadeia: ");
  scanf("%120s", subcadeia);

  /* abrindo arquivo para leitura */
  fp = fopen(entrada, "rt");

  if (fp == NULL)
  {
    printf("Não foi possível abrir arquivo");
    return 1;
  }

  /* lendo linha a linha */
  while (fgets(linha, 121, fp) != NULL)
  {
    n++;

    if (strstr(linha, subcadeia) != NULL)
    {
      achou = 1;
      break;
    }
  }

  /* fechando arquivo */
  fclose(fp);

  /* exibindo saída */
  if (achou)
    printf("Achou na linha %d", n);
  else
    printf("Não achou");

  return 0;
}
