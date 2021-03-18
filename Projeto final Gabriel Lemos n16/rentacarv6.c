#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int menu3;
struct registro {
   char modelo[40];
   char categoria[20];
   int quantidade;
   int precopdia;
   char status;
   char senha[20];
   char senhad[20];
   } reg;
struct funcionarios {
	char nome [40];
	char cargo [25];
	int idade;
	int salario;
	char status;
   } fun; 
struct infopag {
	char nomep [40];
	int ncartao [40];
	int scartao [40];
	int idade;
	char status;
} inf;
char loginl [20];
FILE *fp;
FILE *fpp;
FILE *fppp;
FILE *fs;
void inserir(void);
void abrir(char tipo[3]);
void inserirs (void);
void inserirf (void);
void inserirp (void);
void listarf(void) {
   int cont=0;

   abrirf("rb");
   fseek(fppp, 0L, SEEK_SET);
   fread(&fun, sizeof(struct funcionarios),1, fppp);
   fflush(stdin);
   do
   {
      if (fun.status!='0')
	 {
	 	fflush (stdin);
	    printf("\nNome: %s",fun.nome);
	    printf("\nCargo: %s",fun.cargo);
	    printf("\nIdade: %d",fun.idade);
	    printf("\nSal�rio: %d",fun.salario);
	    printf("\n****************************");
	    cont++;
	 }
      fread(&fun, sizeof(struct funcionarios),1, fppp);
      }while(!feof(fppp));
   printf("\nN�mero de funcion�rios: %d",cont);
   getch();
}

void inserirf(void)
{  
     abrirf("ab+");
     fseek(fppp,0L, SEEK_END);

     do
     {
    fflush (stdin);
	printf("Digite o nome do funcion�rio ou <fim> para sair:\n");
	gets (fun.nome);
	if ((strcmp(fun.nome,"fim")!=0)&&(strcmp(fun.nome,"FIM")!=0)){
		printf("\nCargo:"); 
		gets(fun.cargo);
		printf("\nIdade:"); 
		scanf ("%d",&fun.idade);
		fflush (stdin);
		printf("\nSal�rio:"); 
		scanf ("%d",&fun.salario);
		fun.status='1';
		if(fwrite(&fun, sizeof(struct funcionarios), 1, fppp) != 1)
		{
		printf("\nErro de grava��o!!");
		getch();
		}
		else
		{   printf("\nGrava��o feita com sucesso no ficheiro...\n\n");}
		}
     }while((strcmp(fun.nome,"fim")!=0)&&(strcmp(fun.nome,"FIM")!=0));
     fclose(fppp);
}
void (funcionaris) (void){
	do {
					system ("cls");
					printf ("**********************************\n");\
					printf ("\n1-Verificar funcion�rios");
	    			printf ("\n2-Adicionar funcion�rios");
	    			printf ("\n3-Demitir funcion�rios");
					printf ("\n4-Voltar\n");
					scanf ("%d",&menu3);
					switch (menu3){
					case 1:
					system ("cls");
					listarf();
					break;
					case 2:
					system ("cls");
					inserirf();
					break;
					case 3:
					system ("cls");
					eliminarf();
					break;
					case 4:
					system ("cls");
					printf ("\nVoltando...\n");
					getch ();
					break;
					default:
					system ("cls"); 
					printf ("\nOp��o errada\n");
					system ("pause");
					}
					} while (menu3 != 4);
}
void eliminarf(void){
   fflush (stdin);
   int posf, optf;
   char opcao1f[2], op1f;
   posf=buscaf();
   if(posf==-1)
      {
	 printf("\nFuncion�rio n�o existe na empresa. Qualquer tecla para continuar\n");
	 getch();
      }
      else
	 {
			 fflush (stdin);
		     abrirf("rb+");
		     fseek(fppp, posf*sizeof(struct funcionarios), SEEK_SET);
		     fread(&fun, sizeof(struct funcionarios), 1, fppp);		   	     
		     printf("\nNome: %s",fun.nome);
		     printf("\nCargo: %s",fun.cargo);
		     printf("\nIdade: %d",fun.idade);
		     printf("\nSal�rio: %d",fun.salario);
		    do{
		    printf("\nDeseja mesmo o demitir? <S>-sim <N>-n�o\n");
		    gets(opcao1f);
       		op1f=tolower(*opcao1f);
		    } while(!strchr("sn",op1f));    
		if (op1f=='s')
		{				 
		    //pos=pos+1;
		     fun.status='0';
		     fseek(fppp, posf*sizeof(struct funcionarios), SEEK_SET);
		     if(fwrite(&fun, sizeof(struct funcionarios), 1, fppp)!=1)
			{
			   printf("\nN�o foi poss�vel eliminar o funcion�rio da base de dados.Qualquer tecla para continuar \n");
			   getch();
			}
			else
			{
			   printf("\nFuncion�rio eliminado da base de dados com sucesso.Qualquer tecla para continuar \n");
			   getch();
			}
		
		}
		else{
			printf("\nOptou por n�o demitir o funcion�rio, qualquer tecla para continuar.\n");
			getch();
			
		}
		
			

		  }
	 
   fclose(fppp);
}




