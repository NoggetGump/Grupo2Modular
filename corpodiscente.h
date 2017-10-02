typedef enum {
	CDIS_CondRetOK,	// Executou corretamente
	CDIS_CondRetAlunoNaoCadastrado,	// O aluno não está cadastrado
	CDIS_CondRetFaltouMemoria	// Faltou memória ao alocar dados
} CDIS_tpCondRet;

CDIS_tpCondRet CorpoDisc_cria (void);
