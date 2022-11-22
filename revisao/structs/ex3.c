/* 3) Considerando as definições a seguir, indique as instruções requeridas nos itens de a) até f). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct regProd 
{
  int num;
  char descr[25];
  double valor;
  int qtdes[12];
} TProd;

int main() 
{      
  TProd vProd;
  int i, soma, menor, maior;

  /* a) Configurar, por meio de atribuições, a variável vProd com os valores indicados na figura. */
  vProd.num = 1453;
  strcpy(vProd.descr, "Pino de aco 8mm");
  vProd.valor = 5.32;

  vProd.qtdes[0] = 120;
  vProd.qtdes[1] = 89;
  vProd.qtdes[2] = 72;
  vProd.qtdes[3] = 15;
  vProd.qtdes[4] = 32;
  vProd.qtdes[5] = 33;
  vProd.qtdes[6] = 44;
  vProd.qtdes[7] = 566;
  vProd.qtdes[8] = 281;
  vProd.qtdes[9] = 32;
  vProd.qtdes[10] = 10;
  vProd.qtdes[11] = 29;

  /*
    for (i = 0; i < 12; i++)
      vProd.qtdes[i] = rand() % 100;
  */
  
  printf("Número: %d\nDescrição: %s\nValor: R$%.2lf", vProd.num, vProd.descr, vProd.valor);
  printf("\nQuantidades:");

  for (i = 0; i < 12; i++)
    printf(" %d", vProd.qtdes[i]);

  printf("\n------------------------------------");

  /* b) Editar todos os dados da variável vProd por meio de scanf(...) e fgets(...) */
  printf("\n\nEditar variável vProd");
  
  printf("\nNúmero: ");
  scanf("%d", &vProd.num);

  printf("\nDescrição: ");
  fgets(vProd.descr, 25, stdin);

  printf("\nValor: ");
  scanf("%lf", &vProd.valor);

  printf("------------------------------------");

  /* c) Determinar a soma das quantidades, a menor quantidade e a maior quantidade. */
  soma = 0;
  menor = maior = vProd.qtdes[0];

  for (i = 0; i < 12; i++) 
  {
    soma += vProd.qtdes[i];

    if (vProd.qtdes[i] > maior) 
      maior = vProd.qtdes[i];

    if (vProd.qtdes[i] < menor) 
      menor = vProd.qtdes[i];
  }

  printf("\n\nSoma das quantidades: %d\nMenor quantidade: %d\nMaior quantidade: %d", soma, menor, maior);
  printf("\n------------------------------------");

  /* d) Converter o conteúdo do membro descr para maiúsculas. */
  for (i = 0; vProd.descr[i] != '\0'; i++)
    vProd.descr[i] = toupper(vProd.descr[i]);

  printf("\n\nNova descrição: %s", vProd.descr);
  printf("------------------------------------");

  /* e) Por meio de um looping for (...) colocar zero em todos os elementos do membro qtdes. */
  for (i = 0; i < 12; i++)
    vProd.qtdes[i] = 0;

  printf("\n\nQuantidades zeradas:");

  for (i = 0; i < 12; i++)
    printf(" %d", vProd.qtdes[i]);
  
  printf("\n------------------------------------");

  /* f) Inicializar a variável vProd, colocando zeros nos dados numéricos e uma string de comprimento zero na descrição. */
  vProd.num = 0;
  strcpy(vProd.descr, "");
  vProd.valor = 0.0;

  printf("\n\nNúmero: %d\nDescrição: %s\nValor: R$%.2lf", vProd.num, vProd.descr, vProd.valor);
  printf("\n------------------------------------");

  return 0;
}
