#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"
#include <time.h>

typedef struct {
	char *nome;
	int mat;
	int cpf;
	int telefone;
	char *curso;
	Endereco endereco;
	Data data;
}Aluno;

/*Recebe um ponteiro para aluno e desaloca o espaço de memória apontado pelo mesmo*/
int deleta_Aluno (Aluno *a){
	free (a);
	return (0);
}

/*Recebe um ponteiro para aluno e outro para um inteiro e retorna a matrícula do aluno pelo ponteiro para inteiro.*/
int GetMat (Aluno *a, int* mat){
	*mat = a->mat;
	return (0);
}
/*Recebe um ponteiro para aluno e outro para um char e retorna o nome do aluno pelo ponteiro para char.*/
int GetNome (Aluno *a,char* nome){
   strcpy(nome,a->nome);
   return(0);
}

//Cria um único vazio aluno passado por referencia.
int CriaAlunoVazio(Aluno *a){
	a = (*Aluno) malloc(sizeof(Aluno));

	if(a == NULL){
		printf("\nError na criação do Aluno\n");
		exit(1);
	}

	a->nome = NULL;
	a->mat = NULL;
	a->cfp = NULL;
	a->telefone = NULL;
	a->curso = NULL;
	a->endereco.estado = NULL;
	a->endereco.cidade = NULL;
	a->endereco.bairro = NULL;
	a->endereco.rua = NULL;
	a->endereco.comp = NULL;
	a->data.dia = NULL;
	a->data.mes = NULL;
	a->data.ano = NULL;

	return (0);
}

//Função para pegar os dados digitados e colocar no aluno.
int InsereDadosAluno(Aluno *a){

	printf("\nDigite os dados:");
	printf("\nDados academicos:\n");
	printf("\nNome: ");
	scanf("%s", a->nome);
	printf("\nMatricula: ");
	scanf("%d", a->mat);
	printf("\nTelefone: ");
	scanf("%s", a->telefone);
	printf("\nCurso: ");
	scanf("%s", a->curso);
	printf("\nDados sobre a residencia\n");
	printf("\nEstado: ");
	scanf("%s", a->endereco.estado);
	printf("\nCidade: ");
	scanf("%s", a->endereco.cidade);
	printf("\nBairro: ");
	scanf("%s", a->endereco.bairro);
	printf("\nRua: ");
	scanf("%s", a->endereco.rua);
	printf("\nCompletamento: ");
	scanf("%s", a->endereco.comp);
	printf("\nDados pessoais\n");
	printf("\nCPF: ");
	scanf("%d", a->cpf);
	printf("\nDia do nascimento: ");
	scanf("%d", a->data.dia);
	printf("\nMes do nascimento: ");
	scanf("%d", a->data.mes);
	printf("\nAno do nascimento: ");
	scanf("%d", a->data.ano);

	return (0);
}

// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero).
int AlteraDados (Aluno* aluno, Dados* dados) {
	
	if (dados.nome)
		aluno.nome = dados.nome;
	if (dados.mat)
		aluno.mat = dados.mat;
	if (dados.cpf)
		aluno.cpf = dados.cpf;
	if (dados.telef)
		aluno.telefone = dados.telefone;
	if (dados.nasc && ValidaData(&nasc))
		aluno.Data = dados.Data;
	if (dados.end)
		aluno.endereco = dados.end;

	return (0);
}

/* Função interna para validar uma data. 
Considera a data atual do sistema como data limite. 
Retorna 1 se a data for válida e 0 caso contrário. 
Valida verificando o número de dias por mês, p. ex. O dia 31 de setembro não é válido. */
int ValidaData (Data* data){
	
	time_t t = time(NULL);
	struct tm *time = localtime(&t);
	char* meses31 = {1,3,5,7,8,10,12};
	char* meses30 = {4,6,9,11};
	int i;

	if((data.dia < time->tm_mday && data.mes < (time->tm_mon + 1)) && data.ano < (time->tm_year + 1900))
	{
		for (i=0 ; i < 7 ; i++) {
			if (data.mes == meses31[i])
				if (data.dia <= 31)
					return 1;
		}
		for (i=0 ; i < 4 ; i++) {
			if (data.mes == meses30[i])
				if (data.dia <= 30)
					return 1;
		}
		if (data.mes == 2)
			if (data.dia <= 28)
				return 1;
	}
	return 0;
}
