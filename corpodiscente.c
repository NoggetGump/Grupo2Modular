#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "corpodiscente.h"
#include "aluno.h"
struct corpodisc {
	List* Aluno;
}typedef CorpoDisc;

/* Recebe um ponteiro para CorpoDisc e aloca memória para uma lista de alunos, 
onde serão inseridos os alunos, através das outras funções. */
CDIS_tpCondRet CorpoDisc_cria(CorpoDisc **corpo) {

	// Aloco espaço para o corpo discente.
	corpo = (CorpoDisc*)malloc(sizeof(CorpoDisc));
	// Se a lista não for criada com sucesso, retorno falha de memória.
	if (createList((*corpo)->Aluno) != LIS_CondRetOK) {
		return CDIS_CondRetFaltouMemoria;
	}
	// Se tudo deu certo, retorno OK.
	return CDIS_CondRetOK;

}
/*Recebe um ponteiro para CorpoDisc e procura a matrícula fornecida por referência em matbusca na lista de alunos e caso encontre o aluno
desejado retorna seus dados em alunodesejado que é um ponteiro para Aluno passado por referência.Caso não encontre,retorna a condição
de erro de aluno não encontrado.*/
CDIS_tpCondRet CorpoDisc_busca(CorpoDisc *Corpo, unsigned int matbusca, Aluno **alunodesejado) {
	unsigned int mat2, i, size;
	Aluno *a;
	list_size(Corpo->Aluno, &size);
	first(Corpo->Aluno);
	for (i = 0; i < size; i++) {
		get_val_cursor(Corpo->Aluno, &a);
		ALU_GetMat(a, &mat2);
		if (matbusca == mat2) {
			alunodesejado = &a;
			return CDIS_CondRetOK;
		}
		next(Corpo->Aluno);
	}
	return CDIS_CondRetAlunoNaoCadastrado;
}
/*Início da função CorpoDisc_remove*/
/*Função que recebe como parâmetros a matrícula do aluno a ser removido, o ponteiro para a estrutura Corpo Discente e remove da Lista do Corpo Discente o Aluno com matrícula igual a recebida*/
CDIS_tpCondRet CorpoDisc_remove(CorpoDisc *Corpo, unsigned int matbusca) {
	Aluno *alunodesejado;
	if (CorpoDisc_busca(Corpo, matbusca, &alunodesejado) != CDIS_CondRetOK)
		return CDIS_CondRetAlunoNaoCadastrado;
	else {
		pop_cursor(Corpo->Aluno, &alunodesejado);//Remove da lista o elemento apontado pelo cursor
		return CDIS_CondRetOK;
	}
}
/*Fim da função CorpoDisc_remove*/

/*Início da função CorpoDisc_imprime*/
/*Função que recebe como parâmetro o ponteiro para a estrutura Corpo Discente e imprime na tela todos os seus elementos*/
CDIS_tpCondRet CorpoDisc_imprime(CorpoDisc *Corpo) {
	unsigned int mat2, i, size;
	Aluno *a;
	list_size(Corpo->Aluno, &size);
	if (size == 0) {
		printf("Não há alunos cadastrados no Corpo Discente.\n");
		return CDIS_CondRetCDISVazio;
	}
	first(Corpo->Aluno);
	for (i = 0; i < size; i++) {
		get_val_cursor(Corpo->Aluno, &a);
		ALU_imprimeAluno(a);
		next(Corpo->Aluno);
	}
	return CDIS_CondRetOK;
}
/*Fim da função CorpoDisc_imprime*/
