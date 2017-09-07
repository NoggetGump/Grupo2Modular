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

#define DIM_VT   10
#define  DIM_STRING  250

Aluno vtAlunos[ DIM_VT] ;
Data vtDatas[ DIM_VT];
Endereco vtEnds[ DIM_VT];


   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      ALN_tpCondRet CondRetObtido   = ALN_CondRetOK ;
      ALN_tpCondRet CondRetEsperada = ALN_CondRetFaltouMemoria ;
                               /* inicializa para qualquer coisa,é só para inicializar as variáveis */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
	  char StringNome[ DIM_STRING ];
	  char StringObtido[DIM_STRING];
	  int MatEsperada = '-1';
	  int MatObtida = '-1' ;
	  int indxaluno ='-1';
	  int nome;
	  int cpf;
	  int telefone;
	  int indxdata;
	  int indxendereco;
	
      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar ALU Criar aluno*/

         if ( strcmp( ComandoTeste , CRIAR_ALN_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isiiiiii" ,&indxaluno,StringNome,&MatEsperada,&cpf,&telefone,&indxdata,&indxendereco,
                               &CondRetEsperada ) ;
            if ( NumLidos != 8 )
            {
               return TST_CondRetParm ;
            } 
			/* testando se a matricula é valida, isto é, tem 7 números */
			if(MatEsperada<1000000 || MatEsperada>9999999){
				return TST_CondRetErro;
			}
            CondRetObtido = ALU_CriaAluno(vtAlunos[indxaluno],StringNome,MatEsperada,cpf,telefone,vtDatas[indxdata],vtEnds[indxendereco]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar Aluno." );

         }

      /* Testar ALU pegar matrícula do aluno */

         else if ( strcmp( ComandoTeste , GET_MAT_CMD ) == 0 )
         {
			 /*indxaluno é o index do aluno declarado no script de teste(exemplo:criar aluno0, criar aluno1, a função lerparametros pega esse 0 e 1,que são indices para um vetor de alunos criado nesse módulo para teste */
            NumLidos = LER_LerParametros( "iii" ,&indxaluno,&MatEsperada,&CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = ALU_GetMat(vtAlunos[indxaluno], &MatObtida);
			Ret = TST_CompararInt(CondRetEsperada,CondRetObtido,"Retorno errado");
			if(Ret != TST_CondRetOK){
				return Ret;
			}

            return TST_CompararInt( MatEsperada,MatObtida,
                                    "Matrícula errada." );

         }

      /* Testar ALU pegar nome do aluno */

         else if ( strcmp( ComandoTeste , GET_NOME_CMD ) == 0 )
         {
			 /*nesse caso abaixo StringNome = nome do aluno digitado no script de teste */
            NumLidos = LER_LerParametros( "isi" ,&indxaluno,StringNome,&CondRetEsperada );
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            }

            CondRetObtido = ALU_GetNome(vtAlunos[indxaluno],StringObtido);
			Ret = TST_CompararInt(CondRetEsperada,CondRetObtido,"Retorno errado");
			if(Ret != TST_CondRetOK){
				return Ret;
			}

            return TST_CompararString( StringNome,StringObtido,
                                    "Nome errado." );
         }

      /* Testar deletar aluno */

    else if ( strcmp( ComandoTeste , DEL_ALUN_CMD ) == 0 )
         {
			NumLidos = LER_LerParametros( "ii", &indxaluno,&CondRetEsperada) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            }
            CondRetObtido=ALU_deletaAluno( vtAlunos[ indxaluno ]) ;
            vtAlunos[ indxaluno] = NULL ;
            return TST_CompararInt(CondRetEsperada,CondRetObtido,"Retorno errado");
         }
		 /* Testar imprimir aluno */
		   else if ( strcmp( ComandoTeste ,  IMP_ALUN_CMD) == 0 )
         {
			NumLidos = LER_LerParametros( "ii" ,&indxaluno,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            }
            CondRetObtido = ALU_imprimeAluno( vtAlunos[ indxaluno]) ;
            return TST_CompararInt(CondRetEsperada,CondRetObtida,"Retorno Errado");
         }

      return TST_CondRetNaoConhec ;

   }

      

      

