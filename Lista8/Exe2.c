#include<stdio.h>
#define TAM 2

typedef struct{

char chassi[50];
char placa[7];
char modelo [50];
char marca[50];
int ano;

} Veiculo;



/*
1. Faça um programa C que leia uma estrutura para representar os seguintes dados de
um veículo:
Chassi
Placa
Modelo
Marca
Ano
O programa deve permitir que sejam informados os dados. Ao final listar a estrutura
com seu conteúdo.
*/

void main(){

Veiculo veiculo1;
int i;

for(i=0;i<TAM;i++){

printf("CARRO %i\n", i+1);


printf("Digite o chassi => ");
fgets(veiculo1.chassi,50,stdin);

printf("Digite a placa => ");
fgets(veiculo1.placa,50,stdin);

printf("Digite o modelo => ");
fgets(veiculo1.modelo,50,stdin);

printf("Digite a marca => ");
fgets(veiculo1.marca,50,stdin);

printf("Digite o ano => ");
scanf("%i",&veiculo1.ano);

//Limpeza de buffer linux e windows...
__fpurge(stdin);
fflush(stdin);

}

for(i=0;i<TAM;i++){
printf("\tDADOS DIGITADOS: CARRO %i\n",i+1);
printf("\tchassi => %s",veiculo1.chassi);
printf("\tplaca  => %s",veiculo1.placa);
printf("\tmodelo => %s",veiculo1.modelo);
printf("\tmarca  => %s",veiculo1.marca);
printf("\tano    => %i\n",veiculo1.ano);
}



}
