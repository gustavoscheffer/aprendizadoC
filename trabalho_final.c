#include<stdio.h>
#include<string.h>
#define QTD 10
/*
->Criar a seguinte estrutura para os dados dos alunos:
Matricula
Nome
Sexo
Nota P1
Nota P2
Nota trabalho
Média
->Criar um menu com as seguintes funções:
1 -      Cadastrar Aluno: Deve cadastrar somente a matricula (autoincremental), o nome e o sexo do aluno, um de cada vez.
2 -      Exibir Cadastro: deve exibir o cadastro completo dos alunos.
3 -      Excluir Aluno:  Após o usuário informar a matricula, excluir o registro do aluno reorganizando a lista de alunos, não deixando espaços em branco no vetor.
4 -      Procurar por Nome: procurar aluno pelo nome. Ao encontrar, apresentar as informações do aluno.
5 -      Lançar Notas – Deve chamar a função “Procurar por nome”. Se encontrar o aluno deve permitir o lançamento das notas P1,P2 e do trabalho do aluno. Após deve calcular a média aritmética com base nessas notas e atribuir ao campo Média.
6 -      Relatório por Gênero – Deve apresentar a quantidade de homens e de mulheres na turma.
7 -      Relatório Aprovação – Deve apresentar a quantidade de aprovados e reprovados e os nomes dos alunos nestas condições. Média para aprovação: 7,0.
S -      Sair do program
*/


/*structs*/

typedef struct{

        char nome[50];
        char sexo;
        double notaP1;
        double notaP2;
        double notaTrabalho;
        double media;
	int matricula;


} Aluno;

typedef struct{

	Aluno alunos[QTD];
	int indice;
	
} Colegio;



/*prototype*/
void insert(Aluno aluno, Colegio *colegio);
void insertNotas(Aluno aluno, double notaP1, double notaP2, double notaTrabalho);
void delete(Aluno aluno);
void searchByName(Aluno aluno);
void reportByGen(char genero);
void reportByAprov();
void exibir();

// funcao para verificar se esta cadastrando. ----temporaria.
void relatorio(Colegio colegio);



/*program*/
void main(){

Colegio colegio;
Aluno aluno;
char opcao;
colegio.indice=0;
aluno.matricula=1;


	do{

		printf("Selecione a opcao desejada: \n");
		printf("1 - Cadastrar aluno: \n");
		printf("2 - Exibir Cadastro: \n");
		printf("3 - Excluir aluno: \n");
		printf("4 - Procurar por nome: \n");
		printf("5 - Lancar nota: \n");
		printf("6 - Relatorio por Genero: \n");
		printf("7 - Relatorio Aprovacao: \n");
		printf("S - Sair\n\n");
		printf("==> ");
		
		scanf("%c",&opcao);
		__fpurge(stdin);
                fflush(stdin);
		
		switch(opcao){
			case '1': printf("\n***CADASTRAR ALUNO***\n");
				
				printf("Nome: ");
				fgets(aluno.nome,50,stdin);	
				
				printf("Sexo:(M) masculino ou (F)feminino: ");
				scanf("%c",&aluno.sexo);
				__fpurge(stdin);
               			fflush(stdin);	
				
				insert(aluno, &colegio);
				aluno.matricula++;
				break;	

			case '2':printf("\n***EXIBIR CADASTROS***\n");
				exibir(colegio);
				break;
			
			case '3':printf("\n***EXCLUIR ALUNO***\n");
				break;
			case '4':printf("\n***PROCURAR ALUNO POR NOME***\n");
				break;
			case '5': printf("\n***LANCAR NOTA***\n");
				break;
			case '6': printf("\n***RELATORIO POR GENERO***\n");
				break;
			case '7': printf("\n***RELATORIO APROVACAO- TESTE GERAL...***\n");
				break;
			case 'S': printf("\nSAIR...\n");
				break;
			default: printf("\nOpcao invalida. Tente novamente...\n");
				break;
				
		}		
		system("clear");	
	}while(toupper(opcao) != 'S' );

}

/*functions*/
void insert(Aluno aluno, Colegio *colegio){	
	
	colegio->alunos[colegio->indice]=aluno;
	printf("ALUNO CADASTRADO COM EXITO: %s", colegio->alunos[colegio->indice].nome);
	system("sleep 5");
	colegio->indice++;
	printf("\n\n");
	
}

void exibir(Colegio colegio){
	
	int cont;
	
	printf("RELATORIO DE ALUNOS\n");
	
	for(cont=0;cont<colegio.indice;cont++){

		printf("\tMatricula             => %i\n",colegio.alunos[cont].matricula);
		printf("\tNome                  => %s\n",colegio.alunos[cont].nome);
                printf("\tSexo                  => (%c)\n\n",colegio.alunos[cont].sexo);
		printf("\tNota P1               => %.2f\n",colegio.alunos[cont].notaP1);
		printf("\tNota P2               => %.2f\n",colegio.alunos[cont].notaP2);
		printf("\tNota do Trabalho      => %.2f\n",colegio.alunos[cont].notaTrabalho);
		printf("\t                         ------\n");
		printf("\tMedia                 => %.2f",(colegio.alunos[cont].notaP1+colegio.alunos[cont].notaP2+colegio.alunos[cont].notaTrabalho)/3);
		printf("\n\n\n");
	}
}






