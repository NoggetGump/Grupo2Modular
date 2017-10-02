#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Aluno.h"
#include "disciplina.h"
#include "listas.h"
#include "professor.h"
#include "sala.h"
#include "turma.h"

int main(void)
{
int opcao = 0, pOP = 0, aOP = 0, aDOP = 0;

// Ponteiros


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
		system("cls");
			while(pOP == 0)
			{
				printf("\nDigite 1: ver horarios");
				printf("\nDigite 2: adicionar grau");
				printf("\nDigite 3: ver turmas");
				printf("\nDigite 4: modificar dados");
				printf("\nDigite 5: para sair\n");
				scanf("%d", &pOP);

				switch(pOP)
				{
				case 1:
					// Ver horarios
					break;
				case 2:
					//adicionar grau
					system("cls");
					break;
				case 3:
					//ver turmas
					system("cls");
					break;
				default:
					break;
				}
			}
		break;
	case 2:
		//ir menu aluno
			while(aOP == 0)
			{
				printf("\nDigite 1: ver horarios");
				printf("\nDigite 2: ver disciplina");
				printf("\nDigite 3: ver grade");
				printf("\nDigite 3: cancelar disciplina");
				printf("\nDigite 4: cancelar marticula");
				printf("\nDigite 5: modificar dados");
				printf("\nDigite 6: controle de faltas");
				printf("\nDigite 7: HISTORICO");
				printf("\nDigite 8: ver disciplinas a cursar");
				//tem mais estou procurando
				printf("\nDigite 9: para sair\n");
				scanf("%d", &aOP);

				switch(aOP)
				{
				case 1:
					// Ver horarios
					break;
				case 2:
					//adicionar grau
					system("cls");
					break;
				case 3:
					//ver turmas
					system("cls");
					break;
				default:
					break;
				}
			}
		system("cls");
		break;
	case 3:
		//ir menu admistrador
			while(aOP == 0)
			{
				printf("\nDigite 1: adiconar aluno");
				printf("\nDigite 2: adicionar professor");
				printf("\nDigite 3: ver turmas");
				printf("\nDigite 3: ver alunos");
				printf("\nDigite 4: deletar um aluno");
				printf("\nDigite 5: deletar um professor");
				printf("\nDigite 6: adicionar uma disciplina");
				printf("\nDigite 7: mudar criterio de avaliação");
				printf("\nDigite 8: mudar salas");
				printf("\nDigite 9: adicionar uma sala");
				//tem mais estou procurando
				printf("\nDigite 10: para sair\n");
				scanf("%d", &aDOP);

				switch(aDOP)
				{
				case 1:
					// Ver horarios
					break;
				case 2:
					//adicionar grau
					system("cls");
					break;
				case 3:
					//ver turmas
					system("cls");
					break;
				default:
					break;
				}
			}
		system("cls");
		break;
	default:
		//sair do programa
		break;
	}

	system("cls");
}


return 0;
}