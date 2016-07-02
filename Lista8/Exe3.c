#include<stdio.h>
#define TAM 10

typedef struct{

char chassi[50];
char placa[7];
char modelo [50];
char marca[50];
int ano;

} Veiculo;

typedef struct{

Veiculo veiculos[TAM];

}Estoque;


//prototype
void cadastrar(Veiculo veiculo, Estoque *estoque, int *controller);
void vender();
Veiculo buscar();
void geraRelatorio(Estoque *estoque);


void main(){

Estoque estoque;
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
			case 1: printf("Cadastrar\n");
				
				/*Limpeza de buffer linux e windows...*/
                                __fpurge(stdin);
                                fflush(stdin);

				printf("Digite o chassi => ");
				fgets(veiculo.chassi,50,stdin);

				printf("Digite a placa => ");
				fgets(veiculo.placa,50,stdin);

				printf("Digite o modelo => ");
				fgets(veiculo.modelo,50,stdin);

				printf("Digite a marca => ");
				fgets(veiculo.marca,50,stdin);

				printf("Digite o ano => ");
				scanf("%i",&veiculo.ano);
							
				/*Limpeza de buffer linux e windows...*/
				__fpurge(stdin);
				fflush(stdin);
				 
				cadastrar(veiculo, &estoque, &controller);	
				
				break;
                       
			case 2:printf("Vender");
                        	break;
                        case 3:printf("Buscar");
                        	break;
                        case 4:printf("Gerar Relatorio\n");
				geraRelatorio(&estoque);	
                        	break;
                        case 5: printf("Logout...\n");
                        	break;
                        default: printf("Opcao invalida. Tente novamente...");
                        	break;
				
		}		

	}while(continuar != 5);

}

//functions...

void cadastrar(Veiculo veiculo, Estoque *estoque, int *controller){
	
	estoque->veiculos[*controller] = veiculo;
	*controller++;

}
void vender(Veiculo veiculo){

}
Veiculo buscar(Veiculo veiculo){
 return veiculo;
}
void geraRelatorio( Estoque *estoque){
	int i;
	int *controller;
		
	for(i=0;i <= *controller;i++){
		printf("chassi==> %s",estoque->veiculos[i].chassi);
                printf("placa ==> %s",estoque->veiculos[i].placa);
                printf("modelo==> %s",estoque->veiculos[i].modelo);
                printf("marca ==> %s",estoque->veiculos[i].marca);
                printf("ano   ==> %i",estoque->veiculos[i].ano);
		printf("\n==============================\n");
	}
}

