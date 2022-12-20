/* 
  Exercício 6
*/
#include <stdio.h>
#include <string.h>
  
typedef struct regData {
  unsigned char dia, mes; 
  unsigned short int ano;
} TData;

typedef struct regCliente {
  int codigo; 
  char nome[51]; 
  TData dtUltCompra; 
  float vrTotal; 
  int qtdes[3];
} TCliente;

int main() 
{
  TCliente clientes[20];
  int i, j;

  for (i = 0; i < 20; i++)
  {
    for (j = 0; j < 3; j++)
      clientes[i].qtdes[j] = 0;
  }

  clientes[0].codigo = 2293;
  strcpy(clientes[0].nome, "João da Silva");

  clientes[0].dtUltCompra.dia = 10;
  clientes[0].dtUltCompra.mes = 3;
  clientes[0].dtUltCompra.ano = 2018;
  
  clientes[0].vrTotal = 525.45;
  clientes[0].qtdes[0] = 10;
  clientes[0].qtdes[1] = 25;
  clientes[0].qtdes[2] = 18;

  clientes[5].qtdes[1] = 296;

  clientes[7].codigo = 4597;

  clientes[9].vrTotal = 1986.89;

  strcpy(clientes[11].nome, "Maria da Silva");

  clientes[12].dtUltCompra.mes = 10;
  
  clientes[13].qtdes[0] = 482;

  clientes[14].dtUltCompra.dia = 6;

  clientes[16].dtUltCompra.ano = 2015;
  clientes[16].qtdes[2] = 515;

  return 0;
}
