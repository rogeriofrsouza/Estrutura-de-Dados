/* 
  5) Escreva a instrução para definir um tipo de dados estruturado contendo: um código numérico de tipo inteiro, 
  um nome de pessoa de até 40 caracteres úteis, a data de nascimento da pessoa (que deverá ser do tipo da struct definida no exercício 1 desta atividade),
  o sexo ('M' ou 'F') e o limite de crédito (um número real de precisão simples).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() 
{
  typedef struct {unsigned char dia, mes; unsigned short int ano;} data;
  
  typedef struct {int codigo; 
                  char nome[40]; 
                  data dataNascimento;
                  char sexo[1];
                  float limiteCredito;} dadosCliente;

  dadosCliente cliente;

  cliente.codigo = 20;
  strcpy(cliente.nome, "Senhor Barriga Pançudo");

  cliente.dataNascimento.dia = 05;
  cliente.dataNascimento.mes = 12;
  cliente.dataNascimento.ano = 2005;

  strcpy(cliente.sexo, "M");
  cliente.limiteCredito = 5000.76;

  printf("Dados do cliente\n\n");
  printf("Código: %d\n", cliente.codigo);
  printf("Nome: %s\n", cliente.nome);
  printf("Data de nascimento: %d/%d/%d\n", cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano);
  printf("Sexo: %s\n", cliente.sexo);
  printf("Limite de crédito: R$%.2f\n", cliente.limiteCredito);
}