#define _CRT_SECURE_NO_WARNINGS
#pragma warning( disable : 4996 ) 

#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct aluno {
	char nome[81];
	unsigned int mat;
	CPF cpfA;
	unsigned int telefone;
	Data nasc;
	Endereco end;
};

int ValidaData(Data* data);	// Cabeçalho da função interna que valida data.

							//Cria um único aluno com as informações passadas por referencia.
ALN_tpCondRet ALU_CriaAluno(Aluno **a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end) {

	*a = (Aluno*)malloc(sizeof(Aluno));	// Alocando espaço na memória para um Aluno
										//*a = b;	// Usando outro ponteiro para me referenciar ao aluno, para facilitar leitura
										// e não ter que usar (*a)->atributo.
	if (a == NULL)
		return ALN_CondRetFaltouMemoria;

	strcpy((*a)->nome, nome);	// Atribuo todas as informações ao aluno.
	(*a)->mat = mat;
	(*a)->cpfA.dig1 = cpf->dig1;
	(*a)->cpfA.dig2 = cpf->dig2;
	(*a)->cpfA.dig3 = cpf->dig3;
	(*a)->cpfA.cod = cpf->cod;
	(*a)->telefone = telefone;
	if (ValidaData(nasc)) {
		(*a)->nasc.dia = nasc->dia;
		(*a)->nasc.mes = nasc->mes;
		(*a)->nasc.ano = nasc->ano;
	}
	else {
		printf("\nData de nascimento fornecida invalida.\n\n");
		(*a)->nasc.dia = 0;
		(*a)->nasc.mes = 0;
		(*a)->nasc.ano = 0;
	}
	strcpy((*a)->end.bairro, end->bairro);
	strcpy((*a)->end.cidade, end->cidade);
	strcpy((*a)->end.comp, end->comp);
	strcpy((*a)->end.estado, end->estado);
	strcpy((*a)->end.rua, end->rua);

	return ALN_CondRetOK;	// Retorno que tudo deu certo.
}

/*Recebe um ponteiro para aluno e desaloca o espaço de memória apontado pelo mesmo*/
ALN_tpCondRet ALU_deletaAluno(Aluno* a) {
	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;
	free(a);
	return ALN_CondRetOK;
}

/*Recebe um ponteiro para aluno e outro para um inteiro e retorna a matrícula do aluno pelo ponteiro para inteiro.*/
ALN_tpCondRet ALU_GetMat(Aluno *a, unsigned int *mat) {
	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;

	*mat = a->mat;
	return ALN_CondRetOK;
}
/*Recebe um ponteiro para aluno e outro para um char e retorna o nome do aluno pelo ponteiro para char.*/
ALN_tpCondRet ALU_GetNome(Aluno *a, char* nome) {
	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;
	strcpy(nome, a->nome);
	return ALN_CondRetOK;
}

// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero).
ALN_tpCondRet ALU_AlteraDados(Aluno *a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end) {

	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;

	if (nome)
		strcpy(a->nome, nome);
	if (mat)
		a->mat = mat;
	if (cpf)
	{
		a->cpfA.dig1 = cpf->dig1;
		a->cpfA.dig2 = cpf->dig2;
		a->cpfA.dig3 = cpf->dig3;
		a->cpfA.cod = cpf->cod;
	}
	if (telefone)
		a->telefone = telefone;
	if (nasc && ValidaData(nasc)) {
		a->nasc.ano = nasc->ano;
		a->nasc.mes = nasc->mes;
		a->nasc.dia = nasc->dia;
	}
	if (end) {
		strcpy(a->end.estado, end->estado);
		strcpy(a->end.cidade, end->cidade);
		strcpy(a->end.bairro, end->bairro);
		strcpy(a->end.rua, end->rua);
		strcpy(a->end.comp, end->comp);
	}
	return ALN_CondRetOK;
}

// Função que copia os dados do aluno
ALN_tpCondRet ALU_GetAll(Aluno *a, char *nome, unsigned int *mat, CPF *cpf, unsigned int *tel, Data *nasc, Endereco *endereco) {

	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;
	strcpy(nome, a->nome);
	*mat = a->mat;
	(cpf)->dig1 = a->cpfA.dig1;
	(cpf)->dig2 = a->cpfA.dig2;
	(cpf)->dig3 = a->cpfA.dig3;
	(cpf)->cod = a->cpfA.cod;
	*tel = a->telefone;
	nasc->ano = a->nasc.ano;
	nasc->dia = a->nasc.dia;
	nasc->mes = a->nasc.mes;
	strcpy(endereco->estado, a->end.estado);
	strcpy(endereco->cidade, a->end.cidade);
	strcpy(endereco->bairro, a->end.bairro);
	strcpy(endereco->rua, a->end.rua);
	strcpy(endereco->comp, a->end.comp);

	return ALN_CondRetOK;
}

// Função recebe um ponteiro pra aluno e imprime todos os seus dados
ALN_tpCondRet ALU_imprimeAluno(Aluno *a) {
	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;
	printf("Nome: %s\n", a->nome);
	printf("Matricula: %d\n", a->mat);
	printf("CPF:  %03d.%03d.%03d-%02d\n", a->cpfA.dig1, a->cpfA.dig2, a->cpfA.dig3, a->cpfA.cod);
	printf("Telefone: %d\n", a->telefone);
	printf("Data de Nascimento: %02d/%02d/%d\n", a->nasc.dia, a->nasc.mes, a->nasc.ano);
	printf("Endereco: %s, %s, %s, %s - %s\n", a->end.rua, a->end.comp, a->end.bairro, a->end.cidade, a->end.estado);
	return ALN_CondRetOK;
}

/* Função interna para validar uma data.
Considera a data atual do sistema como data limite.
Retorna 1 se a data for válida e 0 caso contrário.
Valida verificando o número de dias por mês, p. ex. O dia 31 de setembro não é válido. */
int ValidaData(Data* data) {

	time_t t = time(NULL);
	struct tm *time = localtime(&t);	// Pego a data atual do computador para comparar
	char meses31[7] = { 1,3,5,7,8,10,12 };	// Meses com 31 dias
	char meses30[4] = { 4,6,9,11 };	// Meses com 30 dias
	int i;	// iterador

	// Um aluno não pode ter mais de 120 anos, nem menos de 15 anos.

	if ((data->ano >= ((time->tm_year + 1900) - 120) && data->ano <= ((time->tm_year + 1900) - 15) )  && data->ano <= (time->tm_year + 1900))
	{
		if (data->ano == (time->tm_year + 1900))	// verifico se o ano fornecido é o ano atual.
		{
			if (data->mes == (time->tm_mon + 1))	// verifico se o mes fornecido é o mês atual.
				if (data->dia <= time->tm_mday)		// verifico se o dia fornecido é menor ou igual que o dia atual.
					return 1;
				else
					return 0;
		}
		for (i = 0; i < 7; i++) {
			if (data->mes == meses31[i])	// verifico se o mes fornecido possui 31 dias.
				if (data->dia <= 31)	// verifico se o dia fornecido é menor ou igual a 31.
					return 1;
		}
		for (i = 0; i < 4; i++) {
			if (data->mes == meses30[i])	// verifico se o mes fornecido possui 30 dias.
				if (data->dia <= 30)	// verifico se o dia fornecido é menor ou igual a 30.
					return 1;
		}
		if (data->mes == 2)		// verifico se o mes fornecido é fevereiro.
			if (data->dia <= 28)	// verifico se o dia fornecido é menor ou igual a 28.
				return 1;
	}
	return 0;
}
