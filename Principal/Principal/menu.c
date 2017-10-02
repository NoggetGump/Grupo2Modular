#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MenuInicial(void);
int MenuProfessor(void);
int MenuAluno(void);
int MenuAdmistrador(void);
int LoginAluno(void);
int LoginProfessor(void);
int LoginAdmistrador(void);
int ProsLoginAdmistrador(void);
int ProsLoginProfessor(void);
int ProsLoginAdmistrador(void);
int ProsLoginAluno(void);

int MenuInicial(void)
{
	int opcao = 0;
	int retMenuProfessor = 0, retMenuAluno = 0, retMenuAdmistrador = 0;

	while (opcao == 0)
	{
		printf("\nDigite 1: para logar como porfessor");
		printf("\nDigite 2: para logar como aluno");
		printf("\nDigite 3: para logar como admistrador");
		printf("\nDigite 4: para sair\n");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
		case 1:
			//ir menu professor
			retMenuProfessor = MenuProfessor();
			break;
		case 2:
			//ir menu aluno
			retMenuAluno = MenuAluno();
			break;
		case 3:
			//ir menu admistrador
			retMenuAdmistrador = LoginAdmistrador();
			break;
		default:
			//sair do programa
			break;
		}

		system("cls");
	}

	return 1;
}

int MenuProfessor(void)
{
	int opcao = 0;
	int retMenuProfessor = 0, retMenuAluno = 0, retMenuAdmistrador = 0;

	while (opcao == 0)
	{
		printf("\nDigite 1: lista professores");
		printf("\nDigite 2: para logar como aluno");
		printf("\nDigite 3 para logar como admistrador");
		printf("\nDigite 4 para sair\n");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
		case 1:
			//ir menu professor
			retMenuProfessor = MenuProfessor();
			break;
		case 2:
			//ir menu aluno
			retMenuAluno = MenuAluno();
			break;
		case 3:
			//ir menu admistrador
			retMenuAdmistrador = MenuAdmistrador();
			break;
		default:
			//sair do programa
			break;
		}

		system("cls");
	}

	return 1;
}

int MenuAluno(void)
{
	int opcao = 0;
	int retMenuProfessor = 0, retMenuAluno = 0, retMenuAdmistrador = 0;

	while (opcao == 0)
	{
		printf("\nDigite 1 para logar como porfessor");
		printf("\nDigite 2 para logar como aluno");
		printf("\nDigite 3 para logar como admistrador");
		printf("\nDigite 4 para sair\n");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
		case 1:
			//ir menu professor
			retMenuProfessor = MenuProfessor();
			break;
		case 2:
			//ir menu aluno
			retMenuAluno = MenuAluno();
			break;
		case 3:
			//ir menu admistrador
			retMenuAdmistrador = MenuAdmistrador();
			break;
		default:
			//sair do programa
			break;
		}

		system("cls");
	}

	return 1;
}

int MenuAdmistrador(void)
{
	int opcao = 0;
	int retMenuProfessor = 0, retMenuAluno = 0, retMenuAdmistrador = 0;

	while (opcao == 0)
	{
		printf("\nDigite 1 para logar como porfessor");
		printf("\nDigite 2 para logar como aluno");
		printf("\nDigite 3 para logar como admistrador");
		printf("\nDigite 4 para sair\n");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
		case 1:
			//ir menu professor
			retMenuProfessor = MenuProfessor();
			break;
		case 2:
			//ir menu aluno
			retMenuAluno = MenuAluno();
			break;
		case 3:
			//ir menu admistrador
			retMenuAdmistrador = MenuAdmistrador();
			break;
		default:
			//sair do programa
			break;
		}

		system("cls");
	}

	return 1;
}

int LoginAluno(void)
{

}

int LoginProfessor(void)
{
	
}

int LoginAdmistrador(void)
{
	char* adminName = "admin", *entraNome;
	char* adminSenha = "admin", *entraSenha;

	printf("\nLogin para Admistradores\n");
	printf("\nDigite o nome: ");
	scanf(" %s", &entraNome);
	printf("\nDigite a senha: ");
	scanf(" %s", &entraSenha);

	if(strcmp(adminName, entraNome) == 0 && strcmp(adminSenha, entraSenha) == 0)
	{
		printf("Login feito com sucesso\n");
		system("cls");
		return 1;
	}
	else
	{
		printf("Login erro\n");
		system("cls");
		return 0;
	}
}

int ProsLoginAdmistrador(void)
{
	//Ponteiro necessarios

	//Variaveis necessarias


	return 1;
}

int ProsLoginAluno(void)
{
	//Ponteiro necessarios

	//Variaveis necessarias


	return 1;
}

int ProsLoginProfessor(void)
{
	//Ponteiro necessarios

	//Variaveis necessarias


	return 1;
}