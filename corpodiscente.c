#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "corpodiscente.h"

struct corpodisc {
	List* Alunos;
}typedef CorpoDisc;

CDIS_tpCondRet CorpoDisc_cria() {
	CorpoDisc *Corpo;
	
	Corpo = (CorpoDisc*) malloc (sizeof(CorpoDisc));

	if (createList(&Corpo->Alunos) != LIS_CondRetOK) {
		return CDIS_CondRetFaltouMemoria;
	}
	//TODO
	return CDIS_CondRetOK;

}
