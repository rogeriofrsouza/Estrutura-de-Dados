/* 
  Testa algoritmo genérico de ordenação bolha 
  Tipo float
*/

#include <stdio.h>

void BolhaGen(int, void *, int, int (*) (void *, void *));
int ComparaFloat(void *, void *);
void * Acessa(void *, int, int);
void Troca(void *, void *, int);

int main(void)
{
  int i;
  float vet[8] = {2.3, 5.6, 7.2, 3.3, 10.6, 1.2, 8.4, 4.0};

  BolhaGen(8, vet, sizeof(float), ComparaFloat);

  printf("Vetor ordenado: ");

  for (i = 0; i < 8; i++)
    printf("%.1f  ", vet[i]);

  return 0;
}

/* Ordenação bolha genérica */
void BolhaGen(int n, void *v, int tam, int (*ComparaFloat) (void *, void *))
{
  int i, j, fez_troca;

  for (i = n-1; i > 0; i--)
  {
    fez_troca = 0;

    for (j = 0; j < i; j++)
    {
      void *p1 = Acessa(v, j, tam);
      void *p2 = Acessa(v, j+1, tam);

      if (ComparaFloat(p1, p2))  /* troca */
      {
        Troca(p1, p2, tam);
        fez_troca = 1;
      }
    }

    if (fez_troca == 0)  /* não houve troca */
      return;
  }
}

void * Acessa(void *v, int i, int tam)
{
  char *t = (char *) v;
  t += tam * i;

  return (void *) t;
}

int ComparaFloat(void *a, void *b)
{
  float *p1 = (float *) a;
  float *p2 = (float *) b;

  if (*p1 > *p2)
    return 1;
  else
    return 0;
}

void Troca(void *a, void *b, int tam)
{
  char *v1 = (char *) a;
  char *v2 = (char *) b;

  for (int i = 0; i < tam; i++)
  {
    char temp = v1[i];
    v1[i] = v2[i];
    v2[i] = temp;
  }
}
