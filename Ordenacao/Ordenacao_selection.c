/***********************************************/ 
/* Desafio de Lista Encadeada                  */
/* Objetivo: Cadastrar institui��es            */
/* programador: Gustavo Bittencourt,     	   */
/*				Gustavo scheffer, 			   */
/*				Matheus Fonseca                */
/* criado em: 18/10/2016                       */
/* data da ultima alteracao: 18/10/2016        */
/***********************************************/


/***********************************************/ 
/* Importa��es			                       */
/***********************************************/ 
#include <stdio.h> //-> printf(),scanf()
#include <stdio_ext.h> //-> __fpurge()
#include <stdlib.h> //->malloc(),free()
#include <string.h> //-> strstr()
#include <locale.h> //

/***********************************************/ 
/* Constantes                                  */
/***********************************************/
#define T_PADRAO 50 //-> padrao de chars
#define T_MAXIMO 200 //-> maximo de chars
#define T_MINIMO 9 //-> minimo de chars
 


/***********************************************/ 
/* Defini��es dos Registros                    */
/***********************************************/ 
typedef struct {

	int codigo;
	char nome[T_PADRAO];
	char tipo[T_PADRAO];
	char zona[T_MINIMO];
	char endereco[T_MAXIMO];
	char telefone[T_MINIMO];

}ENTIDADE;

typedef struct LISTA{

	ENTIDADE entidade; // -> dados da instituicao
	struct LISTA* proximo; // -> ponteiro para o proximo registro

}LISTA;

/***********************************************/ 
/* Prototipa��o                                */
/***********************************************/
void cria_lista(LISTA* *l); // -> fun��o interna que cria uma nova lista
void inclui_entidade(LISTA* *l); // -> fun��o que inclui registros
void exclui_entidade(LISTA* *l);// -> fun��o que exclui registros
void ordenar_nomes(LISTA* *l);// -> fun��o que ordena os registros por nome
void ordenar_zona(LISTA* *l);// -> fun��o que ordena os registros por zona
void ordenar_telefone(LISTA* *l);// -> fun��o que ordena os registros por telefone
void ordenar_endereco(LISTA* *l);// -> fun��o que ordena os registros por endere�o
void ordenar_tipo(LISTA* *l);// -> fun��o que ordena os registros por tipo de entidade
void relatorio(LISTA* aux);// -> fun��o que exibe os registros
void alterar(LISTA* *l);// -> fun��o que altera os registros
LISTA* procurar(LISTA* *l);// -> fun��o interna que pesquisa registros
void consulta_geral(LISTA* l);// -> fun��o que pesquisa e exibe informa��es dos registros
void total_entidades(LISTA* aux);// -> fun��o que que conta os registros
void new_ordenacao(LISTA* *l );


