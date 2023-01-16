#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço de memoria 
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsavel pelas strings 

int registro() // função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/strings
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/strings
	printf("### Cadastro ###\n");
	
	//Coletando informação do usuário
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

int consulta() //função responsavel por consulta os dados 
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
		printf("Não foi possivel abrir o arquivo, não localizado !!\n");
	}
	
	//trazendo as informações do usuário
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	
	system("pause");
}

int deletar() // função deletar com confirmação 
{
	char cpf[40];
	int confirmacao =0;
	
	printf("Digite o CPF do usúario a ser deletado: \n");
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file != NULL )
	{
		printf("CPF encontrado, Está ação e irreversível deseja continuar ? \n\n");
		printf(" 1- Sim: \n 2- Não: \n");
		scanf("%d", &confirmacao);
			if(confirmacao == 1){
				int retorno;
				retorno = remove(cpf);
				if(retorno == 0){
					printf("Usúario removido com sucesso!. \n");	
				}else{
					printf("Usúario não foi removido!. Houve erro !! \n");	
				}
				system("pause");
			}else{
				printf("Usúario não foi removido!. \n");
				system("pause");
			}
	}else{
		printf("Usuário não consta no banco de dados!. \n");
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
			
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção deseja do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Delatar nomes\n\n"); 
		printf("Opção: ");//Fim do menu
		
		scanf("%d", &opcao); //armazenando as informações 
		
		system("cls");
		
		switch(opcao) //seleção menu
		{
			case 1:
				registro(); //chamada de função
				break;
			
			case 2:
				consulta();
				break;
			
			case 3:
				deletar();
				break;
			
			default:
				printf("Essa opção não está disponivel! \n");
				system("pause");
				break;
		}//final seleção 
		
	}
}
