#pragma once
#define ALUNO_H

typedef struct data {
	short dia;
	short mes;
	short ano;
} Data;

typedef struct endereco {
	char estado[51];
	char cidade[51];
	char bairro[32];
	char rua[81];
	char comp[32];
} Endereco;

typedef struct cpf {
	int dig1;
	int dig2;
	int dig3;
	int cod;
} CPF;

typedef enum {
	ALN_CondRetOK,	// Executou corretamente
	ALN_CondRetAlunoNaoExiste,	// O aluno não existe 
	ALN_CondRetDataInvalida,	// Data inserida foi inválida
	ALN_CondRetFaltouMemoria;	// Faltou memória ao alocar dados
} ALN_tpCondRet;

typedef struct aluno Aluno;

// Função para criar um aluno. Recebe um ponteiro para Aluno e retorna o aluno criado com as informações passadas por parâmetros.
ALN_tpCondRet ALU_CriaAluno(Aluno **a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end);

// Função para deletar um aluno. Recebe o endereço de memória de um aluno e o deleta (apaga da memória).*/
ALN_tpCondRet ALU_deletaAluno(Aluno* a);

// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero). Caso um dado não necessite ser alterado, passar 0 / NULL como parâmetro.
ALN_tpCondRet ALU_AlteraDados(Aluno *a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end);

// Função para pegar a matrícula de um aluno. Recebe o endereço de memória (ponteiro) de um aluno e devolve sua matrícula por referência.
ALN_tpCondRet ALU_GetMat(Aluno *a, unsigned int *mat);

// Função para pegar o nome de um aluno. Recebe um ponteiro para Aluno e devolve seu nome por referência.
ALN_tpCondRet ALU_GetNome(Aluno *a, char* nome);

// Função que copia os dados do aluno
ALN_tpCondRet ALU_GetAll(Aluno *a, char *nome, unsigned int *mat, CPF *cpf, unsigned int *tel, Data *nasc, Endereco *endereco);

// Função recebe um ponteiro pra aluno e imprime todos os seus dados
ALN_tpCondRet ALU_imprimeAluno(Aluno *a);
able : 4996 ) 

typedef struct data {
	int dia;
	int mes;
	int ano;
} Data;

typedef struct endereco {
	char estado[51];
	char cidade[51];
	char bairro[32];
	char rua[81];
	char comp[32];
} Endereco;

typedef struct cpf {
	int dig1;
	int dig2;
	int dig3;
	int cod;
} CPF;

typedef enum {
	ALN_CondRetOK,	// Executou corretamente
	ALN_CondRetAlunoNaoExiste,	// O aluno não existe
	ALN_CondRetFaltouMemoria;	// Faltou memória ao alocar um aluno
} ALN_tpCondRet;

typedef struct aluno Aluno;

// Função para criar um aluno. Recebe um ponteiro para Aluno e retorna o aluno criado com as informações passadas por parâmetros.
ALN_tpCondRet ALU_CriaAluno(Aluno **a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end);

// Função para deletar um aluno. Recebe o endereço de memória de um aluno e o deleta (apaga da memória).*/
ALN_tpCondRet ALU_deletaAluno(Aluno** a);

// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero). Caso um dado não necessite ser alterado, passar 0 / NULL como parâmetro.
ALN_tpCondRet ALU_AlteraDados(Aluno *a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end);

// Função para pegar a matrícula de um aluno. Recebe o endereço de memória (ponteiro) de um aluno e devolve sua matrícula por referência.
ALN_tpCondRet ALU_GetMat(Aluno *a, unsigned int *mat);

// Função para pegar o nome de um aluno. Recebe um ponteiro para Aluno e devolve seu nome por referência.
ALN_tpCondRet ALU_GetNome(Aluno *a, char* nome);

// Função que copia os dados do aluno
ALN_tpCondRet ALU_GetAll(Aluno *a, char *nome, unsigned int *mat, CPF *cpf, unsigned int *tel, Data *nasc, Endereco *endereco);

// Função recebe um ponteiro pra aluno e imprime todos os seus dados
ALN_tpCondRet ALU_imprimeAluno(Aluno *a);