void alugar(void){
   fflush (stdin);
   int pos, opt;
   char opcao1[2], op1;
   pos=busca();
   if(pos==-1)
      {
	 printf("\nCarro n�o existe na frota. Qualquer tecla para continuar\n");
	 getch();
      }
      else
	 {
	    if(pos==-2)
	       {
		  printf("\nO modelo j� foi eliminado da frota. Qualquer tecla para continuar\n");
		  getch();
	       }
	       else
		  {
			 fflush (stdin);
		     abrir("rb+");
		     fseek(fp, pos*sizeof(struct registro), SEEK_SET);
		     fread(&reg, sizeof(struct registro), 1, fp);
			 system ("cls");		   	     
		     printf("\nCategoria: %s",reg.categoria);
		     printf("\nModelo: %s",reg.modelo);
		     printf("\nQuantidade: %d",reg.quantidade);
		     printf("\nPre�o por dia: %d",reg.precopdia);
		    do{
		    printf("\nDeseja mesmo alugar o modelo? <S>-sim <N>-n�o\n");
		    gets(opcao1);
       		op1=tolower(*opcao1);
		    } while(!strchr("sn",op1));    
		if (op1=='s')
		{				 
		    //pos=pos+1;
		     reg.quantidade --;
		     fseek(fp, pos*sizeof(struct registro), SEEK_SET);
		     if(fwrite(&reg, sizeof(struct registro), 1, fp)!=1)
			{
			   printf("\nN�o foi poss�vel alugar o modelo da base de dados\n");
			   getch();
			}
			else
			{
			   printf("\nParab�ns, aluguel conclu�do com sucesso\n");
			   getch();
			}
		
		}
		else{
			printf("\nOptou por n�o alugar o modelo, qualquer tecla para continuar.\n");
			getch();
			
		
		
			

		  } }
	 }
   fclose(fp);
}