/***********************************************/ 
/* Main					                       */
/***********************************************/
int main(){
setlocale(LC_ALL,"portuguese");
	/* variaveis da main aqui */
	int opcao, escolha=1; //-> op��es dos menus
	LISTA* l; // -> declaracao da lista // variavel do tipo lista = lista de ponteiros
	cria_lista(&l); // -> seta o valor default NULL para a lista

	/***************************/	

	while( 1 ){
		system("cls");
    	printf( "\n /----------------------------------------------------/" ); 
        printf( "\n Programa de cadastro - Menu                           " );
        printf( "\n [1]   Inclui entidade                                 " );
        printf( "\n [2]   Exclui entidade                                 " );
        printf( "\n [3]   Ordenar                                         " );
        printf( "\n [4]   Relatorio                                       " );         
        printf( "\n [5]   Consulta geral                                  " );                         
        printf( "\n [6]   Total de entidades                              " );      
		printf( "\n [7]   Alterar entidades                               " );           
        printf( "\n [8]   Ordenar por Codigo                              " );
        printf( "\n [0]   Para sair do programa                           " );
        printf( "\n /----------------------------------------------------/" );      
        printf( "\n Opcao: " );

        //__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
        scanf("%d", &opcao); // tecla de opcao do menu
        switch( opcao ) {
           	
           	case 1: 
           		system("cls");
           		printf( "\t INCLUIR ENTIDADE: \n" );
           		inclui_entidade( &l );
           		system("pause");
                break;
           	
           	case 2: 
           		system("cls");
           		printf( "\t EXCLUIR ENTIDADE \n" );
           		exclui_entidade(&l);
           		system("pause");
                break;
            
            case 3:
				escolha=1;        	
                while(escolha == 1){
                	
                    system("cls");
                    printf ("\n| [1] - Ordenar por Nome             |");
                    printf ("\n| [2] - Ordenar por Zona             |");
                    printf ("\n| [3] - Ordenar por Telefone         |");
                    printf ("\n| [4] - Ordenar por Endere�o         |");
                    printf ("\n| [5] - Ordenar por Tipo de entidade |");
                    printf ("\n| [6] - Voltar                       |");
                    printf ("\n -------------------------------------");
                    printf ("\n\nDigite a sua escolha agora: ");
                    fflush(stdin);
                    scanf("%d", &opcao);

                    switch(opcao) {
                        case 1:
                            ordenar_nomes(&l);
                            break;
                        case 2:
                            ordenar_zona(&l);
                            break;
                            
                        case 3:
                            ordenar_telefone(&l);
                            break;    
                            
                        case 4:
                            ordenar_endereco(&l);
                            break;    
							
						case 5:
                            ordenar_tipo(&l);
                            break; 	 
							 
                        case 6:
                            escolha = 0; //para sair do while que continua enquanto escolha == 1
                            break;
                        default:
                            printf( "\n Digite uma opcao!!\n" );
                            break;
                    }
                     		system("pause");
                }
                escolha = 1 ;
                break;
            
            case 4:
            	system("cls");
            	relatorio( l );
            	system("pause");
                break;

            case 5: 
            	system("cls");
            	printf("\t CONSULTAR \n");
            	consulta_geral( l );
            	system("pause");
            	break;

            case 6:
				system("cls"); 
            	printf( "\t TOTAL DE ENTIDADES \n" );
            	total_entidades( l );
            	system("pause");
                break; 
				
			case 7:
				system("cls");
				printf("\t ALTERAR ENTIDADES \n" );	                 
                alterar(&l);
                system("pause");
				break;
			case 8:
				system("cls");
				printf("\t ORDENA POR CODIGO \n" );	                 
                new_ordenacao(&l);
                system("pause");
				break;				   
            case 0: // termino do programa                                                 
                exit( 1 ); 
                break;
                
            default: 
               	printf( "\n Digite uma opcao!!" );
                break;
        } // switch( opcao )
 
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        
        printf( "\n" );
     } // fim do while( 1 )

	return 0;	
}

/************************************************ 
 * cria_lista(FUN��O INTERNA)                   *
 * objetivo: Cria uma lista nula inicialmente   *
 * entrada : nodo (ponteiro para o novo espaco) *
 * saida   : lista criada                       *
 ************************************************/
void cria_lista(LISTA* *l){

	*l = NULL; //seta o valor default NULL para a lista
}

/************************************************ 
 * inclui_entidade                              *
 * objetivo: inclui um novo registro na lista   *
 * entrada : nodo (ponteiro para o novo espaco) *
 * saida   : lista com + 1 registro             *
 ************************************************/
