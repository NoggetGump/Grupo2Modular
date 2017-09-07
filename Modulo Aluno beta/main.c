#pragma warning( disable : 4996 ) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(void)
{
	Aluno **a = NULL;
	Data *nascTest = (Data*) malloc(sizeof(Data));
	Endereco *endTest = (Endereco*) malloc(sizeof(Endereco));
	int mat, tel = 0;
	long cpf;
	char nome[81];
	
	// Testa funções CriaAluno, GetMat, GetNome, AlteraDados
	
	nascTest->ano = 1995;
	nascTest->mes = 7;
	nascTest->dia = 20;

	strcpy(endTest->estado, "RJ");
	strcpy(endTest->cidade, "Rio de Janeiro");
	strcpy(endTest->bairro, "Gavea");
	strcpy(endTest->rua, "Rua Marques de Sao Vicente");
	strcpy(endTest->comp, "225");

	ALU_CriaAluno(&a,"Pessoa Souza",1612220,14020210100,991749212,nascTest,endTest);
	/*
	ALU_GetMat(a, &mat);
	ALU_GetNome(a,nome);
	printf("Matricula adicionada: %u\n", mat);
	printf("Nome: %s\n",nome);
	ALU_AlteraDados(a,"Aluno da Silva", 1610001,0,0,NULL,NULL);
	ALU_GetMat(a, &mat);
	ALU_GetNome(a, nome);
	printf("Matricula adicionada: %u\n", mat);
	printf("Nome: %s\n", nome);
	*/

	// Testa a Função Solicita Dados, em seguida cria um aluno com os dados inseridos
	// e imprime os dados do aluno na tela.
	//ALU_SolicitaDados(nome,&mat,&cpf,&tel,nascTest,endTest);
	//ALU_CriaAluno(&a, nome, mat, cpf, tel, nascTest, endTest);
	ALU_imprimeAluno(a);
	//ALU_GetMat(a, &mat);
	//ALU_GetNome(a, nome);
	//printf("Matricula adicionada: %u\n", mat);
	//printf("Nome: %s\n", nome);

	return 0;
}
