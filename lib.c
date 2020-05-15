#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct reg_livro{
  int codigo;
  char titulo[50];
  float preco;
};


struct reg_EDITORA
{
  int codigo;
  char nome[50];
 int contato;
 char email [50]
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


void listarAUTOR(){
FILE *fpautor;
struct reg_AUTOR ListAutor;

  //Abrir o Arquivo
  fpautor = fopen("autor.dat","rb");

  //Ler cada registro e mostrar na tela
  while (fread(&ListAutor,sizeof(ListAutor),1,fpautor) ==1) {
    printf("\n%3d %-30s %-10s ", ListAutor.codigo, ListAutor.nome,ListAutor.sobrenome);
  }

  //Fechar o aquivo
  fclose(fpautor);

}



int main(){
int op;

do{
  printf("\n\n::::::::::::::::: Livraria Saber :::::::::::::::::");
  printf("\n:: 1) Cadastrar autor                             ::");
  printf("\n:: 2) Listar autores                             ::");
  printf("\n:: 0) Sair                                        ::");
  printf("\n::                                                ::");
  printf("\n   Opcao-> ");
  fflush(stdin); scanf("%d",&op);

  switch(op){
  case 1:
    cadastrarAUTOR();
    break;
    case 2:
    listarAUTOR();
    break;
  }





}while (op!=0);

}//Fim main()
