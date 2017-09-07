#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

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
	strcpy(endTest->bairro, "Gávea");
	strcpy(endTest->rua, "Rua Marquês de São Vicente");
	strcpy(endTest->comp, "225");
	
	CriaAluno(a,"Bruno Miranda Marinho",1610000,14299300120,992349329,nascTest,endTest);
	GetMat(a, &mat);
	printf("Matrícula adicionada: %d", mat);
	printf("Compilado!\n");
	return 0;
}
