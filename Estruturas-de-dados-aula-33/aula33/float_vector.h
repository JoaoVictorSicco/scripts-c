
typedef struct float_vector FloatVector;

// Definições das funções
FloatVector *create(int capacity);
void destroy(FloatVector **vec_ref);
int size(const FloatVector **vec);      // Retorna o tamanho atual do vetor (número atual de elementos inseridos)
int capacity(const FloatVector *vec);  //Recebe um ponteiro do tipo float vector que aponta para a struct
float at(const FloatVector *vec, int index);
float get(const FloatVector *vec, int index);
void append(FloatVector *vec, float val);
void set(FloatVector *vec, int index,float val);
void print(const FloatVector *vec);


