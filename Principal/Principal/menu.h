
typedef enum{
	MEN_CondRetOK,	// Executou corretamente
	MEN_CondReteERRO // Há erros
}	MEN_tpCondRet;

//Primeiro menu a ser exibido. Retorna 1, quando não há erro. Retorna 0, quando há erro.
MEN_tpCondRet MenuInicial(void);

//Menu que possui todas as opções ligada ao modulo professor. Retorna 1, quando não há erro. Retorna 0, quando há erro.
MEN_tpCondRet MenuProfessor(void);

//Menu que possui todas as opções ligadas ao modulo aluno. Retorna 1, quando não há erro. Retorna 0, quando há erro.
MEN_tpCondRet MenuAluno(void);

//Menu que possui todas as opções administrativas. Retorna 1, quando não há erro. Retorna 0, quando há erro.
MEN_tpCondRet MenuAdmistrador(void);

//Autenticação para alunos. Retorna 1, quando não há erro. Retorna 0, quando há erro.
MEN_tpCondRet LoginAluno(void);

//Autenticação para professores. Retorna 1, quando não há erro. Retorna 0, quando há erro.
MEN_tpCondRet LoginProfessor(void);

//Autenticação para administradores. Retorna 1, quando não há erro. Retorna 0, quando há erro.
MEN_tpCondRet LoginAdmistrador(void);

//Essa função será responsável pela funcionalidades administrativas. Retorna 1, quando não há erro. Retorna 0, quando há erro.
MEN_tpCondRet ProsLoginAdmistrador(void);

//Essa função será responsável pela funcionalidades dos professores. Retorna 1, quando não há erro. Retorna 0, quando há erro.
MEN_tpCondRet ProsLoginProfessor(void);

//Essa função será responsável pela funcionalidades dos alunos. Retorna 1, quando não há erro. Retorna 0, quando há erro.
MEN_tpCondRet ProsLoginAluno(void);
