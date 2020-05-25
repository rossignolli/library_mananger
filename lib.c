#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
struct reg_LIVRO{
  int codigo;
  char titulo[50];
  float preco;
  int codAutor1,codAutor2,codAutor3,codAutor4;
  int codCategoria;
  int codEditora;
  int edicao;
  int ano;
  int qtde;
};


struct reg_EDITORA
{
  int codigo;
  char nome[50];
  char contato[50];
  char fone[25];
 char email [50];
};


struct reg_CATEGORIA
{
  int codigo;
  char nome[50];
};


struct reg_AUTOR
{
  int codigo;
  char sobrenome[50];
  char nome[50];
};


void cadastrarAUTOR(){
FILE *fpautor;
struct reg_AUTOR NovoAutor;
char opc;

  //Solicita os dados
  printf("\nDigite o codigo do Autor: ");
  fflush(stdin); scanf("%i",&NovoAutor.codigo);
  printf("Digite o nome do Autor: ");
  fflush(stdin); gets(NovoAutor.nome);
  printf("Digite o Sobrenome do Autor ");
  fflush(stdin); gets(NovoAutor.sobrenome);


  printf("\nGravar?(S/N) ");
  fflush(stdin); scanf("%c",&opc);

  if ((opc=='S')||(opc=='s')){
    //Abrir o Arquivo
    fpautor = fopen("autor.dat","ab");
    //Gravar
    fwrite(&NovoAutor,sizeof(NovoAutor),1,fpautor);
    //Fechar o Arquivo
    fclose(fpautor);
    printf("\nAutor cadastrado com sucesso");
  }
  else
    printf("\nOperacao Cancelada!");
	}

void cadastrarLIVRO(){
FILE *fplivro;
struct reg_LIVRO NovoLivro;
char opc;

  //Solicita os dados
  printf("Digite o código do livro:\n");
  fflush(stdin); scanf("%d",&NovoLivro.codigo);
  printf("Digite o título do livro:\n");
  fflush(stdin); gets(NovoLivro.titulo);
  printf("Digite o preço do livro:\n");
  fflush(stdin); scanf("%f",&NovoLivro.preco);
  printf("Digite o código do autor 1:\n");
  fflush(stdin); scanf("%d",&NovoLivro.codAutor1);
  printf("Digite o código do autor 2:\n");
  fflush(stdin); scanf("%d",&NovoLivro.codAutor2);
  printf("Digite o código do autor 3:\n");
  fflush(stdin); scanf("%d",&NovoLivro.codAutor3);
  printf("Digite o código do autor 4:\n");
  fflush(stdin); scanf("%d",&NovoLivro.codAutor4);
  printf("Digite o código da categoria do livro:\n");
  fflush(stdin); scanf("%d",&NovoLivro.codCategoria);
  printf("Digite o código da editora do livro:\n");
  fflush(stdin); scanf("%d",&NovoLivro.codEditora);
  printf("Digite a edição do livro:\n");
  fflush(stdin); scanf("%d",&NovoLivro.edicao);
  printf("Digite o ano do livro:\n");
  fflush(stdin); scanf("%d",&NovoLivro.ano);
  printf("Digite quantidade de livros:\n");
  fflush(stdin); scanf("%d",&NovoLivro.qtde);

  printf("\nGravar?(S/N) ");
  fflush(stdin); scanf("%c",&opc);

  if ((opc=='S')||(opc=='s')){
    //Abrir o Arquivo
    fplivro = fopen("livro.dat","ab");
    //Gravar
    fwrite(&NovoLivro,sizeof(NovoLivro),1,fplivro);
    //Fechar o Arquivo
    fclose(fplivro);
    printf("\nLivro cadastrado com sucesso");
  }
  else
    printf("\nOperacao Cancelada!");
}

void listarAUTOR(){
FILE *fpautor;
struct reg_AUTOR ListAutor;

  //Abrir o Arquivo
  fpautor = fopen("autor.dat","rb");

  //Ler cada registro e mostrar na tela
  while (fread(&ListAutor,sizeof(ListAutor),1,fpautor) ==1) {
    printf("\n%2d \n %s\n %s\n", ListAutor.codigo, ListAutor.nome,ListAutor.sobrenome);
  }

  //Fechar o aquivo
  fclose(fpautor);

}

