// 6) Escreva as instruções necessárias em linguagem C para produzir a situação apresentada na figura.

#include<stdio.h>

int main(void) 
{
  float valor, *a, *b, *c;

  valor = 293.04;
  a = &valor;
  b = a;
  c = b;

  printf("A: %f\n", *a);
  printf("C: %f", *c);
}