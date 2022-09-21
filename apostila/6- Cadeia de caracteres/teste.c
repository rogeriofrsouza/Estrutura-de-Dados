#include<stdio.h>

int main(void)
{
  char a;
  printf("Digite um caractere: ");
  scanf(" %c", &a);

  printf("Você digitou: %c", a);  /* O branco no formato pula brancos da entrada */

  return 0;
}