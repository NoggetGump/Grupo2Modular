#define _CRT_SECURE_NO_WARNINGS
#pragma warning( disable : 4996 )
#include <stdio.h>
#include <string.h>
#include "corpodiscente.h"
#include "aluno.h"

int main(void) {
	CPF cpf;
	Data data;
	Endereco end;
	//unsigned int mat;
	//Aluno *aluno;
	cpf.cod = 00; cpf.dig1 = 123; cpf.dig2 = 456; cpf.dig3 = 789;
	data.ano = 1990; data.dia = 14; data.mes = 07;
	strcpy(end.bairro,"Copacabana");
	strcpy(end.cidade, "Rio de Janeiro");
	strcpy(end.estado, "RJ");
	strcpy(end.rua, "Av. Nossa Sra. de Copacabana");
	strcpy(end.comp, "1900, Apto 708");
	//ALU_CriaAluno(&aluno,"Outro", 1412312, &cpf, 990011223, &data, &end);
	CDI_cria();

	CDI_insere("Jose",1412312,&cpf, 990011223,&data,&end);
	//CDI_insere("Outro", 1412312, &cpf, 990011223, &data, &end);
	CDI_imprime();
	//ALU_GetMat(aluno,&mat);
	//printf("%d",mat);

	return 0;
}
