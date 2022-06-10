#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Portuguese");
	char login[10], senha[10];
	int x, a=1, b=1, i=0; //x = o contador do primeiro for. i = contador do segundo for. a e b= identificador de login e senha.
    printf ("\n\n\n\n\n");
	printf(" ||       ||||||  |||||||| ||||||| ||||||| |||||| |||||| |||||| ||||||  |||||\n");
	printf(" ||       ||  ||  ||       ||   || ||      ||  || ||  |  ||  |  ||  ||  ||\n");
	printf(" ||       ||  ||  ||       ||   || ||      ||  || || |   || |   ||  ||  ||\n");
	printf(" ||       ||  ||  ||       ||   || ||      ||  || ||||   ||||   ||  ||  |||||\n");
	printf(" ||       ||  ||  ||       ||||||| ||      |||||| ||  || ||  || ||  ||     ||\n");
	printf(" ||       ||  ||  ||       ||   || ||      ||  || ||  || ||  || ||  ||     ||\n");
	printf(" |||||||| ||||||  |||||||| ||   || ||||||| ||  || ||  || ||  || ||||||  |||||\n");


	puts  (" ___________________________________________________________________________");
	puts  ("| ****************************** TELA DE LOGIN **************************** |");
	puts  ("|___________________________________________________________________________|");
	for(x=0;x<=3;x++)
	{
		system ("color 9f");
		printf("Login: ");
		fflush(stdin);
		gets(login);
		printf("senha: ");
		fflush(stdin);
		for(i=0;i<5;i++) // O 'i' pode variar de acordo com o tamanho da senha
		{
			senha[i] = getch();
			putchar('*');
		}
		a=strcmp(login,"admin");
		b=strcmp(senha,"admin");
		if(a==0 && b==0)
		{
			system("cls");
			printf("\nBem Vindo(a)!\n");
			break;
		}
		else
		{
			if(x==1)
			{
				system("color 4f");
				printf("\nÚltima tentativa!\a\n");
				system("pause");
			}
			else
			{
				if(x==0)
				{
					system ("color 4f");
					printf("\nTente novamente.\a\n");
					system("pause");
				}
				else
				{
					if(x==3)
					{
						system ("color 9f");
						printf("\nVocê excedeu o número máximo de tentativas!\nTente novamente mais tarde.\a");
						system("pause");
						return 0;
					}
				}
			}
		}
	}
	if(x == 2 && a==-1 && b==-1)
	//final do sistema de login!
	//Declaração de structs e variáveis
	i=0; //variavel reciclada para contar na função adicionar cliente.
	struct cliente
	{
		char nome[20];
		char sobrenome[20];
		char CPF[14];
		char cnpj[18];
		char Profissao[30];
		char endereco[400];
		char Ponto_de_Referencia[100];
		char Telefone[24];
		char e_mail[50];
		char nreg[11];
		short int cpcj;  //VARIAVEL MENOR , INT MAIS CURTA ocupa menos espaço na memoria
		short int status;
	}cliente[1000];
	struct carro
	{
		char cor[10];
		char chassi[20];
		char combustivel[10];
		char poten[10];
		char marca[10];
		char airbag[5];
		char portas[5];
		int diaria;
		int ano;
		short int X1;
		short int statuscar;
		float qlm;
	}carro[1000];
	struct registro
	{
		short int cpcj;
		int aluguel;
		float valortotal;
		char nome[20];
		char CPF[14];
		char marca[10];
		char chassi[20];			
	}registro[1000];
	//char nome[1000][20],Bnome[20],sobrenome[1000][20],CPF[1000][14],cnpj[1000][18],Profissao[1000][30],endereco[1000][400],Ponto_de_Referencia[1000][100],Telefone[1000][24],e_mail[1000][50],nreg[1000][11],s_n[3];
	//char cor[10][1000],chassi[20][1000],combustivel[10][1000],poten[10][1000],marca[10][1000],Mcarro[10],airbag[5][1000],portas[5][1000];
	char s_n,Bnome[20],Mcarro[10], escolha;
	int ret = 1,Ccliente=0,c,busca,k,checkf,j,l,r,teste=0; //cpcj = sigla de cpf e cnpj, ret= variável de retorno, Ccliente = código do cliente, status = define se o código está ativo.
	float check;
	FILE *arq1,*arq2,*arq3,*arq4;
	//inicio da função de leitura de arquivos
	for(i=-2;i<1000;i++)
	{
		if(i<0)
		{
			i=0;
		}
		cliente[i].status = 0;
	}
	i=0;
	for(c=0;c<1000;c++)
	{
		carro[c].statuscar = 0;
	}
	c=0;
	arq2 = fopen("count.txt","r");
	if(arq2 == NULL)
	{
		arq1 = fopen("clientes.txt","r");
		if(arq1 == NULL)
		{
			arq3 = fopen("carros.txt","r");
			if(arq3 == NULL)
			{
				arq2 = fopen("count.txt","w");
				if(arq2 == NULL)
				{
					printf("Falha crítica: Não foi possível carregar os arquivos do sistema ou foram danificados.\nCaso isso aconteça com frequência, entre em contato com o desenvolvedor do aplicativo.\n Pela segurança de seus dados o sistema irá desligar!\n");
					system("pause");
					return 0;
				}
				else
				{
					arq1 = fopen("clientes.txt","w");
					if(arq1 == NULL)
					{
						printf("Falha crítica: Não foi possível carregar os arquivos do sistema ou foram danificados.\nCaso isso aconteça com frequência, entre em contato com o desenvolvedor do aplicativo.\n Pela segurança de seus dados o sistema irá desligar!\n");
						system("pause");
						return 0;
					}
					else
					{
						arq3 = fopen("carros.txt","w");
						if(arq3 == NULL)
						{
							printf("Falha crítica: Não foi possível carregar os arquivos do sistema ou foram danificados.\nCaso isso aconteça com frequência, entre em contato com o desenvolvedor do aplicativo.\n Pela segurança de seus dados o sistema irá desligar!\n");
							system("pause");
							return 0;
						}
						else
						{
							printf("Configurando o aplicativo para primeira utilização!\n");
							checkf ++;
							fclose(arq2);
							arq2 = fopen("count.txt","w");
							fprintf(arq2,"%d",checkf);
							fclose(arq2);
							system("pause");
						}
					}
				}
			}
			else
			{
				printf("Falha crítica: Não foi possível carregar os arquivos do sistema ou foram danificados.\nCaso isso aconteça com frequência, entre em contato com o desenvolvedor do aplicativo.\n Pela segurança de seus dados o sistema irá desligar!\n");
				system("pause");
				return 0;
			}
		}
		else
		{
			printf("Falha crítica: Não foi possível carregar os arquivos do sistema ou foram danificados.\nCaso isso aconteça com frequência, entre em contato com o desenvolvedor do aplicativo.\n Pela segurança de seus dados o sistema irá desligar!\n");
			system("pause");
			return 0;
		}
	}
	else
	{
		
		fscanf(arq2,"%d",&checkf);
		fclose(arq2);
		arq2 = fopen("count.txt","w");
		checkf ++;
		fprintf(arq2,"%d",checkf);
		fclose(arq2);
		arq1 = fopen("clientes.txt","r");
		for(i=0;i<1000;i++)
		{
			if(fscanf(arq1,"%d",&teste)==1)
			{
				fscanf(arq1,"%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",&cliente[i].status,&cliente[i].cpcj,&cliente[i].nome,&cliente[i].sobrenome,&cliente[i].cnpj,&cliente[i].Profissao,&cliente[i].endereco,&cliente[i].Ponto_de_Referencia,&cliente[i].Telefone,&cliente[i].e_mail,&cliente[i].nreg);
				cliente[i].status=1;
				if(cliente[i].cpcj==1)
				{
					for(j=0;j<sizeof(cliente[i].cnpj);j++)
					{
						cliente[i].CPF[j]=cliente[i].cnpj[j];
						cliente[i].cnpj[j] = '\0';
					}
				}
			}
		}
		fclose(arq1);
		i=0;
		arq3 = fopen("carros.txt","r");		
		for(c=0;c<1000;c++)
		{
			if(fscanf(arq3,"%d",&teste)==1)
			{
				fscanf(arq3,"%d\n%d\n%s\n%s\n%s\n%s\n%s\n%d\n",&carro[i].statuscar,&carro[i].X1,&carro[i].chassi,&carro[i].combustivel,&carro[i].poten,&carro[i].marca,&carro[i].airbag,&carro[i].ano,&carro[i].cor,&carro[i].portas);
				carro[i].statuscar=1;
			}
		}
		fclose(arq3);
		i=0;//final da função escrita e leitura.
		while(cliente[i].status==1)
		{	
			for(j=0;j<sizeof(cliente[i].nome);j++)
			{
				if(cliente[i].nome[j]== '_')
				{
					cliente[i].nome[j] = ' ';
				}
			}
			for(j=0;j<sizeof(cliente[i].sobrenome);j++)
			{
				if(cliente[i].sobrenome[j]== '_')
				{
					cliente[i].sobrenome[j] = ' ';
				}
			}
			for(j=0;j<sizeof(cliente[i].Profissao);j++)
			{
				if(cliente[i].Profissao[j]== '_')
				{
					cliente[i].Profissao[j] = ' ';
				}
			}
			for(j=0;j<sizeof(cliente[i].endereco);j++)
			{
				if(cliente[i].endereco[j]== '_')
				{
					cliente[i].endereco[j] = ' ';
				}
			}
			for(j=0;j<sizeof(cliente[i].Ponto_de_Referencia);j++)
			{
				if(cliente[i].Ponto_de_Referencia[j]== '_')
				{
					cliente[i].Ponto_de_Referencia[j] = ' ';
				}
			}
			for(j=0;j<sizeof(cliente[i].Telefone);j++)
			{
				if(cliente[i].Telefone[j]== '_')
				{
					cliente[i].Telefone[j] = ' ';
				}
			}
			i++;
		}
		i=0;
		printf("Sistema carregado com Sucesso!!!\n");
		system("pause");
	}
	i=0;
	//final da função de leitura de arquivos
	// Inicio do Menu
	system ("cls");
	system ("color 2f");
	do
	{
		system("cls");
		puts("\n\n\n\n\n");
	    puts(" ___________________________________________________________________");
	    puts("| ***************************************************************** |");
	    puts("| ********************** LOCACARROS AUTOMOTIVA ******************** |");
	    puts("| ***************************************************************** |");
	    puts("|___________________________________________________________________|");
	    printf ("\tFunções do menu: \n\t1 - Adicionar Clientes.\n\t2 - Editar Clientes.\n\t3 - Remover Clientes.\n\t4 - Adicionar Carros. \n\t5 - Editar Carros.\n\t6 - Remover Carros\n\t7 - Sistema de Aluguel.\n\t9 - Sair.\n");
	    printf ("\tAtenção esse programa está em fase de desenvolvimento.\n\tPara salvar as informações criadas nele, use a função sair para grava-las no seu disco.\n");
	    fflush(stdin);
		scanf("%c",&escolha);
	    switch (escolha)
		{
	    	case '1':
	    	{
	    		while(cliente[i].status == 1)
	    		{
	    			i++;
	    			if(i == 1000)
	    			{
	    				i = 0; //variável para evitar de substituir dados de outras pessoas.
					}
				}; //tratamento de erro para evitar sobrescrever dados não-intencionalmente.
	    		do
	    		{
	    		printf("Escolha: 1 - Pessoa Física e 2 - Pessoa Jurídica.\n");
	    		scanf("%d",&cliente[i].cpcj);	
				}while(cliente[i].cpcj != 1 && cliente[i].cpcj != 2);
				cliente[i].status = 1;
				switch (cliente[i].cpcj)
	    		{
	    			case 1:
    				{
    					printf ("Digite seu nome:");
    					fflush(stdin);
			    		scanf  ("%s",&cliente[i].nome);
						printf ("Digite o sobrenome: ");
			    		scanf  ("%s",&cliente[i].sobrenome);
			    		printf ("Digite seu CPF: ");
			    		fflush (stdin);
			    		scanf  ("%s",&cliente[i].CPF);
			    		printf ("Digite o Número do registro da habilitação do cliente: ");
			    		scanf  ("%s",&cliente[i].nreg);
			    		printf ("Digite sua Profissão: ");
			    		scanf  ("%s",&cliente[i].Profissao);
			    		printf ("Digite seu endereço: ");
						fflush(stdin);
			    		gets(cliente[i].endereco);
			    		printf ("Digite um Ponto de Referência: ");
			    		fflush(stdin);
			    		gets(cliente[i].Ponto_de_Referencia);
			    		printf ("Digite seu Telefone: ");
			    		fflush(stdin);
			    		scanf("%s",cliente[i].Telefone);
			    		printf ("Digite seu e-mail: ");
			    		fflush(stdin);
			    		gets(cliente[i].e_mail);
			    		printf ("As informações do novo cliente foram gravadas com sucesso!!\nO código do cliente é: %d.\nObs: O código do cliente é importante para fazer alterações no cadastro e fazer aluguel de veículos.",i);
			    		system ("pause");
			    		break;
					}
					case 2:
					{
						printf ("Digite seu nome:");
    					fflush(stdin);
			    		gets  (cliente[i].nome);
			    		printf ("Digite o sobrenome: ");
			    		scanf  ("%s",&cliente[i].sobrenome);
			    		printf ("Digite seu CNPJ: ");
			    		scanf  ("%s",&cliente[i].cnpj);
			    		printf ("Digite o Número do registro da habilitação do cliente: ");
			    		fflush (stdin);
			    		scanf  ("%s",&cliente[i].nreg);
			    		printf ("Digite sua Profissão: ");
			    		scanf  ("%s",&cliente[i].Profissao);
						printf ("Digite seu endereço: ");
						fflush(stdin);
			    		gets(cliente[i].endereco);
			    		printf ("Digite um Ponto de Referência: ");
			    		fflush(stdin);
			    		gets(cliente[i].Ponto_de_Referencia);
			    		printf ("Digite seu Telefone: ");
			    		fflush(stdin);
			    		scanf("%s",&cliente[i].Telefone);
			    		printf ("Digite seu e-mail: ");
			    		fflush(stdin);
			    		gets(cliente[i].e_mail);
			    		do
			    		{
			    			check=0;
			    			for(l=-1;l<1000;l++)
				    		{
				    			if(cliente[i].e_mail==cliente[l].e_mail && i!=l)
								{
									check++;
								}
							}
							if(check!=0)
							{
								printf("Esse e-mail já existe em nosso Banco de Dados.\nDigite o seu e-mail: ");
								gets(cliente[i].e_mail);
							}
						}while(check!=0);
						do
						{
							for(j=0;j<sizeof(cliente[i].e_mail);j++)
							{
								if(cliente[i].e_mail[j]== ' ')
								{
									check++;
								}
							}
							if(check!=0)
							{
								printf("Você usou caracteres invalidos.\nDigite seu e-mail: ");
								gets(cliente[i].e_mail);
							}
						}while(check!=0);
						printf("As informações do novo cliente foram gravadas com sucesso!!\nO código do cliente é: %d.\nObs: O código do cliente é importante para fazer alterações no cadastro e fazer aluguel de veículos.",i);
			    		system("pause");
			    	}
				}
	    		break;
			} //final da função adicionar cliente
			case '2':
			{ //inicio da função editar cliente.
				system ("color 9f");
			    printf ("================================================================================\n");
				printf ("========================DIGITE O PRIMEIRO NOME DO CLIENTE=======================\n");
    			printf ("================================================================================\n\n");
				busca = 0; //numero de resultados
				do
				{
					fflush(stdin);
					scanf("%s",Bnome);
					busca = 0;
					for(Ccliente=0;Ccliente<=1000;Ccliente++)
					{
						if(cliente[Ccliente].status==1)//busca entre strings se ela for igual o check vai receber um valor = 0 se ele receber um valor = 0 o if irá funcionar
						{
							check=strcmp(Bnome,cliente[Ccliente].nome);
							if(check==0)
							{
								if(cliente[Ccliente].cpcj==1)
								{
									printf("_____________________________________________________________________________________________\n");
									printf("|Código: %d",Ccliente);
									printf("|Nome: %s\n",cliente[Ccliente].nome);
									printf("|Sobrenome: %s\n",cliente[Ccliente].sobrenome);
									printf("|CPF: %s \n",cliente[Ccliente].CPF);
									printf("|Registro de Habilitação:%s \n",cliente[Ccliente].nreg);
									printf("|Profissão:%s \n", cliente[Ccliente].Profissao);
									printf("|Ponto de Referência:%s \n",cliente[Ccliente].Ponto_de_Referencia);
									printf("|E-mail:%s  \n",cliente[Ccliente].e_mail);
									printf("|Telefone:%s \n",cliente[Ccliente].Telefone);
									printf("|____________________________________________________________________________________________\n");									
									busca++;
								}
								else
								{
									if(cliente[Ccliente].cpcj==2)
									{
									printf("_____________________________________________________________________________________________\n");
									printf("|Código: %d",Ccliente);
									printf("|Nome: %s\n",cliente[Ccliente].nome);
									printf("|Sobrenome: %s\n",cliente[Ccliente].sobrenome);
									printf("|CPF: %s \n",cliente[Ccliente].cnpj);
									printf("|Registro de Habilitação:%s \n",cliente[Ccliente].nreg);
									printf("|Profissão:%s \n", cliente[Ccliente].Profissao);
									printf("|Ponto de Referência:%s \n",cliente[Ccliente].Ponto_de_Referencia);
									printf("|E-mail:%s  \n",cliente[Ccliente].e_mail);
									printf("|Telefone:%s \n",cliente[Ccliente].Telefone);
									printf("|____________________________________________________________________________________________\n");									
									busca++;
									}
									else
									{
										printf("Erro fatal! Tente novamente!\n");
										system("pause");
										break;
									}
								}
							}
							else
							{
								
							}
						}
					}
					if(cliente[Ccliente].cpcj!=0 && cliente[Ccliente].cpcj!=1 && cliente[Ccliente].cpcj!=2)
					{
						break;
					}
					
					if(busca == 0)
					{
						printf("Deculpe, não foi encontrado nenhum cliente com este nome.\n");
						system("pause");
					}
				}while(busca == 0);// CASO SAIA DO 0 ELE IRÁ CONTINUAR O PROGRAMA
				if(busca>0)
				{
					printf("Digite aqui o código do cliente:");
					scanf("%d",&Ccliente);
					if(cliente[Ccliente].status==0)
					{
						printf("Não há registro desse nome!");
						system("pause");
						break;
					}
					if(cliente[Ccliente].cpcj ==1)
					{
						printf("Nome do cliente: %s \n",cliente[Ccliente].nome);
						printf("Sobrenome do cliente: %s \n",cliente[Ccliente].sobrenome);
						printf("CPF do cliente: %s \n",cliente[Ccliente].CPF);
						printf("Numero do registro da habilitação do cliente: %s\n",cliente[Ccliente].nreg);
						printf("Profissão do cliente: %s \n",cliente[Ccliente].Profissao);
						printf("Endereço do cliente: %s\n",cliente[Ccliente].endereco);
						printf("Ponto de Referência: %s \n",cliente[Ccliente].Ponto_de_Referencia);
						printf("e-mail do cliente: %s\n",cliente[Ccliente].e_mail);
						printf("Telefone do cliente: %s\n\n",cliente[Ccliente].Telefone);
						do
						{
							printf("Gostaria de fazer a edição deste cliente?(s/n)");
							fflush(stdin);
							scanf("%c",&s_n);
							switch(s_n)
							{
								case 's':
								{
									printf ("Digite seu nome:");
			    					fflush(stdin);
						    		gets  (cliente[Ccliente].nome);
						    		printf ("Digite o sobrenome: ");
						    		scanf  ("%s",&cliente[Ccliente].sobrenome);
						    		printf ("Digite seu CPF: ");
						    		scanf  ("%s",&cliente[Ccliente].CPF);
						    		printf ("Digite o Número do registro da habilitação do cliente: ");
						    		scanf  ("%s",&cliente[Ccliente].nreg);
						    		printf ("Digite sua Profissão: ");
						    		scanf  ("%s",&cliente[Ccliente].Profissao);
						    		printf ("Digite seu endereço: ");
									fflush(stdin);
						    		gets(cliente[Ccliente].endereco);
						    		printf ("Digite um Ponto de Referência: ");
						    		fflush(stdin);
						    		gets(cliente[Ccliente].Ponto_de_Referencia);
						    		printf ("Digite seu Telefone: ");
						    		fflush(stdin);
						    		scanf("%s",&cliente[Ccliente].Telefone);
						    		printf ("Digite seu e-mail: ");
						    		fflush(stdin);
						    		gets(cliente[Ccliente].e_mail);
						    		printf ("As informações do novo cliente foram gravadas com sucesso!!\nO código do cliente é: %d.\nObs: O código do cliente é importante para fazer alterações no cadastro e fazer aluguel de veículos.",Ccliente);
						    		system ("pause");
						    		ret = 0;
						    		break;
								}
								case 'n':
								{
									printf("Voltando ao Menu de Opções.");
									system("pause");
									ret=0;
									break;
								}
								default:
								{
									printf("Opção Invalida! Tente novamente!");
									system("pause");
									break;
								}
							}
						}while(ret==1);
						ret = 1;
					}
					else
					{
						if(cliente[Ccliente].cpcj==2)
						{
							printf("Nome do cliente: %s \n",cliente[Ccliente].nome);
							printf("Sobrenome do cliente: %s \n",cliente[Ccliente].sobrenome);
							printf("CNPJ do cliente: %s \n",cliente[Ccliente].cnpj);
							printf("Numero do registro da habilitação do cliente: %s",cliente[Ccliente].nreg);
							printf("Profissão do cliente: %s \n",cliente[Ccliente].Profissao);
							printf("Ponto de Referência: %s \n",cliente[Ccliente].Ponto_de_Referencia);
							printf("e-mail do cliente: %s",cliente[Ccliente].e_mail);
							printf("Telefone do cliente: %s\n",cliente[Ccliente].Telefone);
							do
							{
								printf("Gostaria de fazer a edição deste cliente?(s/n)");
								scanf ("%c",&s_n);
								switch(s_n)
								{
									case 's':
									{
										printf ("Digite seu nome:");
				    					fflush(stdin);
							    		gets  (cliente[Ccliente].nome);
							    		printf ("Digite o sobrenome: ");
							    		scanf  ("%s",&cliente[Ccliente].sobrenome);
							    		printf ("Digite seu CNPJ: ");
							    		scanf  ("%s",&cliente[Ccliente].cnpj);
							    		printf ("Digite o Número do registro da habilitação do cliente: ");
							    		scanf  ("%s",&cliente[Ccliente].nreg);
							    		printf ("Digite sua Profissão: ");
							    		scanf  ("%s",&cliente[Ccliente].Profissao);
										printf ("Digite seu endereço: ");
										fflush(stdin);
							    		gets(cliente[Ccliente].endereco);
							    		printf ("Digite um Ponto de Referência: ");
							    		fflush(stdin);
							    		gets(cliente[Ccliente].Ponto_de_Referencia);
							    		printf ("Digite seu Telefone: ");
							    		fflush(stdin);
							    		scanf("%s",&cliente[Ccliente].Telefone);
							    		printf ("Digite seu e-mail: ");
							    		fflush(stdin);
							    		gets(cliente[Ccliente].e_mail);
							    		printf("As informações do novo cliente foram gravadas com sucesso!!\nO código do cliente é: %d.\nObs: O código do cliente é importante para fazer alterações no cadastro e fazer aluguel de veículos.",Ccliente);
							    		system("pause");
							    		ret = 0;
							    		break;
									}
									case 'n':
									{
										printf("Voltando ao Menu de Opções.\n");
										system("pause");
										ret = 0;
										break;
									}
									default:
									{
										printf("Opção Invalida! Tente novamente!\n");
										system("pause");
										break;
									}
								}
							}while(ret==1);
							ret=1;
						}
						else
						{
							printf("Erro Fatal!\nTente novamente!\n");
							system("pause");
							break;
						}
						fflush(stdin);
					}
					break;
				}
				else
				{
					printf("Não foi encontrado nenhum cliente com este nome!\n Retornando ao Menu de Opções!\n");
					system("pause");
					break;
				}
				break;
			}	 // término da função editar cliente.
			case '3':
			{ //início da função remover cliente
				printf("=============================================================\n");
	    		printf("====================REMOÇÃO DE USUÁRIO=======================\n");
	    		printf("===========================================================\n\n");
	    		printf("Digite o nome do cliente a ser removido:\n");
	    		do //
				{
					fflush(stdin);
					scanf("%s",&Bnome);
					busca = 0;
					for(Ccliente=0;Ccliente<=1000;Ccliente++)
					{
					
						if(cliente[Ccliente].status==1)//busca entre strings se ela for igual o check vai receber um valor = 0 se ele receber um valor = 0 o if irá funcionar
						{
							check=strcmp(Bnome,cliente[Ccliente].nome);
							if(check==0)
							{
								if(cliente[Ccliente].cpcj==1)
								{
									printf("_____________________________________________________________________________________________\n");
									printf("|Código: %d",Ccliente);
									printf("|Nome: %s\n",cliente[Ccliente].nome);
									printf("|Sobrenome: %s\n",cliente[Ccliente].sobrenome);
									printf("|CPF: %s \n",cliente[Ccliente].CPF);
									printf("|Registro de Habilitação:%s \n",cliente[Ccliente].nreg);
									printf("|Profissão:%s \n", cliente[Ccliente].Profissao);
									printf("|Ponto de Referência:%s \n",cliente[Ccliente].Ponto_de_Referencia);
									printf("|E-mail:%s  \n",cliente[Ccliente].e_mail);
									printf("|Telefone:%s \n",cliente[Ccliente].Telefone);
									printf("|____________________________________________________________________________________________\n");									
									busca++;
								}
								else
								{
									if(cliente[Ccliente].cpcj==2)
									{
										printf("_____________________________________________________________________________________________\n");
										printf("|Código: %d",Ccliente);
										printf("|Nome: %s\n",cliente[Ccliente].nome);
										printf("|Sobrenome: %s\n",cliente[Ccliente].sobrenome);
										printf("|CPF: %s \n",cliente[Ccliente].cnpj);
										printf("|Registro de Habilitação:%s \n",cliente[Ccliente].nreg);
										printf("|Profissão:%s \n", cliente[Ccliente].Profissao);
										printf("|Ponto de Referência:%s \n",cliente[Ccliente].Ponto_de_Referencia);
										printf("|E-mail:%s  \n",cliente[Ccliente].e_mail);
										printf("|Telefone:%s \n",cliente[Ccliente].Telefone);
										printf("|____________________________________________________________________________________________\n");									
										busca++;
									}
									else
									{
										printf("Erro fatal! Tente novamente!\n");
										system("pause");
										break;
									}
								}
							}
						}
					}
					if(cliente[Ccliente].cpcj!=0 && cliente[Ccliente].cpcj!=1 && cliente[Ccliente].cpcj!=2)
					{
						break;
					}
					
					if(busca == 0)
					{
						printf("Deculpe, não foi encontrado nenhum cliente com este nome.\n");
						system("pause");
					}
				}while(busca == 0);// CASO SAIA DO 0 ELE IRÁ CONTINUAR O PROGRAMA
				printf("Digite o código do cliente a ser selecionado:");
	    		scanf("%d",&Ccliente);
	    		if(cliente[Ccliente].status==0)	    	
				{	    			
					printf("Esse código não pertence a nenhum cliente!");
					system("pause");
					break;
				}
				printf("Nome do cliente: %s\n",cliente[Ccliente].nome);
				printf("Sobrenome do cliente: %s \n",cliente[Ccliente].sobrenome);
				if(cliente[Ccliente].cpcj==1)
				{
					printf("CPF do cliente: %s \n",cliente[Ccliente].CPF);
				}
				if(cliente[Ccliente].cpcj==2)
				{
					printf("CNPJ do cliente: %s \n",cliente[Ccliente].cnpj);
				}
				printf("Numero do registro da habilitação do cliente: %s\n",cliente[i].nreg);
				printf("Profissão do cliente: %s \n",cliente[Ccliente].Profissao);
				printf("Endereço do cliente: %s \n",cliente[Ccliente].endereco);
				printf("Ponto de Referência: %s \n",cliente[Ccliente].Ponto_de_Referencia);
				printf("e-mail do cliente: %s \n",cliente[Ccliente].e_mail);
				printf("Telefone do cliente: %s\n\n",cliente[Ccliente].Telefone);
				do //
				{
					printf("Gostaria de fazer a remoção deste cliente?(s/n)");
					fflush(stdin);
					scanf ("%c",&s_n);
					switch(s_n)
					{
						case 's':
						{
							cliente[Ccliente].status = 0;
							printf ("Removendo o nome!\n");
							for(j=0;j<sizeof(cliente[Ccliente].nome);j++)
							{
								cliente[Ccliente].nome[j]='\0';
							}
				    		printf ("Removendo o sobrenome!\n");
				    		for(j=0;j<sizeof(cliente[Ccliente].sobrenome);j++)
							{
								cliente[Ccliente].sobrenome[j]='\0';
							}
				    		printf ("Removendo o CPF/CNPJ!\n");
				    		for(j=0;j<sizeof(cliente[Ccliente].CPF);j++)
							{
								cliente[Ccliente].CPF[j]='\0';
							}
							for(j=0;j<sizeof(cliente[Ccliente].cnpj);j++)
							{
								cliente[Ccliente].cnpj[j]='\0';
							}
				    		printf ("Removendo o Numero do registro da habilitação do cliente!\n");
				    		for(j=0;j<sizeof(cliente[Ccliente].nreg);j++)
							{
								cliente[Ccliente].nreg[j]='\0';
							}
				    		printf ("Removendo a Profissão!\n ");
				    		for(j=0;j<sizeof(cliente[Ccliente].Profissao);j++)
							{
								cliente[Ccliente].Profissao[j]='\0';
							}
				    		printf ("Removendo o endereço!\n");
				    		for(j=0;j<sizeof(cliente[Ccliente].endereco);j++)
							{
								cliente[Ccliente].endereco[j]='\0';
							}
				    		printf ("Removendo o Ponto de Referência!\n");
				    		for(j=0;j<sizeof(cliente[Ccliente].Ponto_de_Referencia[j]);j++)
							{
								cliente[Ccliente].Ponto_de_Referencia[j]='\0';
							}
				    		printf ("Removendo o telefone!\n");
				    		for(j=0;j<sizeof(cliente[Ccliente].endereco);j++)
							{
								cliente[Ccliente].Telefone[j]='\0';
							}
				    		printf ("Removendo o e-mail!\n");
				    		for(j=0;j<sizeof(cliente[Ccliente].endereco);j++)
							{
								cliente[Ccliente].e_mail[j]='\0';
							}
				    		system ("pause");
							ret = 0;
						}
						case 'n':
						{
							printf("Retornando ao Menu de Opções.\n");
							system("pause");
							ret = 0;
						}
						default:
						{
							printf("Opção Invalida! Tente Novamente!");
							system("pause");
						}
					}
				}while(ret == 1);
				ret = 1;
				break;
			} //término da função remover.
			case '4':
			{ //inicio adicionar carro.
				printf("\n******SEJAM BEM VINDOS A LACODORA DE AUTOMÓVEIS AGTP******\n ");
				 //variável para evitar de substituir dados de outros carros.
				
				while (carro[c].statuscar== 1);//inf em cima
				{
					if(c > 999)
					{
						c = 0; //mesmo de tratamento de erro da função adicionar cliente.
					}
					c++;
				}
				carro[c].statuscar = 1;				
				printf("\n1-Grupo A Diária R$100\n2-Grupo B Diária R$150\n3-Grupo C Diária R$200\n4-Grupo D Diária R$250\n");
				scanf("%d",&carro[c].X1);
				if (carro[c].X1==1)
				{
					printf("A baixo insira informações sobre o carro\n");
					printf("Digite a marca do carro: ");
					scanf("%s",&carro[c].marca);
					printf("Ano: ");
			        scanf("%d",&carro[c].ano);
					printf("Cor: ");
					scanf("%s",&carro[c].cor);
					printf("Chassi: ");
					scanf("%s",&carro[c].chassi);
					printf("Tipo de combustivel: ");
					scanf("%s",&carro[c].combustivel);
					printf("Duas ou quatro portas ? ");
					scanf("%s",&carro[c].portas);
					printf("Quilometragem: ");
					fflush(stdin);
					scanf("%f",&carro[c].qlm);
					printf("Possui air bag ? ");
					fflush(stdin);
					scanf("%s",&carro[c].airbag);
					printf("Potencia : ");
					fflush(stdin);
					scanf("%s",&carro[c].poten);
					printf("O código de Registro do carro no sistema é: %d\n",c);
					carro[c].statuscar = 1;
					system("pause");
					break;
				}
			   else
				{
				   if(carro[c].X1==2)
					{
					printf("A baixo insira informações sobre o carro\n");
					printf("Digite a marca do carro: ");
					scanf("%s",&carro[c].marca);
					printf("Ano: ");
			        scanf("%d",&carro[c].ano);
					printf("Cor: ");
					scanf("%s",&carro[c].cor);
					printf("Chassi: ");
					scanf("%s",&carro[c].chassi);
					printf("Tipo de combustivel: ");
					scanf("%s",&carro[c].combustivel);
					printf("Duas ou quatro portas ? ");
					scanf("%s",&carro[c].portas);
					printf("Quilometragem: ");
					fflush(stdin);
					scanf("%f",&carro[c].qlm);
					printf("Possui air bag ? ");
					fflush(stdin);
					scanf("%s",&carro[c].airbag);
					printf("Potencia : ");
					fflush(stdin);
					scanf("%s",&carro[c].poten);
					printf("O código de Registro do carro no sistema é: %d\n",c);
					carro[c].statuscar = 1;
					system("pause");
					break;
					}
					else
					{
						if(carro[c].X1==3)
						{
							printf("A baixo insira informações sobre o carro\n");
							printf("Digite a marca do carro: ");
							scanf("%s",&carro[c].marca);
							printf("Ano: ");
					        scanf("%d",&carro[c].ano);
							printf("Cor: ");
							scanf("%s",&carro[c].cor);
							printf("Chassi: ");
							scanf("%s",&carro[c].chassi);
							printf("Tipo de combustivel: ");
							scanf("%s",&carro[c].combustivel);
							printf("Duas ou quatro portas ? ");
							scanf("%s",&carro[c].portas);
							printf("Quilometragem: ");
							fflush(stdin);
							scanf("%f",&carro[c].qlm);
							printf("Possui air bag ? ");
							fflush(stdin);
							scanf("%s",&carro[c].airbag);
							printf("Potencia : ");
							fflush(stdin);
							scanf("%s",&carro[c].poten);
							printf("O código de Registro do carro no sistema é: %d\n",c);
							carro[c].statuscar = 1;
							system("pause");
							break;
						}
					   else
						{
							if(carro[c].X1==4)
							{
								printf("A baixo insira informações sobre o carro\n");
								printf("Digite a marca do carro: ");
								scanf("%s",&carro[c].marca);
								printf("Ano: ");
						        scanf("%d",&carro[c].ano);
								printf("Cor: ");
								scanf("%s",&carro[c].cor);
								printf("Chassi: ");
								scanf("%s",&carro[c].chassi);
								printf("Tipo de combustivel: ");
								scanf("%s",&carro[c].combustivel);
								printf("Duas ou quatro portas ? ");
								scanf("%s",&carro[c].portas);
								printf("Quilometragem: ");
								fflush(stdin);
								scanf("%f",&carro[c].qlm);
								printf("Possui air bag ? ");
								fflush(stdin);
								scanf("%s",&carro[c].airbag);
								printf("Potencia : ");
								fflush(stdin);
								scanf("%s",&carro[c].poten);
								printf("O código de Registro do carro no sistema é: %d\n",c);
								carro[c].statuscar = 1;
								system("pause");
							break;
							}
							else
						    {
							    if(carro[c].X1==5)
							    {
							        printf("A baixo insira informações sobre o carro\n");
									printf("Digite a marca do carro: ");
									scanf("%s",&carro[c].marca);
									printf("Ano: ");
							        scanf("%d",&carro[c].ano);
									printf("Cor: ");
									scanf("%s",&carro[c].cor);
									printf("Chassi: ");
									scanf("%s",&carro[c].chassi);
									printf("Tipo de combustivel: ");
									scanf("%s",&carro[c].combustivel);
									printf("Duas ou quatro portas ? ");
									scanf("%s",&carro[c].portas);
									printf("Quilometragvem: ");
									fflush(stdin);
									scanf("%f",&carro[c].qlm);
									printf("Possui air bag ? ");
									fflush(stdin);
									scanf("%s",&carro[c].airbag);
									printf("Potencia : ");
									fflush(stdin);
									scanf("%s",&carro[c].poten);
									printf("O código de Registro do carro no sistema é: %d\n",c);
									carro[c].statuscar = 1;
									system("pause");
									break;
								}
								else
								{
									if(carro[c].X1==6)
									{
										printf("A baixo insira informações sobre o carro\n");
									    printf("Digite a marca do carro: ");
									   	scanf("%s",&carro[c].marca);
									   	printf("Ano: ");
								        scanf("%d",&carro[c].ano);
										printf("Cor: ");
										scanf("%s",&carro[c].cor);
										printf("Chassi: ");
										scanf("%s",&carro[c].chassi);
										printf("Tipo de combustivel: ");
										scanf("%s",&carro[c].combustivel);
										printf("Duas ou quatro portas? ");
										scanf("%s",&carro[c].portas);
										printf("Quilometragem: ");
										fflush(stdin);
										scanf("%f",&carro[c].qlm);
										printf("Possui air bag? ");
										fflush(stdin);
										scanf("%s",&carro[c].airbag);
										printf("Potencia : ");
										fflush(stdin);
										scanf("%s",&carro[c].poten);
										printf("O código de Registro do carro no sistema é: %d\n",c);
										carro[c].statuscar = 1;
										system("pause");
										break;
									}
									else
									{
										if(carro[c].X1==7)
										{
											printf("A baixo insira informações sobre o carro\n");
											printf("Digite a marca do carro: ");
											scanf("%s",&carro[c].marca);
											printf("Ano: ");
									        scanf("%d",&carro[c].ano);
											printf("Cor: ");
											scanf("%s",&carro[c].cor);
											printf("Chassi: ");
											scanf("%s",&carro[c].chassi);
											printf("Tipo de combustivel: ");
											scanf("%s",&carro[c].combustivel);
											printf("Duas ou quatro portas? ");
											scanf("%s",&carro[c].portas);
											printf("Quilometragem: ");
											fflush(stdin);
											scanf("%f",&carro[c].qlm);
											printf("Possui air bag? ");
											fflush(stdin);
											scanf("%s",&carro[c].airbag);
											printf("Potencia : ");
											fflush(stdin);
											scanf("%s",&carro[c].poten);
											printf("O código de Registro do carro no sistema é: %d\n",c);
											carro[c].statuscar = 1;
											system("pause");
											break;
										}
										else
										{
											if(carro[c].X1==8)
											{
												printf("A baixo insira informações sobre o carro\n");
												printf("Digite a marca do carro: ");
												scanf("%s",&carro[c].marca);
												printf("Ano: ");
										        scanf("%d",&carro[c].ano);
												printf("Cor: ");
												scanf("%s",&carro[c].cor);
												printf("Chassi: ");
												scanf("%s",&carro[c].chassi);
												printf("Tipo de combustivel: ");
												scanf("%s",&carro[c].combustivel);
												printf("Duas ou quatro portas ? ");
												scanf("%s",&carro[c].portas);
												printf("Quilometragem: ");
												fflush(stdin);
												scanf("%f",&carro[c].qlm);
												printf("Possui air bag ? ");
												fflush(stdin);
												scanf("%s",&carro[c].airbag);
												printf("Potencia : ");
												fflush(stdin);
												scanf("%s",&carro[c].poten);
												printf("O código de Registro do carro no sistema é: %d\n",c);
												carro[c].statuscar = 1;
												system("pause");
												break;
											}
											else
											{
												printf("Opção Invalida! Voltando ao Menu de Opções!");
												system("pause");
												break;
											}
										}												     										
									}										   
								}
							}				
						}      
					}
				}
			} //término do adicionar
			case '5':
			{ //inicio edição carro
				printf("---------------------------------\n");
				printf("Abaixo a opção de editar carro\n");
				printf("---------------------------------\n");
				busca = 0;
				do
				{
					printf("Digite a marca do carro que deseja alterar:");
					scanf("%s",&Mcarro);
					for(k=-2;k<1000;k++)
					{
						if(k<0)
						{
							k=0;
						}
						if(carro[k].statuscar==1)
						{
							check=strcmp(Mcarro,carro[k].marca);
							if(check==0)
							{
								printf("|---------------------------------------------------------------|\n");
								printf("|Código: %d\tMarca: %s\tAno: %d\tCor: %s\tChassi: %s\tTipo de combustivel: %s|\n|\tPortas: %s\tQuilometragem: %.2f\tAir Bag: %s\tPotencia: %s|\n",k,carro[k].marca,carro[k].ano,carro[k].cor,carro[k].chassi,carro[k].combustivel,carro[k].portas,carro[k].qlm,carro[k].airbag,carro[k].poten);
								printf("|---------------------------------------------------------------|\n\n");
								busca++;
							}
						}
					}
					if(busca == 0)
					{
						printf("Deculpe, não foi encontrado nenhum carro deste modelo.\n");
						system("pause");
						break;
					}					
				}while(busca==0);
				if(busca==0)
				{
					break;
				}
				do
				{
					printf("Digite o código do carro a ser editado:");
					scanf("%d",&k);
					if(carro[k].statuscar==0)
					{
						printf("Esse código não existe!\n");
					}
				}while(carro[k].statuscar==0);
				printf("Código: %d\tModelo: %s\tAno: %d\tCor: %s\tChassi: %s\tTipo de combustivel: %s\tPortas: %s\tQuilometragem: %.2f\tAir Bag: %s\tPotencia: %s\n\n",k,carro[k].marca,carro[k].ano,carro[k].cor,carro[k].chassi,carro[k].combustivel,carro[k].portas,carro[k].qlm,carro[k].airbag,carro[k].poten);
				do
				{
					printf("Deseja editar este carro?(s/n)");
					fflush(stdin);
					scanf("%c",&s_n);
					switch(s_n)
					{
						case 's':
						{
							printf("Digite a nova cor: ");
							scanf("%s",&carro[k].cor);
							printf("Digite o(s) combustivel(eis) aceitos pelo carro:");
							scanf("%s",&carro[k].combustivel);
							printf("Digite o número de portas: ");
							scanf("%s",&carro[k].portas);
							printf("Quilometragem: ");
							scanf("%f",&carro[k].qlm);
							printf("Possui air bag ? ");
							scanf("%s",&carro[k].airbag);
							printf("Potencia : ");
							scanf("%s",&carro[k].poten);
							printf("Edição feita com sucesso.");
							system("pause");
							ret = 0;
							break;
						}
						case 'n':
						{
							printf("Retornando ao Menu de Opções.");
							system("pause");
							ret = 0;
							break;
						}
						default:
						{
							printf("Opção Invalida! Tente Novamente!");
							system("pause");
							break;
						}
					}
				}while(ret ==1);
				ret = 1;
				break;
			} //Término da função editar carros.
			case '6':
			{ //Início da função remover carros.
				busca = 0;
				do
				{
					printf("Digite a marca do carro que deseja remover:");
					scanf("%s",&Mcarro);
					for(k=0;k<=1000;k++)
					{
					
						if(carro[k].statuscar==1)
						{
							check=strcmp(Mcarro,carro[k].marca);
							if(check==0)
							{
								printf("|---------------------------------------------------------------|\n");
								printf("|Código: %d\tModelo: %s\tAno: %d\tCor: %s\tChassi: %s\tTipo de combustivel: %s|\n|\tPortas: %s\tQuilometragem: %.2f\tAir Bag: %s\tPotencia: %s|\n",k,carro[k].marca,carro[k].ano,carro[k].cor,carro[k].chassi,carro[k].combustivel,carro[k].portas,carro[k].qlm,carro[k].airbag,carro[k].poten);
								printf("|---------------------------------------------------------------|\n\n");
								busca++;
							}
						}
						
					}
					if(busca == 0)
					{
						printf("Deculpe, não foi encontrado nenhum carro deste modelo.");
						system("pause");
						break;
					}
					system("pause");
				}while(busca==0);
				if(busca==0)
				{
					break;
				}
				do
				{
					printf("Digite o código do carro a ser removido:");
					scanf("%d",&k);
					if(carro[k].statuscar==0)
					{
						printf("Esse código não existe!\n");
					}
				}while(carro[k].statuscar==0);
				printf("Código: %d\tModelo: %s\tAno: %d\tCor: %s\tChassi: %s\tTipo de combustivel: %s\tPortas: %s\tQuilometragem: %.2f\tAir Bag: %s\tPotencia: %s\n\n",k,carro[k].marca,carro[k].ano,carro[k].cor,carro[k].chassi,carro[k].combustivel,carro[k].portas,carro[k].qlm,carro[k].airbag,carro[k].poten);
				do
				{
					printf("Gostaria de excluir este carro?(s/n)");
					scanf("%s",&s_n);
					switch(s_n)
					{
						case 's':
						{
							carro[k].statuscar=0;
							for(j=0;j<sizeof(carro[k].marca);j++)
							{
								carro[k].marca[j]='\0';
							}
							carro[k].ano=0;
							for(j=0;j<sizeof(carro[k].chassi);j++)
							{
								carro[k].chassi[j]='\0';
							}
							for(j=0;j<sizeof(carro[k].combustivel);j++)
							{
								carro[k].combustivel[j]='\0';
							}
							for(j=0;j<sizeof(carro[k].portas);j++)
							{
								carro[k].portas[j]='\0';
							}
							for(j=0;j<sizeof(carro[k].airbag);j++)
							{
								carro[k].airbag[j]='\0';
							}
							for(j=0;j<sizeof(carro[k].poten);j++)
							{
								carro[k].poten[j]='\0';
							}
							carro[k].qlm = 0;
							printf ("Removendo o carro selecionado!\n");
							system("pause");
							ret = 0;
							break;
						}
						case 'n':
						{
							printf("Retornando ao Menu de Opções!\n");
							ret = 0;
							break;
						}
						default:
						{
							printf("Opção Invalida! Tente Novamente!!!\n");
							system("pause");
							break;
						}
					}
				}while(ret == 1);
				ret = 1;
				break;
			} //final da função remover carro.
			case '7':
			{
				system ("color 9f");
			    printf ("================================================================================\n");
				printf ("================================SISTEMA DE ALUGUEL==============================\n");
    			printf ("================================================================================\n\n");
				busca = 0; //numero de resultados
				do // inicio de busca cliente
				{
					printf("Digite o nome do cliente a ser selecionado:");
					fflush(stdin);
					scanf("%s",Bnome);
					busca = 0;
					for(Ccliente=0;Ccliente<1000;Ccliente++)
					{
						if(cliente[Ccliente].status==1)//busca entre strings se ela for igual o check vai receber um valor = 0 se ele receber um valor = 0 o if irá funcionar
						{
							check=strcmp(Bnome,cliente[Ccliente].nome);
							if(check==0)
							{
								if(cliente[Ccliente].cpcj==1)
								{
									printf("____________________________________________________________________\n");
									printf("|Código: %d\n",Ccliente);
									printf("|Nome: %s\n",cliente[Ccliente].nome);
									printf("|Sobrenome: %s\n",cliente[Ccliente].sobrenome);
									printf("|CPF: %s\n",cliente[Ccliente].CPF);
									printf("|Registro de Habilitação: %s\n",cliente[Ccliente].nreg);
									printf("|Profissão: %s\n", cliente[Ccliente].Profissao);
									printf("|Ponto de Referência: %s\n",cliente[Ccliente].Ponto_de_Referencia);
									printf("|E-mail: %s\n",cliente[Ccliente].e_mail);
									printf("|Telefone: %s\n",cliente[Ccliente].Telefone);
									printf("|___________________________________________________________________\n");									
									busca++;
								}
								else
								{
									if(cliente[Ccliente].cpcj==2)
									{
										printf("|___________________________________________________________________\n");
										printf("|Código: %d\n",Ccliente);
										printf("|Nome: %s\n",cliente[Ccliente].nome);
										printf("|Sobrenome: %s\n",cliente[Ccliente].sobrenome);
										printf("|CNPJ: %s\n",cliente[Ccliente].cnpj);
										printf("|Registro de Habilitação: %s\n",cliente[Ccliente].nreg);
										printf("|Profissão: %s\n", cliente[Ccliente].Profissao);
										printf("|Ponto de Referência: %s\n",cliente[Ccliente].Ponto_de_Referencia);
										printf("|E-mail: %s\n",cliente[Ccliente].e_mail);
										printf("|Telefone: %s\n",cliente[Ccliente].Telefone);
										printf("|___________________________________________________________________\n");							
										busca++;
									}
									else
									{
										printf("Erro fatal! Tente novamente!\n");
										system("pause");
										break;
									}
								}
							}
							else
							{
								printf("Não consta nenhuma informação com o nome %s\n",Bnome);
								system("pause");
								break;
							}
						}
					}
					if(cliente[Ccliente].cpcj!=0 && cliente[Ccliente].cpcj!=1 && cliente[Ccliente].cpcj!=2)//neg
					{
						break;
					}
					if(busca == 0)
					{
						printf("Deculpe, não foi encontrado nenhum cliente com este nome.\n");
						system("pause");
					}
				}while(busca == 0);// CASO SAIA DO 0 ELE IRÁ CONTINUAR O PROGRAMA
				printf("Digite aqui o código do cliente:");
				scanf("%d",&Ccliente);
				if(cliente[Ccliente].status==0)
				{
					printf("Não há registro desse nome!");
					system("pause");
					break;
				}
				if(cliente[Ccliente].cpcj ==1)
				{
					printf("Nome do cliente: %s\n",cliente[Ccliente].nome);
					printf("Sobrenome do cliente: %s\n",cliente[Ccliente].sobrenome);
					printf("CPF do cliente: %s\n",cliente[Ccliente].CPF);
					printf("Numero do registro da habilitação do cliente: %s\n",cliente[Ccliente].nreg);
					printf("Profissão do cliente: %s\n",cliente[Ccliente].Profissao);
					printf("Endereço do cliente: %s\n",cliente[Ccliente].endereco);
					printf("Ponto de Referência: %s\n",cliente[Ccliente].Ponto_de_Referencia);
					printf("e-mail do cliente: %s\n",cliente[Ccliente].e_mail);
					printf("Telefone do cliente: %s\n",cliente[Ccliente].Telefone);
					printf("Cliente Selecionado!\n\n");
				}
				else
				{
					if(cliente[Ccliente].cpcj ==2)
					{
						printf("Nome do cliente: %s\n",cliente[Ccliente].nome);
						printf("Sobrenome do cliente: %s\n",cliente[Ccliente].sobrenome);
						printf("CNPJ do cliente: %s\n",cliente[Ccliente].cnpj);
						printf("Numero do registro da habilitação do cliente: %s\n",cliente[Ccliente].nreg);
						printf("Profissão do cliente: %s\n",cliente[Ccliente].Profissao);
						printf("Endereço do cliente: %s\n",cliente[Ccliente].endereco);
						printf("Ponto de Referência: %s\n",cliente[Ccliente].Ponto_de_Referencia);
						printf("e-mail do cliente: %s\n",cliente[Ccliente].e_mail);
						printf("Telefone do cliente: %s\n",cliente[Ccliente].Telefone);
						printf("Cliente Selecionado!\n\n");
					}
				}
				do//busca carros
				{
					printf("Digite a marca do carro que deseja selecionar:");
					scanf("%s",&Mcarro);
					for(c=0;c<=1000;c++)
					{
					
						if(carro[c].statuscar==1)
						{
							check=strcmp(Mcarro,carro[c].marca);
							if(check==0)
							{
								printf("|---------------------------------------------------------------|\n\n");
								printf("| Código: %d\n\t| Modelo: %s\n\t| Ano: %d\n\t| Cor: %s\n\t| Chassi: %s\n\t| Tipo de combustivel: %s\n\t| Portas: %s\n\t| Quilometragem: %.2f\n\t| Air Bag: %s\n\t| Potencia: %s\n",c,carro[c].marca,carro[c].ano,carro[c].cor,carro[c].chassi,carro[c].combustivel,carro[c].portas,carro[c].qlm,carro[c].airbag,carro[c].poten);
								printf("|---------------------------------------------------------------|\n\n");
								busca++;
							}
						}
					}
					if(busca == 0)
					{
						printf("Deculpe, não foi encontrado nenhum carro deste modelo.\n");
						system("pause");
						break;
					}
					system("pause");
				}while(busca==0);
				if(busca==0)
				{
					break;
				}
				do
				{
					printf("Digite o código do carro a ser selecionado:");
					scanf("%d",&c);
					if(carro[c].statuscar==0)
					{
						printf("Esse código não existe!\n");
					}
				}while(carro[c].statuscar==0);
				printf("\tCódigo: %d\n\ttModelo: %s\n\tAno: %d\n\tCor: %s\n\tChassi: %s\n\tTipo de combustivel: %s\n\tPortas: %s\n\tQuilometragem: %.2f\n\tAir Bag: %s\n\tPotencia: %s\n\n",k,carro[c].marca,carro[c].ano,carro[c].cor,carro[c].chassi,carro[c].combustivel,carro[c].portas,carro[c].qlm,carro[c].airbag,carro[c].poten);
				do //Inicio do questionario.
				{
					printf("Tem certeza que deseja alugar este carro?(s/n)\n");
					fflush(stdin);
					scanf("%c",&s_n);
					switch(s_n)
					{
						case 's':
						{
							if(carro[c].X1 == 1)
							{
								registro[j].valortotal = 100; //valor grupo
							}
							if(carro[c].X1 == 2)
							{
								registro[j].valortotal = 150;
							}
							if(carro[c].X1 == 3)
							{
								registro[j].valortotal = 200;
							}
							if(carro[c].X1 == 4)
							{
								registro[j].valortotal = 250;
							}
							ret = 0;
							break;
						}
						case 'n':
						{
							printf("Voltando ao menu de Opções!\n");
							system("pause");
							ret = 0;
							break;
						}
						//grupa A 100 reais, grupo B 150 reais, grupo C 200 reais, grupo D 250 reais
						default:
						{
							printf("Opção Invalida! Tente Novamente!\n");
							system("pause");
							break;
						}
						
					}
				}while (ret==1);
				ret = 1;
				if(s_n == 'n')
				{
					break;
				}
				do
				{
					printf("Escolha um seguro para o carro.\n");
					printf("PROTEÇÃO PARA O VEÍCULO LOCADO:\n1 - PROTEÇÃO PARCIAL R$28,00\n2 - PROTEÇÃO ESPECIAL R$38,00\n3 - SEM PROTEÇÃO R$00,00\n");
					scanf("%d",&escolha);
					switch(escolha)
					{
						case 1:
						{
							printf("Você deseja realmente escolher essa opção?(s/n)");
							fflush(stdin);
							scanf ("%c",&s_n);
							do
							{
								switch(s_n)
								{
									case 's':
									{
										registro[r].valortotal+=28;
										ret = 0;
										break;
									}
									case 'n':
									{
										ret = 0;
										break;
									}
									default:
									{
										printf("Opção Invalida!! Tente Novamente!\n");
										system("pause");
										break;
									}
								}
							}while(ret == 1);
							ret = 1;
						}
						case 2:
						{
							printf("Você deseja realmente escolher essa opção?(s/n)");
							fflush(stdin);
							scanf ("%c",&s_n);
							do
							{
								switch(s_n)
								{
									case 's':
									{
										registro[r].valortotal+=38;
										ret = 0;
										break;
									}
									case 'n':
									{
										ret = 0;
										break;
									}
									default:
									{
										system("pause");
										printf("Opção Invalida!! Tente Novamente!\n");
										break;
									}
								}
							}while(ret == 1);
							ret = 1;
						}
						case 3:
						{
							printf("Escolhendo não ter nenhum seguro a responsabilidade por pagar o reparo do carro em caso de AVARIAS será do contratante.\nVocê deseja realmente escolher essa opção?(s/n)");
							fflush(stdin);
							scanf ("%c",&s_n);
							do
							{
								switch(s_n)
								{
									case 's':
									{
										registro[r].valortotal+=22;
										ret = 0;
										break;
									}
									case 'n':
									{
										ret = 0;
										break;
									}
									default:
									{
										printf("Opção Invalida!! Tente Novamente!\n");
										break;
									}
								}
							}while(ret == 1);
						}
					}
					if(s_n=='s')
					{
						ret == 0;
					}
				}while(ret == 1);
				ret = 1;
				do
				{
					printf("Escolha os acessorios que gostaria de instalar no carro a ser contratado:\n");
					printf("\tACESSÓRIOS:\n\t1 - ASSENTO LOCATÁRIO JOVEM R$22,00\n\t2 - Assento de Elevação para Criança R$22,00\n\t3 - Assento Especial para Criança R$22,00\n\t4 - Assento Especial para Bebe R$22,00\n\t5 - PRONTO.\n");
					scanf ("%d",&escolha);
					switch (escolha)
					{
						case 1:
						{
							do
							{
								printf("Você deseja realmente escolher essa opção?(s/n)");
								fflush(stdin);
								scanf ("%c",&s_n);
								switch(s_n)
								{
									case 's':
									{
										registro[r].valortotal+=22;
										ret = 0;
										break;
									}
									case 'n':
									{
										ret = 0;
										break;
										
									}
									default:
									{
										printf("Opção Invalida!! Tente Novamente!\n");
										break;
									}
								}
							}while(ret == 1);
							ret == 1;
							break;
						}
						case 2:
						{
							do
							{
								printf("Você deseja realmente escolher essa opção?(s/n)");
								fflush(stdin);
								scanf ("%c",&s_n);
								switch(s_n)
								{
									case 's':
									{
										registro[r].valortotal+=22;
										ret = 0;
										break;
									}
									case 'n':
									{
										ret = 0;
										break;
									}
									default:
									{
										printf("Opção Invalida!! Tente Novamente!");
										break;
									}
								}
							}while(ret == 1);
							ret ==1;
							break;
						}
						case 3:
						{
							do
							{
								printf("Você deseja realmente escolher essa opção?(s/n)");
								fflush(stdin);
								scanf ("%c",&s_n);
								switch(s_n)
								{
									case 's':
									{
										registro[r].valortotal+=22;
										ret = 0;
										break;
									}
									case 'n':
									{
										ret = 0;
										break;
									}
									default:
									{
										printf("Opção Invalida!! Tente Novamente!");
										break;
									}
								}
							}while(ret == 1);
							ret == 1;
							break;
						}
						case 4:
						{
							printf("Você deseja realmente escolher essa opção?(s/n)");
							fflush(stdin);
							scanf ("%c",&s_n);
							do
							{
								switch(s_n)
								{
									case 's':
									{
										registro[r].valortotal+=22;
										ret = 0;
										break;
									}
									case 'n':
									{
										ret = 0;
										break;
									}
									default:
									{
										printf("Opção Invalida!! Tente Novamente!");
										break;
									}
								}
							}while(ret == 1);
							ret = 1;
							break;
						}
						case 5:
						{
							ret = 0;
							break;
						}
					}
				}while(ret == 1);
				ret = 1;
				printf("O valor total do aluguel será: R$ %.2f\n",registro[r].valortotal);
				do
				{
					printf("Deseja contratar o aluguel?(s/n)");
					fflush(stdin);
					scanf("%c",&s_n);
					switch(s_n)
					{
						case 's':
						{
							registro[r].aluguel = 1;
							for(j=0;j<sizeof(cliente[Ccliente].nome);j++)
							{
								registro[r].nome[j]=cliente[Ccliente].nome[j];
							}
							if(cliente[Ccliente].cpcj==1)
							{
								for(j=0;j<sizeof(cliente[Ccliente].CPF);j++)
								{
									registro[r].CPF[j]=cliente[Ccliente].CPF[j];
								}
							}
							else
							{
								if(cliente[Ccliente].cpcj==2)
								{
									for(j=0;j<sizeof(cliente[Ccliente].cnpj);j++)
									{
										registro[r].nome[j]=cliente[Ccliente].CPF[j];
									}
								}
							}
							
							for(j=0;j<sizeof(carro[c].marca);j++)
							{
								registro[r].marca[j]=carro[c].marca[j];
							}
							for(j=0;j<sizeof(carro[c].chassi);j++)
							{
								registro[r].chassi[j]=carro[c].chassi[j];
							}
							arq4 = fopen("registro.txt","a");
							if(arq4==NULL)
							{
								printf("Não foi possível abrir o arquivo \"registro.txt\"");
							}
							else
							{
								fprintf(arq4,"%d\n%s\n%s\n%s\n%s",registro[r].aluguel,registro[r].nome,registro[r].CPF,registro[r].marca,registro[r].chassi);
							}
							printf("Aluguel registrado com sucesso!!\n");
							system("pause");
							ret = 0;
							break;
						}
						case 'n':
						{
							ret = 0;
							break;
						}
						default:
						{
							printf("Opção Invalida!!! Tente Novamente!\n");
						}
					}
				}while(ret == 1);
				ret = 1;
				break;
			} // final da função aluguel
			case '9':
			{ //inicio da função saída e escrita em txt
				while(i<1000)
				{	
					for(j=0;j<sizeof(cliente[i].nome);j++)
					{
						if(cliente[i].nome[j]== ' ')
						{
							cliente[i].nome[j] = '_';
						}
					}
					for(j=0;j<sizeof(cliente[i].sobrenome);j++)
					{
						if(cliente[i].sobrenome[j]== ' ')
						{
							cliente[i].sobrenome[j] = '_';
						}
					}
					for(j=0;j<sizeof(cliente[i].CPF);j++)
					{
						if(cliente[i].CPF[j]== ' ')
						{
							cliente[i].CPF[j] = '_';
						}
					}
					for(j=0;j<sizeof(cliente[i].CPF);j++)
					{
						if(cliente[i].CPF[j]== ' ')
						{
							cliente[i].CPF[j] = '_';
						}
					}
					for(j=0;j<sizeof(cliente[i].cnpj);j++)
					{
						if(cliente[i].cnpj[j]== ' ')
						{
							cliente[i].cnpj[j] = '_';
						}
					}
					for(j=0;j<sizeof(cliente[i].Profissao);j++)
					{
						if(cliente[i].Profissao[j]== ' ')
						{
							cliente[i].Profissao[j] = '_';
						}
					}
					for(j=0;j<sizeof(cliente[i].endereco);j++)
					{
						if(cliente[i].endereco[j]== ' ')
						{
							cliente[i].endereco[j] = '_';
						}
					}
					for(j=0;j<sizeof(cliente[i].Ponto_de_Referencia);j++)
					{
						if(cliente[i].Ponto_de_Referencia[j]== ' ')
						{
							cliente[i].Ponto_de_Referencia[j] = '_';
						}
					}
					for(j=0;j<sizeof(cliente[i].Telefone);j++)
					{
						if(cliente[i].Telefone[j]== ' ')
						{
							cliente[i].Telefone[j] = '_';
						}
					}
					for(j=0;j<sizeof(cliente[i].nreg);j++)
					{
						if(cliente[i].nreg[j]== ' ')
						{
							cliente[i].nreg[j] = '_';
						}
					}
					i++;
				}
				arq1=fopen("clientes.txt","w");
				i=0;
				for(i=-2;i<=1000;i++)
				{
					if(i<0)
					{
						i=0;
					}
					if(cliente[i].status==1)
					{
						if(cliente[i].cpcj==1)
						{
							fprintf(arq1,"1\n%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",cliente[i].status,cliente[i].cpcj,cliente[i].nome,cliente[i].sobrenome,cliente[i].CPF,cliente[i].Profissao,cliente[i].endereco,cliente[i].Ponto_de_Referencia,cliente[i].Telefone,cliente[i].e_mail,cliente[i].nreg);
						}
						else
						{
							if(cliente[i].cpcj==2)
							{
								fprintf(arq1,"1\n%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",cliente[i].status,cliente[i].cpcj,cliente[i].nome,cliente[i].sobrenome,cliente[i].cnpj,cliente[i].Profissao,cliente[i].endereco,cliente[i].Ponto_de_Referencia,cliente[i].Telefone,cliente[i].e_mail,cliente[i].nreg);
							}
							fclose(arq1);
						}
					}
				}
				i=0;
				rewind(arq3); //Rewind = Limpa buffer de ponteiro.
				arq3=fopen("carros.txt","w+");
				if(arq3 == NULL)
				{
					printf("Falha ao abrir o arquivo carros.txt!\n");
				}
				else
				{
					for(i=-2;i<1000;i++)
					{
						if(i<0)
						{
							i=0;
						}
						if(carro[i].statuscar==1)
						{
							fprintf(arq3,"1\n%d\n%d\n%s\n%s\n%s\n%s\n%s\n%d\n",carro[i].statuscar,carro[i].X1,carro[i].chassi,carro[i].combustivel,carro[i].poten,carro[i].marca,carro[i].airbag,carro[i].ano,carro[i].cor,carro[i].portas);
						}
					}
				}
				fclose(arq3);
				system("color 2f");
	    		system("cls");
				printf("\n\n\tPROGRAMADORES.\n\n");
				printf("\t ___________________ \n");
		    	printf("\t|  Alexandre Coelho |\n");
		    	printf("\t|  Gabriel Barros   |\n");
		    	printf("\t|  Paulo Marcos     |\n");
		    	printf("\t|  Thales Moraes    |\n");
		    	printf("\t|___________________|\n");
		    	printf("\n");
		    	getchar();
				printf ("\tPressione Enter Para Fechar o Programa.\n");
		        getchar();
				system("cls");
				ret = 0;
				break;
			}//final da função sair
			default : 
			{
				printf ("Opção invalida!\n");
				system("pause");
				break;
			}
		}
	}while(ret == 1);
	printf("Até logo!\n");
	system ("pause");
	return 0;
}
