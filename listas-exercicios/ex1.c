/*
  Faça um programa que implementa uma lista linear duplamente encadeada contendo os dados de 
  cidades informadas pelo usuário. Deverão ser armazenados o nome da cidade (uma palavra de 
  até 30 caracteres úteis), sua população (um inteiro), sua área territorial, PIB e IDH (todos do tipo 
  float). Encerrar a entrada de dados quando o usuário informar “FIM” para o nome do município 
  e imprimir a lista tanto a partir do início como a partir do final. Após a impressão do conteúdo 
  original da lista, o programa deverá executar um looping onde, a cada ciclo, um valor de IDH é 
  informado e todas as ocorrências de cidades na lista que possuem IDH igual ou superior a esse 
  valor devem ser excluídas. Após a exclusão, imprimir a lista novamente, tanto a partir do início 
  como a partir do final. Se não for encontrado nenhum nó com valor de IDH igual ou superior ao 
  informado, emitir mensagem apropriada e não imprimir a lista. Encerrar o programa quando o 
  usuário informar um IDH negativo. Organize o programa em arquivo cliente, de interface e de 
  implementação.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct dCidade
{ 
 char nome[31];
 int pop;
 float area, pib, idh;
} DCidade;

typedef struct lista
{
 DCidade info;
 struct lista *prox, *ant;
} TLista;

int main()
{


 return 0;
}
