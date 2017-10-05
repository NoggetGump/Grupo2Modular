/***************************************************************************
*
*  $MCI M�dulo de defini��o: M�dulo Lista
*
*  Arquivo gerado:              listas.c
*  Letras identificadoras:      LIS
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acad�mico da turma 3WB
*  Gestor:  Grupo 4
*  Autores:   mrol - Matheus Rodrigues de Oliveira Leal
*             SaintL - Leonardo Abreu Santos
*	      	  ngtgmp - Felipe Nogueira de Souza
LL - Clayton Lucas Mendes Lima
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       0.01   ngtgmp   10/09/2017 In�cio do desenvolvimento
*		0.02   ngtgmp   21/09/2017 Implementa��o de mais fun��es
*		0.03   ngtgmp   27/09/2017 Preparo para os testes automatizados e revis�o do c�digo
*		0.04   ngtgmp   01/10/2017 Reparos ap�s testes e revis�o
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include"listas.h"
/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Lista
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o dos N�s em uma Lista
*
***********************************************************************/
struct node
{
	struct node* next;	//Aponta para o pr�ximo n�
	struct node* prev;  //Aponta para o n� anterior
	void* val;			//Aponta para vari�vel val
};
/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Lista
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o de uma Lista pelo cabe�alho. Pode-se fazer Listas de Listas.
*
***********************************************************************/
struct list
{
	Node* first;  //Aponta para o primeiro n�
	Node* last;	  //Aponta para o �ltimo n�
	Node* cursor; //Aponta para o n� cursor
};
/***************************************************************************
*
*  Fun��o: LIS create list
*  ****/
LIS_tpCondRet createList(List** l) { (*l) = (List*)calloc(1, sizeof(List)); if (!l) return LIS_CondRetFaltouMemoria; (*l)->first = NULL; (*l)->last = NULL; (*l)->cursor = NULL; return LIS_CondRetOK; }
/* Fim fun��o: LIS create lista */
/***************************************************************************
*
*  Fun��o: LIS del
*  ****/
LIS_tpCondRet del(List* l)
{
	Node* tnode = l->first;
	l->cursor = l->first;
	while (tnode != NULL)
	{
		l->cursor = l->cursor->next;
		free(tnode);
		tnode = l->cursor;
	}
	free(l);
	return LIS_CondRetOK;
}/* Fim fun��o: LIS del */
 /***************************************************************************
 *
 *  Fun��o: LIS clear
 *  ****/
LIS_tpCondRet clear(List* l)
{
	Node* tnode = l->first;
	l->cursor = l->first;
	while (tnode != NULL)
	{
		l->cursor = l->cursor->next;
		free(tnode);
		tnode = l->cursor;
	}
	l->first = NULL;
	l->last = NULL;
	l->cursor = NULL;
	return LIS_CondRetOK;
}/* Fim fun��o: LIS del */
 /***************************************************************************
 *
 *  Fun��o: LIS push back
 *  ****/
LIS_tpCondRet push_back(List* l, void* val)
{
	Node* Nnode;
	Nnode = (Node*)calloc(1, sizeof(Node));
	if (!Nnode)
		return LIS_CondRetFaltouMemoria;
	Nnode->val = val;
	Nnode->next = NULL;
	if (l->first == NULL)//Se a lista estiver vazia, primeiro n� = �ltimo n� = n� cursor.
	{
		l->first = Nnode;
		l->cursor = Nnode;
		Nnode->prev = NULL;
	}
	else
	{
		Nnode->prev = l->last;
		l->last->next = Nnode;
	}
	l->last = Nnode;
	return LIS_CondRetOK;
} /* Fim fun��o: LIS push back */
  /***************************************************************************
  *
  *  Fun��o: LIS push front
  *  ****/
LIS_tpCondRet push_front(List* l, void* val)
{
	Node* Nnode;
	Nnode = (Node*)calloc(1, sizeof(Node));
	if (!Nnode)
		return LIS_CondRetFaltouMemoria;
	Nnode->val = val;
	Nnode->prev = NULL;
	if (l->first == NULL)
	{
		l->last = Nnode;
		l->cursor = Nnode;
		Nnode->next = NULL;
	}
	else
	{
		Nnode->next = l->first;
		l->first->prev = Nnode;
	}
	l->first = Nnode;
	return LIS_CondRetOK;
} /* Fim fun��o: LIS push front */
  /***************************************************************************
  *
  *  Fun��o: LIS pop back
  *  ****/
