#include<stdio.h>

int main(void)
{
  char cidade[8];
  printf("Digite uma cidade: ");
  scanf(" %8[^\n]", cidade);  /* Captura-se a linha fornecida pelo usuário até que ele tecle enter('\n'), máximo de 8 caracteres */

  printf("Você digitou: %s", cidade);

  return 0;
}