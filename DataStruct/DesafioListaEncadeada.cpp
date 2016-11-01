/***********************************************/ 
/* Desafio de Lista Encadeada                  */
/* Objetivo: Cadastrar instituições            */
/* programador: Gustavo Bittencourt,     	   */
/*				Gustavo scheffer, 			   */
/*				Matheus Fonseca                */
/* criado em: 10/06/2016                       */
/* data da ultima alteracao: xx/xx/xxxx        */
/***********************************************/


/***********************************************/ 
/* Importações			                       */
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
/* Definições dos Registros                    */
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
/* Prototipação                                */
/***********************************************/
void cria_lista(LISTA* *l); // -> função interna que cria uma nova lista
void inclui_entidade(LISTA* *l); // -> função que inclui registros
void exclui_entidade(LISTA* *l);// -> função que exclui registros
void ordenar(LISTA* *l);// -> função que ordena os registros
void relatorio(LISTA* aux);// -> função que exibe os registros
void alterar(LISTA* *l);// -> função que altera os registros
LISTA* procurar(LISTA* *l);// -> função interna que pesquisa registros
void consulta_geral(LISTA* l);// -> função que pesquisa e exibe informações dos registros
void total_entidades(LISTA* aux);// -> função que que conta os registros



/***********************************************/ 
/* Main					                       */
/***********************************************/
int main(){
	setlocale(LC_ALL,"portuguese");
	/* variaveis da main aqui */
	int opcao; //-> opcao do menu
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
        printf( "\n [0]   Para sair do programa                           " );
        printf( "\n /----------------------------------------------------/" );      
        printf( "\n Opcao: " );

        __fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
        scanf("%d", &opcao); // tecla de opcao do menu
        switch( opcao ) {
           	
           	case 1: 
           		system("cls");
           		printf( "\t INCLUIR ENTIDADE: \n" );
           		inclui_entidade( &l );
                break;
           	
           	case 2: 
           		system("cls");
           		printf( "\t EXCLUIR ENTIDADE \n" );
           		exclui_entidade(&l);
                break;
            
            case 3:
            	system("cls");
            	ordenar( &l ); 
                break;
            
            case 4:
            	system("cls");
            	relatorio( l );
                break;

            case 5: 
            	system("cls");
            	printf("\t CONSULTAR \n");
            	consulta_geral( l );
            	break;

            case 6:
				system("cls"); 
            	printf( "\t TOTAL DE ENTIDADES \n" );
            	total_entidades( l );
                break; 
				
			case 7:
				system("cls");
				printf("\t ALTERAR ENTIDADES \n" );	                 
                alterar(&l);
				break;   
            case 0: // termino do programa                                                 
                exit( 1 ); 
                break;
                
            default: 
               	printf( "\n Digite uma opcao!!" );
                break;
        } // switch( opcao )
 
        __fpurge( stdin );
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        
        //getchar();       // parada da tela
        system("pause");
        printf( "\n" );
     } // fim do while( 1 )

	return 0;	
}

