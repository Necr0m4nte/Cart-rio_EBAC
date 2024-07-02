#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string

int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema
{
	// Inicio de cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); // "%s" Refere-se a "string"
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // Cria o arquivo  		// "w" Refere-se a "ESCREVER" um novo arquivo
	fprintf(file,cpf); // Salvo o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" Atualiza a informa��o do arquivo
	fprintf(file,","); // Separa a infoma��o digitada pelo usu�rio
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando o nome de cadastro do usu�rio
	scanf("%s", nome); // Coletando o nome de cadastro do usu�rio
	
	file = fopen(arquivo, "a"); // Atualiza a informa��o do arquivo
	fprintf(file, nome); // Salva o valor da vareavel
	fclose(file); // Fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Abre e atualiza a informa��o do arquivo 
	fprintf(file,","); // Separa a informa��o digitada pelo o usu�rio
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando o sobrenome de cadastro do usu�rio
	scanf("%s", sobrenome); //''         ''              ''
	
	file = fopen(arquivo, "a"); //Abre e atualiza o arquivo
	fprintf(file, sobrenome); // Salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre e atualiza o arquivo
	fprintf(file,","); // Separa a informa��o digitada pelo usu�rio
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando o sobrenome de cadastro do usu�rio
	scanf("%s", cargo); // ''            ''				''
	
	file = fopen(arquivo, "a"); // Abre e atualiza o arquivo 
	fprintf(file, cargo); // Salva o valor da variavel	
	fclose(file); // Fecha o arquivo
	
	system("pause"); // pausa para o usu�rio ler as informa��o digitadas
	
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
		printf("N�o foi possivel localizar o CPF! \n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");
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
	/*				      // Inicio de C�digo do professor
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}*/						// Fim de C�digo do professor

	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("N�o foi possivel localizar o usu�rio");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\n##- INFORMA��ES DE USU�RIO -##\n\n");
	printf("##- %s",conteudo);
	printf(" -##");
	printf("\n\n\n\n");
	printf("Deseja MESMO deletar o usu�rio?");
	printf("\n\n#Digite: 1 para 'SIM'\n");
	printf("#Digite: 2 para 'N�O'\n");
	printf("\n\n");
	scanf("%d", &variavel);
	
	fclose(file);
	switch(variavel)
	{
		case 1:
			file = fopen(cpf,"delete");
			remove(cpf);
			printf("Usu�rio deletado com SUCESSO!!\n");
			break;
		
		case 2:
			printf("\n\nOpera��o CANCELADA!!\n");
			break;
			
		default:
			printf("\n\nOp��o invalida!!!\n");
		break;	
	}
	
	}
	
	
	system("pause");
	
	
}





int main() 
{
	int opcao=0;  //Defininindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{	
	
		system("cls"); // Responsavel por limpar a tela 
			
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("###- Cart�rio da EBAC -###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //aramazenando a escolha do usu�rio
	
		system("cls"); //Responsavel por limpar a tela 
	
		switch(opcao) //Inicio de sele��o do menu
		{
			case 1:
			registro(); // Responsavel por chamar a fun��o registro
			break;
		
			case 2:
			consulta();// Responsavel por chamar a fun��o consulta
			break;
		
			case 3:
			deletar(); // Responsavel por chamar a fun��o deletar
			break;	
		
			default: 
			printf("Essa n�o � uma op��o v�lida!\n");
			system("pause");
			break; //Fim da sele��o do menu
		}		
	}
	
	
}	

