#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

struct float_vector
{
    int capacity; //Número máximo de elementos do vetor
    int size;     //Quantidade de elementos armazenados atualmente
    float *data;  //Vetor de floats
};

/*
    @brief cria (aloca) um vetor de floats com uma dada capacidade
    @param capacity - capacidade do vetor
    @return - retorna um FloatVector* um vetor de floats alocado/criado
*/
FloatVector *create(int capacity)
{
    //Criando o ponteiro que vai apontar para a struct
    FloatVector *vec = (FloatVector*)calloc(1,sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float*)calloc(capacity,sizeof(float));

    return vec;
}

void destroy(FloatVector **vec_ref)
{
    //Primeiro desaloca o data
    FloatVector *vec = *vec_ref;
    free(vec->data);
    free(vec);
    *vec_ref = NULL;
}

void append(FloatVector *vec, float val)
{
    if(vec->size==vec->capacity)
    {
        fprintf(stderr,"ERRO IN 'append'\n");
        fprintf(stderr,"Vector is full\n");
        exit(EXIT_FAILURE);
    }
    vec->data[vec->size] = val;
    vec->size++;
}

void print(const FloatVector *vec)
{
    puts("--------------------------");
    printf("Size: %d\n",vec->size);
    printf("Capacity: %d\n",vec->capacity);
    puts("---------");

    for(int i=0;i<vec->size;i++)
    {
        printf("[%d] = %f\n",i,vec->data[i]);
    }
    puts("--------------------------\n");
    

}
