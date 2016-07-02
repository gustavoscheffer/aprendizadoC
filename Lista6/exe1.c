#include<stdio.h>
#include<locale.h>

/*
1. Faça uma função C que receba 2 números inteiros e retorne 0 se os números forem
iguais, 1 se o primeiro for maior e 2 se o segundo for maior.
*/

int compareIntNumbers(int num1, int num2);

int main(){
	int num1=0, num2=0;	

	printf("Digite o primeiro numero: ");
	scanf("%i",&num1);
	printf("Digite o segundo numero: ");
        scanf("%i",&num2);
	
	switch(compareIntNumbers(num1,num2)){
		case 0:
			printf("The numbers are equals...");
			break;
		case 1:
                        printf("First number is the biggest...");
                	break;
		case 2:
                        printf("Second number is the biggest...");
                	break;
		default: 
			printf("Falha na função!!!");
	}
	
	printf("\n");
	return 0;
}

int compareIntNumbers(int num1, int num2){
	if(num1 > num2){
		return 1;
	}else if(num1 < num2){
		return 2;
	}else{
		return 0;
	}
}
