/* 2) Supondo o par de instruções a seguir, desenhe a variável vDados. */
#include <stdio.h>

struct regDados 
{
  int codigo;
  float preco;
  long long int id;
  int qtde;
};

int main() 
{
  struct regDados vDados;

  vDados.codigo = 123;
  vDados.preco = 1875.98;
  vDados.id = 1234567890;
  vDados.qtde = 25;

  return 0; 
}