void inclui_entidade(LISTA* *l){

	LISTA *nodo = (LISTA*) malloc(sizeof(LISTA)); //Aloca mem�ria para a vari�vel
	LISTA *p; //Vari�vel auxiliar

	if(nodo !=NULL){ //Se nodo n�o estiver nulo, sem lugar na mem�ria, ent�o:

		printf("\n Digite o codigo da entidade: ");
		//__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		scanf("%d", &nodo->entidade.codigo); //Faz a leitura do c�digo

		printf("\n Digite o nome da entidade: ");
		//__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( nodo->entidade.nome, T_PADRAO, stdin); //Faz a leitura do nome

		printf("\n Digite o tipo de entidade: ");
		//__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( nodo->entidade.tipo, T_PADRAO, stdin); //Faz a leitura do tipo

		printf("\n Digite a zona da entidade: "); 
		//__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( nodo->entidade.zona, T_PADRAO, stdin); //Faz a leitura da zona

		printf("\n Digite o telefone da entidade: ");
		//__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( nodo->entidade.telefone, T_MINIMO, stdin); //Faz a leitura do telefone

		printf("\n Digite o endereco da entidade: ");
		//__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( nodo->entidade.endereco, T_MAXIMO, stdin); //Faz a leitura do endere�o

		if( *l == NULL){ //Se L estiver vazio: 

			*l = nodo;  //L passa a apontar para o novo registro
			printf(" \nRegistro incluido! ");
					
		}else{  //Caso L j� esteja apontando para outro(s) registro(s): 
		
			p = *l; //p, vari�vel auxiliar, recebe o conte�do de l
			while(p->proximo != NULL){ //percorre at� achar o fim da lista
				p = p->proximo;	//faz o deslocamento
			}

			p->proximo = nodo; //Quando encontra o ultimo item da lista, inclui o novo registro como �ltimo
			printf(" \nRegistro incluido! ");

		}

		nodo->proximo = NULL; // Recebe Null para sinalizar que � o ultimo registro da lista.

	}else{

		printf("\n Nao ha memoria disponivel");
	
	}
}

/************************************************ 
 * exclui_entidade                              *
 * objetivo: exclui um novo registro na lista   *
 * entrada : nodo (ponteiro para o novo espaco) *
 * saida   : lista - 1 registro                 *
 ************************************************/
void exclui_entidade(LISTA* *l){
	LISTA *atual, *anterior; //Ponteiros auxiliares para ajudar na movimenta��o da lista
	int cod, contador = 0; //cod = Vari�vel digitada pelo usu�rio / contador = mostra se o c�digo digitado foi encontrado e excluido
	
	if (*l == NULL){ //Se l estiver nulo, a lista est� vazia
		
		printf("\nLista Vazia!!");
		
	}else{ // Se n�o est� vazia: 
		atual = *l; //ambos os ponteiros auxiliares recebem as informa��es de *l
		anterior = *l;
		
		printf("\nDigite o c�digo a ser excluido: ");
		scanf("%d",&cod); //Faz a leitura do c�digo digitado pelo usu�rio
		
		while(atual != NULL){ //Percorre at� encontrar o ultimo registro da lista
		
			if(atual->entidade.codigo == cod){ //testa se o c�digo digitado � igual a algum c�digo da estrutura
			
				if(atual == *l){  //se encontrar o c�digo na primeira posi��o da lista
					*l = atual->proximo; // *l passa a apontar para o pr�ximo do atual
					free(atual); //Atual deixa de fazer parte da lista
					contador = 1; //Recebe 1 para sinalizar que o c�digo foi encontrado e o item foi excluido
					break; // Para o While, pois j� encontrou o que precisava
					
				}else if(atual->proximo == NULL){ // se encontrar o c�digo no final da lista
					anterior->proximo = NULL; // posi��o Atual vira nula, tornando o Anterior o ultimo registro da lista
					free(atual); //Atual deixa de fazer parte da lista
					contador = 1; //Recebe 1 para sinalizar que o c�digo foi encontrado e o item foi excluido
					break;	// Para o While, pois j� encontrou o que precisava
					
				}else{   //est� no meio da lista
					anterior->proximo = atual->proximo; // ignora o Atual, pois o mesmo sair� da lista, e passa a apontar para o seguinte
					free(atual); //Atual deixa de fazer parte da lista
					contador = 1; //Recebe 1 para sinalizar que o c�digo foi encontrado e o item foi excluido
					break; // Para o While, pois j� encontrou o que precisava
				}				
			}
			anterior = atual; //Serve para guardar uma posi��o anterior � posi��o do Atual
			atual = atual->proximo; // Se desloca para o pr�ximo
		}
		if(contador != 0){ //Significa que encontrou e exclui o registro
			printf("\nEntidade excluida com sucesso!\n\n");
		}else{ //Se contador = 0 significa que nenhum item foi encontrado
			printf("C�digo n�o encontrado!\n\n");
		}	
	}
}
/************************************************ 
 * ordenar por nomes                            *
 * objetivo: Organiza a lista por nomes         *
 * entrada : Lista encadeada                    *
 * saida   : lista ordenada por nome            *
 ************************************************/
