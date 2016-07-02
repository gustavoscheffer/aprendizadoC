#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<locale.h>
#define QTD 6
#define COMB 3.699
// structs (Ex: typedef struct{.....)
typedef struct{
   int numero;
   float capacidade;
   float status;
} SBomba;

typedef struct{
	SBomba infos[QTD];
	int cont;
} SPosto;

// prototipos
void cadastrar(SPosto *registro);
void estoque(SPosto *registro);
int buscaBomba(SPosto *registro, int bomba, float qtvenda);
void abastecer();

//programa principal (Ex: main(){...)
main(){
	setlocale(LC_ALL,"portuguese");
	char opcao;
	SPosto registro;
	registro.cont=0;
	float caixa;
// menu de op��es
do{
	printf("\n1 - Cadastrar Bomba");
	printf("\n2 - Estoque");
	printf("\n3 - Abastecer estoque");
	printf("\n4 - Vender");
	printf("\n5 - Status Caixa");
	printf("\nS - Sair do Programa \n\tOp��o escolhida ==> ");
	fflush(stdin);
	scanf("%c",&opcao);
	switch(toupper(opcao)){
		case '1':
			// CADASTRAR BOMBA
			cadastrar(&registro);
		break;
		case '2':
			// MOstrar ESTOQUE
			estoque(&registro);
		break;
		case '3':
			// abastecer estoque
			
			
		break;
		case '4':
			// VENDER
		
		break;
		case '5':
			// status caixa
			printf("\n\t ==> Status Caixa ==> R$ %.2f\n",caixa);
		break;
		case 'S':
			//SAIR DO PROGRAMA
		break;
		default: printf("\n\t ==> Op��o inv�lida!! ");
	}
}while(toupper(opcao)!='S');


}

// declara��o das fun��es (Ex:void calcula(){..... )
// fun��o cadastrar
void cadastrar(SPosto *registro){
	//system("cls");
	SBomba aux;
	
	printf("Digite o n�mero da bomba: ");
	fflush(stdin);
	scanf("%i",&aux.numero);
	printf("Digite a capacidade: ");
	scanf("%f",&aux.capacidade);
	registro->infos[registro->cont]=aux;
	registro->cont++;
	//system("cls");
}

void estoque(SPosto *registro){
	//system("cls");
	int x;
	if(registro->cont==0){
		printf("\n\t ==> Sem bombas cadastradas");
	}else{
		  for(x=0;x<registro->cont;x++){
			 printf("\n\t==> Bomba n�: %i",registro->infos[x].numero);
			 printf("\n\t==> Capacidade: %.2f",registro->infos[x].capacidade);
			 printf("\n\t==> Status: %.2f",registro->infos[x].status);
			 printf("\n--------------------------------------------\n");
		}
	}
	
}



int buscaBomba(SPosto *registro, int bomba, float qtvenda){
 int i, posicao = -1;
 for(i=0;i<registro->cont;i++)
   if(bomba==registro->infos[i].numero && registro->infos[i].status>=qtvenda){
       posicao = i;
       break;
   }
return(posicao);
}

void abastecer(){
	
	int numBomba=0;	

	estoque(&registro);
	printf("Digite o numero da bomba=> ");
	scanf("%i",&numBomba);	
	

}



