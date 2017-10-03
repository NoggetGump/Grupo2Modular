#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MEN_menuInicial(void);
void MEN_menuAluno(void);
int MEN_loginAluno(void);
int MEN_loginProfessor(void);
void MEN_menuProfessor(void);

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
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			default:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
		}
	}
}

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
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
		}
	}
}

int MEN_loginAluno(void)
{
	char mat[81];

	printf("\nLogin Aluno\n");

	printf("\nDigite a matricula: ");
	scanf("%s", mat);

	//Quando o modulo aluno estive funcionado irá ser feita
	system("cls");
	return 1;
}

int MEN_loginProfessor(void)
{
	char mat[81];

	printf("\nLogin Professor\n");

	printf("\nDigite a matricula: ");
	scanf(" %s", mat);

	//Quando o modulo aluno estive funcionado irá ser feita
	system("cls");
	return 1;
}

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
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
		}
	}

}