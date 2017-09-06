
#ifndef ALUNO_H
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

typedef struct aluno Aluno;


// Função para criar um aluno. Recebe um ponteiro para Aluno e retorna o aluno criado com as informações passadas por parâmetros.
int CriaAluno(Aluno *a, char *nome, int mat, int cpf, int telefone, Data *nasc, Endereco* end);

// Função para deletar um aluno. Recebe o endereço de memória de um aluno e o deleta (apaga da memória).*/
int deletaAluno(Aluno* a);

// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero). Caso um dado não necessite ser alterado, passar 0 / NULL como parâmetro.
int AlteraDados(Aluno *aluno, char *nome, int mat, int cpf, int telefone, Data *nasc, Endereco* end);

// Função para pegar a matrícula de um aluno. Recebe o endereço de memória (ponteiro) de um aluno e devolve sua matrícula por referência.
int GetMat(Aluno *a, int *mat);

// Função para pegar o nome de um aluno. Recebe um ponteiro para Aluno e devolve seu nome por referência.
int GetNome(Aluno *a, char* nome);

// Função interna para validar uma data.
// Considera a data atual do sistema como data limite.
// Retorna 1 se a data for válida e 0 caso contrário.
// Valida verificando o número de dias por mês, p. ex. O dia 31 de setembro não é válido. */
int ValidaData(Data* data);

// Funcao que copia os dados do aluno.
int GetAll(Aluno *a,char *nome,int *mat,int *cpf,int *tel, Data *nasc,Endereco *endereco);

#endif