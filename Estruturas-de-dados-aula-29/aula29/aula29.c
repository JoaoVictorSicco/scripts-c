/*
CRUD de structs (Create, Read, Update and Delete)

- Considere que o aluno possui possui um livro favorito que, por simplificação, possui um título, número de páginas e preço
- Codifique a struct de livro e adapte a struct de aluno
- Crie as funções de criação (C), Delete, e de impressão para a struct Aluno e Livro
- Na função de Delete, garanta que o ponteiro é atribuído como NULL depois da desalocação

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _livro
{
    char titulo[100];
    unsigned int num_paginas;
    float preco;
}Livro;

typedef struct _aluno
{
    char nome[100];
    int idade;
    Livro *livro_fav;       // Esse ponteiro vai apontar para o endereço da struct Livro    
      
}Aluno;

//Construtor de livro
Livro *create_livro(const char *titulo, unsigned int num_paginas, float preco) // Essa função retorna um endereço
{
    Livro *livro = (Livro *)calloc(1, sizeof(Livro)); // ponteiro que vai apontar para a struct livro e manipular os atributos
    strcpy(livro->titulo, titulo);
    livro->num_paginas = num_paginas;
    livro->preco = preco;
    return livro;
}
void destroy_livro(Livro **livro_ref)       // É passado um ponteiro para ponteiro
{
    // free(*livro_ref);            // *livro_ref aponta para o conteúdo do endereço de livro_harry, ou seja, a própr   ia struct   
    Livro *livro = *livro_ref;      // Esse ponteiro aponta para o própria struct 
    free(livro);
    *livro_ref = NULL;  
}

//Função para imprimir um livro
void print_livro(const Livro *livro)
{
    printf("Titulo: %s\n",livro->titulo);
    printf("Num paginas: %d\n",livro->num_paginas);
    printf("Preco: R$ %.2f\n",livro->preco);

}
Livro *copy_livro(const Livro *livro)
{
    return create_livro(livro->titulo,livro->num_paginas,livro->preco);
}

Aluno *create_aluno(const char *nome, int idade, const Livro *livro_fav)
{
    Aluno *aluno = (Aluno *)calloc(1,sizeof(Aluno));
    strcpy(aluno->nome,nome);
    aluno->idade = idade;
    aluno->livro_fav = copy_livro(livro_fav);
}

void destroy_aluno(Aluno **aluno_ref)
{
    Aluno *aluno = *aluno_ref;
    destroy_livro(&aluno->livro_fav);
    free(aluno);
    *aluno_ref = NULL;
}


void print_aluno(const Aluno *aluno)
{
    printf("Nome: %s\n",aluno->nome);
    printf("Idade: %d\n",aluno->idade);
    puts("Livro favorito: ");
    puts("----------");
    print_livro(aluno->livro_fav);
}

int main()
{

    Livro *livro_harry = create_livro("Harry potter 1",200,25); //Criando o primeiro livro - O ponteiro recebe o endereço retornado pela função
    print_livro(livro_harry);   // Imprimindo o livro usando a função
    puts("==================");
    livro_harry->preco = 100;
    print_livro(livro_harry);   // Imprimindo o livro usando a função


    Aluno *ted = create_aluno("Ted",20,livro_harry);
    // printf("livro_harry == NULL? %d\n", livro_harry == NULL);
    print_aluno(ted);
    destroy_livro(&livro_harry);
    print_aluno(ted);
    destroy_aluno(&ted);
}