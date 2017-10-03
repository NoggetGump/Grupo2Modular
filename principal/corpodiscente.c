#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "corpodiscente.h"
#include "aluno.h"
struct corpodisc {
	List* Aluno;
}typedef CorpoDisc;

CDIS_tpCondRet CorpoDisc_cria() {
	CorpoDisc *Corpo;
	
	Corpo = (CorpoDisc*) malloc (sizeof(CorpoDisc));

	if (createList(&Corpo->Aluno) != LIS_CondRetOK) {
		return CDIS_CondRetFaltouMemoria;
	}
	//TODO
	return CDIS_CondRetOK;

}
/*Recebe um ponteiro para CorpoDisc e procura a matrícula fornecida por referência em matbusca na lista de alunos e caso encontre o aluno
 desejado retorna seus dados em alunodesejado que é um ponteiro para Aluno passado por referência.Caso não encontre,retorna a condição 
 de erro de aluno não encontrado.*/
CDIS_tpCondRet CorpoDisc_busca (CorpoDisc *Corpo, unsigned int matbusca, Aluno **alunodesejado){
	 unsigned int mat2, i, size;
	 Aluno *a;
	 list_size(Corpo->Aluno, &size);
	 for (i = 0; i < size; i++){
        get_val_cursor(Corpo->Aluno, &a);
        ALU_GetMat(a, &mat2);
        if (matbusca == mat2){
            alunodesejado = &a;
            return CDIS_CondRetOK;
        }
        next(Corpo->Aluno);
    }
	 return CDIS_CondRetAlunoNaoCadastrado;
}
/*Início da função CorpoDisc_deleta*/
/*Função que recebe como parâmetros a matrícula do aluno a ser deletado, o ponteiro para a estrutura Corpo Discente e deleta da Lista do Corpo Discente o Aluno com matrícula igual a recebida*/
CDIS_tpCondRet CorpoDisc_deleta(CorpoDisc *Corpo, unsigned int matbusca){
    Aluno *alunodesejado;
    if (CorpoDisc_busca (Corpo, matbusca, &alunodesejado) != CDIS_CondRetOK ) 
		return CDIS_CondRetAlunoNaoCadastrado;
	else{
		pop_cursor(Corpo->Aluno, &alunodesejado);//Remove da lista o elemento apontado pelo cursor
		return CDIS_CondRetOK;
	}
}
/*Fim da função CorpoDisc_deleta*/

/*Início da função CorpoDisc_imprime*/
/*Função que recebe como parâmetro o ponteiro para a estrutura Corpo Discente e imprime na tela todos os seus elementos*/
CDIS_tpCondRet CorpoDisc_imprime (CorpoDisc *Corpo){
	unsigned int mat2, i, size; 
	Aluno *a;
	list_size(Corpo->Aluno, &size);
	if (size == 0){
		printf ("Não há alunos cadastrados no Corpo Discente.\n");
		return CDIS_CondRetCDISVazio;
	}
	for (i = 0; i < size; i++){
		get_val_cursor(Corpo->Aluno, &a);
        ALU_imprimeAluno(a);
		next(Corpo->Aluno);
	}
	return CDIS_CondRetOK;
}
/*Fim da função
