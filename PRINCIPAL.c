#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// definicao de tipos complexos
typedef struct
{
	int dia;
	int mes;
	int ano;
} tData;

typedef struct
{
	tData DataCadastro;
	tData DataObito;
	char Classificacao;
	char Municipio;
	tData IdadeNaDataNotificacao;
	char ComorbidadePulmao;
	char ComorbidadeCardio;
	char ComorbidadeRenal;
	char ComorbidadeDiabetes;
	char ComorbidadeTabagismo;
	char ComorbidadeObesidade;
	char FicouInternado;
} tDadosPaciente;

// prototipos de funcoes
void pularPrimeiraLinha(FILE *arq);
void verifValores(int num, FILE *arq);
int lerDataCadastro(FILE *arq);
int lerDataObito(FILE *arq);
int lerClassificacao(FILE *arq);
int lerMunicipio(FILE *arq);
int lerIdadeNaDataNotificacao(FILE *arq);
int lerComorbidadePulmao(FILE *arq);
int lerComorbidadeCardio(FILE *arq);
int lerComorbidadeRenal(FILE *arq);
int lerComorbidadeDiabetes(FILE *arq);
int lerComorbidadeTabagismo(FILE *arq);
int lerComorbidadeObesidade(FILE *arq);
int lerFicouInternado(FILE *arq);


// ---------------------------------------------------------------------------------------------


// funcao principal
int main()
{
	FILE *arq; // ponteiro de arquivo, armazena o endereco das posicoes do arquivo

	arq = fopen("./data/covid19ES.csv", "r"); // abrir arquivo (endereco_arquivo, MODO_abertura-leitura), funcao passando por referência

	if (arq == NULL) // caso o arquivo nao exista, a funcao retorna um ponteiro nulo (NULL)
	{
		printf("Erro na abertura: arquivo nao encontrado!\n");
		exit(1); // força o encerramento do programa (POR CONVENÇÃO: retorna 0 caso tudo ocorra bem, retorna um número diferente de 0 caso ocorra um erro)
	}
	else
	{
		pularPrimeiraLinha(arq); // ignora os primeiros caracteres ate o \n, ou seja, ate o fim da primeira linha

		while (! feof(arq)) // enquanto arquivo nao chega ao fim...
		{
			if (feof(arq)) // evitar que o while seja executado mesmo quando o arquivo terminar (EOF)
			{
				break;
			}

			char charac = fgetc(arq); // ler caractere

			int i = 0;

			while (i < 12) // 12 e a quantidade de colunas/ de cada paciente, logo serao realizadas 12 coletas por linha
			{
				if (charac == ',') // contabiliza as virgulas e ajuda a prever o que deve ser registrado
				{
					i++;
				}
				if (charac == '\n')
				{
					break;	// !!!!!!!!!!!!!!!!!! TESTAR, VERIFICAR LEITURA E NECESSIDADE
				}
				else
				{
					verifValores(i, arq); // verifica valores separados por virgulas e escolhe a funcao baseado no numero de virgulas registradas
				}
			}
		}
	}

	fclose(arq); // fechar arquivo e limpar o que foi armazenado no buffer

	return 0;
}


// ---------------------------------------------------------------------------------------------


// todas as funcoes
void pularPrimeiraLinha(FILE *arq)
{
	int cont = 0;

	while (fgetc(arq) != '\n')
	{
		// apenas para esquecer a primeira linha
	}
	cont = 1;

	return;
}

void verifValores(int num, FILE *arq)
{
	switch (num)
	{
	case 0:
		lerDataCadastro(arq);
		break;
	case 1:
		/* code */
		break;
	case 2:
		/* code */
		break;
	case 3:
		/* code */
		break;
	case 4:
		/* code */
		break;
	case 5:
		/* code */
		break;
	case 6:
		/* code */
		break;
	case 7:
		/* code */
		break;
	case 8:
		/* code */
		break;
	case 9:
		/* code */
		break;
	case 10:
		/* code */
		break;
	case 11:
		/* code */
		break;
	case 12:
		/* code */
		break;
	default:
		break;
	}

	return;
}
/*
lerDataObito(charac)
lerClassificacao(charac)
lerMunicipio(charac)
lerIdadeNaDataNotificacao(charac)
lerComorbidadePulmao(charac)
lerComorbidadeCardio(charac)
lerComorbidadeRenal(charac)
lerComorbidadeDiabetes(charac)
lerComorbidadeTabagismo(charac)
lerComorbidadeObesidade(charac)
lerFicouInternado(charac)
*/

lerDataCadastro(FILE *arq)
{
	tData Cadastro;
	int ano, mes, dia;

	fscanf(arq, "%d-%d-%d,", &ano, &mes, &dia); 	// !!!!!!!!!!!!!!!!!! TESTAR E VERIFICAR LEITURA

	Cadastro.ano = ano;
	Cadastro.mes = mes;
	Cadastro.dia = dia;
}