void eliminar(void){
   fflush (stdin);
   int pos, opt;
   char opcao1[2], op1;
   pos=busca();
   if(pos==-1)
      {
	 printf("\nCarro n�o existe na frota. Qualquer tecla para continuar\n");
	 getch();
      }
      else
	 {
	    if(pos==-2)
	       {
		  printf("\nO modelo j� foi eliminado da frota. Qualquer tecla para continuar\n");
		  getch();
	       }
	       else
		  {
		     system ("cls");
			 printf ("\nDeseja eliminar apenas um carro, ou todos os modelos?\n");
			 printf ("Digite 1 para apenas um carro e 2 para todos os modelos\n");
			 scanf ("%d",&opt);
			 if (opt < 2) {
			 abrir("rb+");
		     fseek(fp, pos*sizeof(struct registro), SEEK_SET);
		     fread(&reg, sizeof(struct registro), 1, fp);		   	     
		     printf("\nCategoria: %s",reg.categoria);
		     printf("\nModelo: %s",reg.modelo);
		     printf("\nQuantidade: %d",reg.quantidade);
		     printf("\nPre�o por dia: %d",reg.precopdia);
		     fflush (stdin);
		    do{
		    printf("\nDeseja mesmo eliminar uma unidade? <S>-sim <N>-n�o\n");
		    gets(opcao1);
       		op1=tolower(*opcao1);
		    } while(!strchr("sn",op1));  
			if (reg.quantidade > 1){
			
		if (op1=='s')
		{				 
		    //pos=pos+1;
		     reg.quantidade --;
		     fseek(fp, pos*sizeof(struct registro), SEEK_SET);
		     if(fwrite(&reg, sizeof(struct registro), 1, fp)!=1)
			{
			   printf("\nN�o foi poss�vel eliminar o carro da base de dados.Qualquer tecla para continuar \n");
			   getch();
			}
			else
			{
			   printf("\nUnidade eliminado com sucesso.Qualquer tecla para continuar \n");
			   getch();
			} 
		
		
		} 
		else{
			printf("\nOptou por n�o eliminar o modelo, qualquer tecla para continuar.\n");
			getch();}
			}else {
			printf ("\nN�o � poss�vel eliminar o carro da base de dados");
			getch();}
			
		
			 } else {
			 fflush (stdin);
		     abrir("rb+");
		     fseek(fp, pos*sizeof(struct registro), SEEK_SET);
		     fread(&reg, sizeof(struct registro), 1, fp);		   	     
		     printf("\nCategoria: %s",reg.categoria);
		     printf("\nModelo: %s",reg.modelo);
		     printf("\nQuantidade: %d",reg.quantidade);
		     printf("\nPre�o por dia: %d",reg.precopdia);
		    do{
		    printf("\nDeseja mesmo eliminar o modelo? <S>-sim <N>-n�o\n");
		    gets(opcao1);
       		op1=tolower(*opcao1);
		    } while(!strchr("sn",op1));    
		if (op1=='s')
		{				 
		    //pos=pos+1;
		     reg.status='0';
		     fseek(fp, pos*sizeof(struct registro), SEEK_SET);
		     if(fwrite(&reg, sizeof(struct registro), 1, fp)!=1)
			{
			   printf("\nN�o foi poss�vel eliminar o modelo da base de dados.Qualquer tecla para continuar \n");
			   getch();
			}
			else
			{
			   printf("\nModelo eliminado com sucesso.Qualquer tecla para continuar \n");
			   getch();
			}
		
		}
		else{
			printf("\nOptou por n�o eliminar o modelo, qualquer tecla para continuar.\n");
			getch();
			
		}
		
			

		  } }
	 }
   fclose(fp);
}
int busca (void){
   fflush (stdin);
   int achou=-1,posicao=0;
   char marcap[40];
   abrir("rb");
   printf("\n\nDigite o modelo:\n");
   gets(marcap);
   rewind(fp);
   while((!feof(fp))&&(achou==-1))
   {
      fread(&reg, sizeof(struct registro), 1, fp);
      if (!feof(fp))
	 {
	 if (strcmp(marcap, reg.modelo)==0)
	    {
		if (reg.status=='0')
	       {posicao=-2;}
	     achou=1;
	    }
	  else{posicao++;}
	 }
      else{posicao=-1;}
   }
   if (achou==-1)
      {posicao=-1;}
   fclose(fp);
   return(posicao);
}
int buscaf (void){
   fflush (stdin);
   int achouf=-1,posicaof=0;
   char marcapf[40];
   abrirf("rb");
   printf("\nDigite o nome do funcion�rio a ser procurado:\n");
   gets(marcapf);
   rewind(fppp);
   while((!feof(fppp))&&(achouf==-1))
   {
      fread(&fun, sizeof(struct funcionarios), 1, fppp);
      if (!feof(fppp))
	 {
	 if (strcmp(marcapf, fun.nome)==0)
	    {
		if (fun.status=='0')
	       {posicaof=-2;}
	     achouf=1;
	    }
	  else{posicaof++;}
	 }
      else{posicaof=-1;}
   }
   if (achouf==-1)
      {posicaof=-1;}
   fclose(fppp);
   return(posicaof);
}

void listar(void) {
   int cont=0;

   abrir("rb");
   fseek(fp, 0L, SEEK_SET);
   fread(&reg, sizeof(struct registro),1, fp);
   //fflush(stdin);
   do
   {
      if (reg.status!='0')
	 {
	 	fflush (stdin);
	    printf("\nCategoria: %s",reg.categoria);
	    printf("\nModelo: %s",reg.modelo);
	    printf("\nQuantidade: %d",reg.quantidade);
	    printf("\nPre�o por dia: %d",reg.precopdia);
	    printf("\n****************************");
	    cont++;
	 }
      fread(&reg, sizeof(struct registro),1, fp);
      }while(!feof(fp));
   printf("\nN�mero de modelos: %d",cont);
   getch();
}

