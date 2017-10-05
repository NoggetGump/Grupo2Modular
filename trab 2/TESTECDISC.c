/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTECDISC.C
*  Letras identificadoras:      TCDISC
*
*  Nome da base de software:    Teste Automatizado para o Módulo Corpo Discente
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Bruno Marinho, BM
*			Matheus Zeitune, MZ
*			Flávio Franco, FF
*			João Cerqueira, JC
*			Vinicius Btechs, VB.
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   BM   09/09/2017 Desenvolvimento para T2 modificando TESTALN.C
*
*  $ED Descrição do módulo
*     Este modulo contém as funções específicas para o teste do
*     módulo corpo discente. É um interpretador de comandos de teste específicos
*	  utilizando o arcabouço de teste para C.
*
*		CRIAR_CDISC_CMD		Cria o Corpo Discente				"=criar"
*		INS_CDISC_CMD		Insere um aluno no C. Disc.			"=inserir"
*		IMPINF_CDISC_CMD	Imprime a info de um aluno			"=impinfaluno"
*		ALT_CDISC_CMD		Altera dados de um aluno			"=altaluno"
*		RMV_CDISC_CMD		Remove um aluno do C. Disc.			"=remover"
*		IMP_CDISC_CMD		Imprime o C. Disc.					"=imprimir"
*		DEL_CDISC_CMD		Deleta o C. Disc.					"=deletar"
*		LMP_CDISC_CMD		Limpa o C. Disc.					"=limpar"
*
*		Comandos de teste específicos para o módulo Corpo Discente:
*
*		"=criar" <int>CondRet
*
*		"=inserir" <string>nome <int>matricula <int>cpf3primDig <int>cpf3segDig
*		<int>cpf3TercDig <int>cpfcodVerif <int>telefone <int>diaNasc <int>mesNasc <int>anoNasc
*		<string>EndEstado <string>EndCidade <string>EndBairro <string>EndRua <string>EndComplemento
*		<int>CondRet
*
*       "=impinfaluno <int>matbusca <int>CondRet
*
*
*		"altaluno"<int>matbusca <string>nome <int>matricula <int>cpf3primDig <int>cpf3segDig
*		<int>cpf3TercDig <int>cpfcodVerif <int>telefone <int>diaNasc <int>mesNasc <int>anoNasc
*		<string>EndEstado <string>EndCidade <string>EndBairro <string>EndRua <string>EndComplemento
*		<int>CondRet
*
*		"=remover" <int>matbusca <int>CondRet
*
*		"=imprimir" <int>CondRet
*
*		"=deletar"  <int>CondRet
*
*		"=limpar"  <int>CondRet
*
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include	<stdlib.h>
#include    "corpodiscente.h"
#include	"aluno.h"
#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_CDISC_CMD		"=criar"
#define     INS_CDISC_CMD		"=inserir"
#define     IMPINF_CDISC_CMD	"=impinfaluno"
#define     ALT_CDISC_CMD       "=altaluno"
#define     RMV_CDISC_CMD		"=remover"
#define     IMP_CDISC_CMD		"=imprimir"
#define     DEL_CDISC_CMD		"=deletar"
#define     LMP_CDISC_CMD		"=limpar"

