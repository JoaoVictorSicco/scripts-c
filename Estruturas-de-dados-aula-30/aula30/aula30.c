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


typedef struct _vet_livros
{
    Livro **vet;       // Vetor de ponteiros
    int size;          // Numero de elementos
    
}vetor_livros;


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

int main()
{
    // Criando um vetor de livros
    Livro **vet = (Livro **)calloc(3,sizeof(Livro * ));
    vet[0] = create_livro("HP1",100,25);
    vet[1] = create_livro("A batalha do apocalipse",200,40);
    vet[2] = create_livro("O senhor dos aneis",500,10);

    for(int i = 0; i<3;i++)
    {
        print_livro(vet[i]);
    }

    // Destroy
    for(int i=0; i<3;i++)
    {
        destroy_livro(&vet[i]);
    }
    free(vet);
    vet = NULL;
}