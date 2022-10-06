/* 
  6) Para a variável clientes desenhada a seguir, e cuja definição se encontra especificada no código em C fornecido, 
  escreva as instruções capazes de atribuir todos os valores indicados na figura.
*/
#include <stdio.h>
#include <string.h>
  
typedef struct data {
  unsigned char dia, mes; 
  unsigned short int ano;
} TData;

typedef struct cliente {
  int cod; 
  char nome[51]; 
  TData dtUltCompra; 
  float vrTotal; 
  int qtdes[3];
} TCliente;

int main() 
{
  TCliente clientes[20];

  for (int i = 0; i < 20; i++) 
    for (int j = 0; j < 3; j++)
      clientes[i].qtdes[j] = 0;

  clientes[0].cod = 2293;
  strcpy(clientes[0].nome, "João da Silva");

  clientes[0].dtUltCompra.dia = 10;
  clientes[0].dtUltCompra.mes = 3;
  clientes[0].dtUltCompra.ano = 2018;
  
  clientes[0].vrTotal = 525.45;
  clientes[0].qtdes[0] = 10;
  clientes[0].qtdes[1] = 25;
  clientes[0].qtdes[2] = 18;

  return 0;
}
