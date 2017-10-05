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
*     0.01    Flávio   01/10/2017	Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa o Corpo Discente do Sistema Acadêmico a ser desenvolvido.
*     O Corpo Discente é uma lista de Alunos da universidade.
***************************************************************************/
#include "aluno.h"


/***********************************************************************
*
*  $TC Tipo de dados: CDI Condições de retorno
*
*
***********************************************************************/
typedef enum {
	CDI_CondRetOK,	// Executou corretamente
	CDI_CondRetAlunoNaoCadastrado,	// O aluno não está cadastrado
	CDI_CondRetAlunoJaCadastrado,	// O aluno já foi cadastrado
	CDI_CondRetAlunoNãoEncontrado, // O aluno não foi encontrado
	CDI_CondRetFaltouMemoria,	// Faltou memória ao alocar dados
	CDI_CondRetCDIVazio
} CDI_tpCondRet;
/***********************************************************************
*
*  $TD	Typedef 
*			Para que outros módulos conheçam a existencia da struct.
*
***********************************************************************/
typedef struct corpodisc CorpoDisc;

/***********************************************************************
*
*  $FC Função: CDI cria
*
*  $ED Descrição da função
*		Cria lista de Alunos do Corpo Discente.
*
***********************************************************************/
CDI_tpCondRet CDI_cria(void);
/***********************************************************************
*
*  $FC Função: CDI remove
*
*  $ED Descrição da função
*		Varre a lista do Corpo Discente procurando Aluno com matrícula igual ao valor de matbusca e o remove da lista.
*
***********************************************************************/
CDI_tpCondRet CDI_remove(unsigned int matbusca);
/***********************************************************************
*
*  $FC Função: CDI imprime
*
*  $ED Descrição da função
*		Imprime na tela o Corpo Discente.
*
***********************************************************************/
CDI_tpCondRet CDI_imprime(void);
/***********************************************************************
*
*  $FC Função: CDI insere
*
*  $ED Descrição da função
*		Cria e insere um Aluno no final da lista do Corpo Discente.
*
***********************************************************************/
CDI_tpCondRet CDI_insere(char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end);
/***********************************************************************
*
*  $FC Função: CDI altera
*
*  $ED Descrição da função
*		Percorre a lista procurando pelo Aluno com matrícula igual a matbusca e altera os dados passados que sejam diferentes de NULL.
*		Caso não queira alterar um dado, basta passar NULL no parâmetro que se manterá inalterado.
*
***********************************************************************/
CDI_tpCondRet CDI_altera(int matbusca, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco *end);
/***********************************************************************
*
*  $FC Função: CDI deleta
*
*  $ED Descrição da função
*		Deleta o corpo discente. ******TO DO*****
*
***********************************************************************/
CDI_tpCondRet CDI_deleta(void);
