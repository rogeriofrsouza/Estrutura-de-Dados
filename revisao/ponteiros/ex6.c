/* 
  Exercício 6 
*/
#include <stdio.h>

int main()
{
  float **c, **b, *a, valor;

  valor = 293.04;
  a = &valor;
  b = &a;
  c = &b;

  printf("Valor: %f\na: %p\nb: %p\nc: %p", *a, a, b, c);

  return 0;
}
