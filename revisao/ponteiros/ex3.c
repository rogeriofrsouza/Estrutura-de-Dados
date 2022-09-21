// 3) Considerando as definições em C apresentadas a seguir, faça testes em programas e responda às questões formuladas.

#include<stdio.h>

int main() 
{
  float valores[10], *p;

  p = &valores[0];
  printf("%p %p\n", valores, p);
  
  p = valores;
  printf("%p %p\n", valores, p);
  
  p = &valores[1];
  printf("%x %p\n", p - valores, p);
  
  p = &valores[6];
  printf("%x %p\n", p - valores, p);

  return 0;
}

/* 
  a) O que significa mencionar, no código de um programa, apenas o nome de um vetor já declarado?
  R: O endereço de memória do seu primeiro byte;

  b) O que acontece se, ao final das instruções anteriores, fizermos (*p) = 15 ?
  R: Atribuiremos o valor 15 no índice 6 do array apontado pelo ponteiro p;

  c) Qual o significado do resultado impresso no primeiro valor do último printf() do código?
  R: O índice 6 do array;
*/