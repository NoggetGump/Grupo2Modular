#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

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
int GetMat (Aluno *a, int mat){
	mat = a->mat;
	return (0);
}