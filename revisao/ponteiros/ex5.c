/*
  Exercício 5
*/
#include <stdio.h>
#include <string.h>

int main()
{
  char texto[25], palavra[15], descr[11], *p1, *p2;

  strcpy(palavra, "xxxxxxx");
  strcpy(texto, "Linguagem C");
  scanf("%s", &palavra[3]);

  p1 = &texto[6];
  p2 = &descr[0];

  scanf("%s", p2); // O usuário digita "goiaba" aqui
  strcpy(&texto[6], " de trapo");

  return 0;
}

/*
  a) Considerando que no primeiro scanf() o usuário digitou "Banana", qual o conteúdo da variável palavra após essa entrada de dados? 
  Qual seria o resultado da instrução strlen(palavra) nesse caso? E qual o resultado para strlen(&palavra[3])?
  R: palavra = "xxxBanana"; strlen(palavra) = 9; strlen(&palavra[3]) = 6;

  b) Qual o conteúdo da variável descr?
  R: goiaba.

  c) Por que a chamada a scanf() não tem '&' quando o conteúdo digitado destina-se a uma string?
  R: Porque o nome de uma variável do tipo vetor é um ponteiro para o endereço da memória de seu primeiro índice, não necessitando do operador '&'.
*/
