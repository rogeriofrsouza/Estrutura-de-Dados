/*
  Joãozinho está aprendendo a somar frações na escola e quer sua ajuda para escrever um programa que dadas duas frações imprima a soma delas em sua forma irredutível. Assim ele vai poder conferir as respostas dos exercícios que está fazendo.

  A forma irredutível de uma fração é quando o divisor (número de baixo) é o menor possível. Por exemplo, 10⁄3 é uma fração irredutível, pois 10 e 3 não têm nenhum divisor em comum. Mas 10⁄6 não é, pois ela pode ser simplificada para 5⁄3, dividindo-se 10 e 6 por 2.

  Dados quatro inteiros a, b, c, d, escreva um programa que calcule a⁄b + c⁄d na sua forma irredutível.

  Entrada
  A única linha da entrada contém quatro inteiros a, b, c, d, (1 ≤ a, b, c, d ≤ 100) respectivamente dividendo e divisor da primeira fração e dividendo e divisor da segunda fração.

  Saída
  Seu programa deve imprimir uma única linha contendo dois inteiros, dividendo e divisor da fração irredutível formada pela soma das duas frações dadas.
*/
#include <stdio.h>

typedef struct regRac
{
  int num, den;
} TRac;

/* protótipos das funções */
TRac SomaRac(TRac, TRac);
TRac SimplRac(TRac);

int mdc(int, int);

int main(void)
{
  TRac X, Y, R, S;

  printf("Informe uma fração X (Ex.: 1/5): \n");
  scanf("%d/%d", &X.num, &X.den);

  printf("\nInforme outra fração Y (Ex.: 4/3): \n");
  scanf("%d/%d", &Y.num, &Y.den);

  R = SomaRac(X, Y);
  S = SimplRac(R);

  printf("\n%d/%d = %d/%d", R.num, R.den, 
                            S.num, S.den);

  return 0;
}

TRac SomaRac(TRac n1, TRac n2)
{
  TRac res;

  res.num = n1.num * n2.den + n2.num * n1.den;
  res.den = n1.den * n2.den;

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
  if (m < 0) m = -m;
  if (n < 0) n = -n;

  if (m % n == 0)
    return n;

  return mdc(n, m % n);
}
