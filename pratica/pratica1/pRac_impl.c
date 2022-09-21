/*
	Arquivo fonte da IMPLEMENTACAO do TDA de Números Racionais,
	com as definições de tipo de dados e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Num_rac.h"

int mdc(int, int);

TRac SomaRac(TRac n1, TRac n2)
{	
	TRac res;

	res.num = n1.num * n2.den + n2.num * n1.den;
	res.den = n1.den * n2.den;
	
	return res;
}

TRac SubtraiRac(TRac n1, TRac n2)
{	
	TRac res;

	res.num = n1.num * n2.den - n2.num * n1.den;
	res.den = n1.den * n2.den;
	
	return res;
}

TRac MultRac(TRac n1, TRac n2)
{	
	TRac res;

	res.num = n1.num * n2.num;
	res.den = n1.den * n2.den;
	
	return res;
}

TRac DivRac(TRac n1, TRac n2)
{	
	TRac res;

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
	/* Se o número for negativo, inverte o sinal */
	if (m < 0) m = -m;
	if (n < 0) n = -n;

	if (m % n == 0)
		return n;

	return mdc(n, m % n);
}
