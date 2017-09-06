#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "aluno.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_ALN_CMD       "=criar"
#define     GET_MAT_CMD         "=getmat"
#define     GET_NOME_CMD        "=getnome"
#define     ALT_DADO_CMD        "=alteradado"
#define     SOL_DADO_CMD        "=solicdado"
#define     GET_ALL_CMD         "=getall"
#define     VAL_DATA_CMD        "=valdata"
#define     INS_DADO_CMD        "=insdado"
#define     IMP_ALUN_CMD        "=impaluno"

#define DIM_VT_ALUNO   10

Aluno vtAlunos[ DIM_VT_ALUNO ] ;


   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      ALN_tpCondRet CondRetObtido   = ALN_CondRetOK ;
      ALN_tpCondRet CondRetEsperada = ALN_CondRetFaltouMemoria ;
                               /* inicializa para qualquer coisa,é só para inicializar as variáveis */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
	  int MatEsperada = '-1';
	  int MatObtida = '-1' ;
	  int indxaluno ='-1';
	
      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar ALN Criar aluno -AINDA INCOMPLETA*/

         if ( strcmp( ComandoTeste , CRIAR_ALN_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" ,&indxaluno,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = ALN_CriarAluno( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar Aluno." );

         } /* fim ativa: Testar ARV Criar árvore */

      /* Testar ALN pegar matrícula do aluno */

         else if ( strcmp( ComandoTeste , GET_MAT_CMD ) == 0 )
         {
			 /*indxaluno é o index do aluno declarado no script de teste(exemplo:criar aluno0, criar aluno1, a função lerparametros pega esse 0 e 1,que são indices para um vetor de alunos criado nesse módulo para teste */
            NumLidos = LER_LerParametros( "isi" ,&indxaluno,&MatEsperada,&CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GetMat(vtAlunos[indxaluno], &MatObtida);
			Ret = TST_CompararInt(CondRetEsperada,CondRetObtido,"Retorno errado");
			if(Ret != TST_CondRetOK){
				return Ret;
			}

            return TST_CompararInt( MatEsperada,MatObtida,
                                    "Matrícula errada." );

         }

      /* Testar ALN pegar nome do aluno */

         else if ( strcmp( ComandoTeste , GET_NOME_CMD ) == 0 )
         {
			 /*nesse caso abaixo ValorEsperado = nome do aluno digitado no script de teste */
            NumLidos = LER_LerParametros( "isi" ,&indxaluno,&ValorEsperado,&CondRetEsperada );
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GetNome(vtAlunos[indxaluno], &ValorObtido);
			Ret = TST_CompararInt(CondRetEsperada,CondRetObtido,"Retorno errado");
			if(Ret != TST_CondRetOK){
				return Ret;
			}

            return TST_CompararChar( ValorEsperado,ValorObtido,
                                    "Nome errado." );

         }

      /* Testar deletar aluno */

    else if ( strcmp( ComandoTeste , DEL_ALUN_CMD ) == 0 )
         {
			NumLidos = LER_LerParametros( "i", &indxaluno ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */
             deletaAluno( vtAlunos[ indxaluno ]) ;
            vtAlunos[ inxaluno] = NULL ;
            return TST_CondRetOK ;
         }
		 /* Testar imprimir aluno */
		   else if ( strcmp( ComandoTeste ,  IMP_ALUN_CMD) == 0 )
         {
			NumLidos = LER_LerParametros( "ci" ,&indxaluno,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */
            CondRetObtido = imprimeAluno( vtAlunos[ indxaluno]) ;
            return TST_CompararInt(condRetEsperada,CondRetObtida,"Retorno Errado");

         }

      return TST_CondRetNaoConhec ;

   }

      

