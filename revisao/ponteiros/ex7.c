/* 
  7) Suponha que temos uma subrotina que recebeu como seu primeiro parâmetro um vetor, cujos elementos são do tipo struct regDados, 
  e um valor a ser pesquisado nesse vetor como sendo o seu segundo parâmetro. Após feita a pesquisa, o valor foi encontrado, 
  e temos o ponteiro x indicando o endereço de memória desse elemento que contém o dado desejado. 
  Qual a instrução que calcularia quantos bytes existem entre o início do array na memória e o início do elemento onde o valor foi encontrado? 
  Assuma que o nome do primeiro parâmetro formal é v.
*/
#include <stdio.h>

#define MAX 50

typedef struct regDados 
{ 
  int info;
} Dados;

Dados * Pesquisar(Dados *, int);

int main() 
{
  Dados vet[MAX], *x;
  int b, cont = 0, i;
  
  /* inicializa o vetor */
  vet[0].info = 2;
  vet[1].info = 7;
  vet[2].info = 3;
  vet[3].info = 8;

  /* pesquisa se o valor está na lista */
  x = Pesquisar(vet, 8);

  for (i = 0; i < MAX; i++)
  {
    if (&vet[i] != x)
      cont++;
    else
      break;
  }

  b = cont * sizeof(Dados);
  printf("Bytes entre o início do array na memória e o início do elemento encontrado: %d", b);

  return 0;
}

Dados * Pesquisar(Dados *vet, int valor)
{
  int i = 0;

  while (i < MAX && vet[i].info != valor)
    i++;

  if (i == MAX)
    return NULL;

  return &vet[i];
}
