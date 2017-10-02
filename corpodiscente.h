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
*		Cria lista de alunos do corpo discente.
*
***********************************************************************/
CDIS_tpCondRet CorpoDisc_cria (void);
/***********************************************************************
*
*  $FC Função: CDIS deleta
*
*  $ED Descrição da função
*		Varre a lista do corpo discente procurando Aluno com matrícula igual ao valor de mat1 e o remove da lista.
*
***********************************************************************/
CDIS_tpCondRet CorpoDisc_deleta(CorpoDisc *Corpo, unsigned int mat1);
