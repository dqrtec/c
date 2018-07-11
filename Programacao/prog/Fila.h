#include "Aluno.h"

typedef struct fila Fila;

Fila *novo_f(Fila (fila));

int adiciona_f(Fila *fila , Aluno *aluno);

int retira_f(Fila *fila);

Aluno* busca(Fila *fila , int matricula);

int cheia_f(Fila *fila);

