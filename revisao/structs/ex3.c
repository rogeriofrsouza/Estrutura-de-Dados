// 3) Considerando as definições a seguir, indique as instruções requeridas nos itens de a) até f).

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

void main() 
{
  typedef struct {int num;
                  char descr[25];
                  double valor;
                  int qtdes[12];} TProd;
                  
  TProd vProd;

  // a) Configurar, por meio de atribuições, a variável vProd com os valores indicados na figura.
  vProd.num = 1453;
  strcpy(vProd.descr, "Pino de aco 8mm");
  vProd.valor = 5.32;

  for (int i = 0; i < 12; i++)
    vProd.qtdes[i] = rand() % 100;

  // b) Editar todos os dados da variável vProd por meio de scanf(...) e fgets(...).
  printf("Editar variável vProd\n");
  
  printf("\nNúmero: ");
  scanf("%d", &vProd.num);
  printf("\nDescriçao: ");
  scanf("%s", &vProd.descr);
  printf("\nValor: ");
  scanf("%d", &vProd.valor);

  // c) Por meio de um looping for (...) colocar zero em todos os elementos do membro qtdes.
  for (int i = 0; i <= 11; i++) 
  {
    int qtdes[12];
    qtdes[i] = 0;
  }

  // d) Converter o conteúdo do membro descr para maiúsculas.
  toupper(vProd.descr[0]);

  // e) Determinar a soma das quantidades, a menor quantidade e a maior quantidade.
  for (int i = 0; i <= 11; i++) 
  {
    int somaQuantidades = 0; 
    int menorQuantidade = vProd.qtdes[0], maiorQuantidade = vProd.qtdes[0];

    somaQuantidades += vProd.qtdes[i];
    if (vProd.qtdes[i] > maiorQuantidade) maiorQuantidade = vProd.qtdes[i];
    if (vProd.qtdes[i] < menorQuantidade) menorQuantidade = vProd.qtdes[i];
  }

  // f) Inicializar a variável vProd, colocando zeros nos dados numéricos e uma string de comprimento zero na descrição.
  vProd.num = 0;
  strcpy(vProd.descr, "");
}