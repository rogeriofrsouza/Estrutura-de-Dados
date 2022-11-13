/*
  A tarefa aqui neste problema é ler uma expressão matemática na forma de dois números Racionais (numerador / denominador) e apresentar o resultado da operação. Cada operando ou operador é separado por um espaço em branco. A sequência de cada linha que contém a expressão a ser lida é: número, caractere, número, caractere, número, caractere, número. A resposta deverá ser apresentada e posteriormente simplificada. Deverá então ser apresentado o sinal de igualdade e em seguida a resposta simplificada. No caso de não ser possível uma simplificação, deve ser apresentada a mesma resposta após o sinal de igualdade.

  Considerando N1 e D1 como numerador e denominador da primeira fração, segue a orientação de como deverá ser realizada cada uma das operações:
  - Soma: (N1*D2 + N2*D1) / (D1*D2)
  - Subtração: (N1*D2 - N2*D1) / (D1*D2)
  - Multiplicação: (N1*N2) / (D1*D2)
  - Divisão: (N1/D1) / (N2/D2), ou seja (N1*D2)/(N2*D1)

  Entrada
  A entrada contem vários casos de teste. A primeira linha de cada caso de teste contem um inteiro N (1 ≤ N ≤ 1*10^4), indicando a quantidade de casos de teste que devem ser lidos logo a seguir. Cada caso de teste contém um valor racional X (1 ≤ X ≤ 1000), uma operação (-, +, * ou /) e outro valor racional Y (1 ≤ Y ≤ 1000).

  Saída
  A saída consiste em um valor racional, seguido de um sinal de igualdade e outro valor racional, que é a simplificação do primeiro valor. No caso do primeiro valor não poder ser simplificado, o mesmo deve ser repetido após o sinal de igualdade.
*/
#include <stdio.h>

typedef struct 
{
  int num, den;
} TRac;

/* protótipos das funções */
TRac SomaRac(TRac, TRac);
TRac SubtraiRac(TRac, TRac);
TRac MultRac(TRac, TRac);
TRac DivRac(TRac, TRac);
TRac SimplRac(TRac);

int mdc(int, int);

int main(void)
{
  TRac X, Y, R, S;
  int qtde;
  char op;

  printf("Informe a quantidade de casos de teste: ");
  scanf("%d", &qtde);

  if (qtde <= 0)
    return 1;

  while (qtde)
  {
    printf("\nInforme uma expressão matemática com dois números racionais (Ex.: 1/5 + 2/3): \n");
    scanf("%d/%d %c %d/%d", &X.num, &X.den,
                            &op,
                            &Y.num, &Y.den);
    switch (op)
    {
      case '+':
        R = SomaRac(X, Y);
        break;
      case '-':
        R = SubtraiRac(X, Y);
        break;
      case '*':
        R = MultRac(X, Y);
        break;
      case '/':
        R = DivRac(X, Y); 
        break;
      default:
        printf("\nOperador inválido\n");
    }

    S = SimplRac(R);
    printf("\n%d/%d = %d/%d\n", R.num, R.den, S.num, S.den);

    qtde--;
  }

  return 0;
}

TRac SomaRac(TRac n1, TRac n2)
{
  TRac res;

  /* soma: (N1*D2 + N2*D1) / (D1*D2) */
  res.num = n1.num * n2.den + n2.num * n1.den;
  res.den = n1.den * n2.den;

  return res;
}

TRac SubtraiRac(TRac n1, TRac n2)
{
  TRac res;

  /* subtração: (N1*D2 - N2*D1) / (D1*D2) */
  res.num = n1.num * n2.den - n2.num * n1.den;
  res.den = n1.den * n2.den;

  return res;
}

TRac MultRac(TRac n1, TRac n2)
{
  TRac res;

  /* multiplicação: (N1*N2) / (D1*D2) */
  res.num = n1.num * n2.num;
  res.den = n1.den * n2.den;

  return res;
}

TRac DivRac(TRac n1, TRac n2)
{
  TRac res;

  /* divisão: (N1*D2)/(N2*D1) */
  res.num = n1.num * n2.den;
  res.den = n2.num * n1.den;

  return res;
}

TRac SimplRac(TRac n1)
{
  TRac res;

  res.num = n1.num / mdc(n1.num, n1.den);
  res.den = n1.den / mdc(n1.num, n1.den);

  return res;
}

int mdc(int m, int n)
{
  /* se o número for negativo, inverte o sinal */
  if (m < 0)
    m = -m;
  if (n < 0)
    n = -n;

  if (m % n == 0)
    return n;

  return mdc(n, m % n);
}
