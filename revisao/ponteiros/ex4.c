#include <stdio.h>

int main(void)
{ 
  int n[] = {7, 8, 9};
  int *p;

  p = &n[0];
  p++;

  printf("Valor: %d ", *p);  // 8
  (*p)++;
  printf("Valor: %d\n", *p);  // 9
}