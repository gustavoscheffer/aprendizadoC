#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>

/*
2. Faça uma função C que receba como parâmetros uma string e um caracter e indique
quantas vezes este caracter está presente na string.
Ex. função conta_caracter(“casa”,’a’) -> 2
*/


 int findCaracter(char palavra[50], char caractere);

main(){
	char caractere;
	char palavra[50];
	
	printf("Digite sua palavra: ");
	fgets(palavra,50,stdin);
        
	printf("Digite o caractere a ser procurado: ");
        scanf("%c",&caractere);
	
	printf("O caracter '%c' foi encontrado '%i' vezes! ",caractere,findCaracter(palavra,caractere));
	
	printf("\n");	
}

int findCaracter(char palavra[50], char caractere){
	
	int cont;
	int contagem=0;
//Conta quantos caracteres:
	for(cont=0; cont<=strlen(palavra); cont++){
		if(tolower(palavra[cont]) == caractere){
			contagem+=1;
		}
	}
	return contagem;
}