void cadastrarCATEGORIA(){
FILE *fpcategoria;
struct reg_CATEGORIA NovaCategoria;
char opc;

  //Solicita os dados
  printf("\nDigite o codigo da categoria ");
  fflush(stdin); scanf("%i",&NovaCategoria.codigo);
  printf("Digite o nome da categoria (ex: Romance, Suspense, Ciencias");
  fflush(stdin); gets(NovaCategoria.nome);

  printf("\nGravar?(S/N) ");
  fflush(stdin); scanf("%c",&opc);

  if ((opc=='S')||(opc=='s')){
    //Abrir o Arquivo
    fpcategoria = fopen("categoria.dat","ab");
    //Gravar
    fwrite(&NovaCategoria,sizeof(NovaCategoria),1,fpcategoria);
    //Fechar o Arquivo
    fclose(fpcategoria);
    printf("\nAutor cadastrado com sucesso");
  }
  else
    printf("\nOperacao Cancelada!");
}

void listarCATEGORIA(){
FILE *fpCATEGORIA;
struct reg_CATEGORIA Categoria;

  //Abrir o Arquivo
  fpCATEGORIA = fopen("categoria.dat","rb");

  //Ler cada registro e mostrar na tela
  while (fread(&Categoria,sizeof(Categoria),1,fpCATEGORIA) ==1) {
    printf("\n%2d\n %s\n", Categoria.codigo, Categoria.nome);
  }

  //Fechar o aquivo
  fclose(fpCATEGORIA);

}

void cadastrarEDITORA(){
FILE *fpeditora;
struct reg_EDITORA NovaEditora;
char opc;

  //Solicita os dados
  printf("\nDigite o codigo da Editora: ");
  fflush(stdin); scanf("%i",&NovaEditora.codigo);
  printf("Digite o nome da Editora: ");
  fflush(stdin); gets(NovaEditora.nome);
  printf("Digite o nome de contato da Editora ");
  fflush(stdin); gets(NovaEditora.contato);
  printf("Digite o fone de contato da Editora ");
  fflush(stdin); gets(NovaEditora.fone);
  printf("Digite o e-mail de contato da Editora ");
  fflush(stdin); gets(NovaEditora.email);

  printf("\nGravar?(S/N) ");
  fflush(stdin); scanf("%c",&opc);

  if ((opc=='S')||(opc=='s')){
    //Abrir o Arquivo
    fpeditora = fopen("editora.dat","ab");
    //Gravar
    fwrite(&NovaEditora,sizeof(NovaEditora),1,fpeditora);
    //Fechar o Arquivo
    fclose(fpeditora);
    printf("\nEditora cadastrado com sucesso");
  }
  else
    printf("\nOperacao Cancelada!");
	}
	
void listarEditora(){
FILE *fpeditora;
struct reg_EDITORA editora;

  //Abrir o Arquivo
  fpeditora = fopen("editora.dat","rb");

  //Ler cada registro e mostrar na tela
  while (fread(&editora,sizeof(editora),1,fpeditora) ==1) {
    printf("\n%2d \n %s \n %s \n %s \n %s\n", editora.codigo, editora.nome,editora.contato,editora.fone,editora.email);
  }

  //Fechar o aquivo
  fclose(fpeditora);
}