void ordenar_nomes(LISTA* *l)
{
	ENTIDADE aux; //Auxiliar que guardar� somento as informa��es da lista. N�o guarda endere�os
	LISTA *atual, *proximo; //Ponteiros que ajudam a deslocar a lista
	atual = *l; //Atual recebe a primeira posi��o da lista
	if (atual == NULL){ //Se atual estiver Null, a lista est� vazia
		
		printf("Lista Vazia!\n");
		
	}else{ //Caso a listan n�o esteja vazia: 
	
		while(atual != NULL){//Percorre at� encontrar o �ltimo
			
			proximo = atual->proximo; //-> coloca a varial de ponteiro na proxima posicao
			while(proximo != NULL) //Percorre at� encontrar o �ltimo item do ponteiro proximo
			{
				if(strcmp (atual->entidade.nome, proximo->entidade.nome) > 0) //-> compara qual string � menor lexicograficamente.
				{	
					//troca os valores(dados da entidade entre as o ponteiro proximo e o atual)
					aux = atual->entidade;
					atual->entidade = proximo->entidade;
					proximo->entidade = aux;
				}
				//move o ponteiro para a proxima posicao
				proximo = proximo->proximo; 
			}
			//move o ponteiro atual para a proxima posicao
			atual = atual->proximo;
		}
		//mostra a mensagem que a lista foi ordenada
		printf("Lista ordenada com sucesso!!\n");
	}
}
/************************************************ 
 * ordenar por zona                             *
 * objetivo: Organiza a lista por zona          *
 * entrada : Lista encadeada                    *
 * saida   : lista ordenada por zona            *
 ************************************************/
void ordenar_zona(LISTA* *l)
{
	ENTIDADE aux; //Auxiliar que guardar� somento as informa��es da lista. N�o guarda endere�os
	LISTA *atual, *proximo; //Ponteiros que ajudam a deslocar a lista
	atual = *l; //Atual recebe a primeira posi��o da lista
	if (atual == NULL){ //Se atual estiver Null, a lista est� vazia
		
		printf("Lista Vazia!\n");
		
	}else{ //Caso a listan n�o esteja vazia: 
	
		while(atual != NULL){//Percorre at� encontrar o �ltimo
			
			proximo = atual->proximo; //-> coloca a varial de ponteiro na proxima posicao
			while(proximo != NULL) //Percorre at� encontrar o �ltimo item do ponteiro proximo
			{
				if(strcmp (atual->entidade.zona, proximo->entidade.zona) > 0) //-> compara qual string � menor lexicograficamente.
				{	
					//troca os valores(dados da entidade entre as o ponteiro proximo e o atual)
					aux = atual->entidade;
					atual->entidade = proximo->entidade;
					proximo->entidade = aux;
				}
				//move o ponteiro para a proxima posicao
				proximo = proximo->proximo; 
			}
			//move o ponteiro atual para a proxima posicao
			atual = atual->proximo;
		}
		//mostra a mensagem que a lista foi ordenada
		printf("Lista ordenada com sucesso!!\n");
	}
}
/************************************************ 
 * ordenar por telefone                         *
 * objetivo: Organiza a lista por telefones     *
 * entrada : Lista encadeada                    *
 * saida   : lista ordenada por telefones       *
 ************************************************/
