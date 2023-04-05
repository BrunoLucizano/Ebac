#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //bliblioteca responsável por cuidar das string

int cadastro()//função responsável por criar registro
{
	char arquivo[40];//variáveis string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];//final das variáveis
	
	printf("Digite o cpf a ser cadastrado: ");//coletando informações do usuário
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //copia os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,"CPF: ");//tabulação
	fprintf(file,cpf);//salva no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ", Nome: ");//tabulação
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informações
	scanf("%s", nome);// refere-se a string
	
	file = fopen(arquivo, "a");//abre o aruivo
	fprintf(file, nome);//salva no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ", Sobrenome: ");//taulação
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informações
	scanf("%s", sobrenome);//refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,sobrenome);//salva no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ", Cargo: ");//tabulação
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informação
	scanf("%s", cargo);// refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,cargo);//salva no arquivo
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa o sistema
}


int consulta()//função responsável pela consulta
{

	setlocale(LC_ALL, "Portuguese");//definindo a linguagem

	char cpf[40];//variáveis string
	char conteudo[200];// variável string
	
	printf("Digite o CPF a ser consultado: ");//coletando informação
	scanf("%s",cpf);// refere-se a string
	
	FILE *file;//lê o arquivo
	file = fopen(cpf,"r");//lê o arquivo
	
	if(file == NULL)//condicional retorno nulo
	{
	printf("CPF não cadastrado.\n");//retorno
	}
	
	while(fgets(conteudo, 200, file) != NULL);//condicional retorno positivo
	{
	printf("\nEssas são as informações do usuário: ");//retorno
	printf("%s", conteudo);//informações
	printf("\n\n");
	}

	system("pause");//pausa no sistema
	
}

int excluir()//função responsável por excluir cadastro
{
	char cpf[40];//variável
	
	printf("Digite o CPF a ser excluído: ");//coletando informações
	scanf("%s",cpf);//refere-se a string
	
	remove(cpf);//excluindo
	
	FILE *file;//lê o arquivo
	file = fopen(cpf,"r");//lê o arquivo
	
	if(file == NULL)//condicional
	{
	printf("\n\nUsuário não se encontra no sistema\n\n");//retorno do sistema
	system("pause");//pausa o sistema
	}
	
	
}

int main()
{
	int opcao=0;//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)//loop 
	{
	
		system("cls");//limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
		printf("### Cadastro de aluno EBAC ###\n\n");//início do menu
		printf("Escolha a opção desejada\n\n");
		printf("\t1 - Cadastrar aluno\n");
		printf("\t2 - Consultar aluno\n");
		printf("\t3 - Excluir cadastro\n\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d" , &opcao);//armazenando a escolha do usuário
	
		system ("cls");//limpando a tela
	
		switch(opcao)//variáveis
		{
		
			case 1:
			cadastro();//chamar seleção
			break;
			
			case 2:
			consulta();//chamar seleção
			break;
			
			case 3:
			excluir();//chamar seleção
			break;
			
			default:
			printf("Esta opção não está disponivél, tente novamente!\n");
			system("pause");
			break;
		}//fim da seleção
		
}
		
}
