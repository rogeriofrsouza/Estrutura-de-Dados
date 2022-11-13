/*
	Versão inicial do programa da lista linear de números	implementada por CONTIGUIDADE.
	É a versão equivalente (agora por contiguidade) daquela 
	(por encadeamento) encontrada no arquivo 63_ED-ListasLineares.pdf
*/
#include <stdio.h>

#define MAXIMO 50

int main(void)
{	
	int numero, final, cont;
	int lista[MAXIMO];

	/* inicializando a variável de controle do fim da lista */
	final = 0;
	
	while (1)
	{	
		printf("\nInforme o número: ");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		lista[final] = numero;
		final = final + 1;
	}

	/* imprimindo os valores da lista */
	printf("\n\n\nConteúdo da lista:\n");
	cont = 0;

	while (cont != final)
	{	
		printf("%d\n", lista[cont]);
		cont = cont + 1;
	}
	
	return 0;
}
