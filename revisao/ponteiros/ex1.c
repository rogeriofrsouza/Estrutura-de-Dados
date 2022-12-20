/* 
  Exercício 1 
*/
#include <stdio.h>

int main() 
{
  double valor, *p2;
  char letra, *p1;

  valor = 10.25;
  letra = 'C';

  p1 = &letra;
  p2 = &valor;
  *p1 = 'H';

  printf("%c\n", *p1);
  printf("%lf", *p2);
  
  return 0;
}
