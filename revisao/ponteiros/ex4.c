/* 
  4) Dado o seguinte programa escrito em C: 
  Qual é a resposta que será impressa na tela?
*/
#include <stdio.h>

int main()
{ 
  int n[] = {7, 8, 9}, *p;

  p = &n[0];
  p++;

  printf("Valor: %d\n", *p);  // 8
  (*p)++;
  printf("Valor: %d", *p);  // 9

  /* n = {7, 9, 9} */

  return 0;
}
