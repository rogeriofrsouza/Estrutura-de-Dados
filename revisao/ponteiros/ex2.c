// 2) Suponha que um programa declara as variáveis e faz atribuições conforme as instruções a seguir. Desenhe as variáveis com os seus respectivos conteúdos finais.

#include<stdio.h>

int main() 
{
  int comprimento, *pin;
  float altura, *pfl;
  struct regDados {int quantidade; float valor;} vDado, *pDado;

  comprimento = 25;
  pfl = &altura;
  *pfl = 32.87;

  pDado = &vDado;
  pin = &vDado.quantidade;
  pfl = &vDado.valor;

  vDado.quantidade = 15;
  pDado->valor = (*pDado).quantidade * 4.85;

  printf("Comprimento: %d\n", comprimento);  // 25
  printf("Altura: %f\n", altura);  // 32.87
  printf("regDados - quantidade: %d\n", *pin);  // 15
  printf("regDados - valor: %f", *pfl);  // 72,75

  return 0;
}