void ordenar_telefone(LISTA* *l)
{
	ENTIDADE aux; //Auxiliar que guardar� somento as informa��es da lista. N�o guarda endere�os
	LISTA *atual, *proximo; //Ponteiros que ajudam a deslocar a lista
	atual = *l; //Atual recebe a primeira posi��o da lista
	if (atual == NULL){ //Se atual estiver Null, a lista est� vazia
		
		printf("Lista Vazia!\n");
		
	}else{ //Caso a listan n�o esteja vazia: 
	
		while(atual != NULL){//Percorre at� encontrar o �ltimo
			
			proximo = atual->proximo; //-> coloca a varial de ponteiro na proxima posicao
			while(proximo != NULL) //Percorre at� encontrar o �ltimo item do ponteiro proximo
			{
				if(strcmp (atual->entidade.telefone, proximo->entidade.telefone) > 0) //-> compara qual string � menor lexicograficamente.
				{	
					//troca os valores(dados da entidade entre as o ponteiro proximo e o atual)
					aux = atual->entidade;
					atual->entidade = proximo->entidade;
					proximo->entidade = aux;
				}
				//move o ponteiro para a proxima posicao
				proximo = proximo->proximo; 
			}
			//move o ponteiro atual para a proxima posicao
			atual = atual->proximo;
		}
		//mostra a mensagem que a lista foi ordenada
		printf("Lista ordenada com sucesso!!\n");
	}
}

/************************************************ 
 * ordenar por endere�os                        *
 * objetivo: Organiza a lista por endere�o      *
 * entrada : Lista encadeada                    *
 * saida   : lista ordenada por endere�o        *
 ************************************************/
void ordenar_endereco(LISTA* *l)
{
	ENTIDADE aux; //Auxiliar que guardar� somento as informa��es da lista. N�o guarda endere�os
	LISTA *atual, *proximo; //Ponteiros que ajudam a deslocar a lista
	atual = *l; //Atual recebe a primeira posi��o da lista
	if (atual == NULL){ //Se atual estiver Null, a lista est� vazia
		
		printf("Lista Vazia!\n");
		
	}else{ //Caso a listan n�o esteja vazia: 
	
		while(atual != NULL){//Percorre at� encontrar o �ltimo
			
			proximo = atual->proximo; //-> coloca a varial de ponteiro na proxima posicao
			while(proximo != NULL) //Percorre at� encontrar o �ltimo item do ponteiro proximo
			{
				if(strcmp (atual->entidade.endereco, proximo->entidade.endereco) > 0) //-> compara qual string � menor lexicograficamente.
				{	
					//troca os valores(dados da entidade entre as o ponteiro proximo e o atual)
					aux = atual->entidade;
					atual->entidade = proximo->entidade;
					proximo->entidade = aux;
				}
				//move o ponteiro para a proxima posicao
				proximo = proximo->proximo; 
			}
			//move o ponteiro atual para a proxima posicao
			atual = atual->proximo;
		}
		//mostra a mensagem que a lista foi ordenada
		printf("Lista ordenada com sucesso!!\n");
	}
}
/************************************************ 
 * ordenar por tipo de entidade                 *
 * objetivo: Organiza a lista por tipo          *
 * entrada : Lista encadeada                    *
 * saida   : lista ordenada por tipo            *
 ************************************************/
