/*
  Exercício 1
*/
#include <stdio.h>

struct regData 
{
  unsigned char dia, mes; 
  unsigned short int ano;
};

int main() 
{
  struct regData data1, data2;

  data1.dia = 15;
  data1.mes = 8;
  data1.ano = 2009;

  printf("Informe uma data (dd mm aaaa):\n");
  scanf("%hhu %hhu %hu", &data2.dia, &data2.mes, &data2.ano);
    
  printf("\nData 1: %02hhu/%02hhu/%hu", data1.dia, data1.mes, data1.ano);
  printf("\nData 2: %02hhu/%02hhu/%hu\n", data2.dia, data2.mes, data2.ano);

  /* comparando as duas datas */
  if (data1.dia == data2.dia && data1.mes == data2.mes && data1.ano == data2.ano)
    printf("\nDatas idênticas\n");

  return 0;
}
