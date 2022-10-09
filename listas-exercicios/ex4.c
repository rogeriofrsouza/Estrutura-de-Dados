/*
  Fazer um programa em C que recebe uma string de até 20 caracteres contendo uma expressão 
  aritmética digitada pelo usuário. Essa expressão poderá conter 3 tipos de delimitadores de escopo 
  e precedência: parênteses, colchetes e chaves. O programa deverá verificar se os delimitadores 
  estão corretamente balanceados ou não, utilizando uma pilha para essa finalidade.

  Observações: 
  a) Considere que não há qualquer tipo de hierarquia entre os delimitadores, ou seja, o 
  usuário pode, a qualquer momento, iniciar uma expressão com qualquer um dos 3 tipos 
  permitidos. Exemplos de expressões válidas: 
  • (A+B)/C 
  • A+(B/C) 
  • [a-2]*(5+c) 
  • {a*[c+d*(4*x)]} 
  • (A) 

  Exemplos de expressões inválidas: • )A+B(/C 
  • A+B/C) 
  • [a-2)*(5+c] 
  • {a*[c+d*(4*x)}] 
  • (A 
 
  b) Usar subrotinas para empilhar e desempilhar os elementos. 
  
  c) Use a pilha para nela acrescentar (apenas) os delimitadores de abertura, ou seja, '(', '[', 
  '{'encontrados na string. Ao encontrar um delimitador de fechamento, ou seja, ')', ']', 
  '}', retire o elemento do topo da pilha e verifique se ele é compatível com o delimitador 
  que foi encontrado na cadeia. Se for, prossiga o processamento, se não for, encerre 
  emitindo mensagem de erro. Se, ao final, a pilha estiver vazia, concluímos que a 
  expressão contida na string é válida, pois está balanceada, e o programa deverá emitir 
  uma mensagem informando isso.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{


 return 0;
}
