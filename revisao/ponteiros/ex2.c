/* 
  Exercício 2 
*/
#include <stdio.h>

struct regDados 
{
  int quantidade; 
  float valor;
};

int main() 
{
  int comprimento, *pin;
  float altura, *pfl;
  struct regDados vDado, *pDado;

  comprimento = 25;
  pfl = &altura;
  *pfl = 32.87;

  pDado = &vDado;
  pin = &vDado.quantidade;
  pfl = &vDado.valor;

  vDado.quantidade = 15;
  pDado->valor = (*pDado).quantidade * 4.85;

  printf("Comprimento: %d\n", comprimento);
  printf("Altura: %f\n", altura);
  printf("regDados - quantidade: %d\n", *pin);
  printf("regDados - valor: %f", *pfl);

  return 0;
}