void ordenar_tipo(LISTA* *l)
{
	ENTIDADE aux; //Auxiliar que guardar� somento as informa��es da lista. N�o guarda endere�os
	LISTA *atual, *proximo; //Ponteiros que ajudam a deslocar a lista
	atual = *l; //Atual recebe a primeira posi��o da lista
	if (atual == NULL){ //Se atual estiver Null, a lista est� vazia
		
		printf("Lista Vazia!\n");
		
	}else{ //Caso a listan n�o esteja vazia: 
	
		while(atual != NULL){//Percorre at� encontrar o �ltimo
			
			proximo = atual->proximo; //-> coloca a varial de ponteiro na proxima posicao
			while(proximo != NULL) //Percorre at� encontrar o �ltimo item do ponteiro proximo
			{
				if(strcmp (atual->entidade.tipo, proximo->entidade.tipo) > 0) //-> compara qual string � menor lexicograficamente.
				{	
					//troca os valores(dados da entidade entre as o ponteiro proximo e o atual)
					aux = atual->entidade;
					atual->entidade = proximo->entidade;
					proximo->entidade = aux;
				}
				//move o ponteiro para a proxima posicao
				proximo = proximo->proximo; 
			}
			//move o ponteiro atual para a proxima posicao
			atual = atual->proximo;
		}
		//mostra a mensagem que a lista foi ordenada
		printf("Lista ordenada com sucesso!!\n");
	}
}

/************************************************ 
 * Procurar                                     *
 * objetivo: Procura informa��es das entidades  *
 * entrada : Um ponteiro do inicio da lista     *
 * saida   : Informa��es das entidades          *
 ************************************************/
LISTA* procurar(LISTA* *l)
{
	LISTA *p; //Vari�vel auxiliar
	p = *l; //recebe o conteudo de L
	
	int cod,contador=0; //cod = Vari�vel digitada pelo usu�rio / contador = mostra se o c�digo digitado foi encontrado
	
	if (p == NULL){ //Se p estiver Null, a lista est� vazia
		
		printf("Lista Vazia!");
		
	}else{ //caso n�o esteja nulo: 
		
		printf("\nDigite o c�digo da entidade: ");
		fflush(stdin);
		scanf("%d",&cod); //faz a leitura do c�digo digitado pelo usu�rio
		
		while(p != NULL){ //percorre at� encontrar o ultimo registro
				if(p->entidade.codigo == cod){   //pesquisa se o c�digo do usu�rio se encontra na struct, se sim, exibe as infos
				
					printf("\nINFOS: ");
					printf("\nCOD:      %d\n",p->entidade.codigo);
					printf("NOME:     %s",p->entidade.nome);
					printf("TIPO:     %s",p->entidade.tipo);
					printf("ZONA:     %s",p->entidade.zona);
					printf("TELEFONE: %s",p->entidade.telefone);
					printf("ENDERECO: %s\n\n",p->entidade.endereco);
					printf("-----------------------------------------------------------\n");
					contador = 1;
					
						return p;  //retorna a posi��o do item encontrado
					}			
			p = p->proximo;	//avan�a de posi��o
		}
		if(contador == 0){ //se contador permaneceu com 0 significa que o c�digo digitado pelo usu�rio n�o foi encontrado
			printf("C�digo n�o encontrado! \n\n");
		}
		
	}
}

