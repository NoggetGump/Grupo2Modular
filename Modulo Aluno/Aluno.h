#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
	short dia;
	short mes;
	short ano;
} Data;

typedef struct {
	char *estado;
	char *cidade;
	char *bairro;
	char *rua;
	char *comp;
} Endereco;

/*Função para deletar um aluno. Recebe o endereço de memória (ponteiro) de um aluno e o deleta (apaga da memória).*/
int deletaAluno (Aluno *a);

/*Função para pegar a matrícula de um aluno. Recebe o endereço de memória (ponteiro) de um aluno e retorna sua matrícula por referência (em um ponteiro). */
int GetMat (Aluno *a, int mat);

//Função para criar um único aluno vazio. Recebe o endereço de memória (ponteiro) de um aluno e retorna o aluno criado.
int CriaAlunoVazio(Aluno *a);

/*Função para pegar o nome de um aluno. Recebe o endereço de memória (ponteiro) de um aluno e retorna seu nome por referência (em um ponteiro)*/
int GetNome (Aluno *a,char* nome);

#endif
