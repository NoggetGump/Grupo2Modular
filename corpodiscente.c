#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "corpodiscente.h"
#include "aluno.h"
struct corpodisc {
	List* Aluno;
}typedef CorpoDisc;

static CorpoDisc *Corpo;

/*Inicio da função CDI_cria*/
/* Recebe um ponteiro para CorpoDisc e aloca memória para uma lista de alunos,
onde serão inseridos os alunos, através das outras funções. */
CDI_tpCondRet CDI_cria(void) {

	// Aloco espaço para o corpo discente.
	Corpo = (CorpoDisc*)malloc(sizeof(CorpoDisc));
	// Se a lista não for criada com sucesso, retorno falha de memória.
	if (createList(&(Corpo->Aluno)) != LIS_CondRetOK) {
		return CDI_CondRetFaltouMemoria;
	}
	// Se tudo deu certo, retorno OK.
	return CDI_CondRetOK;

}
/*Fim da função CDI_cria*/

/*Inicio da função CDI_insere*/
/*Função que recebe um vetor de ponteiros para aluno a ser inserido, o nome do aluno, sua matricula,seu cpf, seu telefone, sua data de nascimento, seu endereço e um ponteiro para uma estrutura Corpo Discente*/
CDI_tpCondRet CDI_insere(char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end)
{
	Aluno *a;
	if (CDI_busca(mat) != NULL)
		return CDI_CondRetAlunoJaCadastrado;
	ALU_CriaAluno(&a, nome, mat, cpf, telefone, nasc, end);
	if (a == NULL)
		return CDI_CondRetFaltouMemoria;
	else {
		push_back(Corpo->Aluno, a);
		return CDI_CondRetOK;
	}
}
/*Fim da função CDI_insere*/

/*Início da função CDI_busca*/
/*Função INTERNA que recebe um ponteiro para CorpoDisc e procura a matrícula fornecida por referência em matbusca na lista de alunos e caso encontre o aluno
desejado retorna seus dados em alunodesejado que é um ponteiro para Aluno passado por referência.Caso não encontre,retorna a condição
de erro de aluno não encontrado.*/
Aluno* CDI_busca(unsigned int matbusca) {
	unsigned int mat2, i, size;
	Aluno *a;
	list_size(Corpo->Aluno, &size);
	first(Corpo->Aluno);
	for (i = 0; i < size; i++) {
		get_val_cursor(Corpo->Aluno, &a);
		ALU_GetMat(a, &mat2);
		if (matbusca == mat2) {
			return &a;
		}
		next(Corpo->Aluno);
	}
	return NULL;
}
/*Fim da função CDI_busca*/

/*Início da função CDI_altera*/
/*Função que altera os dados de um aluno do corpo docente.*/
CDI_tpCondRet CDI_altera(int matbusca, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end) {
	Aluno *alndesejado;
	ALN_tpCondRet ret;

	alndesejado = CDI_busca(matbusca);	// busco o aluno no corpo discente

	if (alndesejado == NULL)	// se não encontrei
		return CDI_CondRetAlunoNaoCadastrado;	// aluno não está cadastrado.
	ret = ALU_AlteraDados(alndesejado,nome,mat,cpf,telefone,nasc,end);
	if (ret != ALN_CondRetOK) {
		return CDI_CondRetAlunoNãoEncontrado;
	}

	return CDI_CondRetOK;

}
/*Fim da função CDI_altera*/

/*Início da função CDI_remove*/
/*Função que recebe como parâmetros a matrícula do aluno a ser removido, o ponteiro para a estrutura Corpo Discente e remove da Lista do Corpo Discente o Aluno com matrícula igual a recebida*/
CDI_tpCondRet CDI_remove(unsigned int matbusca) {
	Aluno *alndesejado;
	alndesejado = CDI_busca(matbusca);
	if (alndesejado == NULL)
		return CDI_CondRetAlunoNaoCadastrado;
	else {
		pop_cursor(Corpo->Aluno, &alndesejado);//Remove da lista o elemento apontado pelo cursor
		return CDI_CondRetOK;
	}
}
/*Fim da função CDI_remove*/

/*Início da função CDI_imprime*/
/*Função que recebe como parâmetro o ponteiro para a estrutura Corpo Discente e imprime na tela todos os seus elementos*/
CDI_tpCondRet CDI_imprime(void) {
	unsigned int mat2, i, size;
	Aluno *a;
	list_size(Corpo->Aluno, &size);
	if (size == 0) {
		printf("Não há alunos cadastrados no Corpo Discente.\n");
		return CDI_CondRetCDIVazio;
	}
	first(Corpo->Aluno);
	for (i = 0; i < size; i++) {
		get_val_cursor(Corpo->Aluno, &a);
		ALU_imprimeAluno(a);
		next(Corpo->Aluno);
	}
	return CDI_CondRetOK;
}
/*Fim da função CDI_imprime*/

/*Início da função CDI_deleta*/
CDI_tpCondRet CDI_deleta(void) {
	// TODO
}
/*Fim da função CDI_deleta*/
