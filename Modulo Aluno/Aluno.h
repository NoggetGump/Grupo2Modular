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

// Estrutura que contém dados básicos.
typedef struct {
	char* nome;
	int mat;
	int cpf;
	int telefone;
	Data nasc;
	Endereco end;
} Dados;

/*Função para deletar um aluno. Recebe o endereço de memória (ponteiro) de um aluno e o deleta (apaga da memória).*/
int deletaAluno (Aluno *a);

/*Função para pegar a matrícula de um aluno. Recebe o endereço de memória (ponteiro) de um aluno e retorna sua matrícula por referência (em um ponteiro). */
int GetMat (Aluno *a, int* mat);

//Função para criar um único aluno vazio. Recebe o endereço de memória (ponteiro) de um aluno e retorna o aluno criado.
int CriaAlunoVazio(Aluno *a);

/*Função para pegar o nome de um aluno. Recebe o endereço de memória (ponteiro) de um aluno e retorna seu nome por referência (em um ponteiro)*/
int GetNome (Aluno *a,char* nome);

//Função para pegar os dados digitados e colocar no aluno.
int InsereDadosAluno(Aluno *a);

// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero).
int AlteraDados (Aluno* aluno, Dados* dados);

/* Função interna para validar uma data. 
Considera a data atual do sistema como data limite. 
Retorna 1 se a data for válida e 0 caso contrário. 
Valida verificando o número de dias por mês, p. ex. O dia 31 de setembro não é válido. */
int ValidaData (Data* data);

#endif
