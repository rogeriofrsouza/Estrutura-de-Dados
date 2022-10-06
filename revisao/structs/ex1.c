/*
  1) Uma struct para armazenar uma data foi definida como: struct regData {unsigned char dia, mes; unsigned short int ano;};
  Escreva uma instrução para declarar duas variáveis locais desse tipo. Depois, atribua a data 15/08/2009 para a primeira variável e 
  receba na segunda variável uma data informada pelo usuário. Em seguida, compare as duas datas e, se forem idênticas, emita uma mensagem apropriada.
  Ao compilar o programa, utilize o flag –Wall e garanta que a compilação ocorra sem erros e sem warnings.
*/
#include <stdio.h>

struct regData {
  unsigned char dia, mes; 
  unsigned short int ano;
};

int main() 
{
  struct regData data1, data2;

  data1.dia = 15;
  data1.mes = 8;
  data1.ano = 2009;

  printf("Informe uma data (dd/mm/aaaa): \n");
  scanf("%hhu/%hhu/%hu", &data2.dia, &data2.mes, &data2.ano);

  printf("\nData 1: %hhu/%hhu/%hu", data1.dia, data1.mes, data1.ano);
  printf("\nData 2 : %hhu/%hhu/%hu", data2.dia, data2.mes, data2.ano);

  return 0;
}
