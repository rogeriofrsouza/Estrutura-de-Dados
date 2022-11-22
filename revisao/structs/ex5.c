/* 
  5) Escreva a instrução para definir um tipo de dados estruturado contendo: 
  um código numérico de tipo inteiro, um nome de pessoa de até 40 caracteres úteis, 
  a data de nascimento da pessoa (que deverá ser do tipo da struct definida no exercício 1 desta atividade),
  o sexo ('M' ou 'F') e o limite de crédito (um número real de precisão simples).
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

  cliente.codigo = 20;
  strcpy(cliente.nome, "Senhor Barriga Pançudo");

  cliente.dataNasc.dia = 05;
  cliente.dataNasc.mes = 12;
  cliente.dataNasc.ano = 2005;

  cliente.sexo = 'M';
  cliente.limiteCred = 5000.76;

  printf("Dados do cliente\n\n");
  printf("Código: %d\n", cliente.codigo);
  printf("Nome: %s\n", cliente.nome);
  printf("Data de nascimento: %hhu/%hhu/%hu\n", cliente.dataNasc.dia, 
                                                cliente.dataNasc.mes, 
                                                cliente.dataNasc.ano);
  printf("Sexo: %c\n", cliente.sexo);
  printf("Limite de crédito: R$%.2f\n", cliente.limiteCred);

  return 0;
}