/************************************************ 
 * Alterar                                      *
 * objetivo: Altera informa��es das entidades   *
 * entrada : Um ponteiro do inicio da lista     *
 * saida   : Entidade atualizada                *
 ************************************************/
 void alterar(LISTA* *l)
 {
 	LISTA *p, *posicao = NULL; //posicao inicia com null para visualizarmos se a fun��o Procurar retornou algo
	p = *l; //recebe o conteudo de L
	
	if (p == NULL){ //se estiver nulo, a lista est� vazia
		
		printf("\n\n Lista Vazia!");
		
	}else{ //caso a lista n�o esteja vazia: 
		posicao = procurar(&p);  //Posi��o recebe a posi��o retornada pela fun��o de procura
		if (posicao != NULL){ //testa se posi��o realmente recebeu algo da fun��o Procurar
		

		printf("\n Digite o nome da entidade: ");
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( posicao->entidade.nome, T_PADRAO, stdin); //faz a leitura do possivel novo nome digitado pelo usu�rio

		printf("\n Digite o tipo de entidade: ");
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( posicao->entidade.tipo, T_PADRAO, stdin); //faz a leitura do possivel novo tipo digitado pelo usu�rio

		printf("\n Digite a zona da entidade: ");
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( posicao->entidade.zona, T_PADRAO, stdin); //faz a leitura da possivel nova zona digitado pelo usu�rio

		printf("\n Digite o telefone da entidade: ");
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( posicao->entidade.telefone, T_MINIMO, stdin); //faz a leitura do possivel novo telefone digitado pelo usu�rio

		printf("\n Digite o endereco da entidade: ");
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( posicao->entidade.endereco, T_MAXIMO, stdin); //faz a leitura do possivel novo endere�o digitado pelo usu�rio
		
		printf("\n Registro alterado com sucesso! \n");
		
		}else{ //caso n�o tenha encontrado o c�digo na estrutura
			printf("\nDigite um c�digo v�lido! \n\n"); 
		}
 	}
}


/************************************************ 
 * relatorio                                    *
 * objetivo: gera um relatorio de entidades     *
 * entrada : um ponteiro do inicio da lista     *
 * saida   : relatorio                          *
 ************************************************/
void relatorio(LISTA* aux){
	
	LISTA* p;
	p = aux; //p recebe o conteudo de aux

	if(aux != NULL){ //se aux n�o estiver nulo: 

		printf("\n--------------------------RELATORIO----------------------------");
		while(aux != NULL){ //percorre at� encontrar o ultimo registro
		
			//exibe as informa��es dos registros encontrados 
			printf("\nCOD:      %d\n",aux->entidade.codigo);
			printf("NOME:     %s",aux->entidade.nome);
			printf("TIPO:     %s",aux->entidade.tipo);
			printf("ZONA:     %s",aux->entidade.zona);
			printf("TELEFONE: %s",aux->entidade.telefone);
			printf("ENDERECO: %s",aux->entidade.endereco);
			printf("---------------------------------------------------------------\n");
			
			aux = aux->proximo; //avan�a de posi��o 
		}

	}else{ //se aux estiver nulo, a lista est� vazia

		printf("\nLista vazia!");

	}
}

/************************************************ 
 * consulta_geral                                *
 * objetivo: retornar entidade filtrada         *
 * entrada : um ponteiro do inicio da lista     *
 * saida   : retorna entidade filtrada          *
 ************************************************/
void consulta_geral(LISTA* aux){

	char filtro[T_PADRAO]; //-> variavel que receber� o valor a ser pesquisado.
	int contador =0; //-> contador para o numero de entidades encontradas.

	
	printf("\nDigite a palavra a ser pesquisada: ");
	
	//__fpurge(stdin); //-> Limpeza de buffer linux.
	fflush(stdin); // -> Limpeza de buffer Windows.
	
	fgets(filtro ,T_PADRAO ,stdin); //-> capturando o dado informado com fgets para controlar o overflow.

	if(filtro[strlen(filtro)-1] == '\n') //-> verifica se a string est� com um \n(New line)
   		filtro[strlen(filtro)-1] = '\0'; //-> coloca um \0(simb.final da string) no final da string

	if(aux != NULL){ // -> verifica se a lista est� vazia

		printf("\n------------------ENTIDADES ENCONTRADAS--------------------------");
		while(aux != NULL){	

			//-> este if verifica se a palavra digitada est� no telefone,nome,endere�o,tipo,zona
			if (strstr(aux->entidade.nome, filtro) != NULL ||
				strstr(aux->entidade.zona, filtro) != NULL || 
			 	strstr(aux->entidade.tipo, filtro) != NULL ||
			 	strstr(aux->entidade.endereco, filtro) != NULL||
			 	strstr(aux->entidade.telefone, filtro) != NULL)
			{   
				//-> mostra as entidades encontradas 
				printf("\nCOD:      %d\n",aux->entidade.codigo);
				printf("NOME:     %s",aux->entidade.nome);
				printf("TIPO:     %s",aux->entidade.tipo);
				printf("ZONA:     %s",aux->entidade.zona);
				printf("TELEFONE: %s",aux->entidade.telefone);
				printf("ENDERECO: %s",aux->entidade.endereco);
				printf("-----------------------------------------------------------\n");

				contador++; //incrementa sempre que encontrar uma entidade
			}
			aux = aux->proximo; //avan�a de posi��o
		}

	}else{
		//-> mostra se a lista estiver vazia
		printf("\nLista vazia!");

	}
	//-> mostra o total de entidades encontradas
	printf("\nForam encontrado(s) %d registros.",contador);

}