Endereco Endteste;
Data Datateste;
TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{

	CDI_tpCondRet CondRetObtido = CDI_CondRetOK;
	CDI_tpCondRet CondRetEsperada = CDI_CondRetFaltouMemoria;
	/* inicializa para qualquer coisa,é só para inicializar as variáveis */
	unsigned int matbusca = -1;
	char StringEsperada[81];
	unsigned int MatEsperada = -1;
	CPF cpfEsperado;
	unsigned int telefoneEsperado;
	int dia;
	int mes;
	int ano;
	char estado[81];
	char cidade[81];
	char bairro[81];
	char rua[81];
	char complemento[81];
	int  NumLidos = -1;

	/* Testar criar lista de alunos*/

	if (strcmp(ComandoTeste, CRIAR_CDISC_CMD) == 0)
	{

		NumLidos = LER_LerParametros("i", &CondRetEsperada);
		if (NumLidos != 1)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_cria();
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao criar lista.");

	}

	/* Testar CDISC Insere aluno na lista do corpo discente*/

	if (strcmp(ComandoTeste, INS_CDISC_CMD) == 0)
	{

		NumLidos = LER_LerParametros("siiiiiiiiisssssi", StringEsperada, &MatEsperada, &cpfEsperado.dig1, &cpfEsperado.dig2, &cpfEsperado.dig3, &cpfEsperado.cod, &telefoneEsperado, &dia, &mes, &ano, estado, cidade, bairro, rua, complemento,
			&CondRetEsperada);
		if (NumLidos != 16)
		{
			return TST_CondRetParm;
		}
		/* testando se a matricula é valida, isto é, tem 7 números */
		if (MatEsperada<1000000 || MatEsperada>9999999) {
			return TST_CondRetErro;
		}
		Datateste.dia = dia;
		Datateste.mes = mes;
		Datateste.ano = ano;
		strcpy(Endteste.estado, estado);
		strcpy(Endteste.cidade, cidade);
		strcpy(Endteste.bairro, bairro);
		strcpy(Endteste.rua, rua);
		strcpy(Endteste.comp, complemento);
		CondRetObtido = CDI_insere(StringEsperada, MatEsperada, &cpfEsperado, telefoneEsperado, &Datateste, &Endteste);
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao inserir aluno na lista.");
	}


	/* Testar CDISC Altera dados de um aluno do corpo discente*/

	if (strcmp(ComandoTeste, ALT_CDISC_CMD) == 0)
	{

		NumLidos = LER_LerParametros("isiiiiiiiiisssssi", &matbusca, StringEsperada, &MatEsperada, &cpfEsperado.dig1, &cpfEsperado.dig2, &cpfEsperado.dig3, &cpfEsperado.cod, &telefoneEsperado, &dia, &mes, &ano, estado, cidade, bairro, rua, complemento,
			&CondRetEsperada);
		if (NumLidos != 17)
		{
			return TST_CondRetParm;
		}
		/* testando se a matricula é valida, isto é, tem 7 números */
		if (MatEsperada<1000000 || MatEsperada>9999999) {
			return TST_CondRetErro;
		}
		Datateste.dia = dia;
		Datateste.mes = mes;
		Datateste.ano = ano;
		strcpy(Endteste.estado, estado);
		strcpy(Endteste.cidade, cidade);
		strcpy(Endteste.bairro, bairro);
		strcpy(Endteste.rua, rua);
		strcpy(Endteste.comp, complemento);
		CondRetObtido = CDI_altera(matbusca, StringEsperada, MatEsperada, &cpfEsperado, telefoneEsperado, &Datateste, &Endteste);
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao alterar dados do Aluno.");
	}

	/* Testar remove aluno da lista */

	else if (strcmp(ComandoTeste, RMV_CDISC_CMD) == 0)
	{
		NumLidos = LER_LerParametros("ii", &matbusca, &CondRetEsperada);
		if (NumLidos != 2)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_remove(matbusca);
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno errado");
	}

	/* Testar imprimir todos os alunos da lista corpo discente */

	else if (strcmp(ComandoTeste, IMP_CDISC_CMD) == 0)
	{
		NumLidos = LER_LerParametros("i", &CondRetEsperada);
		if (NumLidos != 1)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_imprime();
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}

	/* Testar imprimir info de um aluno da lista corpo discente */

	else if (strcmp(ComandoTeste, IMPINF_CDISC_CMD) == 0)
	{
		NumLidos = LER_LerParametros("ii", &matbusca, &CondRetEsperada);
		if (NumLidos != 2)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_imprimeInfo(matbusca);
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}

	/* Testar deletar o corpo discente */

	else if (strcmp(ComandoTeste, DEL_CDISC_CMD) == 0)
	{
		NumLidos = LER_LerParametros("i", &CondRetEsperada);
		if (NumLidos != 1)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_deleta();
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}

	/* Testar limpar todos os alunos do corpo discente */

	else if (strcmp(ComandoTeste, LMP_CDISC_CMD) == 0)
	{
		NumLidos = LER_LerParametros("i", &CondRetEsperada);
		if (NumLidos != 1)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_limpa();
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}
	return TST_CondRetNaoConhec;
}
