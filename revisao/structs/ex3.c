/* 
  Exercício 3 
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct regProd 
{
  int num;
  char descr[25];
  double valor;
  int qtdes[12];
} TProd;

void LimpaBuffer();

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
  
  printf("a)\nNúmero: %d\nDescrição: %s\nValor: R$%.2lf", vProd.num, vProd.descr, vProd.valor);
  printf("\nQuantidades:");

  for (i = 0; i < 12; i++)
    printf(" %d", vProd.qtdes[i]);

  printf("\n------------------------------------\n");

  /* b) Editar todos os dados da variável vProd por meio de scanf(...) e fgets(...) */
  printf("\nb)");
  
  printf("\nNúmero: ");
  scanf("%d", &vProd.num);

  /* Limpa buffer de entrada para fgets() */
  LimpaBuffer();

  printf("Descrição: ");
  fgets(vProd.descr, 24, stdin);

  printf("Valor: ");
  scanf("%lf", &vProd.valor);

  printf("------------------------------------\n");

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

  printf("\nc)\nSoma das quantidades: %d\nMenor quantidade: %d\nMaior quantidade: %d", soma, menor, maior);
  printf("\n------------------------------------\n");

  /* d) Converter o conteúdo do membro descr para maiúsculas. */
  for (i = 0; vProd.descr[i] != '\0'; i++)
    vProd.descr[i] = toupper(vProd.descr[i]);

  printf("\nd)\nNova descrição: %s", vProd.descr);
  printf("\n------------------------------------\n");

  /* e) Por meio de um looping for (...) colocar zero em todos os elementos do membro qtdes. */
  for (i = 0; i < 12; i++)
    vProd.qtdes[i] = 0;

  printf("\ne)\nQuantidades zeradas:");

  for (i = 0; i < 12; i++)
    printf(" %d", vProd.qtdes[i]);
  
  printf("\n------------------------------------\n");

  /* f) Inicializar a variável vProd, colocando zeros nos dados numéricos e uma string de comprimento zero na descrição. */
  vProd.num = 0;
  strcpy(vProd.descr, "");
  vProd.valor = 0.0;

  printf("\nf)\nNúmero: %d\nDescrição: %s\nValor: R$%.2lf", vProd.num, vProd.descr, vProd.valor);
  printf("\n------------------------------------");

  return 0;
}

void LimpaBuffer()
{ 
  while (getchar()!='\n');
  
  return;
}
