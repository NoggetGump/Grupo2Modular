#pragma warning( disable : 4996 ) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(void)
{
	Aluno *a = NULL;
	Data *nascTest = (Data*) malloc(sizeof(Data));
	Endereco *endTest = (Endereco*) malloc(sizeof(Endereco));
	int mat;

	nascTest->ano = 1995;
	nascTest->mes = 9;
	nascTest->dia = 29;

	strcpy(endTest->estado, "RJ");
	strcpy(endTest->cidade, "Rio de Janeiro");
	strcpy(endTest->bairro, "Itanhanga");
	strcpy(endTest->rua, "Estrada do Itanhanga");
	strcpy(endTest->comp, "2222, Casa 6A");
	
	CriaAluno(a,"Bruno Miranda Marinho",1613071,(long)15773120747,992691584,nascTest,endTest);
	GetMat(a, &mat);
	printf("Matrícula adicionada: %d", mat);
	printf("Compilado!\n");
	return 0;
}
