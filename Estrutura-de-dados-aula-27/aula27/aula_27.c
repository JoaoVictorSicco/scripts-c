/*  struct e typedef struct são usados para definir estruturas em C, mas a diferença entre eles está principalmente na forma como você pode usar o nome da estrutura após a sua definição. */

/*
struct sem typedef:
Ao usar struct sem typedef, você precisa sempre se referir à estrutura usando o nome completo struct NomeDaEstrutura. Isso ocorre porque a estrutura é definida como um novo tipo de dados, mas o nome completo inclui a palavra-chave struct.
*/
struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa pessoa1;      // Sempre se refererindo ao nome completo da struct
    pessoa1.idade = 30;
    // ...
    return 0;
}

/*
typedef struct:
Com typedef struct, você pode criar um novo nome para a estrutura, tornando a sintaxe mais simples. Isso permite que você use apenas o novo nome da estrutura sem a palavra-chave struct.
*/
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main() {
    Pessoa pessoa1;             // Pessoa substitui -> typedef struct
    pessoa1.idade = 30;
    // ...
    return 0;
}

/*
    Ambos os exemplos criam uma estrutura chamada Pessoa com campos nome e idade. A principal diferença é que, no segundo exemplo, a estrutura é definida usando typedef, permitindo que você use apenas Pessoa em vez de struct Pessoa ao declarar variáveis.

    Geralmente, typedef struct é preferido porque torna o código mais legível e menos verboso, mas a escolha entre os dois depende das preferências de estilo e das necessidades do projeto.
*/