/************************************************ 
 * cria_lista(FUNÇÃO INTERNA)                   *
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

	LISTA *nodo = (LISTA*) malloc(sizeof(LISTA)); //Aloca memória para a variável
	LISTA *p; //Variável auxiliar

	if(nodo !=NULL){ //Se nodo não estiver nulo, sem lugar na memória, então:

		printf("\n Digite o codigo da entidade: ");
		__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		scanf("%d", &nodo->entidade.codigo); //Faz a leitura do código

		printf("\n Digite o nome da entidade: ");
		__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( nodo->entidade.nome, T_PADRAO, stdin); //Faz a leitura do nome

		printf("\n Digite o tipo de entidade: ");
		__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( nodo->entidade.tipo, T_PADRAO, stdin); //Faz a leitura do tipo

		printf("\n Digite a zona da entidade: "); 
		__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( nodo->entidade.zona, T_PADRAO, stdin); //Faz a leitura da zona

		printf("\n Digite o telefone da entidade: ");
		__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( nodo->entidade.telefone, T_MINIMO, stdin); //Faz a leitura do telefone

		printf("\n Digite o endereco da entidade: ");
		__fpurge(stdin);
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( nodo->entidade.endereco, T_MAXIMO, stdin); //Faz a leitura do endereço

		if( *l == NULL){ //Se L estiver vazio: 

			*l = nodo;  //L passa a apontar para o novo registro
			printf(" \nRegistro incluido! ");
					
		}else{  //Caso L já esteja apontando para outro(s) registro(s): 
		
			p = *l; //p, variável auxiliar, recebe o conteúdo de l
			while(p->proximo != NULL){ //percorre até achar o fim da lista
				p = p->proximo;	//faz o deslocamento
			}

			p->proximo = nodo; //Quando encontra o ultimo item da lista, inclui o novo registro como último
			printf(" \nRegistro incluido! ");

		}

		nodo->proximo = NULL; // Recebe Null para sinalizar que é o ultimo registro da lista.

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
	LISTA *atual, *anterior; //Ponteiros auxiliares para ajudar na movimentação da lista
	int cod, contador = 0; //cod = Variável digitada pelo usuário / contador = mostra se o código digitado foi encontrado e excluido
	
	if (*l == NULL){ //Se l estiver nulo, a lista está vazia
		
		printf("\nLista Vazia!!");
		
	}else{ // Se não está vazia: 
		atual = *l; //ambos os ponteiros auxiliares recebem as informações de *l
		anterior = *l;
		
		printf("\nDigite o código a ser excluido: ");
		scanf("%d",&cod); //Faz a leitura do código digitado pelo usuário
		
		while(atual != NULL){ //Percorre até encontrar o ultimo registro da lista
		
			if(atual->entidade.codigo == cod){ //testa se o código digitado é igual a algum código da estrutura
			
				if(atual == *l){  //se encontrar o código na primeira posição da lista
					*l = atual->proximo; // *l passa a apontar para o próximo do atual
					free(atual); //Atual deixa de fazer parte da lista
					contador = 1; //Recebe 1 para sinalizar que o código foi encontrado e o item foi excluido
					break; // Para o While, pois já encontrou o que precisava
					
				}else if(atual->proximo == NULL){ // se encontrar o código no final da lista
					anterior->proximo = NULL; // posição Atual vira nula, tornando o Anterior o ultimo registro da lista
					free(atual); //Atual deixa de fazer parte da lista
					contador = 1; //Recebe 1 para sinalizar que o código foi encontrado e o item foi excluido
					break;	// Para o While, pois já encontrou o que precisava
					
				}else{   //está no meio da lista
					anterior->proximo = atual->proximo; // ignora o Atual, pois o mesmo sairá da lista, e passa a apontar para o seguinte
					free(atual); //Atual deixa de fazer parte da lista
					contador = 1; //Recebe 1 para sinalizar que o código foi encontrado e o item foi excluido
					break; // Para o While, pois já encontrou o que precisava
				}				
			}
			anterior = atual; //Serve para guardar uma posição anterior à posição do Atual
			atual = atual->proximo; // Se desloca para o próximo
		}
		if(contador != 0){ //Significa que encontrou e exclui o registro
			printf("\nEntidade excluida com sucesso!\n\n");
		}else{ //Se contador = 0 significa que nenhum item foi encontrado
			printf("Código não encontrado!\n\n");
		}	
	}
}
/************************************************ 
 * ordenar                                      *
 * objetivo: Cria uma lista nula inicialmente   *
 * entrada : nodo (ponteiro para o novo espaco) *
 * saida   : lista ordenada                      *
 ************************************************/
void ordenar(LISTA* *l){
 
	ENTIDADE aux, menor;
	LISTA *p, *q;
	p = *l;


	while(p != NULL)
	{

		menor = p->entidade;
		q = p->proximo;

		printf("\nEntrou 1");
		
		while(q != NULL)
		{	
			printf("\nEntrou 2");

			if( q->entidade.codigo < p->entidade.codigo){
				menor = q->entidade;
				printf("\nEntrou 3");
			}

			q = q->proximo;

		}
		if (p->entidade.codigo != menor.codigo){
			aux = p->entidade;
			p->entidade = menor;
			q->entidade = aux;
			printf("\nEntrou 4");
		}	
		printf("\nEntrou 5");
		p = p->proximo;	
	}
		
}		


/************************************************ 
 * Procurar                                     *
 * objetivo: Procura informações das entidades  *
 * entrada : Um ponteiro do inicio da lista     *
 * saida   : Informações das entidades          *
 ************************************************/