void abrir(char tipo[3])
{
     if((fp=fopen("registo.dat", tipo))==NULL)
     {printf("O ficheiro n�o pode ser aberto...\n");
      getch();
      exit(1);
     }
}
void abrirs(char tipo[3])
{
     if((fpp=fopen("senhas.dat", tipo))==NULL)
     {printf("\n O ficheiro nao pode ser aberto!!\n");
      getch();
      exit(1);
     }
}
void abrirf(char tipo[3])
{
     if((fppp=fopen("funcionarios.dat", tipo))==NULL)
     {printf("\n O ficheiro nao pode ser aberto!!\n");
      getch();
      exit(1);
     }
}
void inserir(void)
{  
     abrir("ab+");
     fseek(fp,0L, SEEK_END);

     do
     {
    fflush (stdin);
	printf("Digite a categoria do ve�culo ou <fim> para sair:\n");
	gets (reg.categoria);
	if ((strcmp(reg.categoria,"fim")!=0)&&(strcmp(reg.categoria,"FIM")!=0)){
		fflush (stdin);
		printf("\nModelo:"); 
		gets(reg.modelo);
		printf("\nQuantidade:"); 
		scanf ("%d",&reg.quantidade);
		fflush (stdin);
		printf("\nPre�o por dia:"); 
		scanf ("%d",&reg.precopdia);
		reg.status='1';
		if(fwrite(&reg, sizeof(struct registro), 1, fp) != 1)
		{
		printf("\nErro de grava��o!!");
		getch();
		}
		else
		{   printf("\nGrava��o feita com sucesso no ficheiro...\n\n");}
		}
     }while((strcmp(reg.categoria,"fim")!=0)&&(strcmp(reg.categoria,"FIM")!=0));
     fclose(fp);
}




void devolver(void)
{  
     abrir("ab+");
     fseek(fp,0L, SEEK_END);

     
    fflush (stdin);
	printf("Digite a categoria do ve�culo que deseja devolver:\n");
	gets (reg.categoria);
		fflush (stdin);
		printf("\nModelo:"); 
		gets(reg.modelo);
		reg.quantidade ++;
		fflush (stdin);
		printf("\nQuanto pagaste por dia?:"); 
		scanf ("%d",&reg.precopdia);
		reg.status='1';
		if(fwrite(&reg, sizeof(struct registro), 1, fp) != 1)
		{
		printf("\nErro de grava��o!!");
		getch();
		}
		else
		{   printf("\nGrava��o feita com sucesso no ficheiro...\n\n");}
     fclose(fp);
}




void inserirp (void)
{  
     abrirp("ab+");
     fseek(fs,0L, SEEK_END);
    fflush (stdin);
	printf("Digite o seu nome:\n");
	gets (inf.nomep);
	
		printf("\nN�mero do cart�o:"); 
		scanf ("%d",inf.ncartao);
		printf("\nSenha do cart�o:"); 
		scanf ("%d",&inf.scartao);
		fflush (stdin);
		inf.status='1';
		if(fwrite(&inf, sizeof(struct infopag), 1, fs) != 1)
		{
		printf("\nErro de grava��o!!");
		getch();
		}
		else
		{   printf("\nGrava��o feita com sucesso no ficheiro...\n\n");
		system ("pause");
		}
		
     
     fclose(fp);
}





void abrirp(char tipo[3])
{
     if((fs=fopen("pagamento.dat", tipo))==NULL)
     {printf("\n O ficheiro nao pode ser aberto!!\n");
      getch();
      exit(1);
     }
}