LIS_tpCondRet pop_back(List* l, void** val)
{
	Node* tnode;
	if (l->first == NULL) { return LIS_CondRetListaVazia; }

	*val = l->last->val;

	if (l->first == l->last)
	{
		l->first = NULL;
		l->last = NULL;
		l->cursor = NULL;
		return LIS_CondRetOK;
	}
	if (l->cursor == l->last)
		l->cursor = l->last->prev;
	tnode = l->last;
	l->last = l->last->prev;
	l->last->next = NULL;
	tnode->prev = NULL;
	return LIS_CondRetOK;
} /* Fim fun��o: LIS pop back */
  /***************************************************************************
  *
  *  Fun��o: LIS pop front
  *  ****/
LIS_tpCondRet pop_front(List* l, void** val)
{
	Node* tnode;
	if (l->first == NULL) { return LIS_CondRetListaVazia; }

	*val = l->first->val;

	if (l->first == l->last)
	{
		l->first = NULL;
		l->last = NULL;
		l->cursor = NULL;
		return LIS_CondRetOK;
	}
	if (l->cursor == l->first)
		l->cursor = l->first->next;
	tnode = l->first;
	l->first = l->first->next;
	l->first->prev = NULL;
	tnode->next = NULL;
	return LIS_CondRetOK;
} /* Fim fun��o: LIS pop front */
  /***************************************************************************
  *
  *  Fun��o: LIS pop cursor
  *  ****/
LIS_tpCondRet pop_cursor(List* l, void** val)
{
	Node* tnode;
	if (l->cursor == l->first)
		return pop_front(l, val);
	else if (l->cursor == l->last)
		return pop_back(l, val);
	else
	{
		if (l->first == NULL) { return LIS_CondRetListaVazia; }

		*val = l->cursor->val;

		if (l->first == l->last)
		{
			l->first = NULL;
			l->last = NULL;
			l->cursor = NULL;
			return LIS_CondRetOK;
		}
		tnode = l->cursor;
		l->cursor->prev->next = l->cursor->next;
		l->cursor->next->prev = l->cursor->prev;
		l->cursor = l->cursor->next;
		tnode->next = NULL;
		tnode->prev = NULL;
		return LIS_CondRetOK;
	}
} /* Fim fun��o: LIS pop cursor */
  /***************************************************************************
  *
  *  Fun��o: LIS get val cursor
  *  ****/
LIS_tpCondRet get_val_cursor(List* l, void** val)
{
	if (l->first == NULL)
		return LIS_CondRetListaVazia; 
	*val = l->cursor->val;
	return LIS_CondRetOK;
}/* Fim fun��o: LIS get val cursor */
 /***************************************************************************
 *
 *  Fun��o: LIS list size
 *  ****/
LIS_tpCondRet list_size(List* l, unsigned int* size)
{
	Node *Tnode = l->first;
	*size = 0;
	if (l->first == NULL)
		return LIS_CondRetListaVazia;
	while (Tnode != NULL)
	{
		Tnode = Tnode->next;
		*size = *size + 1;
	}
	return LIS_CondRetOK;
} /* Fim fun��o: LIS list size */

  /***************************************************************************
  *
  *  Fun��o: LIS first
  *  ****/
LIS_tpCondRet first(List* l) {
	if (l->first == NULL) {
		return LIS_CondRetListaVazia;
	}
	l->cursor = l->first;
	return LIS_CondRetOK;
}


/***************************************************************************
*
*  Fun��o: LIS next
*  ****/
LIS_tpCondRet next(List* l)
{
	if (l->first == NULL) { return LIS_CondRetListaVazia; }
	else if (l->cursor->next == NULL)
	{
		return LIS_CondRetCursorNoFinal;
	}
	else l->cursor = l->cursor->next;
	return LIS_CondRetOK;
} /* Fim fun��o: LIS next */
  /***************************************************************************
  *
  *  Fun��o: LIS prev
  *  ****/
LIS_tpCondRet prev(List* l)
{
	if (l->first == NULL) { return LIS_CondRetListaVazia; }
	else if (l->cursor->prev == NULL)
	{
		return LIS_CondRetCursorNoInicio;
	}
	else l->cursor = l->cursor->prev;
	return LIS_CondRetOK;
} /* Fim fun��o: LIS prev */