LISTA* procurar(LISTA* *l){
	LISTA *p; //Variável auxiliar
	p = *l; //recebe o conteudo de L
	
	int cod,contador=0; //cod = Variável digitada pelo usuário / contador = mostra se o código digitado foi encontrado
	
	if (p == NULL){ //Se p estiver Null, a lista está vazia
		
		printf("Lista Vazia!");
		
	}else{ //caso não esteja nulo: 
		
		printf("\nDigite o código da entidade: ");
		fflush(stdin);
		scanf("%d",&cod); //faz a leitura do código digitado pelo usuário
		
		while(p != NULL){ //percorre até encontrar o ultimo registro
				if(p->entidade.codigo == cod){   //pesquisa se o código do usuário se encontra na struct, se sim, exibe as infos
				
					printf("\nINFOS: ");
					printf("\nCOD:      %d\n",p->entidade.codigo);
					printf("NOME:     %s",p->entidade.nome);
					printf("TIPO:     %s",p->entidade.tipo);
					printf("ZONA:     %s",p->entidade.zona);
					printf("TELEFONE: %s",p->entidade.telefone);
					printf("ENDERECO: %s\n\n",p->entidade.endereco);
					printf("-----------------------------------------------------------\n");
					contador = 1;
					
						return p;  //retorna a posição do item encontrado
					}			
			p = p->proximo;	//avança de posição
		}
		if(contador == 0){ //se contador permaneceu com 0 significa que o código digitado pelo usuário não foi encontrado
			printf("Código não encontrado! \n\n");
		}
		
	}
}

/************************************************ 
 * Alterar                                      *
 * objetivo: Altera informações das entidades   *
 * entrada : Um ponteiro do inicio da lista     *
 * saida   : Entidade atualizada                *
 ************************************************/
void alterar(LISTA* *l){
 	LISTA *p, *posicao = NULL; //posicao inicia com null para visualizarmos se a função Procurar retornou algo
	p = *l; //recebe o conteudo de L
	
	if (p == NULL){ //se estiver nulo, a lista está vazia
		
		printf("\n\n Lista Vazia!");
		
	}else{ //caso a lista não esteja vazia: 
		posicao = procurar(&p);  //Posição recebe a posição retornada pela função de procura
		if (posicao != NULL){ //testa se posição realmente recebeu algo da função Procurar
		

		printf("\n Digite o nome da entidade: ");
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( posicao->entidade.nome, T_PADRAO, stdin); //faz a leitura do possivel novo nome digitado pelo usuário

		printf("\n Digite o tipo de entidade: ");
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( posicao->entidade.tipo, T_PADRAO, stdin); //faz a leitura do possivel novo tipo digitado pelo usuário

		printf("\n Digite a zona da entidade: ");
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( posicao->entidade.zona, T_PADRAO, stdin); //faz a leitura da possivel nova zona digitado pelo usuário

		printf("\n Digite o telefone da entidade: ");
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( posicao->entidade.telefone, T_MINIMO, stdin); //faz a leitura do possivel novo telefone digitado pelo usuário

		printf("\n Digite o endereco da entidade: ");
		fflush( stdin ); // -> limpeza de buffer linux
		fgets( posicao->entidade.endereco, T_MAXIMO, stdin); //faz a leitura do possivel novo endereço digitado pelo usuário
		
		printf("\n Registro alterado com sucesso! \n");
		
		}else{ //caso não tenha encontrado o código na estrutura
			printf("\nDigite um código válido! \n\n"); 
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

	if(aux != NULL){ //se aux não estiver nulo: 

		printf("\n--------------------------RELATORIO----------------------------");
		while(aux != NULL){ //percorre até encontrar o ultimo registro
		
			//exibe as informações dos registros encontrados 
			printf("\nCOD:      %d\n",aux->entidade.codigo);
			printf("NOME:     %s",aux->entidade.nome);
			printf("TIPO:     %s",aux->entidade.tipo);
			printf("ZONA:     %s",aux->entidade.zona);
			printf("TELEFONE: %s",aux->entidade.telefone);
			printf("ENDERECO: %s",aux->entidade.endereco);
			printf("---------------------------------------------------------------\n");
			
			aux = aux->proximo; //avança de posição 
		}

	}else{ //se aux estiver nulo, a lista está vazia

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

	char filtro[T_PADRAO]; //-> variavel que receberá o valor a ser pesquisado.
	int contador =0; //-> contador para o numero de entidades encontradas.

	
	printf("\nDigite a palavra a ser pesquisada: ");
	
	__fpurge(stdin); //-> Limpeza de buffer linux.
	fflush(stdin); // -> Limpeza de buffer Windows.
	
	fgets(filtro ,T_PADRAO ,stdin); //-> capturando o dado informado com fgets para controlar o overflow.

	if(filtro[strlen(filtro)-1] == '\n') //-> verifica se a string está com um \n(New line)
   		filtro[strlen(filtro)-1] = '\0'; //-> coloca um \0(simb.final da string) no final da string

	if(aux != NULL){ // -> verifica se a lista está vazia

		printf("\n------------------ENTIDADES ENCONTRADAS--------------------------");
		while(aux != NULL){	

			//-> este if verifica se a palavra digitada está no telefone,nome,endereço,tipo,zona
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
			aux = aux->proximo; //avança de posição
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
