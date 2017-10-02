/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Corpo Discente
*
*  Arquivo gerado:              corpodiscente.h
*  Letras identificadoras:      CDIS
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 2
*  Autores:   Flávio Thiago Franco Vaz
*             
*	      	  
*	          
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data        Observações
*       0.01   Flávio	01/10/17	Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa o Corpo Discente do Sistema Acadêmico a ser desenvolvido.
*     O Corpo Discente é uma lista de Alunos da universidade.
***************************************************************************/



/***********************************************************************
*
*  $TC Tipo de dados: CDIS Condições de retorno
*
*
***********************************************************************/
typedef enum {
	CDIS_CondRetOK,	// Executou corretamente
	CDIS_CondRetAlunoNaoCadastrado,	// O aluno não está cadastrado
	CDIS_CondRetFaltouMemoria	// Faltou memória ao alocar dados
} CDIS_tpCondRet;
/***********************************************************************
*
*  $FC Função: CDIS cria
*
*  $ED Descrição da função
*		Cria lista de Alunos do Corpo Discente.
*
***********************************************************************/
CDIS_tpCondRet CorpoDisc_cria (void);
/***********************************************************************
*
*  $FC Função: CDIS deleta
*
*  $ED Descrição da função
*		Varre a lista do Corpo Discente procurando Aluno com matrícula igual ao valor de mat1 e o remove da lista.
*
***********************************************************************/
CDIS_tpCondRet CorpoDisc_deleta(CorpoDisc *Corpo, unsigned int mat1);
/***********************************************************************
*
*  $FC Função: CDIS imprime
*
*  $ED Descrição da função
*		Imprime na tela o Corpo Discente.
*
***********************************************************************/
CDIS_tpCondRet CorpoDisc_imprime (CorpoDisc *Corpo);
/***********************************************************************
*
*  $FC Função: CDIS insere
*
*  $ED Descrição da função
*		Cria e insere Aluno no final da lista do Corpo Discente.
*
***********************************************************************/
//FUNÇÃO INSERE--------------------------------------------------
/***********************************************************************
*
*  $FC Função: CDIS busca
*
*  $ED Descrição da função
*		Percorre a lista procurando pelo Aluno com matrícula igual a mat1 e retorna, por referência, em aluno.
*
***********************************************************************/
CDIS_tpCondRet CorpoDisc_busca (CorpoDisc *Corpo, unsigned int mat1, Aluno* aluno);
