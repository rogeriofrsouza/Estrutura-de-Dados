/* 
  Exercício 4
*/
#include <stdio.h>

int main()
{ 
  int n[] = {7, 8, 9}, *p;

  p = &n[0];
  p++;

  printf("Valor: %d\n", *p);
  (*p)++;
  printf("Valor: %d", *p);

  /* n = {7, 9, 9} */

  return 0;
}
