/*
	Arquivo de INTERFACE para a implementação do TDA de Números Racionais
*/
typedef struct {int num, den;} TRac;

/* Protótipos das funções */
TRac SomaRac(TRac, TRac);
TRac SubtraiRac(TRac, TRac);
TRac MultRac(TRac, TRac);
TRac DivRac(TRac, TRac);
TRac SimplRac(TRac);
