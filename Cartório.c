#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string

int registro() // Função responsavel por cadastrar os usuários no sistema
{
	// Inicio de criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cpf); // "%s" Refere-se a "string"
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // Cria o arquivo  		// "w" Refere-se a "ESCREVER" um novo arquivo
	fprintf(file,cpf); // Salvo o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" Atualiza a informação do arquivo
	fprintf(file,","); // Separa a infomação digitada pelo usuário
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando o nome de cadastro do usuário
	scanf("%s", nome); // Coletando o nome de cadastro do usuário
	
	file = fopen(arquivo, "a"); // Atualiza a informação do arquivo
	fprintf(file, nome); // Salva o valor da vareavel
	fclose(file); // Fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Abre e atualiza a informação do arquivo 
	fprintf(file,","); // Separa a informação digitada pelo o usuário
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando o sobrenome de cadastro do usuário
	scanf("%s", sobrenome); //''         ''              ''
	
	file = fopen(arquivo, "a"); //Abre e atualiza o arquivo
	fprintf(file, sobrenome); // Salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre e atualiza o arquivo
	fprintf(file,","); // Separa a informação digitada pelo usuário
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando o sobrenome de cadastro do usuário
	scanf("%s", cargo); // ''            ''				''
	
	file = fopen(arquivo, "a"); // Abre e atualiza o arquivo 
	fprintf(file, cargo); // Salva o valor da variavel	
	fclose(file); // Fecha o arquivo
	
	system("pause"); // pausa para o usuário ler as informação digitadas
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	// Inicio de variaveis
	char cpf[40];
	char conteudo[200];
	// Fim de variaveis
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) 
	{
		printf("Não foi possivel localizar o CPF! \n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	int variavel=0;
	
	char cpf[40];
	char conteudo[200];
	/*				      // Inicio de Código do professor
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}*/						// Fim de Código do professor

	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Não foi possivel localizar o usuário");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\n##- INFORMAÇÕES DE USUÁRIO -##\n\n");
	printf("##- %s",conteudo);
	printf(" -##");
	printf("\n\n\n\n");
	printf("Deseja MESMO deletar o usuário?");
	printf("\n\n#Digite: 1 para 'SIM'\n");
	printf("#Digite: 2 para 'NÃO'\n");
	printf("\n\n");
	scanf("%d", &variavel);
	
	fclose(file);
	switch(variavel)
	{
		case 1:
			file = fopen(cpf,"delete");
			remove(cpf);
			printf("Usuário deletado com SUCESSO!!\n");
			break;
		
		case 2:
			printf("\n\nOperação CANCELADA!!\n");
			break;
			
		default:
			printf("\n\nOpção invalida!!!\n");
		break;	
	}
	
	}
	
	
	system("pause");
	
	
}





int main() 
{
	int opcao=0;  //Defininindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{	
	
		system("cls"); // Responsavel por limpar a tela 
			
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("###- Cartório da EBAC -###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //aramazenando a escolha do usuário
	
		system("cls"); //Responsavel por limpar a tela 
	
		switch(opcao) //Inicio de seleção do menu
		{
			case 1:
			registro(); // Responsavel por chamar a função registro
			break;
		
			case 2:
			consulta();// Responsavel por chamar a função consulta
			break;
		
			case 3:
			deletar(); // Responsavel por chamar a função deletar
			break;	
		
			default: 
			printf("Essa não é uma opção válida!\n");
			system("pause");
			break; //Fim da seleção do menu
		}		
	}
	
	
}	

