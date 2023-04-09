#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //bliblioteca respons�vel por cuidar das string

int cadastro()//fun��o respons�vel por criar registro
{
	char arquivo[40];//vari�veis string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];//final das vari�veis
	
	printf("Digite o cpf a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //copia os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,"CPF: ");//tabula��o
	fprintf(file,cpf);//salva no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ", Nome: ");//tabula��o
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��es
	scanf("%s", nome);// refere-se a string
	
	file = fopen(arquivo, "a");//abre o aruivo
	fprintf(file, nome);//salva no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ", Sobrenome: ");//taula��o
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��es
	scanf("%s", sobrenome);//refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,sobrenome);//salva no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ", Cargo: ");//tabula��o
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��o
	scanf("%s", cargo);// refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,cargo);//salva no arquivo
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa o sistema
}


int consulta()//fun��o respons�vel pela consulta
{

	setlocale(LC_ALL, "Portuguese");//definindo a linguagem

	char cpf[40];//vari�veis string
	char conteudo[200];// vari�vel string
	
	printf("Digite o CPF a ser consultado: ");//coletando informa��o
	scanf("%s",cpf);// refere-se a string
	
	FILE *file;//l� o arquivo
	file = fopen(cpf,"r");//l� o arquivo
	
	if(file == NULL)//condicional retorno nulo
	{
	printf("CPF n�o cadastrado.\n");//retorno
	}
	
	while(fgets(conteudo, 200, file) != NULL);//condicional retorno positivo
	{
	printf("\nEssas s�o as informa��es do usu�rio: ");//retorno
	printf("%s", conteudo);//informa��es
	printf("\n\n");
	}

	system("pause");//pausa no sistema
	
}

int excluir()//fun��o respons�vel por excluir cadastro
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
		
		
	
	FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usu�rio deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
	
}

int main()
{
	int opcao=0;//definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cadastro de aluno EBAC ###\n\n");
	printf("Login de administrador\n\nDigite sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");	
		for(laco=1;laco=1;)//loop 
		{
		
			system("cls");//limpar a tela
			
			setlocale(LC_ALL, "Portuguese");//definindo a linguagem
		
			printf("### Cadastro de aluno EBAC ###\n\n");//in�cio do menu
			printf("Escolha a op��o desejada\n\n");
			printf("\t1 - Cadastrar aluno\n");
			printf("\t2 - Consultar aluno\n");
			printf("\t3 - Excluir cadastro\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: ");//fim do menu
		
			scanf("%d" , &opcao);//armazenando a escolha do usu�rio
		
			system ("cls");//limpando a tela
		
			switch(opcao)//vari�veis
			{
			
				case 1:
				cadastro();//chamar sele��o
				break;
				
				case 2:
				consulta();//chamar sele��o
				break;
				
				case 3:
				excluir();//chamar sele��o
				break;
				
				case 4:
				printf("Obrigado por utilizar nosso sistema!");
				return 0;//fecha o sistema
				break;
				
				default:
				printf("Esta op��o n�o est� disponiv�l, tente novamente!\n");
				system("pause");
				break;
			}//fim da sele��o
		}
	}
	else
	printf("Senha incorreta");
	
		
		
}
