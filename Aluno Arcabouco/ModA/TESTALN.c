#include    <string.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    "Aluno.h"
#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_ALN_CMD       "=criar"
#define     GET_MAT_CMD         "=getmat"
#define     GET_NOME_CMD        "=getnome"
#define     ALT_DADO_CMD        "=alteradado"
#define     SOL_DADO_CMD        "=solicdado"
#define     GET_ALL_CMD         "=getall"
#define     IMP_ALUN_CMD        "=impaluno"
#define		DEL_ALUN_CMD		"=delaluno"

#define DIM_VT   10
#define  DIM_STRING  250

Aluno *vtAlunos[DIM_VT] = { NULL, NULL, NULL, NULL, NULL, 
							NULL, NULL, NULL, NULL, NULL };	// vetor de ponteiros para os alunos criados no script.
Data vtDatas[DIM_VT];
Endereco vtEnds[DIM_VT];
Endereco Endteste;
Data Datateste;
TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{

	ALN_tpCondRet CondRetObtido = ALN_CondRetOK;
	ALN_tpCondRet CondRetEsperada = ALN_CondRetFaltouMemoria;
	/* inicializa para qualquer coisa,é só para inicializar as variáveis */

	char ValorEsperado = '?';
	char ValorObtido = '!';
	short dia;
	short mes;
	short ano;
	char estado[81];
	char cidade[81];
	char bairro[81];
	char rua[81];
	char complemento[81];
	char StringEsperada[81];
	char StringObtida[81];
	unsigned int MatEsperada = -1;
	unsigned int MatObtida = -1;
	int indxdata = -1;
	int indxaluno = -1;
	int indxendereco = -1;
	CPF cpfEsperado;
	CPF cpfObtido;
	unsigned int telefoneEsperado;
	unsigned int telefoneObtido;
	int  NumLidos = -1;

	TST_tpCondRet Ret;

	/* Testar ALU Criar aluno*/

	if (strcmp(ComandoTeste, CRIAR_ALN_CMD) == 0)
	{

		NumLidos = LER_LerParametros("isiiiiiiiiisssssi", &indxaluno, StringEsperada, &MatEsperada, &cpfEsperado.dig1, &cpfEsperado.dig2, &cpfEsperado.dig3, &cpfEsperado.cod, &telefoneEsperado, &dia, &mes, &ano, estado, cidade, bairro, rua, complemento,
			&CondRetEsperada);
		if (NumLidos != 17)
		{
			return TST_CondRetParm;
		}
		/* testando se a matricula é valida, isto é, tem 7 números */
		if (MatEsperada<1000000 || MatEsperada>9999999) {
			return TST_CondRetErro;
		}
		/* montando structs para testar criaaluno */
		Datateste.dia = dia;
		Datateste.mes = mes;
		Datateste.ano = ano;
		strcpy(Endteste.estado,estado);
		strcpy(Endteste.cidade,cidade);
		strcpy(Endteste.bairro,bairro);
		strcpy(Endteste.rua,rua);
		strcpy(Endteste.comp,complemento);

		CondRetObtido = ALU_CriaAluno(vtAlunos+indxaluno, StringEsperada, MatEsperada, &cpfEsperado, telefoneEsperado, &Datateste, &Endteste);
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao criar Aluno.");

	}
	/* Testar ALU Altera dados do aluno*/

	if (strcmp(ComandoTeste, ALT_DADO_CMD) == 0)
	{

		NumLidos = LER_LerParametros("isiiiiiiiiisssssi", &indxaluno, StringEsperada, &MatEsperada, &cpfEsperado.dig1, &cpfEsperado.dig2, &cpfEsperado.dig3, &cpfEsperado.cod, &telefoneEsperado, &dia, &mes, &ano, estado, cidade, bairro, rua, complemento,
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
		CondRetObtido = ALU_AlteraDados(vtAlunos[indxaluno], StringEsperada, MatEsperada, &cpfEsperado, telefoneEsperado, &Datateste, &Endteste);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao alterar dados do Aluno.");

	}
	/* Testar ALU Solicita dados do aluno*/

	/* Testar ALU Get ALL que pega todos os dados do aluno e copia para os parametros enviados*/

	if (strcmp(ComandoTeste, GET_ALL_CMD) == 0)
	{

		NumLidos = LER_LerParametros("isiiiiiiiii", &indxaluno, StringEsperada, &MatEsperada, &cpfEsperado.dig1, &cpfEsperado.dig2, &cpfEsperado.dig3, &cpfEsperado.cod, &telefoneEsperado, &indxdata, &indxendereco,
			&CondRetEsperada);
		if (NumLidos != 11)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = ALU_GetAll(vtAlunos[indxaluno], StringObtida, &MatObtida, &cpfObtido, &telefoneObtido, &vtDatas[indxdata], &vtEnds[indxendereco]);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao pegar dados do Aluno.");
	
		if (Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString(StringEsperada, StringObtida,
			"Retorno por referencia errado ao consultar nome do Aluno.") && 
			TST_CompararInt(MatObtida, MatEsperada,
				"Retorno por referencia errado ao consultar matricula do Aluno.") &&
			TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno por referencia errado ao consultar matricula do Aluno.");
		
		return Ret;
	}

	/* Testar ALU pegar matrícula do aluno */

	else if (strcmp(ComandoTeste, GET_MAT_CMD) == 0)
	{
		/*indxaluno é o index do aluno declarado no script de teste(exemplo:criar aluno0, criar aluno1, a função lerparametros pega esse 0 e 1,que são indices para um vetor de alunos criado nesse módulo para teste */
		NumLidos = LER_LerParametros("iii", &indxaluno, &MatEsperada, &CondRetEsperada);
		if (NumLidos != 3)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = ALU_GetMat(vtAlunos[indxaluno], &MatObtida);
		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno errado");
		if (Ret != TST_CondRetOK) {
			return Ret;
		}

		return TST_CompararInt(MatEsperada, MatObtida,
			"Matrícula errada.");

	}

	/* Testar ALU pegar nome do aluno */

	else if (strcmp(ComandoTeste, GET_NOME_CMD) == 0)
	{
		/*nesse caso abaixo StringNome = nome do aluno digitado no script de teste */
		NumLidos = LER_LerParametros("isi", &indxaluno, StringEsperada, &CondRetEsperada);
		if (NumLidos != 3)
		{
			return TST_CondRetParm;
		}

		CondRetObtido = ALU_GetNome(vtAlunos[indxaluno], StringObtida);
		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno errado");
		if (Ret != TST_CondRetOK) {
			return Ret;
		}
		return TST_CompararString(StringEsperada, StringObtida,
			"Nome errado.");
	}

	/* Testar deletar aluno */

	else if (strcmp(ComandoTeste, DEL_ALUN_CMD) == 0)
	{
		NumLidos = LER_LerParametros("ii", &indxaluno, &CondRetEsperada);
		if (NumLidos != 2)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = ALU_deletaAluno(vtAlunos[indxaluno]);
		vtAlunos[indxaluno] = NULL;
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno errado");
	}
	/* Testar imprimir aluno */
	else if (strcmp(ComandoTeste, IMP_ALUN_CMD) == 0)
	{
		NumLidos = LER_LerParametros("ii", &indxaluno,
			&CondRetEsperada);
		if (NumLidos != 2)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = ALU_imprimeAluno(vtAlunos[indxaluno]);
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}

	return TST_CondRetNaoConhec;

}
