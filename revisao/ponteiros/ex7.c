/* 
  7) Suponha que temos uma subrotina que recebeu como seu primeiro parâmetro um vetor, cujos elementos são do tipo struct regDados, 
  e um valor a ser pesquisado nesse vetor como sendo o seu segundo parâmetro. Após feita a pesquisa, o valor foi encontrado, 
  e temos o ponteiro x indicando o endereço de memória desse elemento que contém o dado desejado. 
  Qual a instrução que calcularia quantos bytes existem entre o início do array na memória e o início do elemento onde o valor foi encontrado? 
  Assuma que o nome do primeiro parâmetro formal é v.
*/
#include <stdio.h>
#define MAX 50

struct regDados {
  int info;
};
typedef struct regDados RegDados;

/* pesquisa se o valor está na lista */
RegDados * Pesquisar(RegDados *, int);

int main() 
{
  RegDados vet[MAX], *x;
  int b, cont, i;
  
  /* inicializa o vetor */
  vet[0].info = 2;
  vet[1].info = 7;
  vet[2].info = 3;
  vet[3].info = 8;

  x = Pesquisar(vet, 8);

  for (i = 0; i < MAX; i++)
  {
    if (&vet[i] != x)
      cont++;
  }

  b = cont * sizeof(vet[i]);
  printf("Bytes entre o início do array na memória e o início do elemento onde o valor foi encontrado: %d", b);

  return 0;
}

RegDados * Pesquisar(RegDados *vet, int valor)
{
  int i;

  for (i = 0; i < MAX; i++)
  {
    if (vet[i].info == valor)
      break;
  }

  return &vet[i];
}
