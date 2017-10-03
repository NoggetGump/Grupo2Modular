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
/*Função que deleta da Lista do Corpo Discente o Aluno com matrícula igual a matbusca*/
CDIS_tpCondRet CorpoDisc_deleta(CorpoDisc *Corpo, unsigned int matbusca){
    Aluno *alunodesejado;
    if (CorpoDisc_busca (Corpo, matbusca, &alunodesejado) != CDIS_CondRetOK ) 
		return CDIS_CondRetAlunoNaoCadastrado;
	else{
		pop_cursor(Corpo->Aluno, &alunodesejado);//Remove da lista o elemento apontado pelo cursor
		return CDIS_CondRetOK;
	}
}