void excluirLivro(){
	
  FILE *fplivro, *fplivronew;
  FILE *fpautor;
  FILE *fpcategoria;
  FILE *fpeditora;
  struct reg_LIVRO livro;
  struct reg_AUTOR autor;
  struct reg_CATEGORIA categoria;
  struct reg_EDITORA editora;
  int achou,cod;
  char op;

  fplivro = fopen("livro.dat","rb");

  printf("\nDigite o Codigo do Livro a ser Excluido: ");
  fflush(stdin); scanf("%i",&cod);

  //Localizar o Livro a ser Excluido
  achou=0;
  while ((!achou)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
    if (livro.codigo == cod){  //Livro Localizado
      printf("\nCodigo:    %d \nTitulo:    %s \nPreco:     %0.2f", livro.codigo, livro.titulo,livro.preco);
    //LISTAR AUTORES
    fpautor = fopen("autor.dat","rb");//Abrir o Arquivo
    while (fread(&autor,sizeof(autor),1,fpautor) ==1) {
    	if(livro.codAutor1 == autor.codigo){
         printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
        }
        if(livro.codAutor2 == autor.codigo){
        	printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor3 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor4 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
     }
     fclose(fpautor);//Fechar o arquivo
     //LISTAR CATEGORIA
     fpcategoria = fopen("categoria.dat","rb");//Abrir o Arquivo
      while (fread(&categoria,sizeof(categoria),1,fpcategoria) ==1) {
    	if(livro.codCategoria == categoria.codigo){
         printf("\nCategoria: %s",categoria.nome);
        }
     }
     fclose(fpcategoria);//Fechar o arquivo
     //LISTAR EDITORA
     fpeditora = fopen("editora.dat","rb");  //Abrir o Arquivo
     while (fread(&editora,sizeof(editora),1,fpeditora) ==1) {
    	if(livro.codEditora == editora.codigo){
         printf("\nEditora:   %s\nContato:   %s\n           %s\n           %s",editora.nome,editora.contato,editora.fone,editora.email);
        }
     }
     fclose(fpeditora);//Fechar o arquivo
     
    printf("\nEdicao:    %d \nAno:       %d \nQtde.:     %d",livro.edicao,livro.ano,livro.qtde);
    printf("\n");
      achou=1;
    }
  }
  
  
  
  
  
  
  fclose(fplivro);
  if (!achou){  //Não achou livro com este codigo. Retorna para o menu Principal
    printf("\nCodigo NAO Localizado!");
    return;
  }
  // Continua Aqui se encontrou o Livro
  printf("\nConfirma Exclusao(S/N)? ");
  fflush(stdin); scanf("%c",&op);
  if ((op=='S')||(op=='s')){
    fplivro = fopen("livro.dat","rb"); //Abre arquivo atual
    fplivronew = fopen("livroNew.dat","wb"); //Cria Arquivo Novo
    while(fread(&livro,sizeof(livro),1,fplivro)==1){ //Lê do Arquivo Atual
      if (livro.codigo!=cod) //Livro diferente do que sera excluido
        fwrite(&livro,sizeof(livro),1,fplivronew); //Grava no novo Arquivo
    }
    fclose(fplivro);  //Fecha arquivo Atual
    fclose(fplivronew); //Fecha arquivo Novo
    system("Del livro.dat");
    system("Ren livroNew.dat livro.dat");
    printf("Exclusao Realizada com Sucesso.");
  }else{
    printf("\nOperacao Cancelada!");
  }

}//Fim excluirLivro()

void consultarPeloCodigo(){
  FILE *fplivro;
  FILE *fpautor;
  FILE *fpcategoria;
  FILE *fpeditora;
  struct reg_LIVRO livro;
  struct reg_AUTOR autor;
  struct reg_CATEGORIA categoria;
  struct reg_EDITORA editora;
  int cod; //codigo a ser Localizado
  int achou=0;

  printf("\nDigite o Codigo do Livro a ser Localizado: ");
  fflush(stdin); scanf("%i",&cod);

  //Abrir o Arquivo
  fplivro = fopen("livro.dat","rb");

  //Ler cada registro e comparar com o codigo a ser localizado
  while ((!achou)&&(fread(&livro,sizeof(livro),1,fplivro) ==1)) {
    if (livro.codigo==cod){
         printf("\nCodigo:    %d \nTitulo:    %s \nPreco:     %0.2f", livro.codigo, livro.titulo,livro.preco);
    //LISTAR AUTORES
    fpautor = fopen("autor.dat","rb");//Abrir o Arquivo
    while (fread(&autor,sizeof(autor),1,fpautor) ==1) {
    	if(livro.codAutor1 == autor.codigo){
         printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
        }
        if(livro.codAutor2 == autor.codigo){
        	printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor3 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor4 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
     }
     fclose(fpautor);//Fechar o arquivo
     //LISTAR CATEGORIA
     fpcategoria = fopen("categoria.dat","rb");//Abrir o Arquivo
      while (fread(&categoria,sizeof(categoria),1,fpcategoria) ==1) {
    	if(livro.codCategoria == categoria.codigo){
         printf("\nCategoria: %s",categoria.nome);
        }
     }
     fclose(fpcategoria);//Fechar o arquivo
     //LISTAR EDITORA
     fpeditora = fopen("editora.dat","rb");  //Abrir o Arquivo
     while (fread(&editora,sizeof(editora),1,fpeditora) ==1) {
    	if(livro.codEditora == editora.codigo){
         printf("\nEditora:   %s\nContato:   %s\n           %s\n           %s",editora.nome,editora.contato,editora.fone,editora.email);
        }
     }
     fclose(fpeditora);//Fechar o arquivo
     
    printf("\nEdicao:    %d \nAno:       %d \nQtde.:     %d",livro.edicao,livro.ano,livro.qtde);
    printf("\n");
         achou=1;
    }
  }

  if (achou==0){
    printf("\nCodigo de Livro NAO existente.");
  }

  //Fechar o aquivo
  fclose(fplivro);
}

void listarLivros(){

FILE *fplivro;
FILE *fpautor;
FILE *fpcategoria;
FILE *fpeditora;

struct reg_AUTOR autor;
struct reg_CATEGORIA categoria;
struct reg_EDITORA editora;
struct reg_LIVRO livro;

  //Abrir o Arquivo
  fplivro = fopen("livro.dat","rb");
  //Ler cada registro e mostrar na tela
      
  while (fread(&livro,sizeof(livro),1,fplivro) ==1) {
  	
    printf("\nCodigo:    %d \nTitulo:    %s \nPreco:     %0.2f", livro.codigo, livro.titulo,livro.preco);
    //LISTAR AUTORES
    fpautor = fopen("autor.dat","rb");//Abrir o Arquivo
    while (fread(&autor,sizeof(autor),1,fpautor) ==1) {
    	if(livro.codAutor1 == autor.codigo){
         printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
        }
        if(livro.codAutor2 == autor.codigo){
        	printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor3 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor4 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
     }
     fclose(fpautor);//Fechar o arquivo
     //LISTAR CATEGORIA
     fpcategoria = fopen("categoria.dat","rb");//Abrir o Arquivo
      while (fread(&categoria,sizeof(categoria),1,fpcategoria) ==1) {
    	if(livro.codCategoria == categoria.codigo){
         printf("\nCategoria: %s",categoria.nome);
        }
     }
     fclose(fpcategoria);//Fechar o arquivo
     //LISTAR EDITORA
     fpeditora = fopen("editora.dat","rb");  //Abrir o Arquivo
     while (fread(&editora,sizeof(editora),1,fpeditora) ==1) {
    	if(livro.codEditora == editora.codigo){
         printf("\nEditora:   %s\nContato:   %s\n           %s\n           %s",editora.nome,editora.contato,editora.fone,editora.email);
        }
     }
     fclose(fpeditora);//Fechar o arquivo
     
    printf("\nEdicao:    %d \nAno:       %d \nQtde.:     %d",livro.edicao,livro.ano,livro.qtde);
    printf("\n");
  }
             

  //Fechar o aquivo
  fclose(fplivro);
}//Fim listarLivros()

void consultarPalavraChaveTitulo(){
	FILE *fplivro;
	FILE *fpautor;
	FILE *fpcategoria;
	FILE *fpeditora;
	
	struct reg_AUTOR autor;
    struct reg_CATEGORIA categoria;
    struct reg_EDITORA editora;
    struct reg_LIVRO livro;
    
    char palavra[50]; //Guarda a palavra chave digitada pelo usuário
    int achou=0;

  printf("\nDigite a Palavra chave: ");
  fflush(stdin); gets(palavra);

  //Abrir o Arquivo
  fplivro = fopen("livro.dat","rb");

  //Ler cada registro e verificar se o Título contém a palavra chave
  //Obs.: A função strstr() retorna NULL se não encontrar a palavra dentro do Título
  while (fread(&livro,sizeof(livro),1,fplivro) ==1) {
    if (strstr(livro.titulo,palavra)!=NULL){
	printf("\nCodigo:    %d \nTitulo:    %s \nPreco:     %0.2f", livro.codigo, livro.titulo,livro.preco);
	//LISTAR AUTORES
    fpautor = fopen("autor.dat","rb");//Abrir o Arquivo
    while (fread(&autor,sizeof(autor),1,fpautor) ==1) {
    	if(livro.codAutor1 == autor.codigo){
         printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
        }
        if(livro.codAutor2 == autor.codigo){
        	printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor3 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor4 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
     }
    fclose(fpautor);//Fechar o arquivo
      //LISTAR CATEGORIA
     fpcategoria = fopen("categoria.dat","rb");//Abrir o Arquivo
      while (fread(&categoria,sizeof(categoria),1,fpcategoria) ==1) {
    	if(livro.codCategoria == categoria.codigo){
         printf("\nCategoria: %s",categoria.nome);
        }
     }
     fclose(fpcategoria);//Fechar o arquivo
     //LISTAR EDITORA
     fpeditora = fopen("editora.dat","rb");  //Abrir o Arquivo
     while (fread(&editora,sizeof(editora),1,fpeditora) ==1) {
    	if(livro.codEditora == editora.codigo){
         printf("\nEditora:   %s\nContato:   %s\n           %s\n           %s",editora.nome,editora.contato,editora.fone,editora.email);
        }
     }
     fclose(fpeditora);//Fechar o arquivo
     printf("\nEdicao:    %d \nAno:       %d \nQtde.:     %d",livro.edicao,livro.ano,livro.qtde);
     printf("\n");
	achou=1;
    }
  }
  if (achou==0){
    printf("\nNenhum Livro possui a Palavra chave.");
  }
  //Fechar o aquivo
  fclose(fplivro);
  
}

void relLivrosTxt(){
	FILE *fplivro, *fpreltxt;;
	FILE *fpautor;
	FILE *fpcategoria;
	FILE *fpeditora;
	
	struct reg_AUTOR autor;
    struct reg_CATEGORIA categoria;
    struct reg_EDITORA editora;
    struct reg_LIVRO livro;


	char linha[100];
	int valor;
  //Abrir o Arquivo
  if ((fplivro = fopen("livro.dat","rb"))==NULL){
    printf("\nErro na Abertura do Arquivo: Livros.dat");
    return;
  }

	printf("\nInforme a quantidade que deseja mostrar:\n");
	fflush(stdin); scanf("%d",&valor);

  //Abrir o Arquivo TXT onde será gravado o Relatório
  if ((fpreltxt = fopen("relLivros.txt","w"))==NULL){
    printf("\nErro na Abertura do Arquivo: relLivros.txt");
    return;
  }

  fputs("========  Livraria Saber  =============\n",fpreltxt);
  fputs("       RELATORIO DE LIVROS\n\n",fpreltxt);
 

  //Ler cada registro e gravar no arquivo TXT
  while (fread(&livro,sizeof(livro),1,fplivro) ==1) {
	if(livro.qtde<=valor){
    sprintf(linha,"\nCodigo:    %d \nTitulo:    %s \nPreco:     %0.2f", livro.codigo, livro.titulo,livro.preco);
    fputs(linha,fpreltxt);
    //LISTAR AUTORES
    fpautor = fopen("autor.dat","rb");//Abrir o Arquivo
    while (fread(&autor,sizeof(autor),1,fpautor) ==1) {
    	if(livro.codAutor1 == autor.codigo){
         sprintf(linha,"\nAutor:     %s %s",autor.nome,autor.sobrenome);
         fputs(linha,fpreltxt);
        }
        if(livro.codAutor2 == autor.codigo){
        	sprintf(linha,"\nAutor:     %s %s",autor.nome,autor.sobrenome);
        	fputs(linha,fpreltxt);
		}
		if(livro.codAutor3 == autor.codigo){
			sprintf(linha,"\nAutor:     %s %s",autor.nome,autor.sobrenome);
			fputs(linha,fpreltxt);
		}
		if(livro.codAutor4 == autor.codigo){
			sprintf(linha,"\nAutor:     %s %s",autor.nome,autor.sobrenome);
			fputs(linha,fpreltxt);
		}
     }
    fclose(fpautor);//Fechar o arquivo
    //LISTAR CATEGORIA
     fpcategoria = fopen("categoria.dat","rb");//Abrir o Arquivo
      while (fread(&categoria,sizeof(categoria),1,fpcategoria) ==1) {
    	if(livro.codCategoria == categoria.codigo){
         sprintf(linha,"\nCategoria: %s",categoria.nome);
         fputs(linha,fpreltxt);
        }
     }
     fclose(fpcategoria);//Fechar o arquivo
     //LISTAR EDITORA
     fpeditora = fopen("editora.dat","rb");  //Abrir o Arquivo
     while (fread(&editora,sizeof(editora),1,fpeditora) ==1) {
    	if(livro.codEditora == editora.codigo){
         sprintf(linha,"\nEditora:   %s\nContato:   %s\n           %s\n           %s",editora.nome,editora.contato,editora.fone,editora.email);
         fputs(linha,fpreltxt);
        }
     }
     fclose(fpeditora);//Fechar o arquivo
     sprintf(linha,"\nEdicao:    %d \nAno:       %d \nQtde.:     %d",livro.edicao,livro.ano,livro.qtde);
     fputs(linha,fpreltxt);
     sprintf(linha,"\n");
     fputs(linha,fpreltxt);
}

  }

  printf("\n Relatorio gerado com sucesso. Arquivo> relLivros.txt");

 //Fechar o aquivo
  fclose(fplivro);
  fclose(fpreltxt);

}

void relLivrosCategoria(){
FILE *fplivro;
FILE *fpautor;
FILE *fpcategoria;
FILE *fpeditora;

struct reg_AUTOR autor;
struct reg_CATEGORIA categoria;
struct reg_EDITORA editora;
struct reg_LIVRO livro;
int cod;
  //Abrir o Arquivo
  fplivro = fopen("livro.dat","rb");
  
    printf("\nDigite a Categoria dos Livros a serem listadas: ");
    fflush(stdin); scanf("%i",&cod);
    
     //Ler cada registro e mostrar na tela
  while (fread(&livro,sizeof(livro),1,fplivro) ==1) {
  	if(livro.codCategoria == cod ){
	  
    printf("\nCodigo:    %d \nTitulo:    %s \nPreco:     %0.2f", livro.codigo, livro.titulo,livro.preco);
    //LISTAR AUTORES
    fpautor = fopen("autor.dat","rb");//Abrir o Arquivo
    while (fread(&autor,sizeof(autor),1,fpautor) ==1) {
    	if(livro.codAutor1 == autor.codigo){
         printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
        }
        if(livro.codAutor2 == autor.codigo){
        	printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor3 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor4 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
     }
     fclose(fpautor);//Fechar o arquivo
     //LISTAR CATEGORIA
     fpcategoria = fopen("categoria.dat","rb");//Abrir o Arquivo
      while (fread(&categoria,sizeof(categoria),1,fpcategoria) ==1) {
    	if(livro.codCategoria == categoria.codigo){
         printf("\nCategoria: %s",categoria.nome);
        }
     }
     fclose(fpcategoria);//Fechar o arquivo
     //LISTAR EDITORA
     fpeditora = fopen("editora.dat","rb");  //Abrir o Arquivo
     while (fread(&editora,sizeof(editora),1,fpeditora) ==1) {
    	if(livro.codEditora == editora.codigo){
         printf("\nEditora:   %s\nContato:   %s\n           %s\n           %s",editora.nome,editora.contato,editora.fone,editora.email);
        }
     }
     fclose(fpeditora);//Fechar o arquivo
     
    printf("\nEdicao:    %d \nAno:       %d \nQtde.:     %d",livro.edicao,livro.ano,livro.qtde);
    printf("\n");
	}	
  }
             

  //Fechar o aquivo
  fclose(fplivro);
}//Fim listarLivros()

void relLivrosAutor(){
FILE *fplivro;
FILE *fpautor;
FILE *fpcategoria;
FILE *fpeditora;

struct reg_AUTOR autor;
struct reg_CATEGORIA categoria;
struct reg_EDITORA editora;
struct reg_LIVRO livro;
int cod;
  //Abrir o Arquivo
  fplivro = fopen("livro.dat","rb");
  
    printf("\nDigite o código autor dos livros a serem listados: ");
    fflush(stdin); scanf("%i",&cod);
    
     //Ler cada registro e mostrar na tela
  while (fread(&livro,sizeof(livro),1,fplivro) ==1) {
  	if((livro.codAutor1 == cod)||(livro.codAutor2 == cod)||(livro.codAutor3 == cod)||(livro.codAutor4 == cod)){
	  
    printf("\nCodigo:    %d \nTitulo:    %s \nPreco:     %0.2f", livro.codigo, livro.titulo,livro.preco);
    //LISTAR AUTORES
    fpautor = fopen("autor.dat","rb");//Abrir o Arquivo
    while (fread(&autor,sizeof(autor),1,fpautor) ==1) {
    	if(livro.codAutor1 == autor.codigo){
         printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
        }
        if(livro.codAutor2 == autor.codigo){
        	printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor3 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(livro.codAutor4 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
     }
     fclose(fpautor);//Fechar o arquivo
     //LISTAR CATEGORIA
     fpcategoria = fopen("categoria.dat","rb");//Abrir o Arquivo
      while (fread(&categoria,sizeof(categoria),1,fpcategoria) ==1) {
    	if(livro.codCategoria == categoria.codigo){
         printf("\nCategoria: %s",categoria.nome);
        }
     }
     fclose(fpcategoria);//Fechar o arquivo
     //LISTAR EDITORA
     fpeditora = fopen("editora.dat","rb");  //Abrir o Arquivo
     while (fread(&editora,sizeof(editora),1,fpeditora) ==1) {
    	if(livro.codEditora == editora.codigo){
         printf("\nEditora:   %s\nContato:   %s\n           %s\n           %s",editora.nome,editora.contato,editora.fone,editora.email);
        }
     }
     fclose(fpeditora);//Fechar o arquivo
     
    printf("\nEdicao:    %d \nAno:       %d \nQtde.:     %d",livro.edicao,livro.ano,livro.qtde);
    printf("\n");
	}	
  }
             

  //Fechar o aquivo
  fclose(fplivro);
}//Fim listarLivros()

void relLivrosMaisCaro(){
FILE *fplivro;
FILE *fpautor;
FILE *fpcategoria;
FILE *fpeditora;

struct reg_AUTOR autor;
struct reg_CATEGORIA categoria;
struct reg_EDITORA editora;
struct reg_LIVRO livro;
struct reg_LIVRO maiscaro; //Guarda os dados do livro mais caro
int cod;
int achou = 0;


  //Abrir o Arquivo
  fplivro = fopen("livro.dat","rb");
  
    printf("\nDigite a Categoria do Livros a ser listado: ");
    fflush(stdin); scanf("%i",&cod);
   //Pega o primeiro e já coloca como mais caro
  if (fread(&livro,sizeof(livro),1,fplivro) ==1){
    maiscaro = livro;
  }else{
    printf("Nenhum livro Cadastrado!!!");
    fclose(fplivro);
    return;
  }

  //Ler os demais e encontrar o mais caro
  while ((fread(&livro,sizeof(livro),1,fplivro) ==1)) {
    if ((livro.codCategoria == cod)&&(livro.preco>maiscaro.preco)){
      maiscaro = livro;
    }
  }
  
	  
    printf("\nCodigo:    %d \nTitulo:    %s \nPreco:     %0.2f", maiscaro.codigo, maiscaro.titulo,maiscaro.preco);
    //LISTAR AUTORES
    fpautor = fopen("autor.dat","rb");//Abrir o Arquivo
    while (fread(&autor,sizeof(autor),1,fpautor) ==1) {
    	if(maiscaro.codAutor1 == autor.codigo){
            printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
        }
        if(maiscaro.codAutor2 == autor.codigo){
        	printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(maiscaro.codAutor3 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
		if(maiscaro.codAutor4 == autor.codigo){
			printf("\nAutor:     %s %s",autor.nome,autor.sobrenome);
		}
     }
     fclose(fpautor);//Fechar o arquivo
     //LISTAR CATEGORIA
     fpcategoria = fopen("categoria.dat","rb");//Abrir o Arquivo
      while (fread(&categoria,sizeof(categoria),1,fpcategoria) ==1) {
    	if(maiscaro.codCategoria == categoria.codigo){
         printf("\nCategoria: %s",categoria.nome);
        }
     }
     fclose(fpcategoria);//Fechar o arquivo
     //LISTAR EDITORA
     fpeditora = fopen("editora.dat","rb");  //Abrir o Arquivo
     while (fread(&editora,sizeof(editora),1,fpeditora) ==1) {
    	if(maiscaro.codEditora == editora.codigo){
         printf("\nEditora:   %s\nContato:   %s\n           %s\n           %s",editora.nome,editora.contato,editora.fone,editora.email);
        }
     }
     fclose(fpeditora);//Fechar o arquivo
     
    printf("\nEdicao:    %d \nAno:       %d \nQtde.:     %d",maiscaro.edicao,maiscaro.ano,maiscaro.qtde);
    printf("\n");
		
 
             

  //Fechar o aquivo
  fclose(fplivro);
}//Fim listarLivros()

void reajustarPreco(){ 
FILE *fplivro;
FILE *fpautor;
FILE *fpcategoria;
FILE *fpeditora;

struct reg_AUTOR autor;
struct reg_CATEGORIA categoria;
struct reg_EDITORA editora;
struct reg_LIVRO livro;
float porc;
long int deslocamento;
int codEditora;

printf("\nInforme o codigo da editora: ");
  fflush(stdin); scanf("%d",&codEditora);
printf("\nDigite a Porcentagem %% de Reajuste: ");
  fflush(stdin); scanf("%f",&porc);

  //Abrir o Arquivo
  if ((fplivro = fopen("livro.dat","rb+"))==NULL){
    printf("\nErro na Abertura do Arquivo: livro.dat");
    return;
  }

  while (fread(&livro,sizeof(livro),1,fplivro) ==1) {
  	if(livro.codEditora == codEditora ){
      livro.preco = livro.preco + (livro.preco*(porc*0.01));
      deslocamento = ftell(fplivro);  //pega a posicao atual do ponteiro (deslocamento em bytes a partir do inicio do arquivo)
      fseek(fplivro,-sizeof(livro),1); //Voltar o ponteiro
      fwrite(&livro,sizeof(livro),1,fplivro); //Gravou o registro com a alteracao do preco
      fseek(fplivro,deslocamento,0);
   }
  }
  fclose(fplivro);

  printf("\nReajuste de Precos realizado com sucesso.");
}


int main(){
int op;
setlocale(LC_ALL, "Portuguese");
do{
  printf("\n\n::::::::::::::::::::::::: Livraria Saber ::::::::::::::::::::::::::::");
  printf("\n:: 1)  Cadastrar livros                                            ::");
  printf("\n:: 2)  Cadastrar autores                                           ::");
  printf("\n:: 3)  Cadastrar categoria                                         ::");
  printf("\n:: 4)  Cadastrar editora                                           ::");
  printf("\n:: 5)  Listar livros                                               ::");
  printf("\n:: 6)  Listar autores                                              ::");
  printf("\n:: 7)  Listar categorias                                           ::");
  printf("\n:: 8)  Listar editoras                                             ::");
  printf("\n:: 9)  Excluir livros                                              ::");
  printf("\n:: 10) Consultar livro pelo código                                 ::");
  printf("\n:: 11) Consultar livro por palavra chave no título                 ::");
  printf("\n:: 12) Relatório de livros em txt                                  ::");
  printf("\n:: 13) Relatório de livros por categoria                           ::");
  printf("\n:: 14) Relatório de todos os livros de um autor                    ::");
  printf("\n:: 15) Relatório de livro mais caro por categoria solicitada       ::");
  printf("\n:: 16) Aplicar aumento de x%% nos livros de uma determinada Editora ::");
  printf("\n:: 0)  Sair                                                        ::");
  printf("\n::                                                                 ::");
  printf("\n   Opcao-> ");
  fflush(stdin); scanf("%d",&op);

  switch(op){
  case 1:
    cadastrarLIVRO();
    break;
  case 2:
    cadastrarAUTOR();
    break;
  case 3:
    cadastrarCATEGORIA();
    break;
  case 4:
     cadastrarEDITORA();
    break;
  case 5:
  	listarLivros();
    break;
  case 6:
    listarAUTOR();
    break;
  case 7:
  	listarCATEGORIA();
    break;
  case 8:
  	  listarEditora();
    break;
  case 9:
      excluirLivro();
    break;
  case 10:
  	  consultarPeloCodigo();
    break;
  case 11:
    consultarPalavraChaveTitulo();
    break;
  case 12:
    relLivrosTxt();
    break;
  case 13:
    relLivrosCategoria();
    break;
  case 14:
    relLivrosAutor();
    break;
  case 15:
    relLivrosMaisCaro();
    break;
  case 16:
    reajustarPreco();
    break;
  }

}while (op!=0);

}//Fim main()
