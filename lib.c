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
    printf("\n%3d %-30s", Categoria.codigo, Categoria.nome);
  }

  //Fechar o aquivo
  fclose(fpCATEGORIA);

}
































int main(){
int op;

do{
  printf("\n\n::::::::::::::::: Livraria Saber :::::::::::::::::");
  printf("\n:: 1) Cadastrar autor                             ::");
  printf("\n:: 2) Listar autores                             ::");
  printf("\n:: 3) Cadastrar Categoria                        ::");
  printf("\n:: 4) Listar Categoria                           ::");
  printf("\n:: 0) Sair                                       ::");
  printf("\n::                                               ::");
  printf("\n   Opcao-> ");
  fflush(stdin); scanf("%d",&op);

  switch(op){
  case 1:
    cadastrarAUTOR();
    break;
    case 2:
    listarAUTOR();
    break;
    case 3:
    cadastrarCATEGORIA();
    break;
    case 4:
    listarCATEGORIA();
    break;
  }





}while (op!=0);

}//Fim main()