/************************************************ 
 * total_entidades                              *
 * objetivo: Gerar o total de entidades         *
 * entrada : nodo (ponteiro para o novo espaco) *
 * saida   : O numero total de entidades        *
 ************************************************/
void total_entidades(LISTA* aux){
	 
	LISTA *p;
	p = aux;
	int contador = 0; //-> variavel contadora.

	if(p != NULL){ //-> verifica se a lista esta vazia.
			
		while(p != NULL) //-> incrementa quando encontra uma entidade.
		{
			contador++;
			p = p->proximo;
		}
		//-> mostra o total de entidades encontradas.
		printf("Existe %d entidade(s) cadastrada(s) no sistema.\n", contador);

	}else{
		//-> mostra se a lista estiver vazia
		printf("\nLista Vazia.");
	}
}


/************************************************ 
 * new_ordenacao                                *
 * objetivo: Ordenar ponteiros atraves do metodo*
 *			Selection Sort.                     *  
 * entrada : nodo (ponteiro para o novo espaco) *
 * saida   : Dados ordenados                    *
 ************************************************/
void new_ordenacao(LISTA* *l ){

	LISTA *min;
	LISTA *x = *l;
	LISTA *y;
	LISTA *ant_x,*ant_y,*ant_min,*aux;

	//VERIFICAR SE A LISTA NAO ESTA VAZIA
	if (*l != NULL){
		
		while(x !=NULL){
	  		
	  		printf("\n Entrou no x");
	  		
	  		min = x;
	  		y = x->proximo;
	  		while(y !=NULL){
	  			printf("\n Entrou no y");

	  			if (y->entidade.codigo < min->entidade.codigo){
					printf("\n Entrou na troca do y para o min...");	  				
	  				
	  				ant_min = ant_y;
	  				min = y;
	  			}	  			

	  			ant_y = y;
	  			//VAI PARA O PROXIMO NODO Y
	  			y = y->proximo;
	  			printf("\nEste � o aux min: %d", min);
	  			printf("\nEste � o aux x: %d", x);
	  		}

	  		if (min != x){
				printf("\n Faz a troca do x para o min");

				if (min != x->proximo){
					printf("\n Entrou aqui!!!");
					if (*l == x)
					{
						
						aux = min->proximo;
						min->proximo = x->proximo;
						ant_y->proximo = x;
						x->proximo = aux;
						*l = min;	
					}


				}else{
					ant_x->proximo = min;
					x->proximo = min->proximo;
					min->proximo = x;
				}
	  		}			

	  		if (x->proximo == NULL)
	  		{
	  			ant_x = x;
	  			//VAI PARA O PROXIMO NODO X
	  			x = x->proximo;	
	  		}else{
	  			ant_x = min;
	  			//VAI PARA O PROXIMO NODO X
	  			x = min->proximo;
	  		}

	  	}
	  
	}else{
	  	
	  	printf("\n Lista vazia!");
	}  

}