void inserirs(void)
{  
     abrirs("ab+");
     fseek(fpp,0L, SEEK_END);
    fflush (stdin);
    system("cls");
    printf ("**********REGISTRO************\n");
	printf("Defina a sua senha:");
	gets (reg.senhad);
		if(fwrite(&reg, sizeof(struct registro), 1, fpp) != 1)
		{
		printf("\n Erro de grava��o!!");
		getch();
		}
		else
		{   printf("\n Grava��o feita com sucesso no ficheiro...\n\n");}
		
     fclose(fp);
}
int loginc, tent;
login (){
	system ("cls");
	printf ("\nDigite seu nome\n");
    scanf ("%s", loginl);
    system ("cls");
    printf ("\nDigite sua senha\n");
    scanf ("%s", reg.senha);
    loginc = 0;
    if (strcmp (reg.senha,reg.senhad) == 0) {
    	system ("cls");
    	printf ("\nLogin efetuado com sucesso!\n");
    	getch();
    	loginc = 7;
	} else {
		printf ("\nSenha incorreta\n");
		system ("pause");
		for (tent = 3; tent > -1; tent --) {
		system ("cls");
    	printf ("\nDigite sua senha\n");
    	scanf ("%s", reg.senha);
    	if (strcmp (reg.senha,reg.senhad) == 0) {
    	system ("cls");
    	printf ("\nLogin efetuado com sucesso!\n");
    	getch ();
    	loginc = 7;
    	tent = -1;
		} else {
		printf ("\nSenha incorreta, %d tentativas restantes\n", tent);
		system ("pause");
		}}
    
	}
}
main () {
	inserirs();
	int menu1,menu2,optz;
	setlocale (LC_ALL, "Portuguese");
	system ("color 0e");
	system ("cls");
	printf ("**********************************\n");
	printf ("Bem vindo a Trust Rent-a-car!\n");
	
	getch();
                do {
                system ("cls");
				printf ("\nVoc� � um cliente ou um administrador?\n");
				printf ("\n1-Cliente");
	    		printf ("\n2-Administrador");
				printf ("\n3-Sair\n");
				scanf ("%d", &menu1);
				switch (menu1){
				case 1:
					do {
				 	system ("cls");
					printf ("**********************************\n");
					printf ("\nBem vindo a central da Trust Rentacar para clientes\n");
					printf ("\n1-Alugar um carro");
	    			printf ("\n2-Verificar carros dispon�veis");
	    			printf ("\n3-Devolver um ve�culo");
	    			printf ("\n4-Sair\n");
					scanf ("%d",&menu2);
					switch (menu2){
					case 1:
					system ("cls");
					inserirp ();
					system ("cls");
					printf ("\nAgora escolha seu ve�culo\n");
					getch();
					listar ();
			        alugar ();
					break;
					case 2:
					system ("cls");
	                listar ();
					break;
					case 3:
					system ("cls");
					devolver ();
					break;
					case 4:
					do {
					system ("cls");
					printf ("\nSe quiser sair, digite 1, se quiser voltar ao menu principal, digite 2\n");
					scanf ("%d",&optz);
					if (optz == 1) {
						system ("cls");
						printf ("\nSaindo...\n");
						getch ();
						exit (0);
					}
				    } while (optz > 2 );
					break;
					default:
					system ("cls"); 
					printf ("\nOp��o errada\n");
					getch();
				} }while (menu2 !=4);
				 
				break;
				case 2:
				login();
				do{
				if (loginc == 7) {
					system ("cls");
					printf ("**********************************\n");
					printf ("\nBem vindo %s\n", loginl);
					printf ("\n1-Verificar a frota");
	    			printf ("\n2-Inserir carros");
	    			printf ("\n3-Eliminar carros");
	    			printf ("\n4-Alterar senha");
	    			printf ("\n5-Verificar funcion�rios");
					printf ("\n6-Sair\n");
					scanf ("%d",&menu2);
					switch (menu2){
					case 1:
					system ("cls");
					listar();
					break;
					case 2:
					system ("cls");
					inserir();
					break;
					case 3:
					system ("cls");
					eliminar();
					break;
					case 4:
					system ("cls");
					inserirs();
					break;
					case 5: 
					system ("cls");
					funcionaris();
					break;
					case 6:
					do {
					system ("cls");
					printf ("\nSe quiser sair, digite 1, se quiser voltar ao menu principal, digite 2\n");
					scanf ("%d",&optz);
					if (optz == 1) {
						system ("cls");
						printf ("\nSaindo...\n");
						getch ();
						exit (0);
					}
				    } while (optz > 2 );
					break;
					default:
					system ("cls"); 
					printf ("\nOp��o errada\n");
					getch();
					}
				} else {
					printf ("\nAcesso negado\n");
					getch ();
					menu1 = 4;
					exit (0);
				}}while (menu2 != 6);
				break;
				case 3:
				system ("cls");
				printf ("\nSaindo...\n");
				getch();
				break;
				default:
				system ("cls"); 
				printf ("\nOp��o errada\n");
				system ("pause");
			
				} } while (menu1 != 3);
		
		return 1;
	}
	
