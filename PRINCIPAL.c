#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// definicao de tipos complexos
typedef struct {
	int c1;
	float c2;
	char c3;
} tExemplo;

// prototipos de funcoes
void imprimeZero();


// ---------------------------------------------------------------------------------------------

// funcao principal
int main()
{
	imprimeZero();

	return 0;
}

// ---------------------------------------------------------------------------------------------


// todas as funcoes
void imprimeZero()
{
	printf("0");
	return;
}


