/***************************************************************************
*  $MCI Módulo de implementação: Módulo Corpo Docente
*
*  Arquivo gerado:              corpoDocente.C
*  Letras identificadoras:      CDO
*
*  Nome da base de software:    Fonte do módulo Corpo Docente
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Bruce Marcellino, BM  
*			Felipe Alfena, FA
*			Nicolas Paes, NP
*			Mariana Ruddy, MR
*			Rodrigo Pumar, RP.
*
*  $HA Histórico de evolução:
*     Versão  Autor 	Data     	Observações
*       0.52   BM/RP	04/10/2017	Revisão
*       0.51   BM   	04/10/2017	Revisão
*       0.50   RP   	03/10/2017	Documentação
*       0.40   FA  	03/10/2017	Funções busca adicionadas
*       0.30   MR   	03/10/2017	Funções de consulta/altera adicionadas 
*       0.20   BM   	02/10/2017	Funcoes modelo adicionadas 
*       0.10   BM  	01/10/2017	Inicio do desenvolvimento 
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para manipular os professores na lista de corpo docente.
*     Este módulo utiliza funcões de interface do modulo professor.
***************************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disciplina.h"
#include "listas.h"
#include "professor.h"
#include "sala.h"
#include "turma.h"
#include "menu.h"
#include "corpodiscente.h"
#include "corpoDocente.h"
#include "aluno.h"

/***************************************************************************
*
*  Função: MEN_menuInicial
*  ****/

int main(void)
{
	MEN_menuInicial();
	return 0;
}