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

/***** Protótipos das funções encapsuladas no módulo *****/
void MEN_menuInicial(void);
void MEN_menuAluno(void);
int MEN_loginAluno(void);
int MEN_loginProfessor(void);
void MEN_menuProfessor(void);
void MEN_menuPAdministrativo(void);
int MEN_loginAdministrativo(void);

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: MEN_menuInicial
*  ****/

void MEN_menuInicial(void)
{
	int opcao = 0;

	while(opcao != 4)
	{
		printf("\nMenu SAU\n");
		printf("\nDigite 1: ir menu Aluno");
		printf("\nDigite 2: ir menu Professor");
		printf("\nDigite 3: ir menu Administrativo");
		printf("\nDigite 4: para sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				MEN_menuAluno();
				break;
			case 2:
				system("cls");
				 MEN_menuProfessor();
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 3:
				system("cls");
				MEN_menuPAdministrativo();
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			default:
				if(opcao != 4)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}
}


/***************************************************************************
*
*  Função: MEN_menuAluno
*  ****/

void MEN_menuAluno(void)
{
	int opcao = 0;

	if(MEN_loginAluno() == 1) // Se volta 1, ok.

	while(opcao != 8)
	{
		printf("\nMenu Aluno\n");
		printf("\nDigite 1: ver disciplinas");
		printf("\nDigite 2: ver horarios");
		printf("\nDigite 3: ver nota");
		printf("\nDigite 4: ver historico");
		printf("\nDigite 5: modificar dados pessoais");
		printf("\nDigite 6: cancelar disciplina");
		printf("\nDigite 7: trancar a faculdade");
		printf("\nDigite 8: sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 2:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 3:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 4:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 5:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 6:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 7:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 8:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			default:
				if(opcao != 8)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}
}

/***************************************************************************
*
*  Função: MEN_loginAluno
*  ****/

int MEN_loginAluno(void)
{
	int mat;

	printf("\nLogin Aluno\n");

	printf("\nDigite a matricula: ");
	scanf("%d", &mat);

	//Quando o modulo aluno estive funcionado irá ser feita
	system("cls");
	return 1;
}

/***************************************************************************
*
*  Função: MEN_loginProfessor
*  ****/

int MEN_loginProfessor(void)
{
	int mat;

	printf("\nLogin Professor\n");

	printf("\nDigite a matricula: ");
	scanf("%d", &mat);

	//Quando o modulo aluno estive funcionado irá ser feita
	system("cls");
	return 1;
}

/***************************************************************************
*
*  Função: MEN_menuProfessor
*  ****/

void MEN_menuProfessor(void)
{
	int opcao = 0;

	if(MEN_loginProfessor() == 1) // Se volta 1, ok.

	while(opcao != 6)
	{
		printf("\nMenu Aluno\n");
		printf("\nDigite 1: ver disciplinas");
		printf("\nDigite 2: ver horarios");
		printf("\nDigite 3: ver nota");
		printf("\nDigite 4: ver turmas");
		printf("\nDigite 5: modificar dados pessoais");
		printf("\nDigite 6: sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 2:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 3:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 4:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 5:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			default:
				if(opcao != 6)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}

}

/***************************************************************************
*
*  Função: MEN_menuPAdministrativo
*  ****/

void MEN_menuPAdministrativo(void)
{
	int opcao = 0;
	char nome[81];
	unsigned int mat, telefone;
	Data nasc; 
	Endereco end;
	CPF cpf;

	if(MEN_loginAdministrativo() == 1) // Se volta 1, ok.

	while(opcao != 16)
	{
		printf("\nMenu Aluno\n");
		printf("\nDigite 1: ver alunos");
		printf("\nDigite 2: ver professores");
		printf("\nDigite 3: ver disciplina");
		printf("\nDigite 4: ver criterio de aprovação");
		printf("\nDigite 5: adicionar aluno");
		printf("\nDigite 6: deletar aluno");
		printf("\nDigite 7: adicionar professor");
		printf("\nDigite 8: deletar professor");
		printf("\nDigite 9: deletar sala");
		printf("\nDigite 10: adicionar sala");
		printf("\nDigite 11: deletar turma");
		printf("\nDigite 12: adicionar turma");
		printf("\nDigite 13: modificar grade");
		printf("\nDigite 14: modificar dados pessoais de um aluno");
		printf("\nDigite 15: modificar dados pessoais de um professor");
		printf("\nDigite 16: sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				CDI_imprime();
				break;
			case 2:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 3:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 4:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 5:
				system("cls");
				printf("\nDigite o nome do aluno: \n");
				scanf(" %s", nome);
				printf("\nDigite a matricula: \n");
				scanf("%d", &mat);
				printf("\nDigite a telefone: \n");
				scanf("%d", &telefone);
				printf("\nDigite a data de nacimento: \n");
				scanf("%d %d %d", nasc.dia, nasc.mes, nasc.ano);
				printf("\nDigite o cpf: \n");
				scanf("%d.%d.%d-%d", cpf.dig1, cpf.dig2, cpf.dig3, cpf.cod);
				printf("\nDigite o estado\n");
				scanf("%s", end.estado);
				printf("\nDigite a cidade\n");
				scanf("%s", end.cidade);
				printf("\nDigite o bairro\n");
				scanf("%s", end.bairro);
				printf("\nDigite a rua\n");
				scanf("%s", end.rua);
				printf("\nDigite o comp\n");
				scanf("%s", end.comp);
				CDI_insere(nome, mat, &cpf, telefone, &nasc, &end);
				break;
			case 6:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 7:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 8:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 9:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 10:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 11:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 12:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 13:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 14:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 15:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			default:
				if(opcao != 16)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}
}

/***************************************************************************
*
*  Função: MEN_loginAdministrativo
*  ****/

int MEN_loginAdministrativo(void)
{
	char user[81];
	char senha[81];
	printf("\nLogin Administrador\n");

	printf("\nDigite a matricula: ");
	scanf(" %s", user);

	printf("\nDigite a senha: ");
	scanf(" %s", senha);

	if(strcmp("admin", user) == 0 && strcmp("admin", senha) == 0 )
	{
		system("cls");
		return 1;
	}

	system("cls");
	return 0;
}