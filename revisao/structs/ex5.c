/* 
  Exercício 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct regData {
  unsigned char dia, mes; 
  unsigned short int ano;
} TData;

typedef struct regCliente {
  int codigo; 
  char nome[41]; 
  TData dataNasc;
  char sexo;
  float limiteCred;
} TCliente;

int main()
{
  TCliente cliente;

  cliente.codigo = rand() % 100;
  strcpy(cliente.nome, "Senhor Barriga Pançudo");

  cliente.dataNasc.dia = 5;
  cliente.dataNasc.mes = 7;
  cliente.dataNasc.ano = 2005;

  cliente.sexo = 'M';
  cliente.limiteCred = 5000.76;

  printf("Dados do cliente\n\n");
  printf("Código: %d\n", cliente.codigo);
  printf("Nome: %s\n", cliente.nome);
  printf("Data de nascimento: %02hhu/%02hhu/%hu\n", cliente.dataNasc.dia, 
                                                    cliente.dataNasc.mes, 
                                                    cliente.dataNasc.ano);
  printf("Sexo: %c\n", cliente.sexo);
  printf("Limite de crédito: R$%.2f\n", cliente.limiteCred);

  return 0;
}
