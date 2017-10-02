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
CDIS_tpCondRet CorpoDisc_busca (CorpoDisc *Corpo, unsigned int matbusca, Aluno *alunodesejado){
	 unsigned int mat2;
	 unsigned int i, size;
	 Aluno *a = (Aluno*)malloc(sizeof(Aluno));
	 list_size(Corpo->Aluno, &size);
	 for (i = 0; i < size; i++){
        get_val_cursor(Corpo->Aluno, &a);
        ALU_GetMat(a, &mat2);
        if (matbusca == mat2){
            *alunodesejado = *a;
            return CDIS_CondRetOK;
        }
        next(Corpo->Aluno);
    }
	 return CDIS_CondRetAlunoNãoEncontrado;
}

CDIS_tpCondRet CorpoDisc_deleta(CorpoDisc *Corpo, int mat1){
    unsigned int mat2;
    Aluno *a = (Aluno*)malloc (sizeof(Aluno));
    unsigned int i, size;
    list_size(Corpo->Aluno, &size);
    for (i = 0; i < size; i++){
        get_val_cursor (Corpo->Aluno, &a);
        ALU_GetMat (a, &mat2);
        if (mat1 == mat2){
            pop_cursor (Corpo->Aluno, &a);
            return CDIS_CondRetOK;
        }
        next (Corpo->Aluno);
    }
	return CDIS_CondRetAlunoNaoCadastrado;
}
