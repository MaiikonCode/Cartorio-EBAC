#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocaçóes de texto por região
#include <string.h> // biblioteca responsavel por cuida das string

int main()
{
	int opcao=0; //Definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");// limpa a tela apos o comando
		
		setlocale(LC_ALL,"Portuguese"); //definindo a liguagem
		
		printf("### Cartorio da EBAC ### \n\n"); //inicio do menu
		printf(" Escolha a opção desejada do menu \n\n");
		printf("\t 1 - Registra nomes \n");
		printf("\t 2 - Consultar nomes \n");
		printf("\t 3 - Deletar nomes \n \n");// Fim do menu
		printf("opção:");
		
		scanf("%d", &opcao);//Escolha e armazenamento dos usuario
		
		
		system("cls");
		
		switch(opcao) 
		{
			
			case 1:
			registra ();
			break;
			
			case 2:
			consulta ();
			break;
			
			case 3:
			deletar ();
			break;
			
			default:
			printf("Essa opção não está disponivel \n \n");
			system("pause");
			break;
				
		}
		
		
	
	}
}

int registra()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf);//Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//cia arquivo
	fprintf(file,cpf); //salco o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Qual o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Qual o seu cargo??:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	
	system("pause");
	
	
	
	
}

int consulta()
{
	setlocale(LC_ALL , "Portuquese");
	
	char cpf[40];
	char conteudo[200];
	char nome[40];
	char *token;
	
	printf("Digite o CPF a ser consulta: \n");
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\n Nao foi possivel encontrar o usuario");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\n Essa são as informações do ususario\n\n");
		
		token = strtok(	conteudo,",");
		printf(" CPF: %s \n", token);
		
		token = strtok(NULL,",");
		printf(" Nome: %s\n", token);
		
		token = strtok(	NULL,",");
		printf(" Sobrenome %s \n" , token);
		
		token = strtok(	NULL,",");
		printf(" Cargo %s \n", token);
		
	}
	
	system("pause");
	
}
	


int deletar()
{
	char cpf[40];
	
	printf("Qual cpf deseja deletar \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo não se encontra \n");
		
		
	}
	system("pause");
}
