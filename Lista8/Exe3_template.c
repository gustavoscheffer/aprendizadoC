#include<stdio.h>
#define TAM 10

typedef struct{

char chassi[50];
char placa[7];
char modelo [50];
char marca[50];
int ano;

} Aluno;


//prototype


void main(){

Estoque estoque.veiculos;
Veiculo veiculo;

int controller=0; // posição atual do estoque;
int continuar = 0;// controla a permanencia no programa;

	do{

		printf("Selecione a opcao desejada: \n");
		printf("1 - Cadastrar\n");
		printf("2 - Vender\n");
		printf("3 - Buscar\n");
		printf("4 - Relatorio do Estoque\n");
		printf("5 - Sair\n\n");
		printf("==> ");
		scanf("%i",&continuar);

		switch(continuar){
			case 1: printf("Cadastrar");
				break;	
                        case 2:printf("Vender");
                        	break;
                        case 3:printf("Buscar");
                        	break;
                        case 4:printf("Gerar Relatorio");
                        	break;
                        case 5: printf("Logout...\n");
                        	break;
                        default: printf("Opcao invalida. Tente novamente...");
                        	break;
				
		}		

	}while(continuar =! 5);

}

