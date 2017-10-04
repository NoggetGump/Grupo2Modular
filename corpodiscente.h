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
*     Versão  Autor    Data			Observações
*     0.01    Flávio   01/10/2017	Início do desenvolvimento.
*     0.02    Flávio   03/10/2017       Funções cria, busca, imprime e remove adicionadas	
*     0.03    Flávio   03/10/2017       Função insere adicionada
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
	CDIS_CondRetAlunoNãoEncontrado, // O aluno não foi encontrado
	CDIS_CondRetFaltouMemoria,	// Faltou memória ao alocar dados
	CDIS_CondRetCDISVazio
} CDIS_tpCondRet;
/***********************************************************************
*
*  $FC Função: CDIS cria
*
*  $ED Descrição da função
*		Cria lista de Alunos do Corpo Discente.
*
***********************************************************************/
CDIS_tpCondRet CorpoDisc_cria(CorpoDisc **corpo);
/***********************************************************************
*
*  $FC Função: CDIS remove
*
*  $ED Descrição da função
*		Varre a lista do Corpo Discente procurando Aluno com matrícula igual ao valor de matbusca e o remove da lista.
*
***********************************************************************/
CDIS_tpCondRet CorpoDisc_remove(CorpoDisc *Corpo, unsigned int matbusca);
/***********************************************************************
*
*  $FC Função: CDIS imprime
*
*  $ED Descrição da função
*		Imprime na tela o Corpo Discente.
*
***********************************************************************/
CDIS_tpCondRet CorpoDisc_imprime(CorpoDisc *Corpo);
/***********************************************************************
*
*  $FC Função: CDIS insere
*
*  $ED Descrição da função
*		Cria e insere Aluno no final da lista do Corpo Discente.
*
***********************************************************************/
CDIS_tpCondRet CorpoDisc_insere(CorpoDisc *Corpo, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end);
/***********************************************************************
*
*  $FC Função: CDIS busca
*
*  $ED Descrição da função
*		Percorre a lista procurando pelo Aluno com matrícula igual a matbusca e retorna, por referência, em alunodesejado.
*
***********************************************************************/
CDIS_tpCondRet CorpoDisc_busca(CorpoDisc *Corpo, unsigned int matbusca, Aluno** alunodesejado);
