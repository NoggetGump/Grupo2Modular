#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(void)
{
	char nomePessoa[81];
	Aluno *a = NULL;
	Data *nascTest = (Data*) malloc(sizeof(Data));
	Endereco *endTest = (Endereco*) malloc(sizeof(Endereco));
	unsigned int mat, tel, t = 0;
	CPF *cpfTest = (CPF*) malloc(sizeof(CPF));
	cpfTest->dig1= 123;
	cpfTest->dig2= 456;
	cpfTest->dig3= 789;
	cpfTest->cod = 00;
	//
	
	// Testa funções CriaAluno, GetMat, GetNome, AlteraDados
	
	nascTest->ano = 1995;
	nascTest->mes = 7;
	nascTest->dia = 20;

	strcpy(endTest->estado, "RJ");
	strcpy(endTest->cidade, "Rio de Janeiro");
	strcpy(endTest->bairro, "Gavea");
	strcpy(endTest->rua, "Rua Marques de Sao Vicente");
	strcpy(endTest->comp, "225");

	ALU_CriaAluno(&a,"Pessoa Souza",1612220,cpfTest,991749212,nascTest,endTest);
	
	ALU_GetMat(a, &mat);
	ALU_GetNome(a, nomePessoa);
	ALU_imprimeAluno(a);
	printf("Matricula Inalterada: %u\n", mat);
	printf("Nome Inalterado: %s\n",nomePessoa);
	printf("--------- ALTERACAO ---------\n");
	ALU_AlteraDados(a,"Aluno da Silva", 1610001,0,0,NULL,NULL);
	ALU_GetMat(a, &mat);
	ALU_GetNome(a, nomePessoa);
	ALU_imprimeAluno(a);
	printf("Matricula Alterada: %u\n", mat);
	printf("Nome Alterado: %s\n", nomePessoa);

	 //Testa a Função Solicita Dados, em seguida cria um aluno com os dados inseridos
	// e imprime os dados do aluno na tela.
	/*ALU_SolicitaDados(nome,&mat,&cpf,&tel,nascTest,endTest);
	ALU_CriaAluno(&a, nome, mat, cpf, tel, nascTest, endTest);
	ALU_imprimeAluno(a);
	ALU_GetMat(a, &mat);
	ALU_GetNome(a, nome);
	printf("Matricula adicionada: %u\n", mat);
	printf("Nome: %s\n", nome);*/
	//Testa função GetAll e imprime os dados obtidos na tela.
	ALU_GetAll(a, nomePessoa, &mat, cpfTest, &tel, nascTest, endTest);
	printf ("-------------------------Dados da GetAll----------------------------\n");
	
	printf ("Nome do Aluno: %s\n", nomePessoa);
	printf ("Matricula: %d\n", mat);
	printf ("CPF: %hd.%hd.%hd-%hd\n", cpfTest->dig1, cpfTest->dig2,cpfTest->dig3, cpfTest->cod);
	printf ("Telefone: %d\n", tel);
	printf ("Data de nascimento: %d/%d/%d\n", nascTest->dia, nascTest->mes, nascTest->ano);
	printf ("Endereço: %s/%s, %s - %s, %s\n", endTest->cidade, endTest->estado, endTest ->bairro, endTest->rua, endTest->comp);
	//Virtual Studio abortando, só usei o scanf pra ele mostrar a tela impressa sem fechar
	scanf ("%d", &t);
	return 0;
}
