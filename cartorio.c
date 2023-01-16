#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o de memoria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca responsavel pelas strings 

int registro() // fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/strings
	printf("### Cadastro ###\n");
	
	//Coletando informa��o do usu�rio
	printf("Digite o seu CPF, a ser cadastrado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); // criar o arquivo 
	fprintf(file, cpf); // salvo valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta() //fun��o responsavel por consulta os dados 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo as linguagens 
	
	printf("### Consulta ###\n");
	
	char cpf[40];
	char conteudo[200];
	
	//consultando se existe o cpf 
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado !!\n");
	}
	
	//trazendo as informa��es do usu�rio
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	
	system("pause");
}

int deletar() // fun��o deletar com confirma��o 
{
	char cpf[40];
	int confirmacao =0;
	
	printf("Digite o CPF do us�ario a ser deletado: \n");
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file != NULL )
	{
		printf("CPF encontrado, Est� a��o e irrevers�vel deseja continuar ? \n\n");
		printf(" 1- Sim: \n 2- N�o: \n");
		scanf("%d", &confirmacao);
			if(confirmacao == 1){
				int retorno;
				retorno = remove(cpf);
				if(retorno == 0){
					printf("Us�ario removido com sucesso!. \n");	
				}else{
					printf("Us�ario n�o foi removido!. Houve erro !! \n");	
				}
				system("pause");
			}else{
				printf("Us�ario n�o foi removido!. \n");
				system("pause");
			}
	}else{
		printf("Usu�rio n�o consta no banco de dados!. \n");
		system("pause");
	}
}

int main()
{
	int opcao = 0; //Definindo as variaveis
	int laco = 1;
	
	for(laco=1; laco=1;)
	{
		system("cls"); // responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo as linguagens 
			
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o deseja do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Delatar nomes\n\n"); 
		printf("Op��o: ");//Fim do menu
		
		scanf("%d", &opcao); //armazenando as informa��es 
		
		system("cls");
		
		switch(opcao) //sele��o menu
		{
			case 1:
				registro(); //chamada de fun��o
				break;
			
			case 2:
				consulta();
				break;
			
			case 3:
				deletar();
				break;
			
			default:
				printf("Essa op��o n�o est� disponivel! \n");
				system("pause");
				break;
		}//final sele��o 
		
	}
}
