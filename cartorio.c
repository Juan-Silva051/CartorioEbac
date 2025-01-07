#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsavel por cuidar das string 

int registro() //Função responsavel por cadastrar os usuários do sistema 
{
	//Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/string
	
	printf("Digite o CPF a Ser Cadastrado: "); //coletando informção do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string 
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome a Ser Cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a Ser Cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a Ser Cadastrado: ");
	scanf("%S",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
		
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem 	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a Ser Consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
	
}



int main ()
{
	int opcao=0; //Definindo Variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
    	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem 
    
    	printf("\t\t\t\t\t\t### Cartório da EBAC ###\n\n"); //inicio do menu 
		printf("\tEscolha a opção desejada do menu: \n\n");
    	printf("\t\t1 - Registrar nomes\n");
    	printf("\t\t2 - Consultar nomes\n");
    	printf("\t\t3 - Deletar nomes\n");
		printf("\t Opção: "); //fim do menu 
    
    	scanf("%d", &opcao); //Armazenando a Escolha Do Usuário 
    
    	system("cls"); //responsavel por limpar a tela 
    	
    	
    	
    	switch(opcao) //inicio da seleção do menu 
    	{
    		case 1:
    		registro(); //chamada de funções 
    		break;
    		
    		case 2:
    		consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("\t\tEssa opção não está disponivel!\n ");
    		system("pause");
    		break;
		} //fim da seleção
    

    }
}
