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

typedef enum {
	ALN_CondRetOK,	// Executou corretamente
	ALN_CondRetAlunoNaoExiste,	// O aluno não existe 
	ALN_CondRetDataInvalida,	// Data inserida foi inválida
	ALN_CondRetFaltouMemoria	// Faltou memória ao alocar dados
} ALN_tpCondRet;



// Função para criar um aluno. Recebe um ponteiro para Aluno e retorna o aluno criado com as informações passadas por parâmetros.
ALN_tpCondRet CriaAluno(Aluno *a, char *nome, int mat, int cpf, int telefone, Data *nasc, Endereco* end);

// Função para deletar um aluno. Recebe o endereço de memória de um aluno e o deleta (apaga da memória).*/
ALN_tpCondRet deletaAluno(Aluno* a);

// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero). Caso um dado não necessite ser alterado, passar 0 / NULL como parâmetro.
ALN_tpCondRet AlteraDados(Aluno *aluno, char *nome, int mat, int cpf, int telefone, Data *nasc, Endereco* end);

// Função para pegar a matrícula de um aluno. Recebe o endereço de memória (ponteiro) de um aluno e devolve sua matrícula por referência.
ALN_tpCondRet GetMat(Aluno *a, int *mat);

// Função para pegar o nome de um aluno. Recebe um ponteiro para Aluno e devolve seu nome por referência.
ALN_tpCondRet GetNome(Aluno *a, char* nome);

// Função para solicitar dados de alunos através da saída DOS. Devolve as entradas como parâmetros.
ALN_tpCondRet SolicitaDados(char *nome, int *mat, int *cpf, int *telefone, Data *nasc, Endereco* end);

// Função que copia os dados do aluno
ALN_tpCondRet GetAll(Aluno *a, char *nome, int *mat, int *cpf, int *tel, Data *nasc, Endereco *endereco);

// Função recebe um ponteiro pra aluno e imprime todos os seus dados
ALN_tpCondRet imprimeAluno(Aluno *a);

// Função interna para validar uma data.
// Considera a data atual do sistema como data limite.
// Retorna 1 se a data for válida e 0 caso contrário.
// Valida verificando o número de dias por mês, p. ex. O dia 31 de setembro não é válido. */
int ValidaData(Data* data);

#endif
