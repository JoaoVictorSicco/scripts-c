// Alocação estática e dinâmica de structs

/*

Alocação Estática de Structs usando typedef:
Na alocação estática usando typedef, você declara uma variável do tipo da struct e a memória para a struct é alocada automaticamente no momento da declaração. Assim como antes, a alocação estática é feita na pilha de execução e a memória é liberada automaticamente quando a variável sai de escopo.

*/

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main() {
    Pessoa pessoa1; // Alocação estática da struct usando typedef
    pessoa1.idade = 30;
    // ...
    return 0;
}


/*

Alocação Dinâmica de Structs usando typedef:
Na alocação dinâmica usando typedef, você declara um ponteiro para o tipo da struct e aloca memória dinamicamente usando funções como malloc. Isso permite que você controle manualmente a alocação e liberação de memória.

*/

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main() {
    Pessoa *pessoa_ptr; // Ponteiro para a struct usando typedef
    pessoa_ptr = (Pessoa *)malloc(sizeof(Pessoa)); // Alocação dinâmica usando typedef
    if (pessoa_ptr != NULL) {
        pessoa_ptr->idade = 30;
        // ...
        free(pessoa_ptr); // Libera a memória alocada dinamicamente
    }
    return 0;
}

