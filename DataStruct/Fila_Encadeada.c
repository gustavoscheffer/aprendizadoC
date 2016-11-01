/***********************************************/ 
/* Fila Encadeada                              */
/* objetivo: cadastro academico                */
/* programador: Daniela Bagatini               */
/* criado em: 27/07/2015                       */
/* data da ultima alteracao: 27/07/2015        */
/***********************************************/ 

#include <stdio.h>
#include <stdio_ext.h> // fpurge()
//#include <conio.h> not used on linux 
#include <stdlib.h>
#include <string.h>



/***********************************************/ 
/* Definicao dos Registros                     */
/***********************************************/ 
typedef struct {          // registro para uma pessoa
       int  matr;
       char nome[30];
} INFORMACAO;
       
typedef struct fila {
       INFORMACAO info;   // dados do registro
       struct fila* prox; // ponteiro para o pr�ximo registro
} FILA;



/***********************************************/ 
/* Definicao das Funcoes                       */
/***********************************************/ 
void entrada_dados    ( FILA* aux );
void imprime_fila     ( FILA* aux );
void cria_fila        ( FILA** f );
void insere           ( FILA** f );
FILA* procura_nodo    ( FILA* f, int matricula );
void exclui           ( FILA** f );
     
    

/***********************************************/ 
/* Programa Principal                          */
/***********************************************/ 
int main( void )
{
    char op;  // opcao do menu                               
    FILA* f;  // declaracao da fila // variavel do tipo fila = fila de ponteiros


    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Programa de cadastro academico - Menu                " );
         printf( "\n [1] Cria fila                                        " );
         printf( "\n [2] Insere                                           " );
         printf( "\n [3] Remove                                           " );
         printf( "\n [4] Imprime fila                                     " );
         printf( "\n [5] Para sair do programa                            " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opcao: " );
         op = getchar(); // tecla de opcao do menu


         switch( op ) {
           case '1':   // rotina cria fila       
                    cria_fila( &f );
                    break;
                                
           case '2':  // rotina inclui registro na fila
                    insere( &f );    
                    break;
                     
           case '3':  // rotina exclui registro da fila
                   exclui( &f );
                   break;
                                 
           case '4': // rotina imprime fila                 
                   imprime_fila( f ); 
                   break;
                                
           case '5': // termino do programa                                                 
                   exit( 1 ); 
                   break;
                
           default : 
                   printf( "\n Digite uma opcao!" );
                   break;
        } // switch( op )
 
        
        __fpurge( stdin );
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        getchar();       // parada da tela
        
        printf( "\n" );
     } // fim do while( 1 )
     
 return 0;
} // fim do programa principal



/************************************************ 
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : nodo (ponteiro para o novo espaco) *
 * saida   : auxiliar com dados                 *
 ************************************************/
void entrada_dados( FILA* aux )
{ 
    printf( "\n\n Digite a matricula: " ); 
    __fpurge( stdin );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    scanf("%d", &aux->info.matr);
  
  /*
    printf( "\n Digite o nome: " );
    __fpurge( stdin );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->info.nome );
  */
    aux->prox = NULL;    // n�o aponta
}



/*************************************************
 * imprime_fila                                  *
 * objetivo: rotina para imprimir dados          *
 * entrada : fila                                *
 * saida   : nenhuma                             *
 *************************************************/ 
void imprime_fila( FILA* aux )
{
    
    if( aux == NULL )
        printf( "\n Underflow - Fila vazia!" );
    else {
         printf("\n ---- Relatorio Geral ---- ");
         while( aux != NULL ){
                /*printf( "\n Nome.....: %s", aux->info.nome ); */
                printf( "\n Matricula: %d", aux->info.matr );
                aux = aux->prox;
         } // fim while( aux != NULL )
    } // fim if( aux == NULL )
}



/************************************************
 * cria_fila                                    *
 * objetivo: rotina para inicializar a fila     *
 * entrada : fila                               *
 * saida   : NULL (inicializa fila)             *
 ************************************************/ 
void cria_fila( FILA** f )
{
    *f = NULL; // fila criada, inicio nao aponta
    printf("\nLista criada com sucesso!");
}



/************************************************ 
 * insere                                       *
 * objetivo: rotina para inserir no fim da fila *
 * entrada : fila                               *
 * saida   : fila com novo registro             *
 ************************************************/ 
void insere( FILA** f )
{       
  //RESERVA UM ESPAÇO PARA O NODO DA LISTA
  FILA* nodo  = (FILA*) malloc(sizeof(FILA));
  FILA* aux  = *f;

  //VERIFICA SE A MEMORIA FOI RESERVADA
  if(nodo !=NULL){

    //COLOCA OS DADOS NO NODO
    entrada_dados(nodo);

    if (*f == NULL)
    {
     
     *f = nodo;

    }else{

      //COM UM AUXILIAR VAMOS NODO POR NODO ATÉ O FIM DA FILA 
      while(aux->prox != NULL){
         aux = aux->prox;    
         printf("\n Passou");    
      }
      
      //PROXIMO REGISTRO NULO RECEBE O NOVO NODO 
      printf("\n Chegamos aqui");    
      aux->prox = nodo;

    }

  }else{

    printf("\n Nun ha memoria disponível");
  
  }
}



/*************************************************** 
 * exclui                                          *
 * objetivo: rotina para excluir nodo da fila      *
 * entrada : fila                                  *
 * sa�da   : fila com registro removido do inicio  *
 ***************************************************/ 
void exclui( FILA** f )
{
  
  //VERIFICAR SE A FILA ESTA VAZIA
  if (*f != NULL)
  {
    //CRIAR FILA AUXILIAR
    FILA * aux = *f;
    
    //FAÇO O INICIO DA FILA APONTAR PARA O SEGUNDO ITEM
    *f = aux->prox;
    
    //LIMPO O APONTAMENTO DO ANTIGO PRIMEIRO NODO
    free(aux);

    printf("\nItem excluido!");

  }else{

    printf("\nFila vazia!");
  
  }
  



}

