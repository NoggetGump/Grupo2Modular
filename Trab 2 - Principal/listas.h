/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Lista
*
*  Arquivo gerado:              listas.h
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
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa o m�dulo lista duplamente encadeada para ser utilizada pelos demais m�dulos do projeto "Sistema Acad�mico da turma 3wb".
*	  Uma lista(list) cont�m um cabe�alho, com um n� apontanto para o primeiro item da lista, um apontando para o �ltimo e outro apontando para o n� cursor.
*	  N�s(node(s)) s�o estrutura contendo o pr�ximo n� e o anterior (duplamente encadeada) e cont�m um ponteiro para um valor (void*)
***************************************************************************/

typedef struct node Node;

typedef struct list List;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Condi��es de retorno
*
*
***********************************************************************/
   typedef enum {
     LIS_CondRetOK = 0 ,
     /* Executou correto */
     LIS_CondRetListaVazia = 1,
     /* Estrutura list est� deletada */
     LIS_CondRetFaltouMemoria = 2 ,
     /* Faltou mem�ria ao alocar dados */
     LIS_CondRetCursorNoFinal = 3,
	 /* Imposs�vel obter pr�ximo */
	 LIS_CondRetCursorNoInicio = 4
	 /* Imposs�vel obter anterior*/

   }LIS_tpCondRet;
/***********************************************************************
*
*  $FC Fun��o: LIS create List
*
*  $ED Descri��o da fun��o
*    Cria uma lista vazia
*
***********************************************************************/
LIS_tpCondRet createList(List** l);
/***********************************************************************
*
*  $FC Fun��o: LIS del
*
*  $ED Descri��o da fun��o
*    Deleta uma lista j� criada
*
***********************************************************************/
LIS_tpCondRet del(List* l);
/***********************************************************************
*
*  $FC Fun��o: LIS clear
*
*  $ED Descri��o da fun��o
*    Limpa uma lista criada para zero n�s
*
***********************************************************************/
LIS_tpCondRet clear(List* l);
/***********************************************************************
*
*  $FC Fun��o: LIS push back
*
*  $ED Descri��o da fun��o
*    Insere um elemento no final da List
*
***********************************************************************/
LIS_tpCondRet push_back(List* l, void* val);
/***********************************************************************
*
*  $FC Fun��o: LIS push front
*
*  $ED Descri��o da fun��o
*    Insere um elemento no come�o da List
*
***********************************************************************/
LIS_tpCondRet push_front(List* l, void* val);
/***********************************************************************
*
*  $FC Fun��o: LIS pop back
*
*  $ED Descri��o da fun��o
*    Atualiza o par�metro val, referenciado, para o �ltimo elemento da lista, que � removido da mesma.
*
***********************************************************************/
LIS_tpCondRet pop_back(List* l, void** val);
/***********************************************************************
*
*  $FC Fun��o: LIS pop front
*
*  $ED Descri��o da fun��o
*    Atualiza o par�metro val, referenciado, para o primeiro elemento da lista, que � removido da mesma.
*
***********************************************************************/
LIS_tpCondRet pop_front(List* l, void** val);
/***********************************************************************
*
*  $FC Fun��o: LIS pop cursor
*
*  $ED Descri��o da fun��o
*    Remove o n� cursor da lista e retorna a refer�ncia para seu valor. 
*	 Caso o n� cursor seja o �ltimo n�, o cursor se torna o anterior, caso seja o primeiro
*	 o cursor se torna o seguinte. Em qualquer outro caso o cursor se torna o pr�ximo.
*
***********************************************************************/
LIS_tpCondRet pop_cursor(List* l, void** val);
/***********************************************************************
*
*  $FC Fun��o: LIS get val cursor
*
*  $ED Descri��o da fun��o
*    Atualiza o par�metro val para o valor no n� cursor.
*
***********************************************************************/
LIS_tpCondRet get_val_cursor(List* l, void** val);
/***********************************************************************
*
*  $FC Fun��o: LIS list size
*
*  $ED Descri��o da fun��o
*    Atualiza o parametro size para o tamanho da lista.
*
***********************************************************************/
LIS_tpCondRet list_size(List* l, unsigned int* size); //retorna a quantidade de elementos na List
/***********************************************************************
*
*  $FC Fun��o: LIS first
*
*  $ED Descri��o da fun��o
*    Atualiza para o primeiro n� da lista
*
***********************************************************************/
LIS_tpCondRet first(List* l);
/***********************************************************************
*
*  $FC Fun��o: LIS next
*
*  $ED Descri��o da fun��o
*    Atualiza o cursor para o pr�ximo n�
*
***********************************************************************/
LIS_tpCondRet next(List* l);//atualiza o cursor para o pr�ximo n�
/***********************************************************************
*
*  $FC Fun��o: LIS prev
*
*  $ED Descri��o da fun��o
*    Atualiza o cursor para o n� anterior
*
***********************************************************************/
LIS_tpCondRet prev(List* l);//atualiza o cursor para o n� anterior